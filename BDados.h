#ifndef BDados_ 
#define BDados_ 

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mysql/mysql.h>
#include <iostream> 
#include <iomanip> 
#include <sstream>
#include <list> 

using namespace std;

#include "Cliente.h"
#include "TipoCarro.h"

class BDados {
private:
    sql::Driver *driver;
    sql::Connection *ligacao;
    //sql::Statement *instrucao;
    sql::PreparedStatement *instrucao;
    sql::ResultSet *rset;

public:
    BDados(string host, string user, string passwd, string db);
    ~BDados();

    void enviarCliente(string nome, int id, int cc, string contacto);
    void enviarTipoCarro(string tipo);

    list<Cliente> listarClientes();

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

#endif
