typedef int tipoinfo;

struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

pNodoA* InsereArvore(pNodoA *a, tipoinfo ch);

//acha onde esta o valor procurado na arvore e passa para FATOR_nodo
int FATOR_achar_no(pNodoA *arv, int valor);

//passa o nodo da esquerda e da direita para o altura_nodo e calcula a diferença entre eles
int FATOR_no(pNodoA *arv);

//calcula a altura da esquerda e da direita
int altura_no(pNodoA *arv);

//verifica se uma árvore é avl
int verifica_avl(pNodoA *arv);

//verifica se uma arvore é R-N
int verifica_rn(pNodoA *arv);

//destroi a arvore e desocupa memoria
void destroi_arvore(pNodoA *arv);
