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
    printf("3 - Buscar\n");
    printf("4 - Sair\n");
    printf("##########################\n");
    
    printf(">>"), scanf("%hu", &option);

    return option;
}



void showMessage(int id) {

    switch (id) {

        case 1:
            puts("Número de argumentos invalidos\n");
            exit(-1);
            break;

        case 2:
            puts("Bye\n");
            break;

        case 3:
            puts("O valor procurado não se encontra na arvore.\n");
            break;

        default:
            break;
    }
}




int main(void) 
{



    struct page *root = NULL;

    root = B_THREE_newNode(7, 4);
    root->keys[1] = 16;
    root->isLeaf = 0;
    root->m++;

    root->p[0] = B_THREE_newNode(1, 4);
    root->p[0]->keys[1] = 2;
    root->p[0]->keys[2] = 5;
    root->p[0]->keys[3] = 6;
    root->p[0]->m++;
    root->p[0]->m++;
    root->p[0]->m++;
    root->p[0]->isLeaf = 1;

    root->p[1] = B_THREE_newNode(9, 4);
    root->p[1]->keys[1] = 12;
    root->p[1]->m++;
    root->p[1]->isLeaf = 1;

    root->p[2] = B_THREE_newNode(18, 4);
    root->p[2]->keys[1] = 21;
    root->p[2]->m++;
    root->p[2]->isLeaf = 1;

    unsigned short option, position;
    int key;
    struct page *pt;



    while (true) {

        option = menu();

        switch (option) {

        case 1:
            break;
        
        case 2:
            break;

        case 3:

            system("clear || cls");
            puts("Digite o valor que deseja procurar: \n");
            printf(">> "), scanf("%d", &key);

            pt = B_THREE_search(root, key, &position);

            if(!pt) {
                showMessage(3);
            } else printf("\nO valor %d foi encontrado na pagina no posição %d\n\n\n", key, position);

            break;

        case 4:
            showMessage(2);
            exit(0);

        default:
            exit(0);

        }
    }

}
