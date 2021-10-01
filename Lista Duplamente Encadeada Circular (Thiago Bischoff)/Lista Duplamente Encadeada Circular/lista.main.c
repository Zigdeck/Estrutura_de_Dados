#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main (){
    int num;
    ptDEC *ptLista;

    ptLista = cria_lista();
    printf("\n Imprimindo... ");
    imprime_lista(ptLista); //Imprime a lista

    printf("\n Digite um numero: ");
    scanf("%d", &num);

    while(num != 0) //Se num=0, o programa fecha
    {
        if(num < 0)
        {
            ptLista = insere_meio(ptLista, num);
        }
        else if(num%2 == 0)
        {
            ptLista = insere_inicio(ptLista, num);
        }
        else
        {
            ptLista = insere_fim(ptLista, num);
        }

        printf("\n Imprimindo lista... ");
        imprime_lista(ptLista);

        printf("\n Digite um numero: ");
        scanf("%d", &num); //Le numero novamente.
    }

    printf("Insira o numero desejado para ser procurado. \n");
    scanf("%d", &num);
    consulta_valor(ptLista, num); //Chama a funcao consulta_valor.

    ptLista = destroi_lista(ptLista); //Destroi a lista
    printf("\nLista Destruida.");

    return 0;
}
