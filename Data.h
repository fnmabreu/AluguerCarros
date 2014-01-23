#ifndef DATA_H
#define	DATA_H

#include <string>
#include <iostream>

using namespace std;

class Data {
private:
    int ano; // qualquer ano
    int mes; // 1-12
    int dia; // 1-31 dependente do męs

    static int diasPorMes[];
    int validaDia(int d) const; // Confirma o valor do dia baseado no mes e ano 
    int validaMes(int m) const;
    int validaAno(int a) const;
    bool anoBissexto(int a) const; // Testa se ano é bissexto
    int contaDias();

public:

    Data();
    Data(int a, int m, int d);
    Data(const Data &d);
    ~Data();

    void setAno(int a);
    void setMes(int m);
    void setDia(int d);
    void setData(Data dt);

    int getAno() const;
    int getMes() const;
    int getDia() const;
    int getAnos() const;

    int diferenca(Data d1);
    void listar() const;

};

int Data::diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Data::Data() {
    setAno(1900);
    setMes(1);
    setDia(1);
}

// Confirma o valor do mes e chama o metodo validaDia
// para confirmar o valor do dia.

Data::Data(int a, int m, int d) {
    setAno(a);
    setMes(m);
    setDia(d);
}

Data::Data(const Data &d) {
    ano = d.ano;
    mes = d.mes;
    dia = d.dia;
}

Data::~Data() {

}

// Confirma o valor do dia baseado no mes e ano.

int Data::validaDia(int d) const {
    if (d > 0 && d <= diasPorMes[ mes ])
        return d;
    // se Fevereiro: Verifica se ano bissexto
    if (mes == 2 && d == 29 && anoBissexto(ano))
        return d;
    cout << "Dia " << d << " invalido. Colocado o dia 1.";
    return 1; // Deixa o objecto num estado consistente
}

int Data::validaMes(int m) const {
    if (m > 0 && m <= 12) // valida o mes
        return m;
    else {
        cout << "\nMęs inválido -> mes=1";
        return 1;
    }
}

int Data::validaAno(int a) const {
    if (a < 0) {
        cout << "\nAno negativo - inválido -> ano=0";
        return 0;
    } else
        return a;
}

bool Data::anoBissexto(int a) const {
    return ( a % 400 == 0 || a % 4 == 0 && a % 100 != 0);
}

// Outros métodos

void Data::setAno(int a) {
    ano = validaAno(a);

}

void Data::setMes(int m) {
    mes = validaMes(m); // valida o mes

}

void Data::setDia(int d) {
    dia = validaDia(d); // valida o dia

}

void Data::setData(Data dt) {
    setAno(dt.ano);
    setMes(dt.mes);
    setDia(dt.dia);
}

int Data::getAno() const {
    return ano;
}

int Data::getMes() const {
    return mes;
}

int Data::getDia() const {
    return dia;
}

int Data::getAnos() const {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    if ((timeinfo->tm_mon + 1) < mes)
        return ((timeinfo->tm_year + 1900)-(ano + 1));
    else if ((timeinfo->tm_mon + 1) == mes)
        if (timeinfo->tm_mday < dia)
            return (timeinfo->tm_year + 1900)-(ano + 1);
        else
            return ((timeinfo->tm_year + 1900) - ano);
    else
        return (timeinfo->tm_year + 1900) - ano;
}

int Data::contaDias() {
    int totalDias = 0;

    for (int i = 1; i < ano; i++) {
        totalDias += anoBissexto(i) ? 366 : 365;
    }
    for (int i = 1; i < mes; i++) {
        totalDias += diasPorMes[i];
    }
    totalDias += (anoBissexto(ano) && mes > 2) ? 1 : 0;
    totalDias += dia;

    return totalDias;
}

int Data::diferenca(Data d1) {
    int totalDias = contaDias();
    int totalDias1 = d1.contaDias();

    return abs(totalDias - totalDias1);
}

void Data::listar() const {
    cout << dia << "/" << mes << "/" << ano;
}

ostream & operator <<(ostream &out, const Data &d) {
    d.listar();
    return out;
}

#endif	/* DATA_H */

