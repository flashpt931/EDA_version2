#include <iostream>
#include "structs.h"
#include "organizacao_Pecas.h"
#include "Funcoes_de_impressao.h"
using namespace std;


int menu(seccao *&armazem,int &numero_de_seccoes,peca *&lista_chegada,int &tamanho_lista_chegada,int *&numeros_saidos ,int &tamanho_dos_numeros_saidos, int &total_de_faturacao,int &chamadas_do_menu) {
    if (chamadas_do_menu == 0){
        deposito_de_pecas_na_lista_de_chegada(lista_chegada,10,numero_de_seccoes, armazem,numeros_saidos,tamanho_dos_numeros_saidos,tamanho_lista_chegada);
        remocao_de_peca_para_o_armazem(armazem,lista_chegada,8,numero_de_seccoes,tamanho_lista_chegada);
        vendas(armazem,numero_de_seccoes,total_de_faturacao);
        primeira_impressao(armazem, lista_chegada,numero_de_seccoes,tamanho_lista_chegada,total_de_faturacao);
        chamadas_do_menu++;
        menu(armazem,numero_de_seccoes,lista_chegada,tamanho_lista_chegada,numeros_saidos ,tamanho_dos_numeros_saidos, total_de_faturacao,chamadas_do_menu);
    }
    else{
        char dia_seguinte_ou_gestão;
        cin >> dia_seguinte_ou_gestão;
        if (dia_seguinte_ou_gestão == 's'){
            deposito_de_pecas_na_lista_de_chegada(lista_chegada,5,numero_de_seccoes, armazem,numeros_saidos,tamanho_dos_numeros_saidos,tamanho_lista_chegada);
            remocao_de_peca_para_o_armazem(armazem,lista_chegada,8,numero_de_seccoes,tamanho_lista_chegada);
            vendas(armazem,numero_de_seccoes,total_de_faturacao);
            primeira_impressao(armazem, lista_chegada,numero_de_seccoes,tamanho_lista_chegada,total_de_faturacao);
            chamadas_do_menu++;
            menu(armazem,numero_de_seccoes,lista_chegada,tamanho_lista_chegada,numeros_saidos ,tamanho_dos_numeros_saidos, total_de_faturacao,chamadas_do_menu);
            return 0;
        }
        else if (dia_seguinte_ou_gestão == 'g'){

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
        }
    }

}