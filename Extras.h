#ifndef EXTRAS_H
#define	EXTRAS_H

using namespace std;

class Extras {
private:
    int codExtra;
    string nome;
    double preco;

public:
    Extras();
    Extras(int codExtra, string nome);
    Extras(int codExtra, string nome, double preco);
    Extras(const Extras &e);
    ~Extras();

    void setCodExtra(const int &codExtra);
    void setNome(string nome);
    void setPreco(const double &preco);

    int getCodExtra() const;
    string getNome() const;
    double getPreco() const;

    virtual Extras* clone() const;

    void escreve(ostream &out)const;
};

Extras::Extras() {
}

Extras::Extras(int codExtra, string nome) {
    setCodExtra(codExtra);
    setNome(nome);
    setPreco(preco);
}

Extras::Extras(int codExtra, string nome, double preco) {
    setCodExtra(codExtra);
    setNome(nome);
    setPreco(preco);
}

Extras::Extras(const Extras &e) {
    setCodExtra(e.getCodExtra());
    setNome(e.getNome());
    setPreco(e.getPreco());
}

Extras::~Extras() {
}

void Extras::setCodExtra(const int &codExtra) {
    this->codExtra = codExtra;
}

void Extras::setNome(string nome) {
    this->nome = nome;
}

void Extras::setPreco(const double &preco) {
    this->preco = preco;
}

int Extras::getCodExtra() const {
    return codExtra;
}

string Extras::getNome() const {
    return nome;
}

double Extras::getPreco() const {
    return preco;
}

Extras* Extras::clone() const {
    return new Extras(*this);
}

void Extras::escreve(ostream &out) const {
    out << "Codigo: " << codExtra
            << "\n\tNome: " << nome
            << "\n\tPreco: " << preco << endl << endl;
}

ostream & operator <<(ostream &out, const Extras &e) {
    e.escreve(out);
    return out;
}


#endif	/* EXTRAS_H */

