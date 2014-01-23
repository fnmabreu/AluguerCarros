#ifndef BDADOS_H
#define	BDADOS_H

#include <iostream> 
#include <sstream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <list>

using namespace std;
using namespace sql;

#include "Cliente.h"
#include "Carro.h"
#include "TipoCarro.h"
#include "Extras.h"
#include "Aluguer.h"

class BDados {
private:
    Driver *driver;
    Connection *ligacao;
    Statement *stmt;
    PreparedStatement *instrucao;
    ResultSet *rset;

    Data stringToData(string data);
    int UltNumAluguer();
    long timeToMilisegundos(string time);


public:
    BDados(string host, string user, string passwd, string db);
    ~BDados();

    void enviarCliente(string nome, int id, int cc, string contacto);
    void enviarTipoCarro(string tipo);
    void enviarCarro(string marca, string modelo, string matricula, string data, int kms, string combustivel, string tipoTransmissao, int nportas, int npassageiros, int codTipoCarro, double preco);
    void enviarExtra(string extra, double preco);
    void enviarAluguer(int nCliente, int nCarro, string dataLev, string horaLev, string dataEnt, string horaEnt, double precoTotal);
    void enviarExtraAlugueres(int codExtra);

    void actualizaPrecoTotal(double precoTotal);

    list<Cliente> listarClientes();
    list<TipoCarro> listarTiposCarro();
    list<Carro> listarCarros();
    list<Extras> listarExtras();
    list<Aluguer> listarAluguer();

    double listaPrecoAluguer(int nCarro);
    double listaPrecoExtra();
    list<Aluguer> pesquisaAluguer(string dataLev);
    list<Extras> pesquisaExtras(int numAluguer);

    int calculaDifDatas(string dataLev, string dataEnt, string horaLev, string horaEnt);
};

BDados::BDados(string host, string user, string passwd, string db) {
    /* Create a connection */
    driver = get_driver_instance();
    ligacao = driver->connect(host, user, passwd);
    /* Connect to the MySQL test database */
    ligacao->setSchema(db);
}

BDados::~BDados() {
    ligacao->close();
    driver->threadEnd();
}

void BDados::enviarCliente(string nome, int id, int cc, string contacto) {

    stringstream out;
    out << "INSERT INTO clientes VALUES(NULL,'" << nome << "'," << id << "," << cc << ",'" << contacto << "')";
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    instrucao->executeUpdate();
    ligacao->commit();
    ligacao->close();
}

void BDados::enviarTipoCarro(string tipo) {

    stringstream out;
    out << "INSERT INTO tipo_carro VALUES(NULL,'" << tipo << "')";
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    instrucao->executeUpdate();
    ligacao->commit();
    ligacao->close();
}

void BDados::enviarCarro(string marca, string modelo, string matricula, string data, int kms, string combustivel, string tipoTransmissao, int nportas, int npassageiros, int codTipoCarro, double preco) {

    stringstream out;
    out << "INSERT INTO carros VALUES(NULL,'" << marca << "','" << modelo << "','" << matricula << "','" << data << "'," << kms << ",'" << combustivel << "','" << tipoTransmissao << "'," << nportas << "," << npassageiros << "," << codTipoCarro << "," << preco << ")";
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    instrucao->executeUpdate();
    ligacao->commit();
    ligacao->close();
}

void BDados::enviarExtra(string extra, double preco) {

    stringstream out;
    out << "INSERT INTO extras VALUES(NULL,'" << extra << "'," << preco << ")";
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    instrucao->executeUpdate();
    ligacao->commit();
    ligacao->close();
}

void BDados::enviarAluguer(int nCliente, int nCarro, string dataLev, string horaLev, string dataEnt, string horaEnt, double precoTotal) {

    stringstream out;
    out << "INSERT INTO alugueres VALUES(NULL," << nCliente << "," << nCarro << ",'" << dataLev << "','" << horaLev << "','" << dataEnt << "','" << horaEnt << "'," << precoTotal << ")";
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    instrucao->executeUpdate();
    ligacao->commit();
}

void BDados::enviarExtraAlugueres(int codExtra) {

    int numAluguer = UltNumAluguer();

    //Guarda os extras selecionados
    stringstream out;
    out << "INSERT INTO extras_alugueres VALUES(" << numAluguer << "," << codExtra << ")";
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    instrucao->executeUpdate();
    ligacao->commit();

}

void BDados::actualizaPrecoTotal(double precoTotal) {

    stringstream out;
    int numAluguer = UltNumAluguer();

    out << "UPDATE alugueres SET preco_total = " << precoTotal << " WHERE num_aluguer = " << numAluguer;
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    instrucao->executeUpdate();
    ligacao->commit();
}

list<Cliente> BDados::listarClientes() {

    list<Cliente> ret;
    string sql = "SELECT * FROM clientes";
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        Cliente c(rset->getInt(1), rset->getString(2), rset->getInt(3), rset->getInt(4), rset->getString(5));
        ret.push_back(c);
    }
    instrucao->close();

    return ret;
}

list<TipoCarro> BDados::listarTiposCarro() {

    list<TipoCarro> ret;
    string sql = "SELECT * FROM tipo_carro";
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        TipoCarro t(rset->getInt(1), rset->getString(2));
        ret.push_back(t);
    }
    instrucao->close();

    return ret;
}

list<Carro> BDados::listarCarros() {

    list<Carro> ret;

    string sql = "SELECT * FROM carros";
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        Data data = stringToData(rset->getString(5));
        Carro c(rset->getInt(1), rset->getString(2), rset->getString(3), rset->getString(4), data, rset->getInt(6), rset->getString(7), rset->getString(8), rset->getInt(9), rset->getInt(10), rset->getInt(11), rset->getDouble(12));
        ret.push_back(c);
    }
    instrucao->close();

    return ret;
}

