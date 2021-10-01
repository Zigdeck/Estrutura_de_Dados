typedef struct tipoNo ptDEC;
struct tipoNo{
    int numero;
    ptDEC *prox;
    ptDEC *ant;
};

//Cria a lista.
ptDEC *cria_lista(void);

//Iimprime a lista.
void imprime_lista(ptDEC *ptLista);

//Insere no inicio da lista.
ptDEC *insere_inicio(ptDEC* ptLista, int num);

//Insere no meio da lista.
ptDEC *insere_meio(ptDEC* ptLista, int num);

//Insere no fim da lista.
ptDEC *insere_fim(ptDEC* ptLista, int num);

//Funcao que procura um valor num na lista e imprime a lista na ordem normal e invertida, tendo como inicio o valor num.
void consulta_valor(ptDEC *ptLista, int num);

//Destroi a lista e libera memoria
ptDEC *destroi_lista(ptDEC *ptLista);
