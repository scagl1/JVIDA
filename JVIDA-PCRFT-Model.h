#ifndef JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
#define JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>


#define max_ordem 30

//Variaveis e estruturas globais
typedef struct{
    int ordem;
    char matriz[max_ordem][max_ordem];
}matriz;


typedef struct{
    int lin,col;
    int vizinhosvivos;
    struct cel *next;
}cel;

typedef struct {
    int cont;
    cel *celula;
}tlista;
//para salvar
typedef struct {
    int cont;
    cel celula[500];
}lista;
typedef struct {
    int cont;
    lista listasalvas[100];
}salvo;





void preenche_matriz(matriz *mundoPtr,tlista *tvivosPtr,tlista *fvivosPtr,tlista *tmortosPtr);
void definir_numero_de_vizinhos_vivo_e_mortos(tlista *tvivosPtr,tlista *tmortosPtr);
void vizinhos_vivo(tlista *tvivosPtr, tlista *tmortosPtr);
void vizinhos_mortos(tlista *tvivosPtr, tlista *tmortosPtr);
void colocandovizinhosmortost(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr,int lin,int col);
void  arrumandolistamortos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void  arrumandolistamortos_invalidos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void  arrumandolistamortos_vivo(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void  arrumandolistamortos_duplicata(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void geracoes(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr,tlista *fvivosPtr);
int mostrar_mortos_vizinhos(bool mostrarmortos);
void limpa_buffer();
void save(salvo *listasalvaPtr);
void pegandovalorsalvo(salvo *listasalvaPtr);
void aumentarlistasalva(salvo *listasalvaPtr,tlista *tvivosPtr);
void pegarlistasalva(matriz *mundoPtr,salvo *listasalvaPtr,tlista *tvivosPtr,tlista *tmortosPtr,int cont_listasalva);
void carregaVivo(tlista *listaPtr,int lin, int col,int vizinhos);
#endif //JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
