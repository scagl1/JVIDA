#ifndef JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
#define JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#define max_ordem 30

//Variaveis globais
typedef struct{
    int ordem;
    char matriz[max_ordem][max_ordem];
}matriz;

typedef struct{
    int lin,col;
    int vizinhosmortos,vizinhosvivos;
}cel;
typedef struct {
    int cont;
    cel celula[max_ordem*max_ordem];
}tlista;

//funções
void preenche_matriz(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);// colocando toda a matriz que vai ser o mundo como celulas mortas
void recebe_ordem(matriz *mundoPtr);//pegar o tamanho da matriz(mundoa) que o usuário quer
void denifir_numero_de_vizinhos_vivo_e_mortos(tlista *tvivosPtr,tlista *tmortosPtr);
void colocandovizinhosmortost(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void colocandovizinhosmortosf(tlista *fvivosPtr,tlista *fmortosPtr);
void arrumandolistamortos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void geracoes(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr,tlista *fvivosPtr,tlista *fmortosPtr);
int mostrar_mortos_vizinhos(bool mostrarmortos);
#endif //JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
