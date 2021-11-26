#ifndef JOGO_DA_VIDA_JVIDA_PCRFT_VIEW_H
#define JOGO_DA_VIDA_JVIDA_PCRFT_VIEW_H

#include "JVIDA-PCRFT-Model.h"

void perguntarordem();//pergunta a ordem que o usuário quer
void mostra_matriz(matriz *mundoPtr,tlista *tmortosPtr,int geracao,bool mostrarmortos);//mostrar  matriz(mundo)
void submenu(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr,int geracao,bool mostrarmortos);//mostra sub-menu para o usuario
void cordenadas();//peguntar as cordenadas para escolher a celulas vivas
void mensagemdeerro();//casa tenha algo de errado informar ao usuario
void interface();//mostrar pagina inicial do jogo
void listas(tlista *tvivosPtr,tlista *tmortosPtr);//Listas de celulas vivas e mortas
//void nVizinhos(tlista *tvivosPtr,tlista *tmortosPtr);//print de quantos vizinhos a celula na cordenada x e y possui
void pergunta_geracoes();
void pergunta_intervalo_geracoes();
void pergunta_passo_a_passo();
void aviso_geracao(int geracao);
void mundosalvo();
void sem_celulas_para_salvar();
void regras();

#endif //JOGO_DA_VIDA_JVIDA_PCRFT_VIEW_H
