#ifndef ALUGUER_H
#define	ALUGUER_H

using namespace std;

#include "Data.h"

class Aluguer {
private:
    int numAluguer;
    int numCliente;
    int numCarro;
    Data dataLevantamento;
    string horaLevantamento;
    Data dataEntrega;
    string horaEntrega;
    double precoTotal;

public:
    Aluguer();
    Aluguer(int numAluguer, int numCliente, int numCarro, string horaLevantamento);
    Aluguer(int numAluguer, int numCliente, int numCarro, Data dataLevantamento, string horaLevantamento, Data dataEntrega, string horaEntrega, double precoTotal);
    Aluguer(const Aluguer &a);
    ~Aluguer();

    void setNumAluguer(const int &numAluguer);
    void setNumCliente(const int &numCliente);
    void setNumCarro(const int &numCarro);
    void setDataLevantamento(const Data &dataLevantamento);
    void setHoraLevantamento(string horaLevantamento);
    void setDataEntrega(const Data &dataEntrega);
    void setHoraEntrega(string horaEntrega);
    void setPrecoTotal(const double &precoTotal);

    int getNumAluguer() const;
    int getNumCliente() const;
    int getNumCarro() const;
    Data getDataLevantamento() const;
    string getHoraLevantamento() const;
    Data getDataEntrega() const;
    string getHoraEntrega() const;
    double getPrecoTotal() const;

    virtual Aluguer* clone() const;

    void escreve(ostream &out)const;
};

Aluguer::Aluguer() {
}

Aluguer::Aluguer(int numAluguer, int numCliente, int numCarro, string horaLevantamento) {
    setNumAluguer(numAluguer);
    setNumCliente(numCliente);
    setNumCarro(numCarro);
    setHoraLevantamento(horaLevantamento);
}

Aluguer::Aluguer(int numAluguer, int numCliente, int numCarro, Data dataLevantamento, string horaLevantamento, Data dataEntrega, string horaEntrega, double precoTotal) {
    setNumAluguer(numAluguer);
    setNumCliente(numCliente);
    setNumCarro(numCarro);
    setDataLevantamento(dataLevantamento);
    setHoraLevantamento(horaLevantamento);
    setDataEntrega(dataEntrega);
    setHoraEntrega(horaEntrega);
    setPrecoTotal(precoTotal);
}

Aluguer::Aluguer(const Aluguer &a) {
    setNumAluguer(a.getNumAluguer());
    setNumCliente(a.getNumCliente());
    setNumCarro(a.getNumCarro());
    setDataLevantamento(a.getDataLevantamento());
    setHoraLevantamento(a.getHoraLevantamento());
    setDataEntrega(a.getDataEntrega());
    setHoraEntrega(a.getHoraEntrega());
    setPrecoTotal(a.getPrecoTotal());
}

Aluguer::~Aluguer() {
}

void Aluguer::setNumAluguer(const int &numAluguer) {
    this->numAluguer = numAluguer;
}

void Aluguer::setNumCliente(const int &numCliente) {
    this->numCliente = numCliente;
}

void Aluguer::setNumCarro(const int &numCarro) {
    this->numCarro = numCarro;
}

void Aluguer::setDataLevantamento(const Data& dataLevantamento) {
    this->dataLevantamento = dataLevantamento;
}

void Aluguer::setHoraLevantamento(string horaLevantamento) {
    this->horaLevantamento = horaLevantamento;
}

void Aluguer::setDataEntrega(const Data& dataEntrega) {
    this->dataEntrega = dataEntrega;
}

void Aluguer::setHoraEntrega(string horaEntrega) {
    this->horaEntrega = horaEntrega;
}

void Aluguer::setPrecoTotal(const double& precoTotal) {
    this->precoTotal = precoTotal;
}

int Aluguer::getNumAluguer() const {
    return numAluguer;
}

int Aluguer::getNumCliente() const {
    return numCliente;
}

int Aluguer::getNumCarro() const {
    return numCarro;
}

Data Aluguer::getDataLevantamento() const {
    return dataLevantamento;
}

string Aluguer::getHoraLevantamento() const {
    return horaLevantamento;
}

Data Aluguer::getDataEntrega() const {
    return dataEntrega;
}

string Aluguer::getHoraEntrega() const {
    return horaEntrega;
}

double Aluguer::getPrecoTotal() const {
    return precoTotal;
}

Aluguer* Aluguer::clone() const {
    return new Aluguer(*this);
}

void Aluguer::escreve(ostream &out) const {
    out << "Nº Aluguer: " << numAluguer
            << "\n\tNº Cliente: " << numCliente
            << "\n\tNº Carro: " << numCarro
            << "\n\n\t<< Levantamento >>\n\t\tData: " << dataLevantamento
            << "\n\t\tHora: " << horaLevantamento
            << "\n\n\t<< ENTREGA >>\n\t\tData: " << dataEntrega
            << "\n\t\tHora: " << horaEntrega
            << "\n\n\tPreco Total: " << precoTotal << " euros" << endl << endl;
}

ostream & operator <<(ostream &out, const Aluguer &a) {
    a.escreve(out);
    return out;
}


#endif	/* ALUGUER_H */

