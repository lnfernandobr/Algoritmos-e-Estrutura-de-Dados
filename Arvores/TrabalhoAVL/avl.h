
const int true = 1;
const int false = 0;

typedef struct s_no {
    int32_t chave:28;
    int32_t bal:2;
    int32_t reservado:2; /* sem uso */
    struct s_no* esq;
    struct s_no* dir;
}AVL;

typedef struct s_arq_no {
    int32_t chave:28;
    int32_t bal:2;
    uint32_t esq:1;
    uint32_t dir:1;
}AVL_FILE;

/* Bloco de código faz a inserção de um elemento na arvore, se preciso rotaciona para manter a arvore
 * balanceada. */
void alocaNo(AVL **pt,int32_t x) {

    (*pt) = malloc(sizeof(AVL));

    if( (*pt) != NULL) {
        (*pt)->esq = NULL;
        (*pt)->dir = NULL;
        (*pt)->chave = x;
        (*pt)->bal = 0;
    }
}
void caso1(AVL **arv, char *h) {

    AVL *ptu, *ptv;

    ptu = (*arv)->esq;

    if(ptu->bal == -1) {
        (*arv)->esq = ptu->dir;
        ptu->dir = (*arv);
        (*arv)->bal = 0;
        (*arv) = ptu;
    }

    else {
        ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*arv)->esq = ptv->dir;
        ptv->dir = (*arv);

        if(ptv->bal == -1)
            (*arv)->bal=1;
        else
            (*arv)->bal=0;

        if(ptv->bal==1)
            ptu->bal=-1;
        else
            ptu->bal=0;

        (*arv) = ptv;
    }

    (*arv)->bal = 0;
    *h = 'f';
}
void caso2(AVL **arv, char *h) {

    AVL *ptu, *ptv;

    ptu = (*arv)->dir;
    if(ptu->bal == 1) {
        (*arv)->dir = ptu->esq;
        ptu->esq = (*arv);
        (*arv)->bal = 0;
        (*arv) = ptu;
    }

    else {
        ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*arv)->dir = ptv->esq;
        ptv->esq = (*arv);

        if(ptv->bal==1)
            (*arv)->bal=-1;
        else
            (*arv)->bal=0;

        if(ptv->bal==-1)
            ptu->bal=1;
        else
            ptu->bal=0;

        (*arv) = ptv;
    }

    (*arv)->bal = 0;
    *h = 'f';
}
void insere(AVL **pt,int32_t x,char *h) {

    if((*pt) == NULL) {
        alocaNo(&(*pt), x);
        *h = 'v';
    }

    else {

        if(x == (*pt)->chave) {
            printf("\nElemento ja inserido");
            *h = 'f';
        } else {

            if(x < (*pt)->chave) {
                insere(&(*pt)->esq, x, h);

                if(*h == 'v') {
                    if((*pt)->bal == 1) {
                        (*pt)->bal = 0;
                        *h = 'f';
                    } else {

                        if((*pt)->bal == 0) {
                            (*pt)->bal = -1;
                        }
                        else {
                            if((*pt)->bal == -1) {
                                caso1(&(*pt), h);
                            }
                        }
                    }
                }

            } else {

                if(x > (*pt)->chave) {

                    insere(&(*pt)->dir, x, h);

                    if(*h == 'v') {

                        if((*pt)->bal == -1) {
                            (*pt)->bal = 0;
                            *h = 'f';
                        } else {
                            if((*pt)->bal==0) {
                                (*pt)->bal=1;
                            }
                            else {

                                if((*pt)->bal == 1) {
                                    caso2(&(*pt), h);
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}


/* Bloco de código faz a remoçao de um elemento na arvore, se preciso rotaciona para manter a arvore
 * balanceada. */
void caso1remocao(AVL **pt, int *h){

    AVL *ptu;
    AVL *ptv;

    ptu = (*pt)->esq;

    //Simples direita
    if(ptu->bal < 1) {
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);

        if(ptu->bal == 0){
            ptu->bal = 1;
            *h = false;
        }
        else{
            ptu->bal = 0;
        }
        (*pt) = ptu;
    }
        //Dupla direita
    else {
        ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*pt)->esq = ptv->dir;
        ptv->dir = (*pt);

        if(ptv->bal == -1) {
            (*pt)->bal = 1;
        }
        else {
            (*pt)->bal = 0;
        }

        if(ptv->bal == 1) {
            ptu->bal = -1;
        }
        else {
            ptu->bal = 0;
        }

        (*pt) = ptv;
        ptv->bal = 0;
    }
}
void caso2remocao(AVL **pt, int *h){
    AVL *ptu = (*pt)->dir;
    AVL *ptv;

    //Rotação simples esquerda
    if(ptu->bal > -1)
    {
        (*pt)->dir = ptu->esq;
        ptu->esq = (*pt);

        if(ptu->bal == 0){
            ptu->bal = -1;
            *h = false;
        }
        else {
            ptu->bal = 0;
        }
        (*pt)->bal = 0;
        (*pt) = ptu;
    }
        //Rotação dupla esquerda
    else {
        ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = (*pt);

        if (ptv->bal == 1) {
            (*pt)->bal = -1;
        }
        else {
            (*pt)->bal = 0;
        }
        if (ptv->bal == -1) {
            ptu->bal = 1;
        }
        else {
            ptu->bal = 0;
        }
        (*pt) = ptv;
        ptv->bal = 0;
    }
}
void sucessor(AVL **pt, AVL **suc, int *h){

    if ((*suc)->esq == NULL) {
        (*pt)->chave = (*suc)->chave;
        *pt = *suc;
        *suc = (*suc)->dir;
        *h = false;
    }

    else {
        sucessor(pt, &(*suc)->esq, h);

        if (*h == true)
        {
            switch((*suc)->bal)
            {
                case -1:
                    (*suc)->bal = 0;
                    break;

                case 0:
                    (*suc)->bal = 1;
                    *h = false;
                    break;

                case 1:
                    caso2remocao(suc, h);
                    break;
            }
        }
    }
}
void remove_elem(AVL **pt, int32_t x, int *h) {
    AVL *suc = NULL;

    if ((*pt) == NULL) {
        printf("Chave nao existe!!!!!\n");
        return;
    }

    if (x == (*pt)->chave) {
        suc = *pt;

        if ((*pt)->esq != NULL && (*pt)->dir != NULL) {

            sucessor(&suc, &suc->dir, h);

            if (*h == true) {
                switch ((*pt)->bal) {
                    case 1:
                        (*pt)->bal = 0;
                        break;

                    case 0:
                        (*pt)->bal = -1;
                        *h = false;
                        break;

                    case -1:
                        caso1remocao(pt, h);
                        break;
                }
            }
        } else {
            if (suc->esq == NULL) {
                *pt = suc->dir;
                *h = true;
            } else {
                *pt = suc->esq;
                *h = true;
            }
        }
        free(suc);
    } else {
        //Se valor estiver a esquerda
        if (x < (*pt)->chave) {
            remove_elem(&((*pt)->esq), x, h);
            if (*h == true) {
                switch ((*pt)->bal) {
                    case 1:
                        caso2remocao(pt, h);
                        break;

                    case 0:
                        (*pt)->bal = 1;
                        *h = false;
                        break;

                    case -1:
                        (*pt)->bal = 0;
                        break;
                }
            }
        }
            //Se valor estiver a direita
        else {
            remove_elem(&((*pt)->dir), x, h);
            if (*h == true) {
                switch ((*pt)->bal) {
                    case 1:
                        (*pt)->bal = 0;
                        break;

                    case 0:
                        (*pt)->bal = -1;
                        *h = false;
                        break;

                    case -1:
                        caso1remocao(pt, h);
                        break;
                }
            }
        }
    }
}



/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
void destruirAux(AVL *subRaiz){
    if (subRaiz){
        destruirAux(subRaiz->esq);
        destruirAux(subRaiz->dir);
        free(subRaiz);
    }
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz    */
void destruirArvore(AVL **raiz){
    destruirAux(*raiz);
    *raiz = NULL;
}

void writeFile(AVL *root, FILE *arquivo) {


    AVL_FILE *file;

    if(root != NULL) {

        file = malloc(sizeof(AVL_FILE));

        if(file == NULL) {
            printf("Sem memória, não foi pissivel alocar.\n");
            return;
        }


        file->chave = root->chave;
        file->bal   = root->bal;
        file->esq   = root->esq != NULL ? 1 : 0;
        file->dir   = root->dir != NULL ? 1 : 0;

        fwrite((void *)file, sizeof(AVL_FILE), 1, arquivo);
        free(file);

        if(root->esq != NULL)
            writeFile(root->esq, arquivo);

        if(root->dir != NULL)
            writeFile(root->dir, arquivo);

    }
}

void readyFile(AVL **pt, int32_t n, FILE *arquivo) {

    if(n == 0)
        return;

    AVL_FILE *file = malloc(sizeof(AVL_FILE));
    if(file == NULL) {
        printf("Sem memória, não foi pissivel alocar.\n");
        return;
    }

    fread(file, sizeof(AVL_FILE),1, arquivo);


    *pt = malloc(sizeof(AVL));
    if(*pt == NULL) {
        printf("Sem memória, não foi possivel alocar.\n");
        return;
    }

    (*pt)->chave = file->chave;
    (*pt)->bal = file->bal;

    if(file->esq == 1)
        readyFile(&(*pt)->esq, n - 1, arquivo);

    if(file->dir == 1)
        readyFile(&(*pt)->dir, n - 1, arquivo);

    free(file);
}

