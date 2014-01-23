#ifndef TIPOCARRO_H
#define	TIPOCARRO_H

using namespace std;

class TipoCarro {
private:
    int codTipo;
    string tipo;

public:
    TipoCarro();
    TipoCarro(int codTipo, string tipo);
    TipoCarro(const TipoCarro &c);
    ~TipoCarro();

    void setCodTipo(const int &codTipo);
    void setTipo(string tipo);

    int getCodTipo() const;
    string getTipo() const;

    virtual TipoCarro* clone() const;

    void escreve(ostream &out)const;
};

TipoCarro::TipoCarro() {
}

TipoCarro::TipoCarro(int codTipo, string tipo) {
    setCodTipo(codTipo);
    setTipo(tipo);
}

TipoCarro::TipoCarro(const TipoCarro &tc) {
    setCodTipo(tc.getCodTipo());
    setTipo(tc.getTipo());
}

TipoCarro::~TipoCarro() {
}

void TipoCarro::setCodTipo(const int &codTipo) {
    this->codTipo = codTipo;
}

void TipoCarro::setTipo(string tipo) {
    this->tipo = tipo;
}

int TipoCarro::getCodTipo() const {
    return codTipo;
}

string TipoCarro::getTipo() const {
    return tipo;
}

TipoCarro* TipoCarro::clone() const {
    return new TipoCarro(*this);
}

void TipoCarro::escreve(ostream &out) const {
    out << "Codigo: " << codTipo
            << "\n\t" << tipo << endl << endl;
}

ostream & operator <<(ostream &out, const TipoCarro &tc) {
    tc.escreve(out);
    return out;
}

#endif	/* TIPOCARRO_H */

