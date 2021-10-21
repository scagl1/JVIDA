#include <stdio.h>

#include "JVIDA-PCRFT-Model.h"
#include "JVIDA-PCRFT-View.h"


//funções
void preenche_matriz() { // colocando toda a matriz que vai ser o mundo como celulas mortas

    for (int i = 0; i < mundo.ordem; i++)
        for (int j = 0; j < mundo.ordem; j++)
            mundo.matriz[i][j] = '.';
}
void recebe_ordem() {//pegar o tamanho da matriz(mundoa) que o usuário quer

    do {
        scanf("%d", &mundo.ordem);
        if (mundo.ordem > max_ordem || mundo.ordem <= 1) {
            mensagemdeerro();
        }
    } while (mundo.ordem > max_ordem || mundo.ordem <= 1);
}
void celulasvolta()
{
    int testando=0;
    for(int linha=0;linha<tvivos.cont;linha++)
    {
       for(int testes;testes<tvivos.cont;testes++)
       {
            if ((tvivos.celula[testes].lin == tvivos.celula[linha].lin) && (tvivos.celula[testes].col == tvivos.celula[linha].col+1 || tvivos.celula[testes].col == tvivos.celula[linha].col-1 ))
            {
                testando++;
                printf("11\n");
            }else if ((tvivos.celula[testes].col == tvivos.celula[linha].col) && (tvivos.celula[testes].lin == tvivos.celula[linha].lin+1 || tvivos.celula[testes].lin == tvivos.celula[linha].lin-1 ))
            {
                testando++;
                printf("22\n");
            }else if (((tvivos.celula[testes].lin == tvivos.celula[linha].lin+1) || (tvivos.celula[testes].lin == tvivos.celula[linha].lin-1) ) && (tvivos.celula[testes].col == tvivos.celula[linha].col-1 || tvivos.celula[testes].col == tvivos.celula[linha].col+1 ))
            {
                printf("33\n");
                testando++;
            }
       }
        printf("celula %d: %d ",linha,testando );

    }


}





