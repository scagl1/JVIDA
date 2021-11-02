#ifndef JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
#define JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#define max_ordem 30

//Variaveis e estruturas globais
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

void preenche_matriz(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void definir_numero_de_vizinhos_vivo_e_mortos(tlista *tvivosPtr,tlista *tmortosPtr);
void colocandovizinhosmortost(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void colocandovizinhosmortosf(tlista *fvivosPtr,tlista *fmortosPtr);
void arrumandolistamortos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void geracoes(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr,tlista *fvivosPtr,tlista *fmortosPtr);
int mostrar_mortos_vizinhos(bool mostrarmortos);
void limpa_buffer();
#endif //JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
