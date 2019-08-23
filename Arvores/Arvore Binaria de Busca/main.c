#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    unsigned int key;
    struct Tree *left;
    struct Tree *right;
}TREE;

/* search structure and return flag to indicate search result  */
TREE *search(unsigned int x, TREE *pt, int *f) {

    if(pt == NULL)  { /* tree empty */
        *f = 0;
        return NULL;
    }

    if(x == (pt)->key) { /* value is already in the tree */
        *f = 1;
        return NULL;
    }

    if(x < pt->key) {

        if((pt)->left == NULL) { /* no pointer to left */
            *f = 2;
            return pt;
        }

        return search(x, pt->left, f); /* next pointer */
    }

    else {

        if((pt)->right == NULL) { /* no pointer to right */
            *f = 3;
            return pt;
        }

        return search(x, pt->right, f); /* next pointer */
    }

}

/* allocate new node to tree */
TREE *allocateNode(int value) {

    TREE *newNode = (TREE*) malloc(sizeof(TREE));
    newNode->right = NULL;
    newNode->left  = NULL;
    newNode->key = value;

    return newNode;
}

/* with larger tree element, returns node pointer and pointer returns by reference child subtree value*/
TREE *biggestRight(TREE **rootPointer) {

    if((*rootPointer)->right != NULL)
        return biggestRight(&(*rootPointer)->right);

    else {
        TREE *aux = *rootPointer;

        if((*rootPointer)->left != NULL)
            *rootPointer = (*rootPointer)->left;
        else
            *rootPointer = NULL;

        return aux;
    }
}

/* remove a node from the tree */
void delete(TREE **rootPointer, TREE **father, int key) {

    /* tree empty */
    if(*rootPointer == NULL) {
        puts("Tree is already null\n");
        return;
    }


    if((*rootPointer)->left == NULL && (*rootPointer)->right == NULL && key == (*rootPointer)->key) {
        *rootPointer = NULL;
        free(*rootPointer);
        return;
    }

    if(key < (*rootPointer)->key)
        *father = *rootPointer, delete(&(*rootPointer)->left, father, key);

    if(key > (*rootPointer)->key)
        *father = *rootPointer, delete(&(*rootPointer)->right, father, key);

    if((*rootPointer)->key == key) {

        /*only son right */
        if ((*rootPointer)->right == NULL) {
            TREE *aux = *rootPointer;
            (*father)->right = (*rootPointer)->left;
            free(aux);
            return;
        }

        /*only son left */
        if ((*rootPointer)->left == NULL) {
            TREE *aux = *rootPointer;
            (*father)->left = (*rootPointer)->right;
            free(aux);
            return;
        }

        /* two sons - left and right */
        TREE *aux = NULL;
        aux = biggestRight(&(*rootPointer)->left);
        aux->left = (*rootPointer)->left;
        aux->right = (*rootPointer)->right;
        (*rootPointer)->left = (*rootPointer)->right = NULL;
        free((*rootPointer));
        *rootPointer = aux;
    }

}

/* insert an element into the tree */
void insertion(TREE **RootPointer, int value) {

    int insertionFlag;
    TREE *pt = search(value, *RootPointer, &insertionFlag);

    if(insertionFlag == 1) {
        puts("Ops, invalid insertion!! element is already in the struct \n\n");
        return;
    }

    TREE *newNode = allocateNode(value);

    if (insertionFlag == 0)
        *RootPointer = newNode;

    else {

        if(insertionFlag == 2)
            pt->left = newNode;
        else
            pt->right = newNode;
    }
}

/* print tree in order */
void inOrder(TREE *pt) {
    if(pt->left != NULL) inOrder(pt->left);
    printf("%d ", pt->key);
    if(pt->right != NULL) inOrder(pt->right);
}

/* print tree in pré order */
void preOrder(TREE *pt) {
    printf("%d ", pt->key);
    if(pt->left != NULL) preOrder(pt->left);
    if(pt->right != NULL) preOrder(pt->right);
}

/* print tree in symmetrical order */
void posOrder(TREE *pt) {
    if(pt->left != NULL) posOrder(pt->left);
    if(pt->right != NULL) posOrder(pt->right);
    printf("%d ", pt->key);
}

int main(void) {
    TREE *tree = NULL;

    /* insertion in binary tree */
    insertion(&tree, 7);
    insertion(&tree, 6);
    insertion(&tree, 25);
    insertion(&tree, 100);
    insertion(&tree, 11);
    insertion(&tree, 13);

    /* show tree */
    printf("In Order: ");
    inOrder(tree);

    /* delete tree node */
    TREE *father = NULL;
    delete(&tree, &father,7);

    printf("\nAfter exclusion: ");
    inOrder(tree);

}