#include <stdio.h>

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
    interface();
    perguntarordem();
    recebe_ordem(mundoPtr);
    preenche_matriz(mundoPtr,tvivosPtr,tmortosPtr);


    do {
        submenu(mundoPtr);
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
                colocandovizinhosmortos(mundoPtr,tvivosPtr,tmortosPtr);
                denifir_numero_de_vizinhos_vivo_e_mortos(tvivosPtr,tmortosPtr);
                break;

            case 2:
                preenche_matriz(mundoPtr,tvivosPtr,tmortosPtr);//Marcar cada termo da matriz com celulas mortas
                break;
            case 3:
                if (tvivosPtr->cont != 0)
                { //Impedir o usuario de selecionar a lista, caso o numero de celulas vivas seja igual a 0 (matriz vazia)
                    listas(tvivosPtr,tmortosPtr);
                }
                break;
            case 4:
                if (tvivosPtr->cont != 0)
                { //Impedir o usuario de ver o numero de celulas MORTAS e VIVAS vizinhas, caso o numero de celulas vivas seja igual a 0 (matriz vazia)
                    nVizinhos(tvivosPtr,tmortosPtr);
                }
                break;
            case 5:

                break;
            default:
                break;
        }

    } while (opt != 0);//Caso a opção 0 for selecionada sai do programa
}