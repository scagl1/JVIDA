


#include "JVIDA-PCRFT-Controller.h"



void menu() { // inicio do sistema com menu inicial e logica do programa
    //chamando struct
    matriz mundo,*mundoPtr;
    mundoPtr= &mundo;
    tlista tvivos, tmortos, fmortos, fvivos, *tvivosPtr, *tmortosPtr, *fmortosPtr, *fvivosPtr;

    tvivosPtr = &tvivos;
    fvivosPtr =&fvivos;
    tmortosPtr= &tmortos;
    fmortosPtr= &fmortos;

    int opt; // opcao switch
    int ngeracao,tempogeracao;//case 5 //numero de gerações-tempo entre essas gerações
    int geracao=1;//case 5 // contador do numero de gerações
    int cont;//case 5 // O contador para o rodar o numero de gerações pedidos
    char geracaopausa;//case 5 // A geração que o mundo está


    interface();
    perguntarordem();
    recebe_ordem(mundoPtr);
    preenche_matriz(mundoPtr,tvivosPtr,tmortosPtr);

    do {
        submenu(mundoPtr,geracao);
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                tvivos.cont++;
                do {
                    cordenadas();

                    scanf("%d %d", &tvivosPtr->celula[tvivosPtr->cont].lin, &tvivosPtr->celula[tvivosPtr->cont].col);//pegando os valores das cordenadas
                    if ((tvivosPtr->celula[tvivosPtr->cont].lin >= mundoPtr->ordem || tvivosPtr->celula[tvivosPtr->cont].lin < 0) || (tvivosPtr->celula[tvivosPtr->cont].col >= mundo.ordem || tvivosPtr->celula[tvivosPtr->cont].col < 0) || mundoPtr->matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col] =='0')//caso o valor seja invalido
                        mensagemdeerro();

                } while ((tvivosPtr->celula[tvivosPtr->cont].lin >= mundoPtr->ordem || tvivosPtr->celula[tvivosPtr->cont].lin < 0) || (tvivosPtr->celula[tvivosPtr->cont].col >= mundo.ordem || tvivosPtr->celula[tvivosPtr->cont].col < 0) || mundoPtr->matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col] =='0');//se o valor for invalido volta de novo para o "do"
                mundoPtr->matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col] = '0';
                colocandovizinhosmortost(mundoPtr,tvivosPtr,tmortosPtr);
                denifir_numero_de_vizinhos_vivo_e_mortos(tvivosPtr,tmortosPtr);
                break;

            case 2:
                preenche_matriz(mundoPtr,tvivosPtr,tmortosPtr);//Marcar cada termo da matriz com celulas mortas
                break;
            case 3:
                if (tvivosPtr->cont != 0)//Impedir o usuario de selecionar a lista, caso o numero de celulas vivas seja igual a 0 (matriz vazia)
                {
                    listas(tvivosPtr,tmortosPtr);
                }
                break;
            case 4:
                if (tvivosPtr->cont != 0)//Impedir o usuario de ver o numero de celulas MORTAS e VIVAS vizinhas, caso o numero de celulas vivas seja igual a 0 (matriz vazia)
                {
                    nVizinhos(tvivosPtr,tmortosPtr);
                }
                break;
            case 5:
                cont=1;
                pergunta_geracoes();
                scanf("%d",&ngeracao);
                pergunta_intervalo_geracoes();
                scanf("%d",&tempogeracao);

                do{

                    geracoes(mundoPtr,tvivosPtr,tmortosPtr,fvivosPtr,fmortosPtr);
                    cont++;
                    geracao++;
                    mostra_matriz(mundoPtr,geracao);
                    printf("\n%d\n",tempogeracao);
                    if(tempogeracao==0)
                    {
                        do{
                            pergunta_passo_a_passo();
                            scanf("%c", &geracaopausa);
                            if ((geracaopausa != 'p') && (geracaopausa != 's'))
                            {
                                mensagemdeerro();
                            }
                        }while((geracaopausa != 'p') && (geracaopausa != 's'));
                    }
                    sleep(tempogeracao);


                } while ((cont<ngeracao)&&(geracaopausa!='s'));


                break;
            default:
                break;
        }

    } while (opt != 0);//Caso a opção 0 for selecionada sai do programa
}