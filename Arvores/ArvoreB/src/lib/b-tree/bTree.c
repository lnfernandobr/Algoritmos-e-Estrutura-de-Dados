#include "bTree.h"

struct page* B_THREE_newNode(int value, unsigned short t) {

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


struct page* B_THREE_search(struct page *pt, const int value, unsigned short *position) {

    unsigned short i = 0;

    while (i < pt->m && value > pt->keys[i])
        i++;

    if(i <= pt->m && value == pt->keys[i]) { // find key
        *position = i;
        return pt;
    }

    else if(pt->isLeaf) // if page is leaf return null
        return NULL;

    return B_THREE_search(pt->p[i], value, position);
}

