#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

ptDEC *cria_lista(void)//Função que cria a lista
{
    return NULL;
}

void imprime_lista(ptDEC *ptLista)
{
    ptDEC *ptAux;

    if (ptLista == NULL)
    {
        printf ("Lista Vazia\n");
    }
    else
    {
        ptAux = ptLista;
        do{
            printf(" / %d ", ptAux->numero);
            ptAux=ptAux->prox;
        }while(ptAux!=ptLista);
    }
}

//Funcao que insere no inicio da lista.
ptDEC *insere_inicio(ptDEC* ptLista, int num)
{
    ptDEC *novo, *ptAux;
    novo = (ptDEC*) malloc(sizeof(ptDEC));//Aloca memoria.
    novo->numero = num;

    if(ptLista == NULL)//Para o caso no qual nao existe elemento na lista.
    {
        novo->prox = novo;
        novo->ant = novo;
        ptLista = novo;

    }
    else if(ptLista->prox == ptLista)//Caso exista apenas um elemento.
    {
        novo->prox = ptLista;
        novo->ant = ptLista;
        ptLista->prox = novo;
        ptLista->ant = novo;
        ptLista = novo;
    }
    else if(ptLista->prox != ptLista)//Caso exista mais de um elemento.
    {
        ptAux = ptLista;
        while(ptAux->prox != ptLista)
        {
            ptAux = ptAux->prox;
        }
        ptAux->prox = novo;
        novo->ant = ptAux;
        novo->prox = ptLista;
        ptLista->ant = novo;
        ptLista = novo;
    }

    return ptLista;
}

//Funcao que insere no meio da lista.
ptDEC *insere_meio(ptDEC* ptLista, int num)
{
    ptDEC *novo, *ptAux=ptLista;
    int i=1, j=1;

    novo = (ptDEC*) malloc(sizeof(ptDEC)); //Aloca memoria.
    novo->numero = num;

    if(ptLista == NULL)
    {
        novo->prox = ptLista;
        novo->ant = novo;
        ptLista = novo;
    }
    else if(ptLista->prox == ptLista) //Caso a lista tenha apenas um elemento.
    {
        novo->prox = ptLista;
        novo->ant = ptLista;
        ptLista->prox = novo;
        ptLista->ant = novo;
        ptLista = novo;
    }
    else if(ptLista->prox != ptLista) //Caso a lista tenha mais de um elemento..
        {
        while(ptAux->prox != ptLista)
        {
            ptAux = ptAux->prox;
            i++; //Variavel que guarda o tamanho da lista.
        }
        ptAux = ptLista;
        if(i%2 == 0)
            {
            i = (i/2);
            while(j != i)
            {
               ptAux = ptAux->prox;
               j++;
            }
            novo->prox = ptAux->prox;
            novo->ant = ptAux;
            ptAux->prox->ant = novo;
            ptAux->prox = novo;
        }
        else //Caso a lista seja impar.
        {
            i = (i - 1) / 2;
            while(j != i){
               ptAux = ptAux->prox;
               j++;
            }
            novo->prox = ptAux->prox;
            novo->ant = ptAux;
            ptAux->prox->ant = novo;
            ptAux->prox = novo;
        }
    }

    return ptLista;
}

//Funcao que insere no fim da lista.
ptDEC *insere_fim(ptDEC* ptLista, int num)
{
    ptDEC *novo, *ptAux=ptLista;
    novo = (ptDEC*) malloc(sizeof(ptDEC));
    novo->numero = num;

    if(ptLista == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        ptLista = novo;
    }
    else if(ptLista->prox == ptLista)//Caso a lista tenha so um elemento.
    {
        ptLista->prox = novo;
        ptLista->ant = novo;
        novo->prox = ptLista;
        novo->ant = ptLista;
    }
    else if(ptLista->prox != ptLista)//Caso a lista tenha mais de um elemento.
    {
        while(ptAux->prox != ptLista)
        {
            ptAux = ptAux->prox;
        }
        ptAux->prox = novo;
        novo->ant = ptAux;
        novo->prox = ptLista;
        ptLista->ant = novo;
    }

    return ptLista;
}

//Funcao que procura um valor num na lista e imprime a lista na ordem normal e invertida, tendo como inicio o valor num.
void consulta_valor(ptDEC *ptLista, int num)
{
    ptDEC *ptAux, *ptAux2;
    int a = 0;

    if (ptLista == NULL)//Caso a lista esteja vazia, nao ira consultar valor nenhum.
    {
        printf("\n A lista esta vazia. Valor nao existe. \n");
    }
    else//Caso nao esteja vazia.
    {
        ptAux = ptLista;
        do
        {
            if(num == ptAux->numero)//Caso encontre o numero.
            {
                ptAux2 = ptAux;
                a = 1;
                printf("\nOrdem do ponteiro proximo. \n");
                do
                {
                    printf(" | %d ", ptAux->numero);
                    ptAux = ptAux->prox;
                }while(ptAux != ptLista);
                printf("\nOrdem do ponteiro anterior. \n");
                do
                {
                    printf(" | %d ", ptAux2->numero);
                    ptAux2 = ptAux2->ant;
                }while(ptAux2 != ptLista->ant);
            }
            else //Se nao encontrar o numero, avanca na lista.
            {
                ptAux = ptAux->prox;
            }
        }while(ptAux != ptLista); //Ira percorrer a lista procurando o numero.

        if(a == 0)
        {
            printf("\n Numero nao encontrado. \n");
        }
    }
}

ptDEC *destroi_lista(ptDEC *ptLista)
{
    ptDEC *ptAux, *ptAux2;

    if(ptLista == NULL){
        printf("\nA lista ja esta vazia. \n");
    }
    else
    {
        printf("\n\n");
        printf("Excluindo a lista: ");
        ptAux2 = ptLista->prox;
        printf(" | %d ", ptLista->numero);
        free(ptLista);
        while (ptAux2 != ptLista) //Ira percorrer a lista.
        {
            ptAux = ptAux2;
            ptAux2 = ptAux2->prox;
            printf(" | %d ", ptAux->numero);
            free(ptAux); //Libera a memoria utilizada.
        }
    }
    return NULL;
}
