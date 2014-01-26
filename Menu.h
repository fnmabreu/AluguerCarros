#ifndef MENU_H
#define	MENU_H

#include <unistd.h>
#include <stdlib.h>

using namespace std;

#include "Teste.h"

class Menu {
private:

public:
    Menu();
    ~Menu();

    void menuPrincipal();
    void menuNovo();
    void menuListar();
    void menuPesquisar();
};

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::menuPrincipal() {
    int opcao;
    string ver;
    char op = 'n';

    do {
        system("clear");
        cout << " =========================================================" << endl;
        cout << "|    ALUGUER DE CARROS                                    |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|             1 > NOVO                                    |" << endl;
        cout << "|             2 > LISTAR                                  |" << endl;
        cout << "|             3 > PESQUISAR                               |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|             0 > Sair                                    |" << endl;
        cout << " =========================================================" << endl;
        cout << " Opcao: ";
        cin >> ver;

        opcao = atoi(ver.c_str());

        switch (opcao) {
            case 1:
                menuNovo();
                break;
            case 2:
                menuListar();
                break;
            case 3:
                menuPesquisar();
                break;
            case 0:
                cout << "Tem certeza que quer sair? (S/N)" << endl;
                cin >> op;
                if (op == 'S' || op == 's') {
                    exit(0);
                } else {
                    system("clear");
                    menuPrincipal();
                }
            default:
                cout << "Opcao invalida!" << endl;
                sleep(1);
        }
    } while (opcao != 0);
}

void Menu::menuNovo() {
    int opcao;
    string ver;

    do {
        system("clear");
        cout << " =========================================================" << endl;
        cout << "|    NOVO                                                 |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|             1 > Carro                                   |" << endl;
        cout << "|             2 > Cliente                                 |" << endl;
        cout << "|             3 > Aluguer                                 |" << endl;
        cout << "|             4 > Tipo Carro                              |" << endl;
        cout << "|             5 > Extra                                   |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|             0 > Voltar                                  |" << endl;
        cout << " =========================================================" << endl;
        cout << " Opcao: ";
        cin >> ver;

        opcao = atoi(ver.c_str());
        Teste exec = Teste();

        switch (opcao) {
            case 1:
                system("clear");
                exec.novoCarro();
                cin.ignore().get();
                break;
            case 2:
                system("clear");
                exec.novoCliente();
                cin.ignore().get();
                break;
            case 3:
                system("clear");
                exec.novoAluguer();
                cin.ignore().get();
                break;
            case 4:
                system("clear");
                exec.novoTipoCarro();
                cin.ignore().get();
                break;
            case 5:
                system("clear");
                exec.novoExtra();
                cin.ignore().get();
                break;
            case 0:
                break;
            default:
                cout << " Opcao invalida!" << endl;
                sleep(1);
        }
    } while (opcao != 0);
}

void Menu::menuListar() {
    int opcao;
    string ver;

    do {
        system("clear");
        cout << " =========================================================" << endl;
        cout << "|    LISTAR                                               |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|             1 > Carro                                   |" << endl;
        cout << "|             2 > Cliente                                 |" << endl;
        cout << "|             3 > Aluguer                                 |" << endl;
        cout << "|             4 > Tipo Carro                              |" << endl;
        cout << "|             5 > Extra                                   |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|             0 > Voltar                                  |" << endl;
        cout << " =========================================================" << endl;
        cout << " Opcao: ";
        cin >> ver;

        opcao = atoi(ver.c_str());
        Teste exec = Teste();

        switch (opcao) {
            case 1:
                system("clear");
                exec.listaCarros();
                cin.ignore().get();
                break;
            case 2:
                system("clear");
                exec.listaClientes();
                cin.ignore().get();
                break;
            case 3:
                system("clear");
                exec.listaAlugueres();
                cin.ignore().get();
                break;
            case 4:
                system("clear");
                exec.listaTipoCarro();
                cin.ignore().get();
                break;
            case 5:
                system("clear");
                exec.listaExtras();
                cin.ignore().get();
                break;
            case 0:
                break;
            default:
                cout << " Opcao invalida!" << endl;
                sleep(1);
        }
    } while (opcao != 0);
}

void Menu::menuPesquisar() {
    int opcao;
    string ver;

    do {
        system("clear");
        cout << " =========================================================" << endl;
        cout << "|    PESQUISAR                                            |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|             1 > Alugueres                               |" << endl;
        cout << "|             2 > Disponibilidades                        |" << endl;
        cout << "|             3 > Cliente                                 |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|             0 > Voltar                                  |" << endl;
        cout << " =========================================================" << endl;
        cout << " Opcao: ";
        cin >> ver;

        opcao = atoi(ver.c_str());
        Teste exec = Teste();

        switch (opcao) {
            case 1:
                system("clear");
                exec.pesquisaAlugueres();
                cin.ignore().get();
                break;
            case 2:
                system("clear");
                exec.pesquisaDisponibilidade();
                cin.ignore().get();
                break;
            case 3:
                system("clear");
                exec.pesquisaClientes();
                break;
            case 0:
                break;
            default:
                cout << " Opcao invalida!" << endl;
                sleep(1);
        }
    } while (opcao != 0);
}

#endif	/* MENU_H */

