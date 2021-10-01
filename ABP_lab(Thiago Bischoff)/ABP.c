#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ABP.h"

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

void CentralE(pNodoA *a)
{
     if (a!= NULL)
     {
          CentralE(a->esq);
          printf("%d - ",a->info);
          CentralE(a->dir);
      }
}

void CentralD(pNodoA *a)
{
     if (a!= NULL)
     {
          CentralD(a->dir);
          printf("%d - ",a->info);
          CentralD(a->esq);
      }
}

int iguais(pNodoA *arv1, pNodoA *arv2)
{
    if ((arv1 == NULL) && (arv2 == NULL))
        return 1;
    else
        if ((arv1 != NULL) && (arv2 != NULL))
            return ((arv1->info == arv2->info)&&
                    iguais(arv1->esq,arv2->esq)&&
                    iguais(arv1->dir,arv2->dir));
        else return 0;

}

int arv_busca(pNodoA *arv)
{
    if ((arv == NULL) || ((arv->esq == NULL) && (arv->dir == NULL)))
    {
        return 1;
    }
    else
    {
        if(arv->esq != NULL)
        {
            if(arv->info > arv->esq->info)
                return arv_busca(arv->esq);
            else
                return 0;
        }
        if(arv->dir != NULL)
        {
            if(arv->info > arv->dir->info)
                return arv_busca(arv->dir);
            else
                return 0;
        }
    }
}

int altura_nodos(pNodoA *arv)
{
    int he, hd;

    if (arv == NULL)
        return -1;
    else
    {
        he = altura_nodos(arv->esq);
        hd = altura_nodos(arv->dir);

        if (he < hd)
        {
            printf("\n\t%d: %d", arv->info, hd+1);
            return hd + 1;
        }
        else
        {
            printf("\n\t%d: %d", arv->info, he+1);
            return he + 1;
        }
    }
}

void caminho_para_valor(pNodoA *arv1, int valor1, int valor2)
{
    pNodoA *aux1;

    printf ("\n\n--Caminho entre %d e %d--", valor1, valor2);

    while((arv1 != NULL)&&(arv1->info != valor1))
    {
        if(arv1->info > valor1)
            arv1 = arv1->esq;
        else
            arv1 = arv1->dir;
    }

    if(arv1 == NULL)
    {
        printf("\nNao existe caminho para os valores\n");
    }

    if(arv1 != NULL)
    {
        aux1 = arv1;
        while((aux1!= NULL)&&(aux1->info != valor2))
        {
            if(aux1->info > valor2)
                aux1 = aux1->esq;
            else
                aux1 = aux1->dir;
        }

        if(aux1 != NULL)
        {
            printf("\n%d", arv1->info);
            while((arv1->info != aux1->info) && (arv1 != NULL))
            {
                if(arv1->info > aux1->info)
                {
                    arv1 = arv1->esq;
                    printf(" - %d", arv1->info);
                }
                else
                {
                    arv1=arv1->dir;
                    printf(" - %d", arv1->info);
                }
            }
        }
        else
            printf("\nNao existe caminho para os valores\n");
    }
}

