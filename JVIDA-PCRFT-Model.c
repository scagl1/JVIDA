#include <stdio.h>

#include "JVIDA-PCRFT-Model.h"
#include "JVIDA-PCRFT-View.h"


//funções
void preenche_matriz() { // colocando toda a matriz que vai ser o mundo como celulas mortas

    for (int i = 0; i < mundo.ordem; i++)
        for (int j = 0; j < mundo.ordem; j++)
        {
            mundo.matriz[i][j] = '.';
        }
        tvivos.cont = 0;
        tmortos.cont = 0;
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
    int vizinhos = 0;

    for(int coordenada=0;coordenada<tvivos.cont;coordenada++)
    {
       for(int testes=0;testes<tvivos.cont;testes++)
       {
            if ((tvivos.celula[testes].lin == tvivos.celula[coordenada].lin) && (tvivos.celula[testes].col == tvivos.celula[coordenada].col+1 || tvivos.celula[testes].col == tvivos.celula[coordenada].col-1 ))
            {
                vizinhos++;
            }else if ((tvivos.celula[testes].col == tvivos.celula[coordenada].col) && (tvivos.celula[testes].lin == tvivos.celula[coordenada].lin+1 || tvivos.celula[testes].lin == tvivos.celula[coordenada].lin-1 ))
            {
                vizinhos++;
            }else if (((tvivos.celula[testes].lin == tvivos.celula[coordenada].lin+1) || (tvivos.celula[testes].lin == tvivos.celula[coordenada].lin-1) ) && (tvivos.celula[testes].col == tvivos.celula[coordenada].col-1 || tvivos.celula[testes].col == tvivos.celula[coordenada].col+1 ))
            {
                vizinhos++;
            }
       }
        nVizinhos(coordenada,vizinhos);
        vizinhos = 0;
    }


}





