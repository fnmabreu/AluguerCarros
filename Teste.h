#ifndef TESTE_H
#define	TESTE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
#include <stdio.h>

using namespace std;

#include "BDados.h"
#define HOST "127.0.0.1:3306"
#define USER "root"
#define PASS "fabio"
#define DB "aluguer_carros"

class Teste {
private:

public:
    Teste();
    ~Teste();
    void novoCliente();
    void novoTipoCarro();
    
    void listaClientes();

};

Teste::Teste() {
}

Teste::~Teste() {
}

/**
 * Cria novo cliente na Base de Dados
 */
void Teste::novoCliente() {
    string nome, contacto;
    int id, cc;

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "\nNOVO CLIENTE" << endl << endl;

        cout << "Nome: ";
        fflush(stdin);
        getline(cin, nome);

        cout << "Doc. ID: ";
        cin >> id;

        cout << "C. conducao: ";
        cin >> cc;

        cout << "Contacto: ";
        cin >> contacto;

        c->enviarCliente(nome, id, cc, contacto);

        cout << endl << "<< Cliente foi guardado na Base de Dados com sucesso! >>" << endl << endl;

    } catch (sql::SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Cria novo tipo de carro na Base de Dados
 */
void Teste::novoTipoCarro() {
    string tipo;

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "\nNOVO TIPO CARRO" << endl << endl;

        cout << "Tipo Carro: ";
        fflush(stdin);
        getline(cin, tipo);

        c->enviarTipoCarro(tipo);

        cout << endl << "<< Tipo Carro foi guardado na Base de Dados com sucesso! >>" << endl << endl;

    } catch (sql::SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}


/**
 * Listar todos os clientes existentes na BD
 */
void Teste::listaClientes() {

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        list<Cliente> clientes = c->listarClientes();
        cout << "CLIENTES:" << endl << endl;
        for (list<Cliente>::iterator it = clientes.begin(); it != clientes.end(); it++) {
            (*it).escreve(cout);
        }
        delete(c);
    } catch (sql::SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}


#endif	/* TESTE_H */

