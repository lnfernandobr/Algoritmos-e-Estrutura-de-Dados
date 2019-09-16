#include <stdio.h>
#include "avl.h"



int main(void) {
    AVL *ptRaiz = NULL;
    int state = 0;

    insere(&ptRaiz,-112,  &state);
    insere( &ptRaiz,3, &state);
    insere(&ptRaiz,-381,  &state);
    insere(&ptRaiz,225,  &state);
    insere(&ptRaiz,-76,  &state);
    insere( &ptRaiz, -399,&state);
    insere(&ptRaiz,-475,  &state);
    insere( &ptRaiz,907, &state);
    insere(&ptRaiz,32,  &state);
    insere(&ptRaiz,-93,  &state);
    insere(&ptRaiz,-492,  &state);
    insere(&ptRaiz,-373,  &state);
    insere( &ptRaiz,-314, &state);
    insere(&ptRaiz,-222,  &state);
    insere(&ptRaiz,378,  &state);
    insere(&ptRaiz,136,  &state);

//    int res = busca(ptRaiz, 20);
//
//    if(res) {
//        puts("apagou");
//    } else puts("não apagou");

//    insere(1, &ptRaiz, &state);
//    insere(30, &ptRaiz, &state);
//    insere(40, &ptRaiz, &state);
//    insere(50, &ptRaiz, &state);
//    insere(25, &ptRaiz, &state);



    printf("Sucesso ?");
}

