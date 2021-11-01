
#include "JVIDA-PCRFT-View.h"


//funções
void perguntarordem()//pergunta a ordem que o usuário quer
{
    printf("\nPor favor, insira a ordem da matriz (De 2 a %d): ", max_ordem);
}
void mostra_matriz(matriz *mundoPtr,int geracao) //mostrar matriz (mundo)
{
    printf("\n");
    printf("\nGERAÇÃO: %d",geracao);
    printf("\nLinha (Numeros da esquerda), Coluna (Numeros de cima)\n\n");

    if (mundoPtr->ordem <= 10) { //matriz de ordem MENOR que 10 (em 10, teremos coodenadas entre 0-9)
        printf("   ");
        for (int i = 0; i < mundoPtr->ordem; i++)
            printf("%d  ", i);
        printf("\n");

        for (int i = 0; i < mundoPtr->ordem; i++) {
            printf("%d  ", i);
            for (int j = 0; j < mundoPtr->ordem; j++)
                printf("%c  ", mundoPtr->matriz[i][j]);
            printf("\n");
        }
    } else { //matriz de ordem MAIOR que 10 (visa-se melhor espacamento)
        printf("    ");
        for (int i = 0; i < mundoPtr->ordem; i++)
            if (i >= 10) {
                printf("%d ", i);
            } else {
                printf("%d  ", i);
            }

        printf("\n");

        for (int i = 0; i < mundoPtr->ordem; i++) {
            if (i > 9)
                printf("%d  ", i);
            else
                printf("%d   ", i);
            for (int j = 0; j < mundoPtr->ordem; j++)
                printf("%c  ", mundoPtr->matriz[i][j]);
            printf("\n");
        }
    }
}
void submenu(matriz *mundoPtr, int geracao)//mostra sub-menu para o usuario
{
    printf("\nLegenda --> Vivo = 0  Morto = .\n\n");
    mostra_matriz(mundoPtr,geracao);
    printf("\nPor favor, escolha uma opcao: \n"
           "1 - Selecionar uma coodernada\n"
           "2 - Limpar mundo matricial\n"
           "3 - Listar celulas vivas, e mortas vizinhas\n"
           "4 - Obter numero de celulas vivas e mortas em volta de uma celula viva\n"
           "5 - Gerações\n"
           "0 - Sair do programa\n");
}
void cordenadas()//perguntar as cordenadas para escolher a celulas vivas
{
    printf("Coodernadas - LINHA E COLUNA (Ex: 1 1): ");
}
void mensagemdeerro()//caso tenha algo de errado a informar ao usuario
{
    printf("\nVoce digitou algo errado\nTente novamente!\n");
}


void interface()//mostrar pagina inicial do jogo
{

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
void listas(tlista *tvivosPtr,tlista *tmortosPtr)
{
    printf("\t    VIVOS\n ");
    printf("\t______________\n");
    printf("\tLinha | Coluna\n");
    for (int i = 1; i <=tvivosPtr->cont; i++) {


        printf(" \t    %d | %d\n", tvivosPtr->celula[i].lin, tvivosPtr->celula[i].col);
    }
    printf("\n\n");
    printf("\t    MORTOS\n ");
    printf("\t______________\n");
    printf("\tLinha | Coluna\n");
    for (int i = 1; i <=tmortosPtr->cont; i++)
    {

        printf(" \t    %d | %d\n", tmortosPtr->celula[i].lin, tmortosPtr->celula[i].col);

    }
}

void  nVizinhos(tlista *tvivosPtr,tlista *tmortosPtr)
{
    printf("\t    VIVOS\n");
    for(int posicaolista=1;posicaolista<=tvivosPtr->cont;posicaolista++)
    {

        printf("Celula %d, na qual esta na coordenada [%d][%d], possui %d vizinho(s) VIVOS.\n",posicaolista,tvivosPtr->celula[posicaolista].lin,tvivosPtr->celula[posicaolista].col,tvivosPtr->celula[posicaolista].vizinhosvivos );
        printf("Celula %d, na qual esta na coordenada [%d][%d], possui %d vizinho(s) MORTOS.\n",posicaolista,tvivosPtr->celula[posicaolista].lin,tvivosPtr->celula[posicaolista].col,tvivosPtr->celula[posicaolista].vizinhosmortos);
    }
    printf("\t    MORTOS\n");
    for(int posicaolista=1;posicaolista<=tmortosPtr->cont;posicaolista++)
    {
        printf("Celula %d, na qual esta na coordenada [%d][%d], possui %d vizinho(s) VIVOS.\n",posicaolista,tmortosPtr->celula[posicaolista].lin,tmortosPtr->celula[posicaolista].col,tmortosPtr->celula[posicaolista].vizinhosvivos );
    }
}
void pergunta_geracoes()
{
    printf("\nPor favor, Digite o numero de gerações que você quer simular:");
}
void pergunta_intervalo_geracoes()
{
    printf("\nAgora, digite o intervalo de tempo da sua escolha entre 0 a 10 segundos(0=passoa-a-passoa,a cada geração:");
}
void pergunta_passo_a_passo()
{
    printf("\nDigite p para ir para proxima geração ou s para sair :");
}
