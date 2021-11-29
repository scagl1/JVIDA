#include "JVIDA-PCRFT-Model.h"

//Preenchimento da matriz com celulas mortas. Esta funcao também é utilizada no Case 3 do switch do menu.
void preenche_matriz(matriz *mundoPtr,tlista *tvivosPtr,tlista *fvivosPtr,tlista *tmortosPtr)
{
    tvivosPtr->cont=0;
    tvivosPtr->celula= NULL;
    tmortosPtr->cont=0;
    tmortosPtr->celula=NULL;
    fvivosPtr->cont=0;
    fvivosPtr->celula=NULL;

    for (int i = 0; i < mundoPtr->ordem; i++)
        for (int j = 0; j < mundoPtr->ordem; j++)
            mundoPtr->matriz[i][j] = '.';

}

//Varre o array verificando celulas vivas proximas
void definir_numero_de_vizinhos_vivo_e_mortos(tlista *tvivosPtr, tlista *tmortosPtr)
{
   vizinhos_vivo(tvivosPtr,tmortosPtr);
    vizinhos_mortos(tvivosPtr,tmortosPtr);
}
void vizinhos_vivo(tlista *tvivosPtr, tlista *tmortosPtr)
{
    cel *atual, *atualaux;
    int vizinhosvivo=0;

if (tvivosPtr->celula != NULL)
    {

        atualaux=tvivosPtr->celula;
        while(atualaux!=NULL)
        {

            atual=tvivosPtr->celula;
            while(atual!=NULL)
            {
                if ((atual->lin == atualaux->lin) && (atual->col == atualaux->col+1 || atual->col == atualaux->col-1 ))
                {
                    vizinhosvivo++;
                } else if ((atual->col == atualaux->col) && (atual->lin == atualaux->lin+1 || atual->lin == atualaux->lin-1 ))
                {
                    vizinhosvivo++;
                } else if (((atual->lin == atualaux->lin+1) || (atual->lin == atualaux->lin-1) ) && (atual->col == atualaux->col-1 || atual->col == atualaux->col+1 ))
                {
                    vizinhosvivo++;

                }
                atual=atual->next;

            }
            atualaux->vizinhosvivos=vizinhosvivo;
            vizinhosvivo=0;
            atualaux=atualaux->next;
        }
    }
}
void vizinhos_mortos(tlista *tvivosPtr, tlista *tmortosPtr)
{
    cel *atual, *atualmortos;
    int vizinhosvivo=0;

    if (tvivosPtr->celula != NULL)
    {

        atualmortos=tmortosPtr->celula;
        while(atualmortos!=NULL)
        {

            atual=tvivosPtr->celula;
            while(atual!=NULL)
            {
                if ((atual->lin == atualmortos->lin) && (atual->col == atualmortos->col+1 || atual->col == atualmortos->col-1 ))
                {
                    vizinhosvivo++;
                } else if ((atual->col == atualmortos->col) && (atual->lin == atualmortos->lin+1 || atual->lin == atualmortos->lin-1 ))
                {
                    vizinhosvivo++;
                } else if (((atual->lin == atualmortos->lin+1) || (atual->lin == atualmortos->lin-1) ) && (atual->col == atualmortos->col-1 || atual->col == atualmortos->col+1 ))
                {
                    vizinhosvivo++;

                }
                atual=atual->next;

            }
            atualmortos->vizinhosvivos=vizinhosvivo;
            vizinhosvivo=0;
            atualmortos=atualmortos->next;
        }
    }
}

//Nesta funcao, adiciona-se todos os vizinhos como mortos
void colocandovizinhosmortost(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr,int lin,int col)
{

    carregaVivo(tmortosPtr,lin+1, col,-1);
    carregaVivo(tmortosPtr,lin-1, col,-1);
    carregaVivo(tmortosPtr,lin, col+1,-1);
    carregaVivo(tmortosPtr,lin, col-1,-1);
    carregaVivo(tmortosPtr,lin+1, col+1,-1);
    carregaVivo(tmortosPtr,lin-1, col+1,-1);
    carregaVivo(tmortosPtr,lin+1, col-1,-1);
    carregaVivo(tmortosPtr,lin-1, col-1,-1);
    arrumandolistamortos(mundoPtr,tvivosPtr,tmortosPtr);

}

//Adiciona-se todos os vizinhos como mortos na lista temporária com representação de mortos '+'
int mostrar_mortos_vizinhos(bool mostrarmortos)
{
    if(mostrarmortos == true)
        mostrarmortos = false;
    else
        mostrarmortos = true;
    return mostrarmortos;
}

