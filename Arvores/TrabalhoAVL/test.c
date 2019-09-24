void caso1remocao(AVL **pt, char *h){

    AVL *ptu;
    AVL *ptv;

    ptu = (*pt)->esq;

    //Simples direita
    if(ptu->bal < 1)
    {
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);

        if(ptu->bal == 0){
            ptu->bal = 1;
            *h = 'f';
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

void caso2remocao(AVL **pt, char *h){
    AVL *ptu = (*pt)->dir;
    AVL *ptv;

    //Rotação simples esquerda
    if(ptu->bal > -1)
    {
        (*pt)->dir = ptu->esq;
        ptu->esq = (*pt);

        if(ptu->bal == 0)
            ptu->bal = -1;
            *h = 'f';
        else
            ptu->bal = 0;

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

        if (ptv->bal == 1)
            (*pt)->bal = -1;
        else
            (*pt)->bal = 0;


        if (ptv->bal == -1)
            ptu->bal = 1;
        else
            ptu->bal = 0;

        (*pt) = ptv;
        ptv->bal = 0;
    }
}

void sucessor(AVL **pt, AVL **suc, char *h){

    if ((*suc)->esq == NULL)
    {
        (*pt)->chave = (*suc)->chave;
        *pt = *suc;
        *suc = (*suc)->dir;
        *h = 't';
    }
    else {
        sucessor(pt, &(*suc)->esq, h);

        if (*h == 't')
        {
            switch((*suc)->bal)
            {
                case -1:
                    (*suc)->bal = 0;
                    break;

                case 0:
                    (*suc)->bal = 1;
                    *h = 'f';
                    break;

                case 1:
                    caso2remocao(suc, h);
                    break;
            }
        }
    }
}

void removeNode(AVL **pt, int32_t x, char *h){
    AVL *suc = NULL;

    if((*pt) == NULL)
    {
        printf("Chave nao existe!!!!!\n");
    }
    else
    {
        if(x == (*pt)->chave)
        {
            suc = *pt;
            if((*pt)->esq != NULL && (*pt)->dir != NULL) {
                sucessor(&suc, &suc->dir, h);

                if (*h == 't') {
                    switch ((*pt)->bal) {
                        case 1:
                            (*pt)->bal = 0;
                            break;

                        case 0:
                            (*pt)->bal = -1;
                            *h = 'f';
                            break;

                        case -1:
                            caso1remocao(pt, h);
                            break;
                    }
                }
            }
            else {
                if(suc->esq == NULL)
                {
                    *pt = suc->dir;
                    *h = 't';
                }
                else {
                    *pt = suc->esq;
                    *h = 't';
                }
            }
            free(suc);
        }
        else {
            //Se valor estiver a esquerda
            if (x < (*pt)->chave) {
                removeNode(&((*pt)->esq), x, h);
                if (*h == 't') {
                    switch ((*pt)->bal) {
                        case 1:
                            caso2remocao(pt, h);
                            break;

                        case 0:
                            (*pt)->bal = 1;
                            *h = 'f';
                            break;

                        case -1:
                            (*pt)->bal = 0;
                            break;
                    }
                }
            }
                //Se valor estiver a direita
            else {
                removeNode(&((*pt)->dir), x, h);
                if (*h == 't') {
                    switch ((*pt)->bal) {
                        case 1:
                            (*pt)->bal = 0;
                            break;

                        case 0:
                            (*pt)->bal = -1;
                            *h = 'f';
                            break;

                        case -1:
                            caso1remocao(pt, h);
                            break;
                    }
                }
            }
        }
    }
}