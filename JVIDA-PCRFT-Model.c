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
void recebe_ordem() { //pegar o tamanho da matriz (mundo) que o usuário quer

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

void conta_vizinhos()
{
    mundo.matriz[tvivos.celula[tvivos.cont].lin][tvivos.celula[tvivos.cont].col] = '0';

    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin=tvivos.celula[tvivos.cont].lin+1;
    tmortos.celula[tmortos.cont].col=tvivos.celula[tvivos.cont].col;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin=tvivos.celula[tvivos.cont].lin-1;
    tmortos.celula[tmortos.cont].col=tvivos.celula[tvivos.cont].col;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin=tvivos.celula[tvivos.cont].lin;
    tmortos.celula[tmortos.cont].col=tvivos.celula[tvivos.cont].col+1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin=tvivos.celula[tvivos.cont].lin;
    tmortos.celula[tmortos.cont].col=tvivos.celula[tvivos.cont].col-1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin=tvivos.celula[tvivos.cont].lin+1;
    tmortos.celula[tmortos.cont].col=tvivos.celula[tvivos.cont].col+1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin=tvivos.celula[tvivos.cont].lin-1;
    tmortos.celula[tmortos.cont].col=tvivos.celula[tvivos.cont].col+1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin=tvivos.celula[tvivos.cont].lin+1;
    tmortos.celula[tmortos.cont].col=tvivos.celula[tvivos.cont].col-1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin=tvivos.celula[tvivos.cont].lin-1;
    tmortos.celula[tmortos.cont].col=tvivos.celula[tvivos.cont].col-1;

    for(int k=1;k<=tmortos.cont;k++)
    {
        for(int j=1;j<=tmortos.cont;j++)
        {
            if( (k!=j) && (((tmortos.celula[k].lin == tmortos.celula[j].lin) && (tmortos.celula[k].col == tmortos.celula[j].col)) || ((tmortos.celula[j].lin<0) ||(tmortos.celula[j].lin>mundo.ordem-1) ||  (tmortos.celula[j].col<0) ||(tmortos.celula[j].col>mundo.ordem-1))))
            {

                for(int z=j+1;z<=tmortos.cont;z++)
                {
                    printa_zmenos1(z);
                    tmortos.celula[z - 1].lin = tmortos.celula[z].lin;
                    tmortos.celula[z - 1].col = tmortos.celula[z].col;
                    printa_zmenos1(z);

                }
                tmortos.cont--;
            }
        }
    }
    for(int k=1;k<=tmortos.cont;k++)
    {
        for (int j =1 ; j <= tvivos.cont; j++)
        {
            if (((tmortos.celula[k].lin == tvivos.celula[j].lin) && (tmortos.celula[k].col == tvivos.celula[j].col)))
            {
                if (tmortos.cont!=j)
                    for (int z = k+1; z <= tmortos.cont; z++)
                    {
                        printa_z(z);
                        tmortos.celula[z - 1].lin = tmortos.celula[z].lin;
                        tmortos.celula[z - 1].col = tmortos.celula[z].col;
                        printa_z(z);
                    }
                tmortos.cont--;
            }
        }
    }
}




