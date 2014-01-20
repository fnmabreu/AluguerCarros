#ifndef CLIENTE_H
#define	CLIENTE_H

using namespace std;

class Cliente {
private:
    int codCliente;
    string nome;
    int docId; /* Nº Documento identificao */
    int cc; /* Nº Carta Conducao */
    string contacto;

public:
    Cliente();
    Cliente(int codCliente, string nome, int docId, int cc, string contacto);
    Cliente(const Cliente &c);
    ~Cliente();

    void setCodCliente(const int &codCliente);
    void setNome(string nome);
    void setDocId(const int &docId);
    void setCc(const int &cc);
    void setContacto(string contacto);

    int getCodCliente() const;
    string getNome() const;
    int getDocId() const;
    int getCc() const;
    string getContacto() const;

    virtual Cliente* clone() const;

    void escreve(ostream &out)const;
};

Cliente::Cliente() {
}

Cliente::Cliente(int codCliente, string nome, int docId, int cc, string contacto) {
    setCodCliente(codCliente);
    setNome(nome);
    setDocId(docId);
    setCc(cc);
    setContacto(contacto);
}

Cliente::Cliente(const Cliente &c) {
    setCodCliente(c.getCodCliente());
    setNome(c.getNome());
    setDocId(c.getDocId());
    setCc(c.getCc());
    setContacto(c.getContacto());
}

Cliente::~Cliente() {
}

void Cliente::setCodCliente(const int &codCliente) {
    this->codCliente = codCliente;
}

void Cliente::setNome(string nome) {
    this->nome = nome;
}

void Cliente::setDocId(const int &docId) {
    this->docId = docId;
}

void Cliente::setCc(const int &cc) {
    this->cc = cc;
}

void Cliente::setContacto(string contacto) {
    this->contacto = contacto;
}

int Cliente::getCodCliente() const {
    return codCliente;
}

string Cliente::getNome() const {
    return nome;
}

int Cliente::getDocId() const {
    return docId;
}

int Cliente::getCc() const {
    return cc;
}

string Cliente::getContacto() const {
    return contacto;
}

Cliente* Cliente::clone() const {
    return new Cliente(*this);
}

void Cliente::escreve(ostream &out) const {
    out << "Nº: " << codCliente
            << "\nNome: " << nome
            << "\nDoc. ID: " << docId
            << "\nC. Conducao: " << cc
            << "\nContacto: " << contacto << endl << endl;
}

ostream & operator <<(ostream &out, const Cliente &c) {
    c.escreve(out);
    return out;
}

#endif	/* CLIENTE_H */

