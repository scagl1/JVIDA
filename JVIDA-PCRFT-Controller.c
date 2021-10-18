#include <stdio.h>

#include "JVIDA-PCRFT-Controller.h"

ordem ordem1;

void menu() { // inicio do sistema com menu inicial e logica do programa

    int opt; // opcao switch
    int col, lin; //case 1
    interface();
    perguntarordem();
    recebe_ordem();
    preenche_matriz();

    do {
        submenu();
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                do {
                    cordenadas();
                    scanf("%d %d", &col, &lin);//pegando os valores das cordenadas
                    if (((lin >= ordem1.ordem || lin < 0) || (col >= ordem1.ordem || col < 0)) || (ordem1.matriz[lin][col] == '0'))//caso o valor seja invalido
                        mensagemdeerro();
                } while (((lin >= ordem1.ordem || lin < 0) || (col >= ordem1.ordem || col < 0)) || (ordem1.matriz[lin][col] == '0'));//se o valor for invalido volta de novo para o "do"
                ordem1.matriz[lin][col] = '0';
                break;

            case 2:
                preenche_matriz();//marcar cada termo da matriz com celulas mortas
                break;

            default:
                break;
        }
    } while (opt != 0);//caso a opção 0 for selecionada sai do programa
}


