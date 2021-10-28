#ifndef JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
#define JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H

#include "JVIDA-PCRFT-Model.h"

#define max_ordem 30

//Variaveis globais
typedef struct{
    int ordem;
    char matriz[max_ordem][max_ordem];
}matriz;

typedef struct{
    int lin,col;
}cel;
typedef struct {
    int cont;
    cel celula[max_ordem*max_ordem];
}tlista;

//chamando struct
matriz mundo;
tlista tvivos ,tmortos;


//funções
void preenche_matriz();// colocando toda a matriz que vai ser o mundo como celulas mortas
void recebe_ordem();//pegar o tamanho da matriz(mundoa) que o usuário quer
void celulasvolta();
void conta_vizinhos();
#endif //JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
