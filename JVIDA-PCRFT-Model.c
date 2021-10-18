#include <stdio.h>

#include "JVIDA-PCRFT-Model.h"
#include "JVIDA-PCRFT-View.h"

ordem ordem1;
//funções
void preenche_matriz() { // colocando toda a matriz que vai ser o mundo como celulas mortas

    for (int i = 0; i < ordem1.ordem; i++)
        for (int j = 0; j < ordem1.ordem; j++)
            ordem1.matriz[i][j] = '.';
}
void recebe_ordem() {//pegar o tamanho da matriz(mundoa) que o usuário quer

    do {
        scanf("%d", &ordem1.ordem);
        if (ordem1.ordem > max_ordem || ordem1.ordem <= 1) {
            mensagemdeerro();
        }
    } while (ordem1.ordem > max_ordem || ordem1.ordem <= 1);
}





