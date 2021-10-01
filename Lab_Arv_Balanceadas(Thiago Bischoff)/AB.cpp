#include <stdio.h>
#include <stdlib.h>
#include "AB.h"

pNodoA* InsereArvore(pNodoA *a, tipoinfo ch)
{
     if (a == NULL)
     {
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info)
              a->esq = InsereArvore(a->esq,ch);
          else if (ch > a->info)
              a->dir = InsereArvore(a->dir,ch);
     return a;
}

int FATOR_achar_no(pNodoA *arv, int valor)
{
    int fator;

    if (arv == NULL)
    {
        printf("Valor %d nao esta na arvore.\n", valor);
    }

    else if (arv->info != valor) //continua procurando se não achar
        {
            if (valor > arv->info)
                FATOR_achar_no(arv->dir, valor);
            else
                FATOR_achar_no(arv->esq, valor);
        }

    else // achou o valor
    {
        fator = FATOR_no(arv); //passa o valor para a proxima funçao

        return fator;
    }
}

int FATOR_no(pNodoA *arv)
{
    int fator;
    fator = ((altura_no(arv->esq)) - (altura_no(arv->dir)));
    return fator;
}

int altura_no(pNodoA *arv)
{
    int he, hd;

    if (arv == NULL)
        return -1;
    else
    {
        he = altura_no(arv->esq);
        hd = altura_no(arv->dir);
        if(he>hd)
            return (1+he);
        else
            return (1+hd);
    }
}

int verifica_avl(pNodoA *arv)
{
    int he, hd;

    if(arv != NULL)
    {
        he = altura_no(arv->esq);
        hd = altura_no(arv->dir);

        return ((he-hd < 2) && (hd-he < 2) && (verifica_avl(arv->esq)) && (verifica_avl(arv->dir)));
    }
    else
        return 1;
}


int verifica_rn(pNodoA *arv)
{
    int he, hd;

    if(arv != NULL)
    {
        he = altura_no(arv->esq);
        hd = altura_no(arv->dir);

        return ((he <= 2*hd) && (hd <= 2*he) && (verifica_rn(arv->esq)) && (verifica_rn(arv->dir)));
    }
    else
        return 1;
}

void destroi_arvore(pNodoA *arv)
{
    if(arv == NULL)
    {
        return;
    }
    destroi_arvore(arv->esq);
    destroi_arvore(arv->dir);
    free(arv);
}
