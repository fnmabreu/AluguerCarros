#ifndef TESTE_H
#define	TESTE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

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
    void novoCarro();
    void novoExtra();
    void novoAluguer();

    void listaClientes();
    void listaTipoCarro();
    void listaCarros();
    void listaExtras();
    void listaAlugueres();

    void pesquisaAlugueres();
    void pesquisaClientes();

};

Teste::Teste() {
}

Teste::~Teste() {
}

/**
 * Cria novo cliente na Base de Dados
 */
void Teste::novoCliente() {
    string nome, contacto, verifica;
    int id, cc;

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "\nNOVO CLIENTE" << endl << endl;

        do {
            cout << "Nome: ";
            fflush(stdin);
            getline(cin, nome);
        } while (nome.empty());

        do {
            cout << "Doc. ID: ";
            cin >> verifica;
            id = atoi(verifica.c_str());
        } while (id == 0);

        do {
            cout << "C. conducao: ";
            cin >> verifica;
            cc = atoi(verifica.c_str());
        } while (cc == 0);

        do {
            cout << "Contacto: ";
            fflush(stdin);
            getline(cin, contacto);
        } while (contacto.empty());

        c->enviarCliente(nome, id, cc, contacto);
        cout << endl << "<< Dados do cliente " << nome << " foi guardado na Base de Dados com sucesso! >>" << endl << endl;


    } catch (SQLException &e) {
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

        do {
            cout << "Tipo Carro: ";
            fflush(stdin);
            getline(cin, tipo);
        } while (tipo.empty());

        c->enviarTipoCarro(tipo);
        cout << endl << "<< Tipo Carro " << tipo << " foi guardado na Base de Dados com sucesso! >>" << endl << endl;

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Cria novo carro na Base de Dados
 */
void Teste::novoCarro() {
    string marca, modelo, matricula, data, combustivel, tipoTransmissao, verifica;
    int kms, nportas, npassageiros, tipoCarro;
    double preco;
    char op = 's';

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "\nNOVO CARRO" << endl << endl;

        do {
            cout << "Marca: ";
            setbuf(stdin, NULL);
            getline(cin, marca);
        } while (marca.empty());

        cout << "Modelo: ";
        fflush(stdin);
        getline(cin, modelo);

        do {
            cout << "Matricula: ";
            fflush(stdin);
            getline(cin, matricula);
        } while (matricula.empty());

        do {
            cout << "Data (YYYY/MM/DD): ";
            cin >> data;
        } while (data.empty());

        do {
            cout << "Kms: ";
            cin >> verifica;
            kms = atoi(verifica.c_str());
        } while (kms == 0);

        do {
            cout << "Combustivel (gasoleo,gasolina): ";
            cin >> combustivel;
        } while (combustivel.compare("gasoleo") && combustivel.compare("gasolina"));

        do {
            cout << "Transmissao (manual,automatico): ";
            cin >> tipoTransmissao;
        } while (tipoTransmissao.compare("manual") && tipoTransmissao.compare("automatico"));

        do {
            cout << "Nº portas: ";
            cin >> verifica;
            nportas = atoi(verifica.c_str());
        } while (nportas == 0);

        do {
            cout << "Nº passageiros: ";
            cin >> verifica;
            npassageiros = atoi(verifica.c_str());
        } while (npassageiros == 0);


        cout << "\nDeseja listar tipos de carro? (S/N)" << endl;
        cin >> op;
        if (op == 's' || op == 'S') {
            listaTipoCarro();
        }

        do {
            cout << "Escolha o codigo do tipo de carro: ";
            cin >> verifica;
            tipoCarro = atoi(verifica.c_str());
        } while (tipoCarro == 0);

        do {
            cout << "Preco diario: ";
            cin >> verifica;
            preco = atof(verifica.c_str());
        } while (preco == 0);

        c->enviarCarro(marca, modelo, matricula, data, kms, combustivel, tipoTransmissao, nportas, npassageiros, tipoCarro, preco);
        delete(c);
        cout << endl << "<< Dados do carro " << marca << " foi guardado na Base de Dados com sucesso! >>" << endl << endl;

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Cria novo extra na Base de Dados
 */
void Teste::novoExtra() {
    string extra, verifica;
    double preco;

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "\nNOVO EXTRA" << endl << endl;

        do {
            cout << "Extra: ";
            fflush(stdin);
            getline(cin, extra);
        } while (extra.empty());

        do {
            cout << "Preco: ";
            cin >> verifica;
            preco = atof(verifica.c_str());
        } while (preco == 0);

        c->enviarExtra(extra, preco);
        delete(c);
        cout << endl << "<< Extra " << extra << " foi guardado na Base de Dados com sucesso! >>" << endl << endl;

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Cria novo Aluguer na Base de Dados
 */
void Teste::novoAluguer() {
    int nCliente, nCarro, codExtra;
    string dataLev, horaLev, dataEnt, horaEnt, verifica;
    double precoTotal = 0;
    char opcao = 's';

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "\nNOVO ALUGUER" << endl << endl;

        do {
            cout << "Cliente: ";
            cin >> verifica;
            nCliente = atoi(verifica.c_str());
        } while (nCliente == 0);

        do {
            cout << "Carro: ";
            cin >> verifica;
            nCarro = atoi(verifica.c_str());
        } while (nCarro == 0);

        cout << "\n<< LEVANTAMENTO >>";
        cout << "\n\tData (YYYY-MM-DD): ";
        cin >> dataLev;

        cout << "\tHora: ";
        cin >> horaLev;

        cout << "\n<< ENTREGA >>";
        cout << "\n\tData (YYYY-MM-DD): ";
        cin >> dataEnt;

        cout << "\tHora: ";
        cin >> horaEnt;

        c->enviarAluguer(nCliente, nCarro, dataLev, horaLev, dataEnt, horaEnt, precoTotal);

        cout << "\nDeseja adicionar um extra? (S/N)" << endl;
        cin >> opcao;
        while (opcao == 's' || opcao == 'S') {

            listaExtras();

            do {
                cout << "\nEscolha o codigo do extra: ";
                cin >> verifica;
                codExtra = atoi(verifica.c_str());
            } while (codExtra == 0);

            //Guarda os extras selecionados
            c->enviarExtraAlugueres(codExtra);

            cout << endl << "<< Extra foi adicionado com sucesso. >>" << endl;

            cout << "\nDeseja inserir mais algum extra? (S/N)" << endl;
            cin >> opcao;
        }

        //Calculo total = (PrecoCarro + PrecoExtras) ou (PrecoCarro)
        //PrecoExtras e opcional
        double precoTotal = c->listaPrecoAluguer(nCarro) * c->calculaDifDatas(dataLev, dataEnt, horaLev, horaEnt) + c->listaPrecoExtra();
        c->actualizaPrecoTotal(precoTotal);

        cout << endl << "<< Dados do Aluguer foram guardados com sucesso! >>" << endl << endl;
        delete(c);

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Listar todos os clientes existentes na BD
 */
void Teste::listaClientes() {

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "CLIENTES:" << endl << endl;
        list<Cliente> clientes = c->listarClientes();
        for (list<Cliente>::iterator it = clientes.begin(); it != clientes.end(); it++) {
            (*it).escreve(cout);
        }
        delete(c);

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Listar todos os tipos de carro existentes na BD
 */
void Teste::listaTipoCarro() {

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "\nTIPOS CARRO:" << endl << endl;
        list<TipoCarro> tipos = c->listarTiposCarro();
        for (list<TipoCarro>::iterator it = tipos.begin(); it != tipos.end(); it++) {
            (*it).escreve(cout);
        }
        delete(c);

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Listar todos os carros existentes na BD
 */
void Teste::listaCarros() {

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "AUTOMOVEIS:" << endl << endl;
        list<Carro> carros = c->listarCarros();
        for (list<Carro>::iterator it = carros.begin(); it != carros.end(); it++) {
            (*it).escreve(cout);
        }
        delete(c);
    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Listar todos os extras existentes na BD
 */
void Teste::listaExtras() {

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "EXTRAS:" << endl << endl;
        list<Extras> extras = c->listarExtras();
        for (list<Extras>::iterator it = extras.begin(); it != extras.end(); it++) {
            (*it).escreve(cout);
        }
        delete(c);

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Listar todos os alugueres existentes na BD
 */
void Teste::listaAlugueres() {

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "ALUGUERES:" << endl << endl;
        list<Aluguer> alugueres = c->listarAluguer();
        for (list<Aluguer>::iterator it = alugueres.begin(); it != alugueres.end(); it++) {
            (*it).escreve(cout);
        }
        delete(c);

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Pesquisa todos os alugueres numa data levantamento recebida por utilizador 
 */
void Teste::pesquisaAlugueres() {

    string dataLev = "";
    int numAluguer = 0;
    char op = 'n';

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);

        cout << "\n<< PESQUISA >>";
        cout << "\n\tInsira Data Levantamento (YYYY-MM-DD): ";
        cin >> dataLev;

        system("clear");
        cout << "\nPESQUISA COM DATA LEVANTAMENTO EM " << dataLev << endl << endl;
        list<Aluguer> alugueres = c->pesquisaAluguer(dataLev);
        for (list<Aluguer>::iterator it = alugueres.begin(); it != alugueres.end(); it++) {
            cout << "Nº Aluguer: " << (*it).getNumAluguer() << "\n\tNº Cliente: " << (*it).getNumCliente() << "\n\tNº Carro: " << (*it).getNumCarro() << "\n\tHora Levantamento: " << (*it).getHoraLevantamento() << endl << endl;
        }

        cout << "\nDeseja visualizar os extras do aluguer? (S/N)" << endl;
        cin >> op;
        if (op == 's' || op == 'S') {
            cout << "\n\tNº Aluguer: ";
            cin >> numAluguer;
            cout << "\n\t--- Extras ---" << endl << endl;
            list<Extras> extras = c->pesquisaExtras(numAluguer);
            for (list<Extras>::iterator it = extras.begin(); it != extras.end(); it++) {
                cout << "\tCodigo: " << (*it).getCodExtra() << "\n\tNome: " << (*it).getNome() << endl << endl;
            }
        }
        delete(c);

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

/**
 * Pesquisa/Altera/Elimina os clientes existentes na BD por nome
 */
void Teste::pesquisaClientes() {

    string nomeP, nome, verifica, contacto;
    int numCliente, id = 0, cc = 0;
    char op = 's', rsp = 'n';

    try {
        BDados *c = new BDados(HOST, USER, PASS, DB);
        cout << "\n<< PESQUISA >>" << endl;

        do {
            cout << "\tCliente: ";
            setbuf(stdin, NULL);
            getline(cin, nomeP);
        } while (nomeP.empty());

        system("clear");
        cout << "\nCLIENTE(s) COM NOME '" << nomeP << "'" << endl << endl;
        list<Cliente> clientes = c->pesquisaCliente(nomeP);
        for (list<Cliente>::iterator it = clientes.begin(); it != clientes.end(); it++) {
            (*it).escreve(cout);
        }
        cout << "(1)-ALTERAR CLIENTE / (2)-ELIMINAR CLIENTE / (0)-Sair" << endl;
        cin >> op;
        if (op == '2') {
            system("clear");
            cout << "<< ELIMINAÇÃO DO CLIENTE >>" << endl;

            do {
                cout << "\nNº Cliente: ";
                cin >> verifica;
                numCliente = atoi(verifica.c_str());
            } while (numCliente == 0);

            c->eliminarCliente(numCliente);

            cout << "Cliente " << numCliente << " foi eliminado com sucesso!" << endl;
            cin.ignore().get();
        }
        if (op == '1') {
            system("clear");
            cout << "<< ALTERAÇÃO DO CLIENTE>>" << endl << endl;

            do {
                cout << "Nº Cliente a alterar? ";
                cin >> verifica;
                numCliente = atoi(verifica.c_str());
            } while (numCliente == 0);

            cout << "\nPretende alterar o nome? (S/N) " << endl;
            cin >> rsp;
            if (rsp == 'S' || rsp == 's') {
                do {
                    cout << "Nome: ";
                    setbuf(stdin, NULL);
                    getline(cin, nome);

                } while (nome.empty());
            }

            cout << "\nPretende alterar o Nº Identificação? (S/N) " << endl;
            cin >> rsp;
            if (rsp == 'S' || rsp == 's') {
                do {
                    cout << "Doc. ID: ";
                    cin >> verifica;
                    id = atoi(verifica.c_str());
                } while (id == 0);
            }

            cout << "\nPretende alterar o Nº da Carta Condução? (S/N) " << endl;
            cin >> rsp;
            if (rsp == 'S' || rsp == 's') {
                do {
                    cout << "C. conducao: ";
                    cin >> verifica;
                    cc = atoi(verifica.c_str());
                } while (cc == 0);
            }

            cout << "\nPretende alterar o contacto? (S/N) " << endl;
            cin >> rsp;
            if (rsp == 'S' || rsp == 's') {
                do {
                    cout << "Contacto: ";
                    setbuf(stdin, NULL);
                    getline(cin, contacto);
                } while (contacto.empty());
            }

            c->editarCliente(numCliente, nome, id, cc, contacto);
            cout << endl << "Cliente " << numCliente << " alterado na Base de Dados com sucesso." << endl;
            cin.ignore().get();

        } else if (op == '0'){
            return;
        }

    } catch (SQLException &e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

#endif	/* TESTE_H */

