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
                                    printf(" \t\n    %d | %d\n", tmortos.celula[z-1].lin, tmortos.celula[z-1].col);
                                    tmortos.celula[z - 1].lin = tmortos.celula[z].lin;
                                    tmortos.celula[z - 1].col = tmortos.celula[z].col;
                                    printf(" \t\n    %d | %d\n", tmortos.celula[z-1].lin, tmortos.celula[z-1].col);

                                }
                            printf("111");
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

                                    printf(" \t\n    %d | %d\n", tmortos.celula[z-1].lin, tmortos.celula[z].col);
                                    tmortos.celula[z - 1].lin = tmortos.celula[z].lin;
                                    tmortos.celula[z - 1].col = tmortos.celula[z].col;
                                    printf(" \t\n    %d | %d\n", tmortos.celula[z-1].lin, tmortos.celula[z].col);
                                }
                            printf("testtttt");
                            tmortos.cont--;
                        }
                    }
                }
                break;

            case 2:
                preenche_matriz();//marcar cada termo das matrix com celulas mortas
                break;
            case 3:
                listas();
                break;
            case 4:
                celulasvolta();
                break;
            default:
                break;
        }

    } while (opt != 0);//caso a opição 0 for selecionada sai do programa
}
