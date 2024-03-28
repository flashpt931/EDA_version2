#include "seccoes.h"
#include <cstdlib>
#include "structs.h"
#include "Abertura_de_ficheiro.h"
#define MAX 50

using namespace std;

void seccao_comprimento(int &tamanho_da_seccao){
    tamanho_da_seccao = (rand()%4) +3; // O rand%4 dando um intervalo de [0,3] adicionando 3 dará [3,6] -> inclui 3,4,5,6
}

void numero_de_seccoes(int &numero_de_seccoes){
    numero_de_seccoes = (rand()%4) +7; //O rand%4 dando um intervalo de [0,3] adicionando 7 dará [7,10] -> inclui 7,8,9,10
}

void criar_seccao(int &numero_de_seccoes, seccao *armazem) {
    char id = 'A'; // ID incial, ja que é sequencial o id inicial é 'A'
    int tamanho_da_seccao; //declaração de uma variavel para indicar o tamanho da expecifica secção
    for (int index = 0; index < numero_de_seccoes; index++){//For para percorrer o numero de seccões
        seccao_comprimento(tamanho_da_seccao); // Utiliza a função que define o tamanho da secção
        armazem[index].categoria = Marca_ou_categoria_aleatoria("categorias.txt");
        armazem[index].ID = id++;
        //cout << "A Seccao " << armazem[index].ID << " || Categoria: " << armazem[index].categoria << " || Tamanho: " << armazem[index].tamanho_da_seccao << endl;
    }
}
