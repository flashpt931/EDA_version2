#include "organizacao_Pecas.h"
#include <iostream>
#include <cstdlib>
#include "structs.h"
#include "Abertura_de_ficheiro.h"
#include <algorithm>
#define MAX 50
using namespace std;

bool serie_existe(int *numeros_de_series_ja_saidos, int &numero_da_serie) {
    for (int i = 0; numeros_de_series_ja_saidos[i] != 0; i++) {
        if (numeros_de_series_ja_saidos[i] == numero_da_serie) {
            return true;
        }
    }
    return false;
}
int criar_serie(int *numeros_de_series_ja_saidos, int &tamanho) {
    int numero_da_serie = (rand() % 9000) + 1000;
    while (serie_existe(numeros_de_series_ja_saidos, numero_da_serie)) {
        numero_da_serie = (rand() % 9000) + 1000;
    }
    tamanho++;
    numeros_de_series_ja_saidos[tamanho-1] = numero_da_serie;
    return numeros_de_series_ja_saidos[tamanho-1];
}

/*bool comparaMarca(const peca& a, const peca& b) {
    return a.marca == b.marca;
}
void ordenarPorMarca(peca lista_chegada[],int tamanho_lista_chegada) {
    sort(lista_chegada, lista_chegada + tamanho_lista_chegada, comparaMarca);
}
void ordenarPorMarca(peca lista_chegada[],int tamanho_lista_chegada){
    for (int index = 2; index < tamanho_lista_chegada; index++){
        for(int j = 1; j <index;j++){
            if ()
        }
    }
}
*/
int preco_peca (){
    return ((rand()%179) + 2) * 5; //10-900
}
int atribuicao_de_probabilade() {
    int probabilidade = rand() % 46 + 5; // [0,45] -> [5,50]
    return probabilidade;
}
peca criarPeca_de_categoria_seccao(int numeros_de_series_ja_saidos[], int &tamanho, string categoria_da_seccao) {
    peca novaPeca;
    novaPeca.categoria = categoria_da_seccao;
    novaPeca.marca = Marca_ou_categoria_aleatoria("marcas.txt");
    novaPeca.preco = preco_peca ();
    novaPeca.numero_de_serie = criar_serie(numeros_de_series_ja_saidos,tamanho);
    novaPeca.probabilidade_de_ser_vendida = atribuicao_de_probabilade();
    return novaPeca;
}
void deposito_de_pecas_na_lista_de_chegada(peca *lista_chegada,int quantidade_de_pecas, int &numero_seccoes, seccao * armazem,int* &numeros_saidos,int &tamanho_dos_numeros_saidos,int &tamanho_da_lista_de_chegada){
    for (int index = 0; index < quantidade_de_pecas; index++){
        int a = rand()%numero_seccoes;
        lista_chegada[tamanho_da_lista_de_chegada] = criarPeca_de_categoria_seccao(numeros_saidos,tamanho_dos_numeros_saidos,armazem[a].categoria);
        tamanho_da_lista_de_chegada++;
    }
}
bool foi_vendido_ou_nao(int probabilidade){
    bool foi_vendido_ou_nao = (probabilidade >= rand()%101);
    return foi_vendido_ou_nao;
}
void apagar_peca(peca &uma_peca){
    uma_peca.preco = 0;
    uma_peca.probabilidade_de_ser_vendida = 0;
    uma_peca.categoria = "";
    uma_peca.marca = "";
    uma_peca.numero_de_serie = 0;
}
void ordenar_pecas_existentes(peca *&lista_de_pecas,int indice, int &quantidade_da_seccao){
    for(;indice< quantidade_da_seccao-1; indice++){
        lista_de_pecas[indice] = lista_de_pecas[indice+1];
    }
    quantidade_da_seccao--;
}

