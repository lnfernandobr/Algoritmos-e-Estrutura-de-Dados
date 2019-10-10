/*

Fernando Lima - 19/09/2019

*/

#include <stdio.h>
#include <stdlib.h>

#ifndef _TREE_B_H
#define _TREE_B_H

struct page {
    int isLeaf;
    unsigned short m; // page length
    int *keys;        // page keys
    struct page **p;   // page pointers
};

/* Dynamically allocate a new page to the tree, you must know the tree order beforehand */
struct page* B_THREE_newNode(int value, unsigned short t);
struct page* B_THREE_search(struct page *pt, const int value, unsigned short *position);


#endif
