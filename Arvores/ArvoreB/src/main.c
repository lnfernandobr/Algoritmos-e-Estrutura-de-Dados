#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "gfx.h"
#include "bTree.h"

enum boolean {
    true = 1, false = 0
};


unsigned short menu(void) {

    unsigned short option;

    printf("########## MENU ##########\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Atualizar\n");
    printf("4 - Sair\n");
    printf("##########################\n");
    
    printf(">>"), scanf("%hu", &option);

    return option;
}



void showMessage(int id) {
    switch (id) {

    case 1:
        printf("Número de argumentos invalidos\n");
        exit(-1);
        break;

    case 2:
        printf("Bye\n");
        break;
    
    default:
        break;
    }
}




int main(void) 
{

    struct page *root = NULL;

    root = NewBTreeNode(7, 4);
    root->keys[1] = 16;
    root->m++;

    root->p[0] = NewBTreeNode(1, 4);
    root->p[0]->keys[1] = 2;
    root->p[0]->keys[2] = 5;
    root->p[0]->keys[3] = 6;
    root->p[0]->m++;
    root->p[0]->m++;
    root->p[0]->m++;

    root->p[1] = NewBTreeNode(9, 4);
    root->p[1]->keys[1] = 12;
    root->p[1]->m++;


    root->p[2] = NewBTreeNode(18, 4);
    root->p[2]->keys[1] = 21;
    root->p[2]->m++;


    unsigned short option;



    while (true) {

        option = menu();

        switch (option) {

        case 1:
            insert();
            break;
        
        case 2:
            delete();
            break;

        case 3: 
            search(root);
            break;

        case 4:
            showMessage(2);
            exit(0);

        default:
            exit(0);

        }
    }

}
