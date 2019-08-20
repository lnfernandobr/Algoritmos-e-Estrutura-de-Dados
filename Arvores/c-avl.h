#include <stdint.h>
#include <stdlib.h>
//int max(int a, int b) {
//    return (a > b)? a : b;
//}
//int altura(AVL *N) {
//    return N == NULL ? 0 : N->bal;
//}
//int getBalance(AVL *N){
//    if (N == NULL)
//        return 0;
//
//    return altura(N->esq) - altura(N->dir);
//}

//AVL* insere (AVL *ptRaiz, int32_t valor) {

//
//    /* 1.  Se o ptRaiz for nulo, criamos e retornamos o novo nó */
//    if (ptRaiz == NULL)
//        return(criaNo(valor));
//
//    if (valor < ptRaiz->chave)
//        ptRaiz->esq = insere(ptRaiz->esq, valor);
//
//    else {
//
//        if(valor > ptRaiz->chave)
//            ptRaiz->dir = insere(ptRaiz->dir, valor);
//
//        else // Chaves iguais não são permitidas, retorne...
//            return ptRaiz;
//    }
//
//
//    /* 2. Atualiza a altura do nó ancestral */
//    ptRaiz->bal = 1 + max(altura(ptRaiz->esq), altura(ptRaiz->dir));
//
//    /* 3. Get the balance factor of this ancestor
//          node to check whether this node became
//          unbalanced */
//    int balance = getBalance(ptRaiz);
//
//    // If this node becomes unbalanced, then
//    // there are 4 cases
//
//    // Left Left Case
//    if (balance > 1 &&
//
//
//
//
//
//        return rightRotate(node);
//
//    // Right Right Case
//    if (balance < -1 && key > node->right->key)
//        return leftRotate(node);
//
//    // Left Right Case
//    if (balance > 1 && key > node->left->key)
//    {
//        node->left =  leftRotate(node->left);
//        return rightRotate(node);
//    }
//
//    // Right Left Case
//    if (balance < -1 && key < node->right->key)
//    {
//        node->right = rightRotate(node->right);
//        return leftRotate(node);
//    }
//
//    /* return the (unchanged) node pointer */
//    return node;
//
//}

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
    no->chave   = valor;
    no->esq   = NULL;
    no->dir  = NULL;
    no->bal = 0;

    return no;
}

void caso1(AVL** pt, Bool h) {

    AVL *ptu = (*pt)->esq;

    if(ptu->bal == -1) {
        (*pt)->esq = ptu->dir;
        (*pt)->dir = *pt;
        (*pt)->bal = 0;
        (*pt) = ptu;

    } else {
        AVL *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = *pt;

        (*pt)->esq = ptv->dir;
        ptv->dir = *pt;
        (*pt)->bal  = ptv->bal == -1 ?  1 : 0;
        ptu->bal  = ptv->bal == 1 ?  -1 : 0;
        *pt = ptv;

    };

    (*pt)->bal = 0;
    h = false;
}

void caso2(AVL** pt, Bool h) {

}

AVL* insere (int32_t valor, AVL* pt, Bool h) {

    if(pt == NULL) {
        criaNo(pt);
        h = true;
    }

    else {
        if(valor == pt->chave) {
            puts("Ops, não pode inserir chaves repetidos em uma AVL\n");
            return NULL;
        }

        if(valor < pt->chave) {
            insere(valor,pt->esq, h);

            if(h == true) {
                switch (pt->bal) {
                    case 1:
                        pt->bal = 0, h = false;
                        break;

                    case 0:
                        pt->bal = -1;
                        break;

                    case -1:
                        caso1(&pt, h);
                        break;

                    default:
                        puts("Valor de balanço errado, aconteceu algum problema!\n");
                        return NULL;
                }
            }

        }

        else {
            insere(valor, pt->dir, h);

            if(h == true) {
                switch (pt->bal) {
                    case -1:
                        pt->bal = 0, h = false;
                        break;

                    case 0:
                        pt->bal = 1;
                        break;

                    case 1:
                        caso2(&pt, h);
                        break;

                    default:
                        puts("Valor de balanço errado, aconteceu algum problema!\n");
                        return NULL;
                }
            }
        }
    }
}
