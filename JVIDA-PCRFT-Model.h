#ifndef JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
#define JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H

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
void colocandovizinhosmortos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
void arrumandolistamortos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr);
#endif //JOGO_DA_VIDA_JVIDA_PCRFT_MODEL_H
