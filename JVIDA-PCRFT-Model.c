#include "JVIDA-PCRFT-Model.h"
#include "JVIDA-PCRFT-View.h"

//funções
void preenche_matriz(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr) // colocando toda a matriz que vai ser o mundo como celulas mortas
{

    for (int i = 0; i < mundoPtr->ordem; i++)
        for (int j = 0; j < mundoPtr->ordem; j++)
        {
            mundoPtr->matriz[i][j] = '.';
        }
    tvivosPtr->cont = 0;
    tmortosPtr->cont = 0;
}
void recebe_ordem(matriz *mundoPtr) //pegar o tamanho da matriz (mundo) que o usuário quer
{
    do {
        scanf("%d", &mundoPtr->ordem);
        if (mundoPtr->ordem > max_ordem || mundoPtr->ordem <= 1) {
            mensagemdeerro();
        }
    } while (mundoPtr->ordem > max_ordem || mundoPtr->ordem <= 1);
}
void denifir_numero_de_vizinhos_vivo_e_mortos(tlista *tvivosPtr, tlista *tmortosPtr)
{
    int vizinhos = 0;

    for(int coordenada = 1;coordenada<=tvivosPtr->cont;coordenada++)
    {
        for(int testes = 1; testes <= tvivosPtr->cont; testes++)
        {
            if ((tvivosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin) && (tvivosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col+1 || tvivosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col-1 ))
            {
                vizinhos++;
            } else if ((tvivosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col) && (tvivosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin+1 || tvivosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin-1 ))
            {
                vizinhos++;
            } else if (((tvivosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin+1) || (tvivosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin-1) ) && (tvivosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col-1 || tvivosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col+1 ))
            {
                vizinhos++;
            }
        }
        tvivosPtr->celula[coordenada].vizinhosvivos=vizinhos;
        vizinhos = 0;
    }
    vizinhos=0;

    for(int coordenada = 1;coordenada<=tvivosPtr->cont;coordenada++)
    {
        for(int testes = 1; testes <= tmortosPtr->cont; testes++)
        {
            if ((tmortosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin) && (tmortosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col+1 || tmortosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col-1 ))
            {
                vizinhos++;
            } else if ((tmortosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col) && (tmortosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin+1 || tmortosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin-1 ))
            {
                vizinhos++;
            } else if (((tmortosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin+1) || (tmortosPtr->celula[testes].lin == tvivosPtr->celula[coordenada].lin-1) ) && (tmortosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col-1 || tmortosPtr->celula[testes].col == tvivosPtr->celula[coordenada].col+1 ))
            {
                vizinhos++;
            }
        }
        tvivosPtr->celula[coordenada].vizinhosmortos=vizinhos;
        vizinhos = 0;
    }
    vizinhos = 0;
    for(int coordenada = 1;coordenada<=tmortosPtr->cont;coordenada++)
    {
        for(int testes = 1; testes <= tvivosPtr->cont; testes++)
        {
            if ((tmortosPtr->celula[coordenada].lin == tvivosPtr->celula[testes].lin) && (tmortosPtr->celula[coordenada].col == tvivosPtr->celula[testes].col+1 || tmortosPtr->celula[coordenada].col == tvivosPtr->celula[testes].col-1 ))
            {
                vizinhos++;
            } else if ((tmortosPtr->celula[coordenada].col == tvivosPtr->celula[testes].col) && (tmortosPtr->celula[coordenada].lin == tvivosPtr->celula[testes].lin+1 || tmortosPtr->celula[coordenada].lin == tvivosPtr->celula[testes].lin-1 ))
            {
                vizinhos++;
            } else if (((tmortosPtr->celula[coordenada].lin == tvivosPtr->celula[testes].lin+1) || (tmortosPtr->celula[coordenada].lin == tvivosPtr->celula[testes].lin-1) ) && (tmortosPtr->celula[coordenada].col == tvivosPtr->celula[testes].col-1 || tmortosPtr->celula[coordenada].col == tvivosPtr->celula[testes].col+1 ))
            {
                vizinhos++;
            }
        }
        tmortosPtr->celula[coordenada].vizinhosvivos=vizinhos;
        vizinhos = 0;
    }
}
void colocandovizinhosmortost(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{

    //Adiciona todos os vizinhos como mortos
        tmortosPtr->cont++;
        tmortosPtr->celula[tmortosPtr->cont].lin = tvivosPtr->celula[tvivosPtr->cont].lin + 1;
        tmortosPtr->celula[tmortosPtr->cont].col = tvivosPtr->celula[tvivosPtr->cont].col;
        tmortosPtr->cont++;
        tmortosPtr->celula[tmortosPtr->cont].lin = tvivosPtr->celula[tvivosPtr->cont].lin - 1;
        tmortosPtr->celula[tmortosPtr->cont].col = tvivosPtr->celula[tvivosPtr->cont].col;
        tmortosPtr->cont++;
        tmortosPtr->celula[tmortosPtr->cont].lin = tvivosPtr->celula[tvivosPtr->cont].lin;
        tmortosPtr->celula[tmortosPtr->cont].col = tvivosPtr->celula[tvivosPtr->cont].col + 1;
        tmortosPtr->cont++;
        tmortosPtr->celula[tmortosPtr->cont].lin = tvivosPtr->celula[tvivosPtr->cont].lin;
        tmortosPtr->celula[tmortosPtr->cont].col = tvivosPtr->celula[tvivosPtr->cont].col - 1;
        tmortosPtr->cont++;
        tmortosPtr->celula[tmortosPtr->cont].lin = tvivosPtr->celula[tvivosPtr->cont].lin + 1;
        tmortosPtr->celula[tmortosPtr->cont].col = tvivosPtr->celula[tvivosPtr->cont].col + 1;
        tmortosPtr->cont++;
        tmortosPtr->celula[tmortosPtr->cont].lin = tvivosPtr->celula[tvivosPtr->cont].lin - 1;
        tmortosPtr->celula[tmortosPtr->cont].col = tvivosPtr->celula[tvivosPtr->cont].col + 1;
        tmortosPtr->cont++;
        tmortosPtr->celula[tmortosPtr->cont].lin = tvivosPtr->celula[tvivosPtr->cont].lin + 1;
        tmortosPtr->celula[tmortosPtr->cont].col = tvivosPtr->celula[tvivosPtr->cont].col - 1;
        tmortosPtr->cont++;
        tmortosPtr->celula[tmortosPtr->cont].lin = tvivosPtr->celula[tvivosPtr->cont].lin - 1;
        tmortosPtr->celula[tmortosPtr->cont].col = tvivosPtr->celula[tvivosPtr->cont].col - 1;
        arrumandolistamortos(mundoPtr,tvivosPtr,tmortosPtr);


}
void colocandovizinhosmortosf(tlista *fvivosPtr,tlista *fmortosPtr)
{
    fmortosPtr->cont++;
    fmortosPtr->celula[fmortosPtr->cont].lin = fvivosPtr->celula[fvivosPtr->cont].lin + 1;
    fmortosPtr->celula[fmortosPtr->cont].col = fvivosPtr->celula[fvivosPtr->cont].col;
    fmortosPtr->cont++;
    fmortosPtr->celula[fmortosPtr->cont].lin = fvivosPtr->celula[fvivosPtr->cont].lin - 1;
    fmortosPtr->celula[fmortosPtr->cont].col = fvivosPtr->celula[fvivosPtr->cont].col;
    fmortosPtr->cont++;
    fmortosPtr->celula[fmortosPtr->cont].lin = fvivosPtr->celula[fvivosPtr->cont].lin;
    fmortosPtr->celula[fmortosPtr->cont].col = fvivosPtr->celula[fvivosPtr->cont].col + 1;
    fmortosPtr->cont++;
    fmortosPtr->celula[fmortosPtr->cont].lin = fvivosPtr->celula[fvivosPtr->cont].lin;
    fmortosPtr->celula[fmortosPtr->cont].col = fvivosPtr->celula[fvivosPtr->cont].col - 1;
    fmortosPtr->cont++;
    fmortosPtr->celula[fmortosPtr->cont].lin = fvivosPtr->celula[fvivosPtr->cont].lin + 1;
    fmortosPtr->celula[fmortosPtr->cont].col = fvivosPtr->celula[fvivosPtr->cont].col + 1;
    fmortosPtr->cont++;
    fmortosPtr->celula[fmortosPtr->cont].lin = fvivosPtr->celula[fvivosPtr->cont].lin - 1;
    fmortosPtr->celula[fmortosPtr->cont].col = fvivosPtr->celula[fvivosPtr->cont].col + 1;
    fmortosPtr->cont++;
    fmortosPtr->celula[fmortosPtr->cont].lin = fvivosPtr->celula[fvivosPtr->cont].lin + 1;
    fmortosPtr->celula[fmortosPtr->cont].col = fvivosPtr->celula[fvivosPtr->cont].col - 1;
    fmortosPtr->cont++;
    fmortosPtr->celula[fmortosPtr->cont].lin = fvivosPtr->celula[fvivosPtr->cont].lin - 1;
    fmortosPtr->celula[fmortosPtr->cont].col = fvivosPtr->celula[fvivosPtr->cont].col - 1;
}
void arrumandolistamortos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{
    //Limpando a lista de mortos das invalidas, das celulas
    for (int j = 1; j<=tmortosPtr->cont; j++)
    {
        //Limpando a lista de mortos das e invalidas das celulas
        if ((tmortosPtr->celula[j].lin <= -1) || (tmortosPtr->celula[j].col <= -1) || (tmortosPtr->celula[j].lin >= mundoPtr->ordem) || (tmortosPtr->celula[j].col >= mundoPtr->ordem))
        {
            //Sobrepondo elementos errados da lista com os posteriores]
            if (j != tmortosPtr->cont)
                for (int z = j + 1; z <= tmortosPtr->cont; z++) {
                    tmortosPtr->celula[z - 1].lin = tmortosPtr->celula[z].lin;
                    tmortosPtr->celula[z - 1].col = tmortosPtr->celula[z].col;
                }
            //Diminuindo o tamanho da lista
            j--;
            tmortosPtr->cont--;
        }
    }
    // Limpando a lista de mortos das duplicatas
    for (int k=1; k <= tmortosPtr->cont; k++)
    {
        for (int j = 1; j<=tmortosPtr->cont; j++)
        {
            //Limpando a lista de mortos das duplicatas das celulas
            if ((k!=j) && (tmortosPtr->celula[k].lin == tmortosPtr->celula[j].lin) && (tmortosPtr->celula[k].col == tmortosPtr->celula[j].col))
            {
                if(j!=tmortosPtr->cont)
                    for(int z = j + 1; z<=tmortosPtr->cont; z++)//Sobrepondo elementos errados da lista com os posteriores
                    {
                        tmortosPtr->celula[z - 1].lin = tmortosPtr->celula[z].lin;
                        tmortosPtr->celula[z - 1].col = tmortosPtr->celula[z].col;
                    }
                //Diminuindo o tamanho da lista
                j--;
                tmortosPtr->cont--;
            }

        }
    }
    //Tirando lista de mortos e removendo celulas vivas
    for(int k=1; k <= tvivosPtr->cont; k++)
    {
        for (int j = 1; j <= tmortosPtr->cont; j++)
        { //Caso uma celula na lista de mortos esteja viva, ela entra na condicao
            if ((tmortosPtr->celula[j].lin == tvivosPtr->celula[k].lin) && (tmortosPtr->celula[j].col == tvivosPtr->celula[k].col))
            {

                //Sobrepondo elementos errados da lista com os posteriores
                if (j!=tmortosPtr->cont)
                    for (int z = j + 1; z <= tmortosPtr->cont; z++)
                    {
                        tmortosPtr->celula[z - 1].lin = tmortosPtr->celula[z].lin;
                        tmortosPtr->celula[z - 1].col = tmortosPtr->celula[z].col;
                    }

                j--;
                //Diminuindo o tamanho da lista
                tmortosPtr->cont--;
            }
        }
    }
}

void geracoes(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr,tlista *fvivosPtr,tlista *fmortosPtr)
{
    fvivosPtr->cont=0;
    fmortosPtr->cont=0;

  for(int k=1;k<=tmortosPtr->cont;k++)
  {
      if(tmortosPtr->celula[k].vizinhosvivos==3)
      {
          fvivosPtr->cont++;
          fvivosPtr->celula[fvivosPtr->cont].lin=tmortosPtr->celula[k].lin;
          fvivosPtr->celula[fvivosPtr->cont].col=tmortosPtr->celula[k].col;
          mundoPtr->matriz[tmortosPtr->celula[k].lin][tmortosPtr->celula[k].col]='0';
          colocandovizinhosmortosf(fvivosPtr,fmortosPtr);

      }
  }
  for(int j=1;j<=tvivosPtr->cont;j++)
  {
      if((tvivosPtr->celula[j].vizinhosvivos==2) || (tvivosPtr->celula[j].vizinhosvivos==3))
      {
          fvivosPtr->cont++;
          fvivosPtr->celula[fvivosPtr->cont].lin=tvivosPtr->celula[j].lin;
          fvivosPtr->celula[fvivosPtr->cont].col=tvivosPtr->celula[j].col;

          colocandovizinhosmortosf(fvivosPtr,fmortosPtr);
      }else
      {
          mundoPtr->matriz[tvivosPtr->celula[j].lin][tvivosPtr->celula[j].col]= '.';
      }
  }
    for(int f=1;f<=fmortosPtr->cont;f++)
    {
        tmortosPtr->celula[f].lin=fmortosPtr->celula[f].lin;
        tmortosPtr->celula[f].col=fmortosPtr->celula[f].col;
    }
    tmortosPtr->cont=fmortosPtr->cont;
    for(int f=1;f<=fvivosPtr->cont;f++)
    {
        tvivosPtr->celula[f].lin=fvivosPtr->celula[f].lin;
        tvivosPtr->celula[f].col=fvivosPtr->celula[f].col;
    }
    tvivosPtr->cont=fvivosPtr->cont;
    arrumandolistamortos(mundoPtr,tvivosPtr,tmortosPtr);
    denifir_numero_de_vizinhos_vivo_e_mortos(tvivosPtr,tmortosPtr);

}