list<Extras> BDados::listarExtras() {

    list<Extras> ret;
    string sql = "SELECT * FROM extras";
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        Extras e(rset->getInt(1), rset->getString(2), rset->getDouble(3));
        ret.push_back(e);
    }
    instrucao->close();

    return ret;
}

list<Aluguer> BDados::listarAluguer() {

    list<Aluguer> ret;
    string sql = "SELECT * FROM alugueres";
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        Data dataLev = stringToData(rset->getString(4));
        Data dataEnt = stringToData(rset->getString(6));
        Aluguer a(rset->getInt(1), rset->getInt(2), rset->getInt(3), dataLev, rset->getString(5), dataEnt, rset->getString(7), rset->getDouble(8));
        ret.push_back(a);
    }
    instrucao->close();

    return ret;
}

double BDados::listaPrecoAluguer(int nCarro) {

    stringstream out;
    double preco;

    out << "SELECT preco_diario AS preco FROM carros WHERE num_carro= " << nCarro;
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        preco = rset->getDouble("preco");
    }
    instrucao->close();

    return preco;
}

double BDados::listaPrecoExtra() {

    stringstream out;
    double precoExtra = 0;
    int numAluguer = UltNumAluguer();

    out << "SELECT SUM(preco_extra) AS totalExtra FROM extras,extras_alugueres WHERE extras.cod_extra = extras_alugueres.cod_extra AND extras_alugueres.num_aluguer = " << numAluguer;
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        precoExtra = rset->getDouble("totalExtra");
    }
    instrucao->close();

    return precoExtra;
}

list<Aluguer> BDados::pesquisaAluguer(string dataLev) {

    stringstream out;
    list<Aluguer> ret;
    bool encontrouAlugueres = false;

    out << "SELECT * FROM alugueres where data_levantamento = '" << dataLev << "'";
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        encontrouAlugueres = true;
        Aluguer a(rset->getInt(1), rset->getInt(2), rset->getInt(3), rset->getString(5));
        ret.push_back(a);
    }

    if (encontrouAlugueres == false) {
        cout << "\t** Não existe nenhum aluguer na data indicada!" << endl;
    }
    instrucao->close();

    return ret;
}

list<Extras> BDados::pesquisaExtras(int numAluguer) {

    stringstream out;
    list<Extras> ret;
    bool encontrouAlugueres = false;

    out << "SELECT * FROM extras,extras_alugueres WHERE extras.cod_extra = extras_alugueres.cod_extra AND extras_alugueres.num_aluguer = " << numAluguer;
    string sql = out.str();
    instrucao = ligacao->prepareStatement(sql);
    rset = instrucao->executeQuery();

    while (rset->next()) {
        encontrouAlugueres = true;
        Extras e(rset->getInt(1), rset->getString(2));
        ret.push_back(e);
    }

    if (encontrouAlugueres == false) {
        cout << "\t** Não existe nenhum aluguer na data indicada!" << endl;
    }
    instrucao->close();

    return ret;
}

/**
 * Converte uma string para um tipo Data
 */
Data BDados::stringToData(string data) {
    int ano, mes, dia;
    if (data.size() > 1) {
        int inic = 0;

        int pos = data.find('-', inic);
        string primeiro(data.substr(inic, pos - inic));
        ano = atoi(primeiro.c_str());
        pos++;
        inic = pos;

        pos = data.find('-', inic);
        string segundo(data.substr(inic, pos - inic));
        mes = atoi(segundo.c_str());
        pos++;
        inic = pos;

        pos = data.find('-', inic);
        string terceiro(data.substr(inic, pos - inic));
        dia = atoi(terceiro.c_str());
    }
    return Data(ano, mes, dia);
}

/**
 * Retorna o ultimo codigo criado na base dados
 */
int BDados::UltNumAluguer() {

    int numAluguer = 0;

    //Determina o num_aluguer gerado
    string sqlUltimoNumAluguer = "SELECT MAX(num_aluguer) AS ultimo_num FROM alugueres";
    instrucao = ligacao->prepareStatement(sqlUltimoNumAluguer);
    rset = instrucao->executeQuery();
    if (rset->next())
        numAluguer = rset->getInt("ultimo_num");

    return numAluguer;
}

/**
 * Retorna numero dias entre duas datas 
 */
int BDados::calculaDifDatas(string dataLev, string dataEnt, string horaLev, string horaEnt) {

    int numDias = stringToData(dataLev).diferenca(stringToData(dataEnt));

    if (timeToMilisegundos(horaEnt) > timeToMilisegundos(horaLev))
        numDias++;

    return numDias;
}

/**
 * Converte uma hora para Milisegundos
 */
long BDados::timeToMilisegundos(string time) {
    int hora, min, sec;

    if (time.size() > 1) {
        int inic = 0;

        int pos = time.find(':', inic);
        string primeiro(time.substr(inic, pos - inic));
        hora = atoi(primeiro.c_str());
        pos++;
        inic = pos;

        pos = time.find(':', inic);
        string segundo(time.substr(inic, pos - inic));
        min = atoi(segundo.c_str());
        pos++;
        inic = pos;

        pos = time.find(':', inic);
        string terceiro(time.substr(inic, pos - inic));
        sec = atoi(terceiro.c_str());
    }

    long horaMilisegundos = (hora * 1000 * 60 * 60) + (min * 1000 * 60) + sec * 1000;

    return horaMilisegundos;
}

#endif	/* BDADOS_H */
