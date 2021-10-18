#ifndef JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
#define JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H

#include "JVIDA-PCRFT-Model.h"

#define max_ordem 60

//Variaveis globais
typedef struct{
    int ordem;
    char matriz[max_ordem][max_ordem];
}ordem;

//funções
void preenche_matriz();// colocando toda a matriz que vai ser o mundo como celulas mortas
void recebe_ordem();//pegar o tamanho da matriz(mundoa) que o usuário quer

#endif //JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H