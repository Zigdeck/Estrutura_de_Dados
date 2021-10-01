typedef int tipoinfo;

struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

pNodoA* InsereArvore(pNodoA *a, tipoinfo ch);
void CentralE(pNodoA *a);
void CentralD(pNodoA *a);

//verifica se duas arvores sao iguais em estrutura e conteudo
int iguais(pNodoA *arv1, pNodoA *arv2);
//verifica se a arvore é de busca
int arv_busca(pNodoA *arv);
//verifica a altura de cada nodo
int altura_nodos(pNodoA *arv);
//mostra o caminho de um valor até o outro
void caminho_para_valor(pNodoA *arv1, int valor1, int valor2);
