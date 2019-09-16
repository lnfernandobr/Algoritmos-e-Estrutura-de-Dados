#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>



typedef unsigned int Bool;
const unsigned int true = 1;
const unsigned int false = 0;


struct s_no {
    int32_t chave:28;
    int32_t bal:2;
    int32_t reservado:2; /* sem uso */
    struct s_no* esq;
    struct s_no* dir;
};

struct s_arq_no {
    int32_t chave:28;
    int32_t bal:2;
    uint32_t esq:1;
    uint32_t dir:1;
};

typedef struct s_no AVL;
typedef struct s_arq_no NO_AVL;



void withMessage(int code, ...) {

    va_list ap;
    va_start(ap, code);

    int vals[10];
    for (size_t i = 0; i < 10; i++) {
        vals[i] = va_arg(ap, int);
    }


    switch (code) {
        case 1:
            perror("Ops, não pode inserir chaves repetidos em uma AVL\n");
            break;

        case 2:
            perror("Valor de balanço errado, aconteceu algum problema!\n");
            break;

        case 3:
            perror("Erro em alocação de memoria\n");
            break;

        case 4:
            printf("\nChave %d encontrada", vals[0]);
            break;

        case 5:
            perror("Referencia nula de ponteiro na abertura de arquio - função: [gravarArquivo]\n");
            break;
        default:
            break;
    }
    va_end(ap);


}

    void caso1(AVL **rz, int32_t *h)
    {
        AVL *ptu;
        AVL *ptv;

        ptu = (*rz)->esq;

        if(ptu->bal == -1)
        {
            (*rz)->esq = ptu->dir;
            ptu->dir = *rz;
            (*rz)->bal = 0;
            *rz = ptu;
        }
        else
        {
            ptv = ptu->dir;

            ptu->dir = ptv->esq;
            ptv->esq = ptu;
            (*rz)->esq = ptv->dir;
            ptv->dir = *rz;

            if(ptv->bal == -1)
                (*rz)->bal = 1;
            else
                (*rz)->bal = 0;

            if(ptv->bal == 1)
                ptu->bal = -1;
            else
                ptu->bal = 0;

            *rz = ptv;
        }

        (*rz)->bal = 0;
        *h = 0;
    }

/*-----------------------------------------------------------------------------
OBJETIVO: 	FAZER UMA ROTAÇÃO ESQUERDA OU DUPLA ESQUERDA
PARAMETROS:	rz - RAIZ DA ÁRVORE
			h - VALIDADOR
------------------------------------------------------------------------------*/
void caso2 (AVL **rz, int32_t *h)
{
    AVL *ptu = (*rz)->dir;
    AVL *ptv = ptu->esq;

    if(ptu->bal == 1)
    {
        (*rz)->dir = ptu->esq;
        ptu->esq = *rz;
        (*rz)->bal = 0;
        *rz = ptu;
    }
    else
    {
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*rz)->dir = ptv->esq;
        ptv->esq = *rz;

        if(ptv->bal == 1)
            (*rz)->bal = -1;
        else
            (*rz)->bal = 0;

        if(ptv->bal == -1)
            ptu->bal = 1;
        else
            ptu->bal = 0;

        *rz = ptv;
    }
    (*rz)->bal = 0;
    *h = 0;
}

/*-----------------------------------------------------------------------------
OBJETIVO: 	INSERIR UM NÓ NA ÁRVORE(SÃO TODAS DIFERENTES)
PARAMETROS:	rz - RAIZ DA ÁRVORE
			x - NUMERO A SER INSERIDO
------------------------------------------------------------------------------*/
void insere(AVL **rz, int32_t x, int32_t *h)
{

    if(*rz == NULL)
    {

        assert(((*rz) = malloc(sizeof(AVL))) != NULL);
        (*rz)->chave = x;
        (*rz)->esq = NULL;
        (*rz)->dir = NULL;
        (*rz)->bal = 0;
        *h = 1;
    }
    else
    {
        if(x == (*rz)->chave)
        {
            printf("CHAVE JA ESTA CONTIDA!!\n");
            *h = 0;
        }
        else
        {
            if (x < (*rz)->chave)
            {
                insere(&(*rz)->esq, x, h);
                if(*h == 1)
                {
                    switch((*rz)->bal)
                    {
                        case 1:
                            (*rz)->bal = 0;
                            *h = 0;
                            break;

                        case 0:
                            (*rz)->bal = -1;
                            break;

                        case -1:
                            caso1(rz,h);
                            break;
                    }
                }
            }
            else
            {
                insere(&((*rz)->dir), x, h);
                if(*h == 1)
                {
                    switch((*rz)->bal)
                    {
                        case 1:
                            caso2(rz,h);
                            break;

                        case 0:
                            (*rz)->bal = 1;
                            break;

                        case -1:
                            (*rz)->bal = 0;
                            *h = 0;
                            break;
                    }
                }
            }
        }

    }
}



    //int busca(AVL *root, const int32_t x) {
//
//    if(root == NULL) /* Valor não foi encontrado */
//        return 0;
//
//    if(x == root->chave)
//        return 1;
//
//    if(x < root->chave) { /* Valor possivelmente está na subarvore esqueda do nó */
//        if(root->esq != NULL)  /* Se tem esquerda, avança a pesquisa recursiamente */
//            busca(root->esq, x);
//
//        else
//            if(root->dir != NULL)  /* Se tem direita, avança a pesquisa recursiamente */
//                busca(root->dir, x);
//    }
//
//}





//
//void gravar_arquio(AVL *root) {
//
//    if(root == NULL)
//        return;
//
//    const char nomeArquivo = "arquivo_avl.bin";
//
//    FILE *arq = open(nomeArquivo, "wb");
//    if(arq == NULL) {
//        withMessage(5);
//        exit(-1);
//    }
//
//    printf("%d ", root->chave);
//    fwrite(root->chave, 1, sizeof(NO_AVL), arq);
//
//    gravar_arquio(root->esq);
//    gravar_arquio(root->dir);
//    fclose(arq);
//}

//}
