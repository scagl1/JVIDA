#include <stdio.h>
#include "JVIDA-PCRFT-View.h"


//funções
void perguntarordem()//pergunta a ordem que o usuário quer
{
    printf("\nPor favor, insira a ordem da matriz (De 1 a %d): ", max_ordem);
}
void mostra_matriz() { //mostrar  matriz(mundo)

    printf("\t");
    for (int x = 0; x < mundo.ordem; x++)
        printf("%d   ", x);
    printf("\n");

    for (int i = 0; i < mundo.ordem; i++) {
        printf("%d\t", i);
        for (int j = 0; j < mundo.ordem; j++)
            printf("%c   ", mundo.matriz[i][j]);
        printf("\n");
    }
}
void submenu()//mostra sub-menu para o usuario
{
    printf("\nLegenda --> Vivo = 0  Morto = .\n\n");
    mostra_matriz();
    printf("\nPor favor, escolha uma opcao: \n");
    printf("1 - Selecionar uma coodernada\n");
    printf("2 - Limpar mundo matricial\n");
    printf("3 - Lista\n");
    printf("4 - obiter numero de celulas vivas em volta\n");
    printf("0 - Sair do programa\n");
}
void cordenadas()//perguntar as cordenadas para escolher a celulas vivas
{
    printf("Coodernadas (linha coluna): ");
}
void mensagemdeerro()//caso tenha algo de errado a informar ao usuario
{
    printf("\nVoce digitou algo errado\nTente novamente!\n");
}


void interface(){ //mostrar pagina inicial do jogo

    printf("_________________________________________________________________________________\n"
           "|           ____                                                                |\n"
           "|       _.-'78o `\"`--._                                                         |\n"
           "|   ,o888o.  .o888o,   ''-.                                                     |\n"
           "| ,88888P  `78888P..______.]                                                    |\n"
           "|/_..__..----\"\"        __.'                                                     |\n"
           "|`-._       /\"\"| _..-''                ___                    _,   _            |\n"
           "|    \"`-----\\  `\\                     ( /               /     (|  /o    /       |\n"
           "|            |   ;.-\"\"--..             / __ _,  __   __/ __,   | /,  __/ __,    |\n"
           "|            | ,8o.  o88. `.         _/_(_)(_)_(_)  (_/_(_/(_  |/ (_(_/_(_/(_   |\n"
           "|            `;888P  `788P  :       //      /|                                  |\n"
           "|      .o\"\"-.|`-._         ./      (/      (/                                   |\n"
           "|     J88 _.-/    \";\"-P----'                                                    |\n"
           "|     `--'\\`|     /  /                                                          |\n"
           "|         | /     |  |                                                          |\n"
           "|         \\|     /   |                                                          |\n"
           "|          `-----`---'                                                          |\n"
           "|_______________________________________________________________________________|\n");
}
void listaviva() {
    printf("\t    VIVOS\n ");
    printf("\t______________\n");
    printf("\tlinha | coluna\n");
    for (int i = 0; i < tvivos.cont; i++) {

        if (tvivos.cont > 0)
            printf(" \t    %d | %d\n", tvivos.celula[i].lin, tvivos.celula[i].col);
    }
    printf("\n\n");
    printf("\t    MORTOS\n ");
    printf("\t______________\n");
    printf("\tlinha | coluna\n");
    for (int i = 0; i < tmortos.cont; i++) {

        if (tmortos.cont > 0)
            printf(" \t\n    %d | %d\n", tmortos.celula[i].lin, tmortos.celula[i].col);
    }
}