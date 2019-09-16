#include <stdint.h>
#include <stdlib.h>


typedef unsigned int Bool;
int true = 1;
int false = 0;

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


AVL* criaNo(int32_t valor) {

    AVL* no = (AVL*) malloc(sizeof(AVL));
    if(no == NULL) {
        puts("Erro em alocação de memoria\n");
        exit(-1);
    }

    no->chave   = valor;
    no->esq   = NULL;
    no->dir  = NULL;
    no->bal = 0;

    return no;
}
void caso1(AVL** pt, Bool *h) {

    AVL *ptu = (*pt)->esq;

    if(ptu->bal == -1) {
        (*pt)->esq = ptu->dir;
        (*pt)->dir = *pt;
        (*pt)->bal = 0;
        (*pt) = ptu;

    }

    else {

        AVL *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;

        (*pt)->esq = ptv->dir;
        ptv->dir = *pt;

        (*pt)->bal  = ptv->bal == -1 ?  1 : 0;
        ptu->bal  = ptv->bal == 1 ?  -1 : 0;

        *pt = ptv;

    };

    (*pt)->bal = 0;
    *h = false;
}
void caso2(AVL **pt, Bool *h) {

    AVL *ptu = (*pt)->dir;

    if(ptu->bal == 1) {
        (*pt)->dir = ptu->esq;
        ptu->esq = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    }

    else {
        AVL *ptv = (*pt)->esq;
        ptu->esq = ptv->dir;
        ptv->dir  = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = *pt;
        (*pt)->bal = ptv->bal == 1 ? -1: 0;
        ptu->bal = ptv->bal == -1 ? 1: 0;
        *pt = ptv;

    }

    (*pt)->bal = 0;
    *h = 0;
}

void insere (int32_t valor, AVL **pt, Bool *h) {

    if(*pt == NULL) {
        *pt = criaNo(valor);
        *h = 1;
    }

    else {
        if(valor == (*pt)->chave) {
            puts("Ops, não pode inserir chaves repetidos em uma AVL\n");
            return;
        }

        if(valor < (*pt)->chave) {
            insere(valor,&((*pt)->esq), h);

            if(*h == true) {
                switch ((*pt)->bal) {
                    case 1:
                        (*pt)->bal = 0, *h = false;
                        break;

                    case 0:
                        (*pt)->bal = -1;
                        break;

                    case -1:
                        caso1(&(*pt), h);
                        break;

                    default:
                        puts("Valor de balanço errado, aconteceu algum problema!\n");
                        return;
                }
            }

        }

        else {
            insere(valor, &((*pt)->dir), h);

            if(*h == true) {
                switch ((*pt)->bal) {
                    case -1:
                        (*pt)->bal = 0, *h = false;
                        break;

                    case 0:
                        (*pt)->bal = 1;
                        break;

                    case 1:
                        caso2(&(*pt), h);
                        break;

                    default:
                        puts("Valor de balanço errado, aconteceu algum problema!\n");
                        return ;
                }
            }
        }
    }
}

