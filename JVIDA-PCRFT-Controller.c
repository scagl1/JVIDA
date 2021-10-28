#include <stdio.h>

#include "JVIDA-PCRFT-Controller.h"



void menu() { // inicio do sistema com menu inicial e logica do programa

    int opt; // opcao switch
    interface();
    perguntarordem();
    recebe_ordem();
    preenche_matriz();

    do {
        submenu();
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                tvivos.cont++;
                do {
                    cordenadas();

                    scanf("%d %d", &tvivos.celula[tvivos.cont].lin, &tvivos.celula[tvivos.cont].col);//pegando os valores das cordenadas
                    if ((tvivos.celula[tvivos.cont].lin >= mundo.ordem || tvivos.celula[tvivos.cont].lin < 0) || (tvivos.celula[tvivos.cont].col >= mundo.ordem || tvivos.celula[tvivos.cont].col < 0)|| mundo.matriz[tvivos.celula[tvivos.cont].col][tvivos.celula[tvivos.cont].lin] =="0")//caso o valor seja invalido
                        mensagemdeerro();
                } while ((tvivos.celula[tvivos.cont].lin >= mundo.ordem || tvivos.celula[tvivos.cont].lin < 0) || (tvivos.celula[tvivos.cont].col >= mundo.ordem || tvivos.celula[tvivos.cont].col < 0) || mundo.matriz[tvivos.celula[tvivos.cont].col][tvivos.celula[tvivos.cont].lin] =="0");//se o valor for invalido volta de novo para o "do"

                conta_vizinhos();
                break;

            case 2:
                preenche_matriz();//marcar cada termo das matrix com celulas mortas
                break;
            case 3:
                if (tvivos.cont != 0){
                    listas();
                }
                break;
            case 4:
                if (tvivos.cont != 0) {
                    celulasvolta();
                }
                break;
            default:
                break;
        }

    } while (opt != 0);//caso a opção 0 for selecionada sai do programa
}
