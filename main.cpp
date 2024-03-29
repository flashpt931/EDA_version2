#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structs.h"
#include <algorithm>
#include "menu.h"
#include "seccoes.h"
#include "organizacao_Pecas.h"
#define MAX_LISTA 50
#define MAX 1000


using namespace std;
int main() {
    srand(time(0));
    int numero_seccoes = 0 , tamanho_dos_numeros_saidos = 0, tamanho_lista_chegada = 0,total_de_faturacao = 0;
    numero_de_seccoes(numero_seccoes);
    seccao *armazem = new seccao[numero_seccoes];
    criar_seccao(numero_seccoes,armazem);
    int *numeros_saidos = new int[MAX];
    peca lista_chegada[MAX_LISTA];
    deposito_de_pecas_na_lista_de_chegada(lista_chegada,10,numero_seccoes, armazem,numeros_saidos,tamanho_dos_numeros_saidos,tamanho_lista_chegada);
    //ordenarPorMarca(lista_chegada, tamanho_lista_chegada);
    for (int index = 0; index < tamanho_lista_chegada; index++) {
        cout << "A Peca " << index << " e da Categoria: " << lista_chegada[index].categoria << " e a Marca: " << lista_chegada[index].marca << endl;
    }
    armazem[0].pecas_aqui[0] = lista_chegada[0];
    armazem[0].quantidade_na_seccao++;
    cout << armazem[0].pecas_aqui[0].probabilidade_de_ser_vendida << endl;
    vendas(armazem,numero_seccoes,total_de_faturacao);
    cout << armazem[0].pecas_aqui[0].probabilidade_de_ser_vendida << " "<< total_de_faturacao << endl;
    delete[] armazem;
    delete[] numeros_saidos;
    return 0;
}






    /*for(int i = 0; i< 50; i++){
        if (!lista_chegada[i].marca.empty()){
            cout << lista_chegada[i].marca << endl;
        }
    }

    int tamanho_lista_chegada;
    tamanho_lista_chegada = calcula_tamanho(lista_chegada, tamanho_lista_chegada);
    ordenarPorMarca(lista_chegada, tamanho_lista_chegada);
    cout << lista_chegada[0].categoria << endl;
    cout << "A Lista de chegada e esta: " << endl;
    for (int index = 0; index < tamanho_lista_chegada; index++) {
        cout << "A Peca " << index+1 << " e da Categoria: " << lista_chegada[index].categoria << " e a Marca: "
             << lista_chegada[index].marca << endl;
    }
    peca lista_chegada[MAX];
    for (int index = 0; index < 10; index++) {
        lista_chegada[index] = criarPeca(numeros_saidos, tamanho);
    }
    int tamanho_lista_chegada;
    tamanho_lista_chegada = calcula_tamanho(lista_chegada, tamanho_lista_chegada);
    ordenarPorMarca(lista_chegada, tamanho_lista_chegada);
    cout << "A Lista de chegada e esta: " << endl;
    for (int index = 1; index < tamanho_lista_chegada; index++) {
        cout << "A Peca " << index << " e da Categoria: " << lista_chegada[index].categoria << " e a Marca: "
             << lista_chegada[index].marca << endl;
    }*/