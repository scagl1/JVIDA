#include "JVIDA-PCRFT-Controller.h"

void menu() { //Inicio do programa, acompanhado do menu inicial e logica do programa

    matriz mundo, *mundoPtr;
    tlista tvivos, tmortos, fvivos, *tvivosPtr, *tmortosPtr, *fvivosPtr;
    salvo listasalva, *listasalvaPtr;


    mundoPtr = &mundo;
    listasalvaPtr=&listasalva;

    tvivosPtr = &tvivos;
    fvivosPtr = &fvivos;
    tmortosPtr = &tmortos;



    int lin=-2;
    int col=-2;
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
    preenche_matriz(mundoPtr, tvivosPtr,fvivosPtr,tmortosPtr);

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

                    do {

                        //perguntar as cordenadas
                        cordenadas();
                        scanf("%i %i", &lin,&col);//Recebendo os valores das cordenadas
                        if ((lin >= mundoPtr->ordem ||lin < -1) || (col >= mundo.ordem || col < -1)||(mundo.matriz[lin][col]=='0') )//Caso o valor seja invalido
                        {
                            mensagemdeerro();//mensagem de erro caso for digitado algo errado
                        }
                    } while ((lin >= mundoPtr->ordem || lin < -1) || (col >= mundo.ordem || col < -1)||(mundo.matriz[lin][col]=='0') );//Se o valor for invalido volta de novo para o "do"
                    if (lin !=-1 && col!= -1)//se for doferente de -1 e -1
                    {
                        mundoPtr->matriz[lin][col] = '0';//define celula como viva
                        carregaVivo(tvivosPtr,lin,col,-1);
                        colocandovizinhosmortost(mundoPtr,tvivosPtr,tmortosPtr,lin,col);//adiciona mortos vizinhos
                    }
                } while (lin !=-1 && col!= -1);

                definir_numero_de_vizinhos_vivo_e_mortos(tvivosPtr, tmortosPtr);//define o numero de vizinho vivos das celulas
                break;

                //Case 2: Limpar mundo matricial
            case 2:

                preenche_matriz(mundoPtr,tvivosPtr,fvivosPtr,tmortosPtr); //Marcar cada termo da matriz com celulas mortas
                break;


            case 3: //Case 3: Geracoes
                cont = 1;// iniciando contador
                //perguntar numero de gerações a serem rodadas
                pergunta_geracoes();
                scanf("%d", &ngeracao);
                //perguntado o intervalo de tempo que essas gerações serem mostradas na tela
                pergunta_intervalo_geracoes();
                scanf("%d", &tempogeracao);
                //loop (do-while) para rodar o número de gerações pedidas
                do {
                    geracaopausa='p';
                    //Essa função testa as celulas vivas e seleciona as que de acordo as regras passaram para a próxima geração
                    geracoes(mundoPtr, tvivosPtr, tmortosPtr, fvivosPtr);
                    cont++;//contador do número de gerações pedidas
                    geracao++;//aumentando o número de gerações
                    mostra_matriz(mundoPtr, tmortosPtr, geracao, mostrarmortos);//imprimir na tela mundo
                    listas(tvivosPtr, tmortosPtr);//imprimir na tela lista de vivos e mortos para teste

                    if (tvivosPtr->cont == 0)//Caso não haja nenhuma célula viva
                        aviso_geracao(geracao);
                    else if (tempogeracao == 0) //caso seja 0 o tempogeração e pegunta para passar para proxima
                    {
                        do {
                            pergunta_passo_a_passo();//pergunta
                            limpa_buffer();//limpa o buffer
                            scanf("%c", &geracaopausa);//pegar a resposta
                            if ((geracaopausa != 'p') && (geracaopausa != 's'))//caso a resposta seja invalida
                            {
                                mensagemdeerro();//mensagem de erro e printada
                            }
                        } while ((geracaopausa != 'p') && (geracaopausa != 's'));//caso o valor seja invalido pergunta de novo
                    }
                    sleep(tempogeracao);//tempo de espera que o usuario pediu

                } while ((cont < ngeracao) && (geracaopausa != 's') && (tvivosPtr->cont != 0));//caso não foi rodado o numero de gerações pedido ou não foi selecionado para sair

                break;

            case 4: //Case 4: Mostrar mortos vizinhos em notação '+', NA MATRIZ
                mostrarmortos = mostrar_mortos_vizinhos(mostrarmortos);
                break;

            case 5://case5: Adicionar lista salva
               //salvar
               if(tvivosPtr->cont>0)//caso exista pelomenos 1 celula viva para salvar
               {
                    aumentarlistasalva(listasalvaPtr,tvivosPtr);

                   save(listasalvaPtr);

                    mundosalvo();

               }else//caso não tenha nem uma celula viva no mundo que vai salvar
               {
                  sem_celulas_para_salvar();
               }



                break;
            case 6://case: recuperar listas salvas em ordem
                preenche_matriz(mundoPtr, tvivosPtr,fvivosPtr,tmortosPtr);//Marcar cada termo da matriz com celulas mortas
                pegarlistasalva(mundoPtr,listasalvaPtr,tvivosPtr,tmortosPtr,cont_listasalva);


                if(cont_listasalva>=listasalvaPtr->cont)//caso  o contador seja igual a o  maximo
                {
                    cont_listasalva=0;//volta para o inicio
                }
                cont_listasalva++;//aumenta o contador
                break;
                 
            case 7://case 7:imprimindo as regras
                regras();//regras
                break;

            default: //Case 0:Sair do programa//default:foi digitado algo errado
            if (opt!=0)
            {
                mensagemdeerro();//mensagem de erro caso foi digitado uma opção invalida

            }

                break;
        }
    } while (opt != 0); //Caso a opcao 0 for selecionada.O programa é finalizado

}
