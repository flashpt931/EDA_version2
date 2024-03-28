//
// Created by octav on 28/03/2024.
//

#ifndef PROJETOEDA_ORGANIZACAO_PECAS_H
#define PROJETOEDA_ORGANIZACAO_PECAS_H
#include "structs.h"
#define MAX 50
bool serie_existe(int *numeros_de_series_ja_saidos, int &numero_da_serie);
int criar_serie(int *numeros_de_series_ja_saidos,int &tamanho);
int atribuicao_de_probabilade();
bool comparaMarca(const peca& a, const peca& b);
void ordenarPorMarca(peca lista_chegada[],int tamanho_lista_chegada);
peca criarPeca_de_categoria_seccao(int numeros_de_series_ja_saidos[], int &tamanho, string categorias);
void deposito_de_pecas_na_lista_de_chegada(peca lista_chegada[MAX],int quantidade_de_pecas, int &numero_seccoes, seccao * armazem,int* &numeros_saidos,int &tamanho_dos_numeros_saidos,int &tamanho_da_lista_de_chegada);


#endif //PROJETOEDA_ORGANIZACAO_PECAS_H
