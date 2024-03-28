

#ifndef PROJETOEDA_FUNCTIONS_H
#define PROJETOEDA_FUNCTIONS_H
#include "structs.h"
#define MAX 50
void seccao_comprimento(int &tamanho_da_seccao);
void numero_de_seccoes(int &numero_de_seccoes);
void criar_seccao(int &numero_de_seccoes, seccao *armazem);
bool serie_existe(int *numeros_de_series_ja_saidos, int &numero_da_serie);
int criar_serie(int *numeros_de_series_ja_saidos,int &tamanho);
int atribuicao_de_probabilade();
bool comparaMarca(const peca& a, const peca& b);
void ordenarPorMarca(peca lista_chegada[],int tamanho_lista_chegada);
peca criarPeca_de_categoria_seccao(int numeros_de_series_ja_saidos[], int &tamanho, string categorias);
void deposito_de_pecas_na_lista_de_chegada(peca lista_chegada[MAX],int quantidade_de_pecas, int &numero_seccoes, seccao * armazem,int* &numeros_saidos,int &tamanho_dos_numeros_saidos,int &tamanho_da_lista_de_chegada);

//peca* dez_primeiras(const string* linhas_Categorias, int& numero_de_linhas_file_Categorias, const string* linhas_Marcas, int& numero_de_linhas_file_Marcas);
#endif //PROJETOEDA_FUNCTIONS_H