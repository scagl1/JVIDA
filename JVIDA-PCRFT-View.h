#ifndef JOGO_DA_VIDA_JVIDA_PCRFT_VIEW_H
#define JOGO_DA_VIDA_JVIDA_PCRFT_VIEW_H

#include "JVIDA-PCRFT-Model.h"

//funções
void perguntarordem();//pergunta a ordem que o usuário quer
void mostra_matriz();//mostrar  matriz(mundo)
void submenu();//mostra sub-menu para o usuario
void cordenadas();//peguntar as cordenadas para escolher a celulas vivas
void mensagemdeerro();//casa tenha algo de errado informar ao usuario
void interface();//mostrar pagina inicial do jogo
void listas();//Listas de celulas vivas e mortas
void nVizinhos(int,int);//print de quantos vizinhos a celula na cordenada x e y possui
#endif //JOGO_DA_VIDA_JVIDA_PCRFT_VIEW_H
