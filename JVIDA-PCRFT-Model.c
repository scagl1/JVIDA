#include "JVIDA-PCRFT-Model.h"

//Preenchimento da matriz com celulas mortas. Esta funcao também é utilizada no Case 3 do switch do menu.
void preenche_matriz(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{
    for (int i = 0; i < mundoPtr->ordem; i++)
        for (int j = 0; j < mundoPtr->ordem; j++)
            mundoPtr->matriz[i][j] = '.';
    tvivosPtr->cont = 0;
    tmortosPtr->cont = 0;
}

//Varre o array verificando celulas vivas proximas
void definir_numero_de_vizinhos_vivo_e_mortos(tlista *tvivosPtr, tlista *tmortosPtr)
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
    vizinhos = 0;

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

//Nesta funcao, adiciona-se todos os vizinhos como mortos
void colocandovizinhosmortost(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{
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

//Adiciona-se todos os vizinhos como mortos na lista temporária com representação de mortos '+'
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

//Organiza a lista de mortos,
void arrumandolistamortos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{
    //Limpa a lista de mortos das celulas invalidas
    for (int j = 1; j<=tmortosPtr->cont; j++)
    {
        if ((tmortosPtr->celula[j].lin <= -1) || (tmortosPtr->celula[j].col <= -1) || (tmortosPtr->celula[j].lin >= mundoPtr->ordem) || (tmortosPtr->celula[j].col >= mundoPtr->ordem))
        {
            //Sobrepoe elementos errados da lista com seus devidos posteriores
            if (j != tmortosPtr->cont)
                for (int z = j + 1; z <= tmortosPtr->cont; z++) {
                    tmortosPtr->celula[z - 1].lin = tmortosPtr->celula[z].lin;
                    tmortosPtr->celula[z - 1].col = tmortosPtr->celula[z].col;
                }
            //Diminui o tamanho da lista
            j--;
            tmortosPtr->cont--;
        }
    }
    //Limpando a lista de mortos das duplicatas
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
                if (j != tmortosPtr->cont)
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
    fvivosPtr->cont = 0;
    fmortosPtr->cont = 0;

  for(int k = 1; k<=tmortosPtr->cont; k++) {
      if (tmortosPtr->celula[k].vizinhosvivos == 3) {
          fvivosPtr->cont++;
          fvivosPtr->celula[fvivosPtr->cont].lin = tmortosPtr->celula[k].lin;
          fvivosPtr->celula[fvivosPtr->cont].col = tmortosPtr->celula[k].col;
          mundoPtr->matriz[tmortosPtr->celula[k].lin][tmortosPtr->celula[k].col] = '0';
          colocandovizinhosmortosf(fvivosPtr, fmortosPtr);

      } else
      {
          mundoPtr->matriz[tmortosPtr->celula[k].lin][tmortosPtr->celula[k].col] = '.';
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
    definir_numero_de_vizinhos_vivo_e_mortos(tvivosPtr,tmortosPtr);
}

int mostrar_mortos_vizinhos(bool mostrarmortos)
{
    if(mostrarmortos == true)
        mostrarmortos = false;
    else
        mostrarmortos = true;
    return mostrarmortos;
}

//Limpa o buffer do teclado
void limpa_buffer(){
    int x;
    while((x = fgetc(stdin)) != EOF && x != '\n' ){}
}


void save(salvo *listasalvaPtr)
{
    FILE *listas = fopen("listas.txt","w+"); //Saves a lista de vivos

    if(fopen("listas.txt","w+") != NULL) {

        fprintf(listas, "%i\n", listasalvaPtr->cont);
        for (int i=1; i <= listasalvaPtr->cont; i++)
        {
            fprintf(listas,"%i\n",listasalvaPtr->listasalvas[i].cont);
            for(int j=1;j<=listasalvaPtr->listasalvas[i].cont;j++)
            fprintf(listas, "%d/%d-%d-%d\n",listasalvaPtr->listasalvas[i].celula[j].lin,listasalvaPtr->listasalvas[i].celula[j].col,listasalvaPtr->listasalvas[i].celula[j].vizinhosvivos,listasalvaPtr->listasalvas[i].celula[j].vizinhosmortos);
        }
    }
    fclose(listas);

}
void pegandovalorsalvo(salvo *listasalvaPtr)
{
    FILE *listas = fopen("listas.txt","r+"); //Saves a lista de vivos


    if(fopen("listas.txt","r+") != NULL) {

        fscanf(listas, "%i\n",&listasalvaPtr->cont);
        for (int i=1; i <= listasalvaPtr->cont; i++)
        {
            fscanf(listas,"%i\n",&listasalvaPtr->listasalvas[i].cont);
            for(int j=1;j<=listasalvaPtr->listasalvas[i].cont;j++)
                fscanf(listas, "%d/%d-%d-%d\n",&listasalvaPtr->listasalvas[i].celula[j].lin,&listasalvaPtr->listasalvas[i].celula[j].col,&listasalvaPtr->listasalvas[i].celula[j].vizinhosvivos,&listasalvaPtr->listasalvas[i].celula[j].vizinhosmortos);
        }
    }

    fclose(listas);

}
void aumentarlistasalva(salvo *listasalvaPtr,tlista *tvivosPtr)
{
    listasalvaPtr->cont++;
    listasalvaPtr->listasalvas[listasalvaPtr->cont].cont=tvivosPtr->cont;
    for(int i=1;i<=tvivosPtr->cont;i++)
    {
        listasalvaPtr->listasalvas[listasalvaPtr->cont].celula[i].lin=tvivosPtr->celula[i].lin;
        listasalvaPtr->listasalvas[listasalvaPtr->cont].celula[i].col=tvivosPtr->celula[i].col;
        listasalvaPtr->listasalvas[listasalvaPtr->cont].celula[i].vizinhosvivos=tvivosPtr->celula[i].vizinhosvivos;
        listasalvaPtr->listasalvas[listasalvaPtr->cont].celula[i].vizinhosmortos=tvivosPtr->celula[i].vizinhosmortos;
    }

}
void pegarlistasalva(matriz *mundoPtr,salvo *listasalvaPtr,tlista *tvivosPtr,tlista *tmortosPtr,int cont_listasalva)
{
    for(int k=1;k<=listasalvaPtr->listasalvas[cont_listasalva].cont;k++)
    {
        tvivosPtr->cont++;
        tvivosPtr->celula[k].lin=listasalvaPtr->listasalvas[cont_listasalva].celula[k].lin;
        tvivosPtr->celula[k].col=listasalvaPtr->listasalvas[cont_listasalva].celula[k].col;
        mundoPtr->matriz[tvivosPtr->celula[k].lin][tvivosPtr->celula[k].col]='0';
        colocandovizinhosmortost(mundoPtr,tvivosPtr,tmortosPtr);

    }
}





