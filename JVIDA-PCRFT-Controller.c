#include "JVIDA-PCRFT-Controller.h"

void menu() { //Inicio do programa, acompanhado do menu inicial e logica do programa

    matriz mundo, *mundoPtr;
    mundoPtr = &mundo;
    tlista tvivos, tmortos, fmortos, fvivos, *tvivosPtr, *tmortosPtr, *fmortosPtr, *fvivosPtr;
    salvo listasalva, *listasalvaPtr;

    listasalvaPtr=&listasalva;
    tvivosPtr = &tvivos;
    fvivosPtr = &fvivos;
    tmortosPtr = &tmortos;
    fmortosPtr = &fmortos;

    int opt; //Opcao do usuario embutida no switch
    int ngeracao, tempogeracao;//Case 4 -> numero de geracoes-tempo entre essas gerações
    int geracao = 1;//Case 4 -> contador do numero de gerações
    int cont;//Case 4 -> O contador para o rodar o numero de gerações pedidos
    char geracaopausa;//Case 4 -> A geração que o mundo se encontra
    bool mostrarmortos = false;//case 5-> variavel para definir se quer que mostre os vizinhos mortos como "+"
    int cont_listasalva=1;//case 7 ->contador para listas salvas

    pegandovalorsalvo(listasalvaPtr);
    //interface inicial
    interface();
   //perguntando a ordem do mundo
    perguntarordem();
    //Recebe o tamanho da matriz (mundo), dado pelo usuário
    do {
        scanf("%d", &mundoPtr->ordem);
        if (mundoPtr->ordem > max_ordem || mundoPtr->ordem <= 1)
            mensagemdeerro();
    } while (mundoPtr->ordem > max_ordem || mundoPtr->ordem <= 1);
//limpando as listas e o mundo para prevenir sujeira de memória
    preenche_matriz(mundoPtr, tvivosPtr, tmortosPtr);

    do {
        geracao = 1;// iniciando a geração com  1
        //imprimindo sub-menu e opções para o jogador
        submenu(mundoPtr,tvivosPtr,tmortosPtr, geracao, mostrarmortos);
        //pegando opção
        scanf("%d", &opt);

        switch (opt) {
            //Case 1: Seleção uma coordenada
            case 1:

                do {
                    mostra_matriz(mundoPtr, tmortosPtr, geracao, mostrarmortos);//imprimir na tela mundo
                    listas(tvivosPtr, tmortosPtr);//imprimir na tela lista de vivos e mortos para teste

                    tvivosPtr->cont++;
                    do {

                        //perguntar as cordenadas
                        cordenadas();
                        scanf("%d %d", &tvivosPtr->celula[tvivosPtr->cont].lin,&tvivosPtr->celula[tvivosPtr->cont].col);//Recebendo os valores das cordenadas
                        if ((tvivosPtr->celula[tvivosPtr->cont].lin >= mundoPtr->ordem || tvivosPtr->celula[tvivosPtr->cont].lin < -1) ||(tvivosPtr->celula[tvivosPtr->cont].col >= mundo.ordem ||tvivosPtr->celula[tvivosPtr->cont].col < -1)||(mundo.matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col]=='0') )//Caso o valor seja invalido
                        {
                            mensagemdeerro();

                        }
                    } while ((tvivosPtr->celula[tvivosPtr->cont].lin >= mundoPtr->ordem || tvivosPtr->celula[tvivosPtr->cont].lin < -1) || (tvivosPtr->celula[tvivosPtr->cont].col >= mundo.ordem || tvivosPtr->celula[tvivosPtr->cont].col < -1)||(mundo.matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col]=='0') );//Se o valor for invalido volta de novo para o "do"
                    if (tvivosPtr->celula[tvivosPtr->cont].lin !=-1 && tvivosPtr->celula[tvivosPtr->cont].col!= -1)
                    {
                        mundoPtr->matriz[tvivosPtr->celula[tvivosPtr->cont].lin][tvivosPtr->celula[tvivosPtr->cont].col] = '0';
                        colocandovizinhosmortost(mundoPtr, tvivosPtr, tmortosPtr);
                        definir_numero_de_vizinhos_vivo_e_mortos(tvivosPtr, tmortosPtr);
                    }
                } while (tvivosPtr->celula[tvivosPtr->cont].lin !=-1 && tvivosPtr->celula[tvivosPtr->cont].col!= -1);
                if(tvivosPtr->celula[tvivosPtr->cont].lin ==-1 && tvivosPtr->celula[tvivosPtr->cont].col== -1)
                {
                    tvivosPtr->cont--;
                }
                break;

                //Case 2: Limpar mundo matricial
            case 2:

                preenche_matriz(mundoPtr, tvivosPtr, tmortosPtr); //Marcar cada termo da matriz com celulas mortas
                break;
                //Case 3: Obter numero de celulas vivas e mortas em volta de uma celula viva
            case 3:

                if (tvivosPtr->cont != 0) //Impedir o usuario de ver o numero de celulas MORTAS e VIVAS vizinha// caso o numero de celulas vivas seja igual a 0 (matriz vazia)
                    nVizinhos(tvivosPtr, tmortosPtr);
                break;


            case 4: //Case 4: Geracoes
                cont = 1;// iniciando contador
                //perguntar numero de gerações a serem rodadas
                pergunta_geracoes();
                scanf("%d", &ngeracao);
                //perguntado o intervalo de tempo que essas gerações serem mostradas na tela
                pergunta_intervalo_geracoes();
                scanf("%d", &tempogeracao);
                //loop (do-while) para rodar o número de gerações pedidas
                do {
                    //Essa função testa as celulas vivas e seleciona as que de acordo as regras passaram para a próxima geração
                    geracoes(mundoPtr, tvivosPtr, tmortosPtr, fvivosPtr, fmortosPtr);
                    cont++;//contador do número de gerações pedidas
                    geracao++;//aumentando o número de gerações
                    mostra_matriz(mundoPtr, tmortosPtr, geracao, mostrarmortos);//imprimir na tela mundo
                    listas(tvivosPtr, tmortosPtr);//imprimir na tela lista de vivos e mortos para teste

                    if (tvivosPtr->cont == 0)//Caso não haja nenhuma célula viva
                        aviso_geracao(geracao);
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

            case 5: //Case 5: Mostrar mortos vizinhos em notação '+', NA MATRIZ
                mostrarmortos = mostrar_mortos_vizinhos(mostrarmortos);
                break;
            case 6:
               //salvar
                aumentarlistasalva(listasalvaPtr,tvivosPtr);
                save(listasalvaPtr);
                mundosalvo();

                break;
            case 7:
                preenche_matriz(mundoPtr, tvivosPtr, tmortosPtr); //Marcar cada termo da matriz com celulas mortas
                pegarlistasalva(mundoPtr,listasalvaPtr,tvivosPtr,tmortosPtr,cont_listasalva);

                if(cont_listasalva>=listasalvaPtr->cont)
                {
                    cont_listasalva=0;
                }
                cont_listasalva++;
                break;

            default: //Case 0/default: Sair do programa
            if (opt!=0)
                mensagemdeerro();
                break;
        }
    } while (opt != 0); //Caso a opcao 0 for selecionada. o programa é finalizado

}
