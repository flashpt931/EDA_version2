#include <iostream>

using namespace std;

int menu() {
    cout << "\t*******************************************\n\t***** Armazem EDA | Total Faturacao 0 *****\n\t*******************************************";
    int opcao;
    cout << "\n ***** Bem Vindo Gestor *****\n";
    cout << "(1).Venda Manual\n";
    cout << "(2).Promocao\n";
    cout << "(3).Alterar Categoria\n";
    cout << "(4).Adicionar Seccao\n";
    cout << "(5).Gravar Armazem\n";
    cout << "(6).Carregar Armazem\n";
    cout << "(7).Imprimir Armazem\n";
    cout << "Selecione a sua opcao:";
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Indique o produto desejado e a respetiva seccao...\n";
            break;
        case 2:
            cout << "Indique a duracao da promocao e a sua %...\n";
            break;
        case 3:
            cout << "Escolha uma seccao...\n";
            break;
        case 4:
            cout << "Isto vai ser pa meter funcoes aqui :p\n";
            break;
        case 5:
            cout << "A gravar...\n";
            break;
        case 6:
            cout << "A carregar...\n";
            break;
        case 7:
            cout << "A imprimir...\n";
            break;
        default:
            cout <<"\nEscolha uma opcao valida\n";
    }

    return 0;
};