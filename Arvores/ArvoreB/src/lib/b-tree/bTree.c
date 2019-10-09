#include "bTree.h"


void delete(void) {
    return;
}

struct page* search(struct page *root, int value, int *pos) {

    if(root == NULL)
        return NULL;

    unsigned short m = root->m, count  = 0;

    while (count < m) {


        if(value == root->keys[count]) {
            printf("VALOR ENCONTRNADO");
            *pos= count;
            return root;
        }

        if(value < root->keys[count]) {

            root = root->p[count]; // troca pagina, chaves menores
            if(root == NULL)
                return NULL;

            count = 0;
            m = root->m;

        }

        if(value > root->keys[count] && count + 1 < m) {
            count++;
        } else {
            if(count + 1 < m) {
                root = root->p[count + 1];// troca pagina, chaves maiores
                count = 0;
                m = root->m;
            } else return NULL;
        }

    }


    return NULL;
}

//void insert(struct page **root, int k, int tamanho_maximo) {
//
//    search();
//
//    if(*root == NULL) {
//        root = NewBTreeNode();
//        root->keys[0] = k;
//        root->m = 1;
//    }
//
//    else {
//
//        if(root->m == 2 * tamanho_maximo - 1) {
//            // tem coisa pra fazer
//
//
//
//        } else
//            insertNonFull(*root, k);
//    }
//
//}


struct page* NewBTreeNode(int value, int t) {

    struct page *newNode  = (struct page*) malloc(sizeof(struct page));

    newNode->keys =  (int *) malloc(t * sizeof(int));
    newNode->p =  (struct page**) malloc((t + 1) * sizeof(struct page));

    for (int i = 0; i < t; ++i) {
        newNode->p[i] = NULL;
        newNode->keys[i] = 0;
    }

    newNode->keys[0] = value;
    newNode->m = 1;

    return newNode;
}


static void deallocate(void) {
    return;
}
