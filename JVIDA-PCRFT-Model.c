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

    for(int coordenada = 0;coordenada<tvivos.cont;coordenada++)
    {
        for(int testes = 0; testes < tvivos.cont; testes++)
        {
            if ((tvivos.celula[testes].lin == tvivos.celula[coordenada].lin) && (tvivos.celula[testes].col == tvivos.celula[coordenada].col+1 || tvivos.celula[testes].col == tvivos.celula[coordenada].col-1 ))
            {
                vizinhos++;
            } else if ((tvivos.celula[testes].col == tvivos.celula[coordenada].col) && (tvivos.celula[testes].lin == tvivos.celula[coordenada].lin+1 || tvivos.celula[testes].lin == tvivos.celula[coordenada].lin-1 ))
            {
                vizinhos++;
            } else if (((tvivos.celula[testes].lin == tvivos.celula[coordenada].lin+1) || (tvivos.celula[testes].lin == tvivos.celula[coordenada].lin-1) ) && (tvivos.celula[testes].col == tvivos.celula[coordenada].col-1 || tvivos.celula[testes].col == tvivos.celula[coordenada].col+1 ))
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

    //Adiciona todos os vizinhos como mortos
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin = tvivos.celula[tvivos.cont].lin+1;
    tmortos.celula[tmortos.cont].col = tvivos.celula[tvivos.cont].col;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin = tvivos.celula[tvivos.cont].lin-1;
    tmortos.celula[tmortos.cont].col = tvivos.celula[tvivos.cont].col;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin = tvivos.celula[tvivos.cont].lin;
    tmortos.celula[tmortos.cont].col = tvivos.celula[tvivos.cont].col+1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin = tvivos.celula[tvivos.cont].lin;
    tmortos.celula[tmortos.cont].col = tvivos.celula[tvivos.cont].col-1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin = tvivos.celula[tvivos.cont].lin+1;
    tmortos.celula[tmortos.cont].col = tvivos.celula[tvivos.cont].col+1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin = tvivos.celula[tvivos.cont].lin-1;
    tmortos.celula[tmortos.cont].col = tvivos.celula[tvivos.cont].col+1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin = tvivos.celula[tvivos.cont].lin+1;
    tmortos.celula[tmortos.cont].col = tvivos.celula[tvivos.cont].col-1;
    tmortos.cont++;
    tmortos.celula[tmortos.cont].lin = tvivos.celula[tvivos.cont].lin-1;
    tmortos.celula[tmortos.cont].col = tvivos.celula[tvivos.cont].col-1;

    //Limpando a lista de mortos das duplicatas, e invalidas, das celulas
    for (int k=1; k <= tmortos.cont; k++)
    {
        for (int j = 1; j<=tmortos.cont; j++)
        {
            //Limpando a lista de mortos das duplicatas das celulas
            if ((k!=j) && (((tmortos.celula[k].lin == tmortos.celula[j].lin) && (tmortos.celula[k].col == tmortos.celula[j].col))))
            {
                //Sobrepondo elementos errados da lista com os posteriores
                for(int z = j + 1; z<=tmortos.cont; z++)
                {
                    tmortos.celula[z - 1].lin = tmortos.celula[z].lin;
                    tmortos.celula[z - 1].col = tmortos.celula[z].col;
                }
                //Diminuindo o tamanho da lista
                tmortos.cont--;
            }
            //Limpando a lista de mortos das e invalidas das celulas
            if ((((tmortos.celula[j].lin <= -1) || (tmortos.celula[j].col <= -1)) || ((tmortos.celula[j].lin > mundo.ordem-1) || (tmortos.celula[j].col > mundo.ordem - 1))))
            {
                //Sobrepondo elementos errados da lista com os posteriores
                for(int z = j + 1; z <= tmortos.cont; z++)
                {
                    tmortos.celula[z - 1].lin = tmortos.celula[z].lin;
                    tmortos.celula[z - 1].col = tmortos.celula[z].col;
                }
                //Diminuindo o tamanho da lista
                tmortos.cont--;
            }
        }
    }

    //Tirando lista de mortos e removendo celulas vivas
    for(int k=1; k <= tmortos.cont; k++)
    {
        for (int j = 1; j <= tvivos.cont; j++)
        { //Caso uma celula na lista de mortos esteja viva, ela entra na condicao
            if (((tmortos.celula[k].lin == tvivos.celula[j].lin) && (tmortos.celula[k].col == tvivos.celula[j].col)))
            {
                if (tmortos.cont != j)
                { //Sobrepondo elementos errados da lista com os posteriores
                    for (int z = k + 1; z <= tmortos.cont; z++) {
                        tmortos.celula[z - 1].lin = tmortos.celula[z].lin;
                        tmortos.celula[z - 1].col = tmortos.celula[z].col;
                    }
                }
                //Diminuindo o tamanho da lista
                tmortos.cont--;
            }
        }
    }
}
