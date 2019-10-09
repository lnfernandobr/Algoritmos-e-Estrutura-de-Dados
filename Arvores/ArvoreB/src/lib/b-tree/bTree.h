/*

Fernando Lima - 19/09/2019

*/

#ifndef _TREE_B_H
#define _TREE_B_H

struct page {
     unsigned short m; // page length
     int *keys;        // page keys
     struct page **p;   // page pointes
 };


void delete(void);
struct page* search(struct page *root, int value, int *pos);

void insert(void);
static void deallocate(void);
struct page* NewBTreeNode(int tamanho_maximo);


#endif
