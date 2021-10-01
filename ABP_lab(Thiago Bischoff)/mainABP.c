#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ABP.h"

int main()
{
    pNodoA *arv1 = NULL, *arv2 = NULL;
    int numero;

    arv1 = InsereArvore(arv1,30);
    arv1 = InsereArvore(arv1,45);
    arv1 = InsereArvore(arv1,25);
    arv1 = InsereArvore(arv1,90);
    arv1 = InsereArvore(arv1,80);
    arv1 = InsereArvore(arv1,95);

/*  //arv2 = arv1
    arv2 = InsereArvore(arv1,30);
    arv2 = InsereArvore(arv1,45);
    arv2 = InsereArvore(arv1,25);
    arv2 = InsereArvore(arv1,90);
    arv2 = InsereArvore(arv1,80);
    arv2 = InsereArvore(arv1,95);

    //arv2 != arv1
    arv2 = InsereArvore(arv2,30);
    arv2 = InsereArvore(arv2,25);
    arv2 = InsereArvore(arv2,90);
    arv2 = InsereArvore(arv2,80);
    arv2 = InsereArvore(arv2,95);
*/

    printf("-- Central Esquerda Arvore 1 --\n");
    CentralE(arv1);
    printf("\n\n");

    printf("-- Central Direita Arvore 1 --\n");
    CentralD(arv1);
    printf("\n\n");

    printf("-- Central Esquerda Arvore 2 --\n");
    CentralE(arv2);
    printf("\n\n");

    printf("-- Central Direita Arvore 2 --\n");
    CentralD(arv2);
    printf("\n\n");

    numero = iguais(arv1, arv2);
    printf (" (0 = Diferentes / 1 = Iguais)");
    printf("\n\t\t -- %d --",numero);

    printf ("\n\n (0 = Nao eh de busca / 1 = Eh de busca)");
    printf ("\n\t\t -- %d --", arv_busca(arv1));

    printf ("\n\n-- Altura dos nodos --");
    if (altura_nodos(arv1) == -1)
        printf ("\nErro!\n");

    caminho_para_valor(arv1, 30, 95);
    printf("\n");

    system("pause");
}
