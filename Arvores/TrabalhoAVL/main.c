#include <stdio.h>
#include "avl.h"



int main(void) {
    AVL *ptRaiz = NULL;
    Bool state = 0;

    insere(10, &ptRaiz, &state);
    insere(20, &ptRaiz, &state);
    insere(30, &ptRaiz, &state);
    insere(40, &ptRaiz, &state);
    insere(50, &ptRaiz, &state);
    insere(25, &ptRaiz, &state);



    printf("Sucesso ?");
}

