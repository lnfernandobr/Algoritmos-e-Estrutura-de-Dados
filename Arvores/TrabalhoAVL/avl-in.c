#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>



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



void withMessage(int code, ...)  
{

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
    va_end(ap) ;

}



AVL* criaNo(int32_t valor) {

    AVL* no = (AVL*) malloc(sizeof(AVL));
    
    if(no == NULL) {
        withMessage(3);
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

        if(valor == (*pt)->chave) 
            withMessage(1); return;

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
                        withMessage(2);
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
                        withMessage(2);
                        return;
                }
            }
        }
    }
}

void caso1R(AVL **rz, int* h)
{
	AVL *ptu;
	AVL *ptv;

	ptu = (*rz)->esq;

	if(ptu->bal == 0 || ptu->bal == -1)
	{
		(*rz)->esq = ptu->dir;
		ptu->dir = *rz;
		if(ptu->bal == 0){
			(*rz)->bal = -1;
            *h = 0;
        }
		else{
			(*rz)->bal = 0;
            *h = 1;
        }

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
        *h = 0;
	}
}

int busca(AVL *root, const int32_t x) {

    if(root == NULL) /* Valor não foi encontrado */
        return 0;
    
    if(x == root->chave)
        return 1;

    if(x < root->chave)  /* Valor possivelmente está na subarvore esqueda do nó */
        if(root->esq != NULL)  /* Se tem esquerda, avança a pesquisa recursiamente */
            busca(root->esq, x); 

    else 
        if(root->dir != NULL)  /* Se tem direita, avança a pesquisa recursiamente */
            busca(root->dir, x); 
}


void gravar_arquio(AVL *root) {

    if(root == NULL) 
        return; 

    const char nomeArquivo = "arquivo_avl.bin";

    FILE *arq = open(nomeArquivo, "wb");
    if(arq == NULL) {
        withMessage(5);
        exit(-1);
    }
    
    printf("%d ", root->chave);   
    fwrite(root->chave, 1, sizeof(NO_AVL), arq);

    gravar_arquio(root->esq);   
    gravar_arquio(root->dir); 
    fclose(arq);
}