void vendas(seccao *armazem,int numero_seccoes, int &total_de_faturacao){
    for (int index = 0; index< numero_seccoes;index++){
        //entrou na seccao
        for (int j = 0; j <armazem[index].quantidade_na_seccao; j++){
            //entrou na lista de pecas
            if(foi_vendido_ou_nao(armazem[index].pecas_aqui[j].probabilidade_de_ser_vendida)){
                //foi vendido
                cout << "foi vendido " <<  " por "<< armazem[index].pecas_aqui[j].preco << endl;
                total_de_faturacao += armazem[index].pecas_aqui[j].preco;
                apagar_peca(armazem[index].pecas_aqui[j]);
                ordenar_pecas_existentes(armazem[index].pecas_aqui,j,armazem[index].quantidade_na_seccao);

            }
        }
    }
}
void remocao_de_peca_para_o_armazem(seccao *&armazem,peca *&lista_de_pecas,int n_de_pecas_para_entrar,int numero_seccoes, int &tamanho_lista_chegada){
    for(int i= 0; i<n_de_pecas_para_entrar;i++){
        for(int j = 0; j<numero_seccoes;j++){
            if(lista_de_pecas[i].categoria == armazem[j].categoria){
                armazem[j].pecas_aqui[armazem[j].quantidade_na_seccao] = lista_de_pecas[i];
                cout << "j e igual a " << j << " i e igual a " << i << " esta peca " << armazem[j].pecas_aqui[armazem[j].quantidade_na_seccao].numero_de_serie << " e isto " << lista_de_pecas[i].numero_de_serie << endl;
                ++(armazem[j].quantidade_na_seccao);
                apagar_peca(lista_de_pecas[i]);
                ordenar_pecas_existentes(lista_de_pecas,i, tamanho_lista_chegada);
                i--;
                n_de_pecas_para_entrar--;
                break;
            }
        }
    }
}

void reseta_seccao(seccao seccao_do_armazem){
    for (int i = 0; i<seccao_do_armazem.quantidade_na_seccao;i++){
        apagar_peca(seccao_do_armazem.pecas_aqui[i]);
    }
}

void alterar_categoria(seccao *&armazem, int &numero_de_seccoes) {
    cout<<"Qual seccao pertende alterar?" << endl;
    char id_local;
    cin >> id_local;
    bool seccao_encontrada = false;
    for (int i = 0; i < numero_de_seccoes; i++) {
        if (armazem[i].ID == id_local) {
            cout << "Nova categoria para a seccao " << id_local << ": " << endl;
            string nova_categoria;
            cin >> nova_categoria;
            armazem[i].categoria = nova_categoria;
            reseta_seccao(armazem[i]);
            armazem[i].quantidade_na_seccao = 0;
            seccao_encontrada = true;
            break;
        }
    }
    if (!seccao_encontrada) {
        cout << "A seccao selecionada nao existe!" << endl;
    }
}
void vendaManual(seccao* armazem, int numero_de_seccoes, int &total_de_faturacao) {
    int id_produto;char id_seccao;
    cout << "Indique a seccao que pretende entrar " << endl;
    cin >> id_seccao;
    cout << "Indique o id do produto que pretende vender " << endl;
    cin >> id_produto;
    int i = 0;
    while(i < numero_de_seccoes){ // Loop sobre todas as secções do armazém
        int j = 0;
        while(j < armazem[i].tamanho_da_seccao){ // Loop sobre todas as peças na secção atual
            if( armazem[i].pecas_aqui[j].numero_de_serie == id_produto){ // Verifica se encontrou o produto
                total_de_faturacao +=armazem[i].pecas_aqui[j].preco;
                apagar_peca(armazem[i].pecas_aqui[j]);
                ordenar_pecas_existentes(armazem[i].pecas_aqui,j,armazem[i].quantidade_na_seccao);
                //Decrementamos o tamanho da secção para "mostrar" a remoção da peça vendida
                break;
            }
            j++;
        }
        i++;
    }
    cin.clear();
}