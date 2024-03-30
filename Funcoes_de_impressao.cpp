#include <iostream>
#include <string>
#include "structs.h"
#define MAX 50

using namespace std;


void primeira_impressao(seccao *&armazem, peca *lista_chegada, int numero_seccoes, int &tamanho_lista_chegada, int &total_de_faturacao){
    cout << "\t\t*************************************************\t" << endl;
    cout << "\t\t***** Armazem EDA " << "|" << " Total Faturacao " << total_de_faturacao << " Euros " << "*****\t" << endl;
    cout << "\t\t*************************************************\t" << endl;

    for (int i=0; i < numero_seccoes; i++){
        cout << "Seccao " << armazem[i].ID << " | Categoria " << armazem[i].categoria << " | Capacidade :" << armazem[i].tamanho_da_seccao << " | Quantidade :" << armazem[i].quantidade_na_seccao << " | Faturacao " << armazem[i].faturacao_desta_seccao<< endl;

        for (int j=0; j < armazem[i].quantidade_na_seccao; j++){
            cout << "\t" << armazem[i].pecas_aqui[j].marca << " | " << armazem[i].pecas_aqui[j].categoria << " | " << armazem[i].pecas_aqui[j].numero_de_serie << " | " << armazem[i].pecas_aqui[j].preco << " Euros" << endl;
        }
    }

    cout << "\t******************************************\t" << endl;
    cout << "\t************ Lista de Chegada ************\t" << endl;

    for (int i=0; i < tamanho_lista_chegada; i++){
        cout << "\t" << lista_chegada[i].categoria << " | " << lista_chegada[i].marca << " | " << lista_chegada[i].numero_de_serie << " | " << lista_chegada[i].preco << " Euros " << endl;
    }

    cout << "Dia (s)eguinte *********** (g)estao" << endl;
    cout << "Selecione a sua opcao:" << endl;

}

//void aplicar_promocao(seccao *armazem, )