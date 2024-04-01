#ifndef PROJETOEDA_GESTAO_H
#define PROJETOEDA_GESTAO_H
#include "structs.h"

void vendaManual(seccao* &armazem, int numero_de_seccoes, int &total_de_faturacao,peca *&lista_chegada, int tamanho_lista_chegada);
void alterar_categoria(seccao *&armazem, int &numero_de_seccoes);
void imprimir_lista_pecas(seccao* seccoes, int numero_seccoes, peca* lista_chegada, int tamanho_lista_chegada);
void imprimir_lista_pecas_preco(seccao* seccoes, int numero_seccoes, peca* lista_chegada, int tamanho_lista_chegada);
#endif //PROJETOEDA_GESTAO_H
