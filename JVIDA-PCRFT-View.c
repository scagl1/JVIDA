#include "JVIDA-PCRFT-View.h"

void perguntarordem()//Pergunta a ordem do mundo matricial que o usuário quer
{
    printf("\nPor favor, insira a ordem da matriz (De 2 a %d): ", max_ordem);
}

//Mostrar matriz (mundo)
void mostra_matriz(matriz *mundoPtr,tlista *tmortosPtr ,int geracao, bool mostrarmortos)
{
    if(mostrarmortos==true)
    {
        for(int cont=1;cont<=tmortosPtr->cont;cont++)
        {
            mundoPtr->matriz[tmortosPtr->celula[cont].lin][tmortosPtr->celula[cont].col]='+';
        }
    }else
    {
        for(int cont=1;cont<=tmortosPtr->cont;cont++)
        {
            mundoPtr->matriz[tmortosPtr->celula[cont].lin][tmortosPtr->celula[cont].col]='.';
        }
    }
    printf("\n");
    printf("\nLegenda --> Vivo = 0  Morto = . Mortos vizinho = + \n");
    printf("\nGERACAO: %d", geracao);
    printf("\nLinha (numeros da esquerda), Coluna (numeros de cima)\n\n");

    if (mundoPtr->ordem <= 10) { //Condição caso matriz seja de ordem MENOR que 10 (em 10, teremos coodenadas entre 0-9)
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
    } else { //Condição caso matriz seja de ordem MAIOR que 10 (visando melhor espacamento)
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

//Visualização do sub-menu
void submenu(matriz *mundoPtr,tlista *tmortosPtr, int geracao, bool mostrarmortos )
{
    mostra_matriz(mundoPtr,tmortosPtr,geracao, mostrarmortos);
    printf("\nPor favor, escolha uma opcao: \n"
           "1 - Selecionar uma coodernada\n"
           "2 - Limpar mundo matricial\n"
           "3 - Listar celulas vivas, e mortas vizinhas\n"
           "4 - Obter numero de celulas vivas e mortas em volta de uma celula viva\n"
           "5 - Geracoes\n"
           "6 - Mostrar mortos vizinhos (Selecione novamente para desativar)\n"
           "0 - Sair do programa\n");
}
void cordenadas()//Perguntar as cordenadas para escolher a celulas vivas (Case 1)
{
    printf("Coodernadas - LINHA E COLUNA (Ex: 1 1): ");
}
void mensagemdeerro()//Mensagem de erro ao usuário
{
    printf("\nVoce digitou algo errado\nTente novamente!\n");
}

void interface()//Arte da página inicial do jogo
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

//Apresenta a tabela de células vivas, e mortas vizinhas
void listas(tlista *tvivosPtr,tlista *tmortosPtr)
{
    printf("\nVIVOS (Linha | Coluna):\n ");

    for (int i = 1; i <= tvivosPtr->cont; i++)
        printf("(%d | %d) ", tvivosPtr->celula[i].lin, tvivosPtr->celula[i].col);

    printf("\n\n");
    printf("MORTOS (Linha | Coluna):\n ");
    for (int i = 1; i <=tmortosPtr->cont; i++)
    {
        printf("(%d | %d) ", tmortosPtr->celula[i].lin, tmortosPtr->celula[i].col);
    }
}

void  nVizinhos(tlista *tvivosPtr,tlista *tmortosPtr)
{
    printf("\t    VIVOS\n");
    for(int posicaolista=1;posicaolista<=tvivosPtr->cont;posicaolista++)
    {
        printf("Celula %d, na qual esta na coordenada [%d][%d], possui %d vizinho(s) VIVOS.\n", posicaolista,tvivosPtr->celula[posicaolista].lin,tvivosPtr->celula[posicaolista].col,tvivosPtr->celula[posicaolista].vizinhosvivos );
        printf("Celula %d, na qual esta na coordenada [%d][%d], possui %d vizinho(s) MORTOS.\n", posicaolista,tvivosPtr->celula[posicaolista].lin,tvivosPtr->celula[posicaolista].col,tvivosPtr->celula[posicaolista].vizinhosmortos);
    }
    printf("\t    MORTOS\n");
    for(int posicaolista = 1; posicaolista <= tmortosPtr->cont; posicaolista++)
    {
        printf("Celula %d, na qual esta na coordenada [%d][%d], possui %d vizinho(s) VIVOS.\n", posicaolista,tmortosPtr->celula[posicaolista].lin,tmortosPtr->celula[posicaolista].col,tmortosPtr->celula[posicaolista].vizinhosvivos );
    }
}

//As seguintes funcoes realizam a funcao de print, para serem utilizadas em outras funcoes distintas:
//Começo das funções de print
void pergunta_geracoes()
{
    printf("\nPor favor, digite o numero de geracoes que deseja simular:");
}

void pergunta_intervalo_geracoes()
{
    printf("Digite o intervalo de tempo de sua escolha,\nentre 0 a 10 segundos para visualizar"
           "o desenvolvimento\nde cada geracao: ");
}
void pergunta_passo_a_passo()
{
    printf("\nDigite p para prosseguir, s para sair :");
}

void aviso_geracao()
{
    printf("\nNao existe nenhuma celula viva depois dessa geracao!");
}
//Término das funções de print