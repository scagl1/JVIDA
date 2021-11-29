#include "JVIDA-PCRFT-View.h"
//As seguintes funcoes realizam a funcao de print, para serem utilizadas em outras funcoes distintas:

void perguntarordem()//Pergunta a ordem do mundo matricial que o usuário quer
{
    printf("\nPor favor, insira a ordem da matriz (De 2 a %d): ", max_ordem);
}

//Mostrar matriz (mundo)
void mostra_matriz(matriz *mundoPtr,tlista *tmortosPtr ,int geracao, bool mostrarmortos)
{
    cel *mortosvizinhos;
    mortosvizinhos=tmortosPtr->celula;
    if(mostrarmortos==true)
    {
        while(mortosvizinhos!=NULL)
        {
            mundoPtr->matriz[mortosvizinhos->lin][mortosvizinhos->col]='+';
            mortosvizinhos=mortosvizinhos->next;
        }
    }else
    {
        while(mortosvizinhos!=NULL)
        {
            mundoPtr->matriz[mortosvizinhos->lin][mortosvizinhos->col]='.';
            mortosvizinhos=mortosvizinhos->next;
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
void submenu(matriz *mundoPtr,tlista *tvivosPtr,tlista *tmortosPtr, int geracao, bool mostrarmortos )
{
    mostra_matriz(mundoPtr,tmortosPtr,geracao, mostrarmortos);//mostrar mundo
    listas(tvivosPtr, tmortosPtr);// mostrar lista de vivos e mortos-vizinhos
    printf("\nNUMEROS DE VIVOS: %d",tvivosPtr->cont);
    printf("\nNUMEROS DE MORTOS-VIZINHOS: %d",tmortosPtr->cont);
    printf("\n==============================");
    printf("\nPor favor, escolha uma opcao: \n"
           "1 - Selecionar uma coodernada para adicionar celula viva\n"
           "2 - Limpar mundo matricial\n"
           "3 - Geracoes\n"
           "4 - Mostrar mortos vizinhos (Selecione novamente para desativar)\n"
           "5 - Salvar mundo nas listas de mundos\n"
           "6 - Abrir mundo salvo\n"
           "7 - Regras\n"
           "0 - Sair do programa\n");
}
void cordenadas()//Perguntar as cordenadas para escolher a celulas vivas (Case 1)
{
    printf("\nCoodernadas - LINHA E COLUNA (Ex: 1 1) para sair (-1 -1): ");
}
void mensagemdeerro()//Mensagem de erro ao usuário
{
    printf("\n=======================\n");
    printf("\nVoce digitou algo errado"
           "\nTente novamente!\n");
    printf("\n=======================\n");
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
    cel *vivos, *mortos;

    printf("\nVIVOS (Linha | Coluna):\n ");
    vivos=tvivosPtr->celula;
    while (vivos!=NULL)
    {
        printf("(%d | %d) ", vivos->lin, vivos->col);
        vivos=vivos->next;
    }


    printf("\n\n");
    mortos=tmortosPtr->celula;
    printf("MORTOS (Linha | Coluna):\n ");
    while (mortos!=NULL)
    {
        printf("(%d | %d) ", mortos->lin, mortos->col);
        mortos=mortos->next;
    }
}



//perguntar numero de gerações que o usuario quer
void pergunta_geracoes()
{
    printf("\nPor favor, digite o numero de geracoes que deseja simular:");
}
//perguntar intervalo de tempo entre a gerações
void pergunta_intervalo_geracoes()
{
    printf("\nDigite o intervalo de tempo,entre 0 a 10 segundos para visualizar o desenvolvimento de cada geracao(0=passo a passo): ");
}
//pergunta se deve continuar para proxima geração ou sair para o sub-menu
void pergunta_passo_a_passo()
{
    printf("\nDigite 'p' para prosseguir, 's' para sair :");
}
//caso não tenha celula viva na geração informa o usuario
void aviso_geracao(int geracao)
{
    printf("\n====================================================\n"
           "\nNao existe nenhuma celula viva depois dessa geracao!\n"
           "\nNumero de geracoes rodadas:%d"
           "\n====================================================\n",geracao);
}
//mostrar que o mundo está salvo
void mundosalvo()
{
    printf("\n========================\n");
    printf("\n     MUNDO SALVO        \n");
    printf("\n========================\n");
}
//imprimir na tela que não tem nem uma celula no mundo para salvar
void sem_celulas_para_salvar()
{
    printf("\n================================================\n");
    printf("\n   NAO TEM NEM UMA CELULA NO MUNDO PARA SALVAR  \n");
    printf("\n================================================\n");
}
//imprimir as regras na tela
void regras()
{
    printf("\n============================================================================================================\n"
           "\nREGRAS:\n"
           "REPRODUÇÂO: Um ser vivo nasce numa célula vazia se essa célula vazia tiver exatamente 3 seres vivos vizinhos.\n"
           "SOBREVIVÊNCIA: Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geração seguinte.\n"
           "MORTE POR FALTA DE COMIDA: Um ser vivo com 4 ou mais vizinhos morre porque fica sem comida.\n"
           "MORTE POR SOLIDÃO: Um ser vivo com 0 ou 1 vizinhos morre de solidão.\n"
           "\n============================================================================================================\n");
}