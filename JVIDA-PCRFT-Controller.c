#include "JVIDA-PCRFT-Controller.h"

void menu() { //Inicio do programa, acompanhado do menu inicial e logica do programa

    matriz mundo, *mundoPtr;
    mundoPtr = &mundo;
    tlista tvivos, tmortos, fmortos, fvivos, *tvivosPtr, *tmortosPtr, *fmortosPtr, *fvivosPtr;

    tvivosPtr = &tvivos;
    fvivosPtr = &fvivos;
    tmortosPtr = &tmortos;
    fmortosPtr = &fmortos;

    int opt; //Opcao do usuario embutida no switch
    int ngeracao, tempogeracao;//Case 5 -> numero de geracoes-tempo entre essas gerações
    int geracao = 1;//Case 5 -> contador do numero de gerações
    int cont;//Case 5 -> O contador para o rodar o numero de gerações pedidos
    char geracaopausa;//Case 5 -> A geração que o mundo se encontra
    bool mostrarmortos = false;

    interface();
    perguntarordem();

    //Recebe o tamanho da matriz (mundo), dado pelo usuário
    do {
        scanf("%d", &mundoPtr->ordem);
        if (mundoPtr->ordem > max_ordem || mundoPtr->ordem <= 1)
            mensagemdeerro();
    } while (mundoPtr->ordem > max_ordem || mundoPtr->ordem <= 1);

    preenche_matriz(mundoPtr, tvivosPtr, tmortosPtr);

    do {
        geracao = 1;
        submenu(mundoPtr, tmortosPtr, geracao, mostrarmortos);
        scanf("%d", &opt);

        switch (opt) {
            //Case 1: Seleção uma coordenada
            case 1:
                tvivos.cont++;
                do {
                    cordenadas();

                    scanf("%d %d", &tvivosPtr->celula[tvivosPtr->cont].lin,
                          &tvivosPtr->celula[tvivosPtr->cont].col);//Recebendo os valores das cordenadas
                    if ((tvivosPtr->celula[tvivosPtr->cont].lin >= mundoPtr->ordem ||
                         tvivosPtr->celula[tvivosPtr->cont].lin < 0) ||
                        (tvivosPtr->celula[tvivosPtr->cont].col >= mundo.ordem ||
                         tvivosPtr->celula[tvivosPtr->cont].col < 0) ||
                        mundoPtr->matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col] ==
                        '0')//Caso o valor seja invalido
                        mensagemdeerro();

                } while ((tvivosPtr->celula[tvivosPtr->cont].lin >= mundoPtr->ordem ||
                          tvivosPtr->celula[tvivosPtr->cont].lin < 0) ||
                         (tvivosPtr->celula[tvivosPtr->cont].col >= mundo.ordem ||
                          tvivosPtr->celula[tvivosPtr->cont].col < 0) ||
                         mundoPtr->matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col] ==
                         '0');//Se o valor for invalido volta de novo para o "do"
                mundoPtr->matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col] = '0';
                colocandovizinhosmortost(mundoPtr, tvivosPtr, tmortosPtr);
                definir_numero_de_vizinhos_vivo_e_mortos(tvivosPtr, tmortosPtr);
                break;

                //Case 2: Limpar mundo matricial
            case 2:

                preenche_matriz(mundoPtr, tvivosPtr, tmortosPtr); //Marcar cada termo da matriz com celulas mortas
                break;

                //Case 3: Lista celulas vivas, e mortas vizinhas
            case 3:
                if (tvivosPtr->cont !=
                    0) //Impedir o usuario de selecionar a lista, caso o numero de celulas vivas seja igual a 0 (matriz vazia)
                    listas(tvivosPtr, tmortosPtr);
                break;

                //Case 4: Obter numero de celulas vivas e mortas em volta de uma celula viva
            case 4:

                if (tvivosPtr->cont != 0) //Impedir o usuario de ver o numero de celulas MORTAS e VIVAS vizinhas,
                    //caso o numero de celulas vivas seja igual a 0 (matriz vazia)
                    nVizinhos(tvivosPtr, tmortosPtr);
                break;


            case 5: //Case 5: Geracoes
                cont = 1;
                pergunta_geracoes();
                scanf("%d", &ngeracao);
                pergunta_intervalo_geracoes();
                scanf("%d", &tempogeracao);

                do {
                    geracoes(mundoPtr, tvivosPtr, tmortosPtr, fvivosPtr, fmortosPtr);
                    cont++;
                    geracao++;
                    mostra_matriz(mundoPtr, tmortosPtr, geracao, mostrarmortos);
                    listas(tvivosPtr, tmortosPtr);

                    if (tvivosPtr->cont == 0)//Caso não haja nenhuma célula viva
                        aviso_geracao();
                    else if (tempogeracao == 0) {
                        do {
                            pergunta_passo_a_passo();
                            limpa_buffer();
                            scanf("%c", &geracaopausa);
                            if ((geracaopausa != 'p') && (geracaopausa != 's')) {
                                mensagemdeerro();
                            }
                        } while ((geracaopausa != 'p') && (geracaopausa != 's'));
                    }
                    sleep(tempogeracao);

                } while ((cont < ngeracao) && (geracaopausa != 's') && (tvivosPtr->cont != 0));

                break;

            case 6: //Case 6: Mostrar mortos vizinhos em notação '+', NA MATRIZ
                mostrarmortos = mostrar_mortos_vizinhos(mostrarmortos);
                break;

            default: //Case 0/default: Sair do programa
                mensagemdeerro();
                break;
        }
    } while (opt != 0); //Caso a opcao 0 for selecionada. o programa é finalizado
}
