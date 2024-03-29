//
// Created by octav on 08/03/2024.
//

#ifndef PROJETOEDA_STRUCTS_H
#define PROJETOEDA_STRUCTS_H
#include <string>
#include <stdlib.h>

using namespace std;

struct peca {
    string categoria;
    string marca;
    int preco;
    int numero_de_serie;
    int probabilidade_de_ser_vendida;
};

struct seccao {
    string categoria;
    char ID;
    int tamanho_da_seccao = (rand()%4) +3;
    peca *pecas_aqui = new peca[tamanho_da_seccao];
    int quantidade_na_seccao = 0;
    int faturacao_desta_seccao = 0;
    int *numeros_de_serie_vendidos_aqui = new int[100];
};

#endif //PROJETOEDA_STRUCTS_H
