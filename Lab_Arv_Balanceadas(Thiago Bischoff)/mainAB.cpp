#include <stdio.h>
#include <stdlib.h>
#include "AB.h"

int main()
{
    pNodoA *arv = NULL;
    int valor;

    arv = InsereArvore(arv,30);
    arv = InsereArvore(arv,50);
    arv = InsereArvore(arv,25);
    arv = InsereArvore(arv,90);
    arv = InsereArvore(arv,80);
    arv = InsereArvore(arv,95);
    arv = InsereArvore(arv,20);
    arv = InsereArvore(arv,26);

    //Outros valores para teste
    /*
    arv = InsereArvore(arv,10);
    arv = InsereArvore(arv,25);
    arv = InsereArvore(arv,30);
    arv = InsereArvore(arv,40);
    arv = InsereArvore(arv,80);
    */

    //valor a ser procurado
    valor = 30;
    printf("Fator do nodo %d: %d\n\n", valor, FATOR_achar_no(arv, valor));
    valor = 80;
    printf("Fator do nodo %d: %d\n\n", valor, FATOR_achar_no(arv, valor));
    valor = 99;
    FATOR_achar_no(arv, valor);


    printf("\nVerifica se eh AVL (0= NAO/ 1= SIM): ");
    printf("%d\n\n", verifica_avl(arv));


    printf("Verifica se eh R-N (0= NAO/ 1= SIM): ");
    printf("%d\n\n", verifica_rn(arv));


    destroi_arvore(arv);
    printf("Arvore apagada...\n");

    system("pause");
    return 0;
}
