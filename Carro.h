#ifndef CARRO_H
#define	CARRO_H

using namespace std;

#include "Data.h"

class Carro {
private:
    int numCarro;
    string marca;
    string modelo;
    string matricula;
    Data dataMatricula;
    int kms;
    string combustivel;
    string tipoTransmissao;
    int numPortas;
    int numPassageiros;
    int codTipoCarro;
    double precoDiario;

public:
    Carro();
    Carro(int numCarro, string marca, string modelo, string matricula, Data dataMatricula, int kms, string combustivel, string tipoTransmissao, int numPortas, int numPassageiros, int codTipoCarro, double precoDiario);
    Carro(const Carro &c);
    ~Carro();

    void setNumCarro(const int &numCarro);
    void setMarca(string marca);
    void setModelo(string modelo);
    void setMatricula(string matricula);
    void setDataMatricula(const Data &dataMatricula);
    void setKms(const int &kms);
    void setCombustivel(string combustivel);
    void setTipoTransmissao(string tipoTransmissao);
    void setNumPortas(const int &numPortas);
    void setNumPassageiros(const int &numPassageiros);
    void setCodTipoCarro(const int &codTipoCarro);
    void setPrecoDiario(const double &precoDiario);

    int getNumCarro() const;
    string getMarca() const;
    string getModelo() const;
    string getMatricula() const;
    Data getDataMatricula() const;
    int getKms() const;
    string getCombustivel() const;
    string getTipoTransmissao() const;
    int getNumPortas() const;
    int getNumPassageiros() const;
    int getCodTipoCarro() const;
    double getPrecoDiario() const;

    virtual Carro* clone() const;

    void escreve(ostream &out)const;
};

Carro::Carro() {
}

Carro::Carro(int numCarro, string marca, string modelo, string matricula, Data dataMatricula, int kms, string combustivel, string tipoTransmissao, int numPortas, int numPassageiros, int codTipoCarro, double precoDiario) {
    setNumCarro(numCarro);
    setMarca(marca);
    setModelo(modelo);
    setMatricula(matricula);
    setDataMatricula(dataMatricula);
    setKms(kms);
    setCombustivel(combustivel);
    setTipoTransmissao(tipoTransmissao);
    setNumPortas(numPortas);
    setNumPassageiros(numPassageiros);
    setCodTipoCarro(codTipoCarro);
    setPrecoDiario(precoDiario);
}

Carro::Carro(const Carro &c) {
    setNumCarro(c.getNumCarro());
    setMarca(c.getMarca());
    setModelo(c.getModelo());
    setMatricula(c.getMatricula());
    setDataMatricula(c.getDataMatricula());
    setKms(c.getKms());
    setCombustivel(c.getCombustivel());
    setTipoTransmissao(c.getTipoTransmissao());
    setNumPortas(c.getNumPortas());
    setNumPassageiros(c.getNumPassageiros());
    setCodTipoCarro(c.getCodTipoCarro());
    setPrecoDiario(c.getPrecoDiario());
}

Carro::~Carro() {
}

void Carro::setNumCarro(const int &numCarro) {
    this->numCarro = numCarro;
}

void Carro::setMarca(string marca) {
    this->marca = marca;
}

void Carro::setModelo(string modelo) {
    this->modelo = modelo;
}

void Carro::setMatricula(string matricula) {
    this->matricula = matricula;
}

void Carro::setDataMatricula(const Data &dataMatricula) {
    this->dataMatricula = dataMatricula;
}

void Carro::setKms(const int &kms) {
    this->kms = kms;
}

void Carro::setCombustivel(string combustivel) {
    this->combustivel = combustivel;
}

void Carro::setTipoTransmissao(string tipoTransmissao) {
    this->tipoTransmissao = tipoTransmissao;
}

void Carro::setNumPortas(const int &numPortas) {
    this->numPortas = numPortas;
}

void Carro::setNumPassageiros(const int &numPassageiros) {
    this->numPassageiros = numPassageiros;
}

void Carro::setCodTipoCarro(const int &codTipoCarro) {
    this->codTipoCarro = codTipoCarro;
}

void Carro::setPrecoDiario(const double &precoDiario) {
    this->precoDiario = precoDiario;
}

int Carro::getNumCarro() const {
    return numCarro;
}

string Carro::getMarca() const {
    return marca;
}

string Carro::getModelo() const {
    return modelo;
}

string Carro::getMatricula() const {
    return matricula;
}

Data Carro::getDataMatricula() const {
    return dataMatricula;
}

int Carro::getKms() const {
    return kms;
}

string Carro::getCombustivel() const {
    return combustivel;
}

string Carro::getTipoTransmissao() const {
    return tipoTransmissao;
}

int Carro::getNumPortas() const {
    return numPortas;
}

int Carro::getNumPassageiros() const {
    return numPassageiros;
}

int Carro::getCodTipoCarro() const {
    return codTipoCarro;
}

double Carro::getPrecoDiario() const {
    return precoDiario;
}

Carro* Carro::clone() const {
    return new Carro(*this);
}

void Carro::escreve(ostream &out) const {
    out << "Nº: " << numCarro
            << "\n\tMarca: " << marca
            << "\n\tModelo: " << modelo
            << "\n\tMatricula: " << matricula
            << "\n\tData: " << dataMatricula
            << "\n\tKms: " << kms
            << "\n\tCombustivel: " << combustivel
            << "\n\tTransmissao: " << tipoTransmissao
            << "\n\tNº Portas: " << numPortas
            << "\n\tNº Passageiros: " << numPassageiros
            << "\n\tTipo Carro: " << codTipoCarro
            << "\n\tPreco Diario: " << precoDiario  << " euros" << endl << endl;
}

ostream & operator <<(ostream &out, const Carro &c) {
    c.escreve(out);
    return out;
}
#endif	/* CARRO_H */

