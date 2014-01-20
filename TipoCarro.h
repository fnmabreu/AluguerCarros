#ifndef TIPOCARRO_H
#define	TIPOCARRO_H

using namespace std;

class TipoCarro {
private:
    string tipo;

public:
    TipoCarro();
    TipoCarro(string tipo);
    TipoCarro(const TipoCarro &c);
    ~TipoCarro();

    void setTipo(string tipo);

    string getTipo() const;

    virtual TipoCarro* clone() const;

    void escreve(ostream &out)const;
};

TipoCarro::TipoCarro() {
}

TipoCarro::TipoCarro(string tipo) {
    setTipo(tipo);
}

TipoCarro::TipoCarro(const TipoCarro &tc) {
    setTipo(tc.getTipo());
}

TipoCarro::~TipoCarro() {
}

void TipoCarro::setTipo(string tipo) {
    this->tipo = tipo;
}

string TipoCarro::getTipo() const {
    return tipo;
}

TipoCarro* TipoCarro::clone() const {
    return new TipoCarro(*this);
}

void TipoCarro::escreve(ostream &out) const {
    out << "\t" << tipo << endl << endl;
}

ostream & operator <<(ostream &out, const TipoCarro &tc) {
    tc.escreve(out);
    return out;
}


#endif	/* TIPOCARRO_H */

