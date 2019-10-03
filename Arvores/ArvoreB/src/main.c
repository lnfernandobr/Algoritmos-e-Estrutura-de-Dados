#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "gfx.h"
#include "bTree.h"

enum boolean {
    true = 1, false = 0
};

int menu(void) {

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
            search();
            break;

        case 4:
            showMessage(2);
            exit(0);

        default:
            break;

        }
    }

    return 0;
}