//Organiza a lista de mortos,
void  arrumandolistamortos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{
    arrumandolistamortos_invalidos(mundoPtr,tvivosPtr,tmortosPtr);
    arrumandolistamortos_vivo(mundoPtr,tvivosPtr,tmortosPtr);
    arrumandolistamortos_duplicata(mundoPtr,tvivosPtr,tmortosPtr);
}
//retirar mortos invalidos
void  arrumandolistamortos_invalidos(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{
    cel *atual, *anterior;

    //Limpa a lista de mortos das celulas invalidas
    if (tmortosPtr->celula != NULL)
    {
        atual = tmortosPtr->celula->next;
        anterior = tmortosPtr->celula;

        while (atual != NULL)
        {

            if ((tmortosPtr->celula->lin <= -1) || (tmortosPtr->celula->col <= -1) || (tmortosPtr->celula->lin >= mundoPtr->ordem) || (tmortosPtr->celula->col >= mundoPtr->ordem))
            {
                tmortosPtr->celula = atual;
                atual = tmortosPtr->celula->next;
                anterior = tmortosPtr->celula;
                tmortosPtr->cont--;
            } else if ((atual->lin <= -1) || (atual->col <= -1) || (atual->lin >= mundoPtr->ordem) || (atual->col >= mundoPtr->ordem))
            {
                anterior->next=atual->next;
                //Diminui o tamanho da lista
                atual=anterior->next;
                tmortosPtr->cont--;
            }else
            {
                anterior=atual;
                atual=atual->next;

            }

        }
    }
}
//tirar celulas vivas do mortos
void  arrumandolistamortos_vivo(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{
    cel *atualvivos,*atual, *anterior;

    if (tmortosPtr->celula != NULL)
    {
        atualvivos=tvivosPtr->celula;
        while (atualvivos!=NULL)
        {
            atual=tmortosPtr->celula->next;
            anterior=tmortosPtr->celula;
            while(atual!=NULL)
            {
                if ((tmortosPtr->celula->lin == atualvivos->lin) && (tmortosPtr->celula->col== atualvivos->col))
                {
                    tmortosPtr->celula = atual;
                    atual = tmortosPtr->celula->next;
                    anterior = tmortosPtr->celula;
                    tmortosPtr->cont--;
                }else if((atual->lin==atualvivos->lin)&&(atual->col==atualvivos->col))
                {
                    anterior->next=atual->next;
                    //Diminui o tamanho da lista

                    atual=anterior->next;
                    tmortosPtr->cont--;
                }else
                {
                    anterior=atual;
                    atual=atual->next;
                }
            }
            atualvivos=atualvivos->next;
        }
    }
}
//arrumar duplicatas
void  arrumandolistamortos_duplicata(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr)
{
    cel *atualaux,*atual, *anterior;

    if (tmortosPtr->celula != NULL)
    {

        atualaux=tmortosPtr->celula;
        while(atualaux!=NULL)
        {
            anterior=tmortosPtr->celula;
            atual=tmortosPtr->celula->next;

            while(atual!=NULL)
            {

                if((atual!=atualaux)&&(atual->lin==atualaux->lin)&&(atual->col==atualaux->col))
                {

                    anterior->next=atual->next;
                    //Diminui o tamanho da lista
                    atual=anterior->next;
                    tmortosPtr->cont--;
                }else
                {
                    anterior=atual;
                    atual=atual->next;
                }
            }
            atualaux=atualaux->next;
        }
    }
}

//fazer seleção das celulas que continuarão vivas e que também nasceram
void geracoes(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr,tlista *fvivosPtr)
{
    cel *mortosaux,*vivosaux,*aux;
    fvivosPtr->celula=NULL;
    fvivosPtr->cont = 0;

    mortosaux=tmortosPtr->celula;
    while (mortosaux!=NULL)
    {
      if (mortosaux->vizinhosvivos== 3)
      {
          carregaVivo(fvivosPtr,mortosaux->lin,mortosaux->col,-1);
          mundoPtr->matriz[mortosaux->lin][mortosaux->col] = '0';

      } else
      {
          mundoPtr->matriz[mortosaux->lin][mortosaux->col] = '.';
      }
      mortosaux=mortosaux->next;
  }


   vivosaux=tvivosPtr->celula;
  while(vivosaux!=NULL)
  {
      if((vivosaux->vizinhosvivos==2) || (vivosaux->vizinhosvivos==3))
      {
          carregaVivo(fvivosPtr,vivosaux->lin,vivosaux->col,-1);
      }else
      {
          mundoPtr->matriz[vivosaux->lin][vivosaux->col]= '.';
      }
      vivosaux=vivosaux->next;
  }
    tmortosPtr->cont=0;
    tmortosPtr->celula=NULL;
    tvivosPtr->cont=0;
    tvivosPtr->celula=NULL;

    if(fvivosPtr->celula!=NULL)
    {

        tvivosPtr->cont=fvivosPtr->cont;
        tvivosPtr->celula=fvivosPtr->celula;
        fvivosPtr->celula=NULL;
        fvivosPtr->cont=0;
        aux=tvivosPtr->celula;
        while(aux!=NULL)
        {
            colocandovizinhosmortost(mundoPtr,tvivosPtr,tmortosPtr,aux->lin,aux->col);

            aux=aux->next;
        }

    }

    arrumandolistamortos(mundoPtr,tvivosPtr,tmortosPtr);
    definir_numero_de_vizinhos_vivo_e_mortos(tvivosPtr,tmortosPtr);
}

//Limpa o buffer do teclado
void limpa_buffer(){
    int x;
    while((x = fgetc(stdin)) != EOF && x != '\n' ){}
}

//salvando listasalva no arquivo
void save(salvo *listasalvaPtr)
{
    FILE *listas = fopen("listas.txt","w+"); //Saves a lista de vivos

    if(fopen("listas.txt","w+") != NULL) {

        fprintf(listas, "%i\n", listasalvaPtr->cont);
        for (int i=1; i <= listasalvaPtr->cont; i++)
        {
            fprintf(listas,"%i\n",listasalvaPtr->listasalvas[i].cont);
            for(int j=1;j<=listasalvaPtr->listasalvas[i].cont;j++)
                fprintf(listas, "%d/%d-%d\n",listasalvaPtr->listasalvas[i].celula[j].lin,listasalvaPtr->listasalvas[i].celula[j].col,listasalvaPtr->listasalvas[i].celula[j].vizinhosvivos);
        }
    }
    fclose(listas);

}

//pegando a listasalva do arquivo
void pegandovalorsalvo(salvo *listasalvaPtr)
{
    FILE *listas = fopen("listas.txt","r+"); //Saves a lista de vivos


    if(fopen("listas.txt","r+") != NULL) {

        fscanf(listas, "%i\n",&listasalvaPtr->cont);
        for (int i=1; i <= listasalvaPtr->cont; i++)
        {
            fscanf(listas,"%i\n",&listasalvaPtr->listasalvas[i].cont);
            for(int j=1;j<=listasalvaPtr->listasalvas[i].cont;j++)
                fscanf(listas, "%d/%d-%d\n",&listasalvaPtr->listasalvas[i].celula[j].lin,&listasalvaPtr->listasalvas[i].celula[j].col,&listasalvaPtr->listasalvas[i].celula[j].vizinhosvivos);
        }
    }

    fclose(listas);
}

// colocando um novo mundo nas listasalvas
void aumentarlistasalva(salvo *listasalvaPtr,tlista *tvivosPtr)
{
    cel *aux;

    aux=tvivosPtr->celula;

        listasalvaPtr->cont++;
        listasalvaPtr->listasalvas[listasalvaPtr->cont].cont=tvivosPtr->cont;
    printf("iii");

        for(int i=1;i<=tvivosPtr->cont ;i++)
        {
            listasalvaPtr->listasalvas[listasalvaPtr->cont].celula[i].lin=aux->lin;
            listasalvaPtr->listasalvas[listasalvaPtr->cont].celula[i].col=aux->col;
            listasalvaPtr->listasalvas[listasalvaPtr->cont].celula[i].vizinhosvivos=aux->vizinhosvivos;
            aux=aux->next;

        }



}

//colocando no sub-menu os  mundos  salvos nas listasalva  em ordem
void pegarlistasalva(matriz *mundoPtr,salvo *listasalvaPtr,tlista *tvivosPtr,tlista *tmortosPtr,int cont_listasalva)
{



  for(int i=1;i<=listasalvaPtr->listasalvas[cont_listasalva].cont;i++)
  {

      carregaVivo(tvivosPtr,listasalvaPtr->listasalvas[cont_listasalva].celula[i].lin,listasalvaPtr->listasalvas[cont_listasalva].celula[i].col,listasalvaPtr->listasalvas[cont_listasalva].celula[i].vizinhosvivos);
      mundoPtr->matriz[listasalvaPtr->listasalvas[cont_listasalva].celula[i].lin][listasalvaPtr->listasalvas[cont_listasalva].celula[i].col] = '0';
      colocandovizinhosmortost(mundoPtr,tvivosPtr,tmortosPtr,listasalvaPtr->listasalvas[cont_listasalva].celula[i].lin,listasalvaPtr->listasalvas[cont_listasalva].celula[i].col);
  }



}

//inclui uma célula na Lista de vivos
void carregaVivo(tlista *listaPtr,int lin, int col,int vizinhos)

{
    cel *aux = malloc(sizeof(cel));
    //alocação dinâmica
    if (aux == NULL)
    {
        return;
    }
    aux->lin = lin;
    aux->col = col;
    if(vizinhos!=-1)
    aux->vizinhosvivos=vizinhos;
    //sempre inclui no início da lista
    if(listaPtr->cont == 0)  //se a lista está vazia
    {
        listaPtr->celula = aux;
        listaPtr->celula->next = NULL;
    }
    else                //lista não vazia
    {
        aux->next = listaPtr->celula;
        listaPtr->celula = aux;  //o inicio da lista passa a ser a nova celula
    }
    listaPtr->cont++;
}






