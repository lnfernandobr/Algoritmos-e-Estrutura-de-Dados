#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdio_ext.h>
#include "functions.h"
#include "linkedlist.h"
#include "circularlinkedlist.h"
#include "stack.h"
#include "queue.h"
#include "doublyLinked.h"
#include "gfx.h"


/// Variaveis com tamanho das listas
int listChainedSize = 0;
int sizeStack = 0;
int sizeQueue = 0;
int chainCircularListSize = 0;
int doubleChainedListSize = 0;

/// Delcaração de ponteiros para as estruturas de dados
nodeLinkedList *ptr_linkedList = NULL, *tmpLinkedList = NULL;
nodeCircular *circularListPointer = NULL, *tmpCircularLinkedList;
nodeQueue *queuePointer = NULL;
nodeStack *stackPointer = NULL, *tmpStack = NULL;
nodeDoublyLinked *doublyLinkedPointer = NULL;


/// Declaração de funções usadas no programa
void drawArrowList(int x, int y);
void drawLamb(int x, int y);
void drawNodeLinkedList(int x, int y, char *msg, int flag);
void drawLinkedList(nodeLinkedList *ptList);
void drawQueue(nodeQueue *ptList);
void drawLambdaStack(int x, int y);
void drawArrowStack(int x, int y);
void drawStackNode(int x, int y, char *msg, int flag);
void drawStack(nodeStack *ptList);
void drawArrowReverse(int x, int y);
void drawNodeDoublyLinked(int x, int y, char *msg, int flag, int flagHead);
void drawDoublyLinked(nodeDoublyLinked *ptList);
void drawCircularArrow(int x, int y);
void drawNodeCircularLinkedList(int x, int y, char *msg, int flag);
void drawCircularLinkedList(nodeCircular *ptList);
char *itoa (int value, char *result, int base);
void deallocate(void);
void stack(int operation);
void queue(int operation);
void doublyLinked(int operation);
int options(void);
int getPosition(int size, char *method);
void messageSearch(int boolean, int value);
void validateInput(int operation);
void circularChainedList(int operation);
void linkedList(int operation);
void dataStructures(int id, int operation);
void messageContinue(void);
void menu(void);
int main(void);


/// Funções para desenhar lista encadeada
void drawArrowList(int x, int y) {

    gfx_set_color(255, 255, 255);              // Desenha com cor branca
    gfx_line(x, y, x + 50, y);                 // Desenha a linha
    gfx_line(x + 50, y - 5, x + 50, y + 5);    // Desenha a base do triangulo (seta)
    gfx_line(x + 50, y - 5, x + 55, y );       // Desenha a segunda linha do triangulo (seta)
    gfx_line(x + 50, y + 5, x + 55, y );       // Desenha a terceira linha do triangulo (seta)

    gfx_paint();
}
void drawLamb(int x, int y) {
    gfx_set_color(255, 255, 255);
    gfx_text(x - 14, y + 20, "&");
    gfx_paint();
}
void drawNodeLinkedList(int x, int y, char *msg, int flag) {

    int x2 = x + 100;
    int y2 = y + 50;

    gfx_set_color(255, 255, 255);  /// Desenha com cor branca
    gfx_rectangle(x, y, x2, y2); /// Desenha o retangulo
    gfx_line(x + 80, y, x + 80, y2); /// Desenha linha separando o ponteiro
    gfx_text(x2 - 70, y + 20, msg); /// Desenha o texto no meio do nó

    flag ? drawLamb(x2, y) : drawArrowList(x2, y + 25);

    gfx_paint();
}
void drawLinkedList(nodeLinkedList *ptList) {
    gfx_clear();

    if(ptList != NULL && listChainedSize > 0) {
        int
                x = 50,
                y = 250;

        nodeLinkedList *tmp = ptList;

        while (tmp != NULL) {
            char snum[5];

            itoa(tmp->value, snum, 10);

            tmp->next == NULL ? drawNodeLinkedList(x, y, snum, 1) : drawNodeLinkedList(x, y, snum, 0);
            x = x + 100 + 50 + 5;
            tmp = tmp->next;
        }
    }
    gfx_paint();

}

/// Funções para desenhar fila
void drawQueue(nodeQueue *ptList) {
    gfx_clear();

    int
        x = 50,
        y = 250;

    if(sizeQueue > 0) {
        nodeQueue *tmp = ptList;
        drawNodeLinkedList(x, y, "HEAD", 0);
        x = x + 100 + 50 + 5;

        tmp = tmp->next;

        while (tmp != NULL) {
            char snum[5];

            itoa(tmp->value, snum, 10);


            tmp->next == NULL ? drawNodeLinkedList(x, y, snum, 1) : drawNodeLinkedList(x, y, snum, 0);
            x = x + 100 + 50 + 5;
            tmp = tmp->next;
        }
    }
    gfx_paint();

}


/// Funçõs para desenhar pilha
void drawLambdaStack(int x, int y) {
    gfx_set_color(255, 255, 255);  /// Desenha com cor branca

    gfx_text(x - 20, y  + 20, "&"); /// Desenha o texto no meio do nó
    gfx_paint();
}
void drawArrowStack(int x, int y) {
    gfx_set_color(255, 255, 255);  /// Desenha com cor branca

    gfx_line(x - 15, y + 35, x - 15 , y + 35 +  20); /// Desenha linha separando o ponteiro

    gfx_line(x - 20, y + 35 + 20, x - 10 , y + 35 + 20); ///
    gfx_line(x - 20, y + 35 + 20, x - 15 , y + 40 + 20); ///
    gfx_line(x - 10, y + 35 + 20, x - 15 , y + 40 + 20); ///

    gfx_paint();
}
void drawStackNode(int x, int y, char *msg, int flag) {

    int x2 = x + 80;
    int y2 = y + 60;

    gfx_set_color(255, 255, 255);  /// Desenha com cor branca

    gfx_rectangle(x, y, x2, y2); /// Desenha o retangulo

    gfx_line(x + 50, y , x + 50, y2); /// Desenha linha separando o ponteiro

    gfx_text(x + 10, y + 20, msg); /// Desenha o texto no meio do nó


    flag ? drawLambdaStack(x2, y) : drawArrowStack(x2, y + 25);

    gfx_paint();
}
void drawStack(nodeStack *ptList) {
    int x = 450, y = 25;

    gfx_clear();

    if(sizeStack > 0) {
        nodeStack *tmp = ptList;
        drawStackNode(x, y, "HEAD", 0);
        y = y + 60 + 20 + 7;
        tmp = tmp->next;

        while (tmp != NULL) {
            char snum[5];
            itoa(tmp->value, snum, 10);
            tmp->next == NULL ? drawStackNode(x, y, snum, 1) : drawStackNode(x, y, snum, 0);
            y = y + 60 + 20 + 7;
            tmp = tmp->next;
        }
    }

    gfx_paint();
}


/// FUnções para desenhar lista duplamente encadeada
void drawArrowReverse(int x, int y) {
    gfx_set_color(255, 255, 255);              // Desenha com cor branca
    gfx_line(x - 50, y, x, y);                 // Desenha a linha

    gfx_line(x - 50, y - 5, x - 50, y + 5);    // Desenha a base do triangulo (seta)
    gfx_line(x - 50, y - 5, x - 55, y );       // Desenha a segunda linha do triangulo (seta)
    gfx_line(x - 50, y + 5, x - 55, y );       // Desenha a terceira linha do triangulo (seta)

    gfx_paint();
}
void drawNodeDoublyLinked(int x, int y, char *msg, int flag, int flagHead) {




    int x2 = x + 100;
    int y2 = y + 50;

    gfx_set_color(255, 255, 255);  /// Desenha com cor branca
    gfx_rectangle(x, y, x2, y2); /// Desenha o retangulo

    gfx_line(x + 80, y, x + 80, y2); /// Desenha linha separando o ponteiro

    gfx_line(x + 20 , y, x + 20, y2); /// Desenha linha separando o ponteiro

    flagHead == 1 ? gfx_text(x2 - 70, y + 20, "HEAD") : gfx_text(x2 - 70, y + 20, msg);



    if(flag == 0) {
        drawArrowList(x2, y + 10 );
        drawArrowReverse(x, y + 40);
    }

    if(flag == -1) {
        drawLamb(x + 20, y);
        drawArrowList(x2, y + 10 );
    }

    if(flag == 1) {
        drawLamb(x2 , y);
        drawArrowReverse(x, y + 40);
    }
    if(flag == 2) {
        drawLamb(x2 , y);
        drawLamb(x + 20  , y);

    }

    gfx_paint();
}
void drawDoublyLinked(nodeDoublyLinked *ptList) {
    gfx_clear();


    int
            x = 50,
            y = 250;

    if(doubleChainedListSize > 0) {
        nodeDoublyLinked *tmp = ptList;

        while (tmp != NULL) {
            char snum[5];

            itoa(tmp->value, snum, 10);

            if(tmp->next != NULL && tmp->prev != NULL) {
                drawNodeDoublyLinked(x, y, snum, 0, 0);
            }

            if(tmp->next != NULL && tmp->prev == NULL) {
                drawNodeDoublyLinked(x, y, snum, -1, 1);
            }

            if(tmp->next == NULL && tmp->prev != NULL) {
                drawNodeDoublyLinked(x, y, snum, 1, 0);
            }

            if(tmp->next == NULL && tmp->prev == NULL) {
                drawNodeDoublyLinked(x, y, snum, 2, 1);

            }


            x = x + 100 + 50 + 5;
            tmp = tmp->next;
        }
    }

}


/// Funções para desenhar lista encadeada circular
void drawCircularArrow(int x, int y) {

    gfx_set_color(155, 251, 235);  /// Desenha com cor branca

    /// Linhas do ponteiro
    gfx_line(x, y + 25, x + 30, y + 25); /// Desenha linha separando o ponteiro
    gfx_line(x + 30, y + 25, x + 30, y + 75); /// Desenha linha separando o ponteiro
    gfx_line(x + 30, y + 75,100, y + 75); /// Desenha linha separando o ponteiro
    gfx_line(100, y + 75, 100, y + 60 ); /// Desenha linha separando o ponteiro

    /// Seta do ponteiro
    gfx_line(100 - 8, y + 60, 100 + 8, y + 60 ); /// Desenha linha separando o ponteiro
    gfx_line(100 - 8, y + 60, 100, y + 60 - 8); /// Desenha linha separando o ponteiro
    gfx_line(100 + 8, y + 60, 100, y + 60 - 8); /// Desenha linha separando o ponteiro

    gfx_paint();
}
void drawNodeCircularLinkedList(int x, int y, char *msg, int flag) {

    int x2 = x + 100;
    int y2 = y + 50;

    gfx_set_color(255, 255, 255);  /// Desenha com cor branca
    gfx_rectangle(x, y, x2, y2); /// Desenha o retangulo
    gfx_line(x + 80, y, x + 80, y2); /// Desenha linha separando o ponteiro
    gfx_text(x2 - 70, y + 20, msg); /// Desenha o texto no meio do nó


    flag ? drawCircularArrow(x2, y) : drawArrowList(x2, y + 25);


    gfx_paint();
}


void drawCircularLinkedList(nodeCircular *ptList) {



    // Função para chamar  as funçõs para desenhar na tela a lista circular encadeada
    gfx_clear();

    if(ptList != NULL && chainCircularListSize > 0) {
        char snum[5];

        int
                x = 50,
                y = 250;

        nodeCircular *tmp = ptList->next;
        itoa(ptList->value, snum, 10); // COnverter valor para

        if(ptList->next == ptList) {
            drawNodeCircularLinkedList(x, y, snum, 1);
        } else {
            drawNodeCircularLinkedList(x, y, snum, 0);
        }

        x += 155;

        while (tmp != ptList) {
            itoa(tmp->value, snum, 10);
            tmp->next == ptList ? drawNodeCircularLinkedList(x, y, snum, 1) : drawNodeCircularLinkedList(x, y, snum, 0);
            x += 155;
            tmp = tmp->next;
        }
    }

    gfx_paint();

}



///  **** CORPO DAS FUNÇÕES USADAS NO PROGRAMA - A EXPLICAÇÃO DE CADA FUNÇÃO SE ENCONTRA NO INICIO DE CADA ****
void queue(int operation) {

    int value;

    validateInput(operation);


    // inicializa a fila caso o ponteiro seja nulo
    if(queuePointer == NULL)
        initQueue(&queuePointer);


    // Faz a busca de um elemento na fila
    if(operation == 1) {
        value = searchOptions(); // Retorna o valor que o usuario ira procurar na fila
        int findValue = search_queue(value, &queuePointer);
        messageSearch(findValue, value);
    }


    // Faz a inserção na fila
    if(operation == 2) {
        int flag = insertQueue(&queuePointer, getValue());

        // se flag vir verdadeira, aumentamos tamanho da fila
        if(flag) {
            sizeQueue++;
            printf("\n\nSeu novo nó foi adicionado! ;)\n\n");
        }
    }


    // Faz a remoção na fila
    if(operation == 3) {
        if(sizeQueue > 0) {
            printf("Operação de Remoção na FILA\n");

            int flag = remove_queue(&queuePointer);
            if(flag) sizeQueue--; /// flag = 1, atualizamos novo tamanho da fila
        } else
            printf("Fila vazia :| \n");
    }

    drawQueue(queuePointer); // desenha fila
    messageContinue();
}
void stack(int operation) {

    int value;
    validateInput(operation);


    /// pilçha vazia, inicializamos ela com a nó cabeça
    if(stackPointer == NULL)
        init(&stackPointer);


    // Operation = 1, fazemos busca na pilha
    if(operation == 1) {
        value = searchOptions(); // Retorna o valor que o usuario ira procurar na pilha
        int findValue = stack_search(value, &stackPointer);
        messageSearch(findValue, value);
    }


    // Operation = 2, inserimos na pilha
    if(operation == 2) {
        printf("\nOperação a ser realizada: PUSH\n");

        int flag = push(&stackPointer, getValue());

        // se flag vir verdadeira, aumentamos tamanho da pilha
        if(flag) {
            sizeStack++;
            printf("\n\nSeu novo nó foi adicionado na pilha! ;)\n\n");
        }
    }

    // Operation = 3, removemos da piha
    if(operation == 3) {
        if(sizeStack > 0) {
            printf("Operação a ser realizada: POP\n");

            tmpStack = pop(&stackPointer);

            if(tmpStack != NULL) {
                printf("O nó %p com valor de %d foi removido com sucesso\n", (void *)tmpStack, tmpStack->value);
                sizeStack--;
            } else
                printf("Ops, não foi possivel, Pilha vazia\n");

        } else
            printf("Fila vazia :| \n");

    }

    drawStack(stackPointer); /// Chama função para desenhar pilha
    messageContinue();
}
char *itoa (int value, char *result, int base) {

    /* Função para converter inteiro para char */

    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}
void deallocate() {

    /* Função faz a desalocação de memoria para todas as estruturas de dados e logo apos encerra o programa, essa função só é
     * chamada quando o usuario explicita a sua saida do programa
     *
     * Os metodos a seguir, guarda o ponteiro atual no nó em um auxiliar, avança com o ponteiro autual que percorrera a lista, desaloca o auxiliar, segue
     * esse processo até o final da lista, quando o ponteiro que percorre a lista é NULLO ou a o proprio nó quando a lista é circular,
     * */


    /// Desaloca lista encadeada
    if(ptr_linkedList != NULL) {
        while (ptr_linkedList != NULL) {
            tmpLinkedList = ptr_linkedList;
            ptr_linkedList = ptr_linkedList->next;
            free(tmpLinkedList);
        }
    }

    /// Desaloca lista encadeada circular
    if(circularListPointer != NULL) {
        nodeCircular *head = circularListPointer;
        circularListPointer = circularListPointer->next;

        if(circularListPointer != head) {
            tmpCircularLinkedList = circularListPointer;
            circularListPointer = circularListPointer->next;
            free(tmpCircularLinkedList);
        }

        free(head);
    }

    /// Desaloca fila
    if(queuePointer != NULL) {
        nodeQueue *nextNode = NULL, *current = NULL;

        if(queuePointer->next != NULL) {
            current = queuePointer->next;
            while(current != NULL) {
                nextNode = current->next;
                free(current);
                current = nextNode;
            }
        }

        free(queuePointer);
    }

    /// Desaloca pilha
    if(stackPointer != NULL) {
        nodeStack *nextNode = NULL, *current = NULL;

        if(stackPointer->next != NULL) {
            current = stackPointer->next;
            while(current != NULL) {
                nextNode = current->next;
                free(current);
                current = nextNode;
            }
        }
        free(stackPointer);
    }

    /// Desaloca lista duplamente encadeada
    if(doublyLinkedPointer != NULL) {
        nodeDoublyLinked *nextNode = NULL, *current = NULL;

        current = doublyLinkedPointer->next;
        while(current != NULL) {
            nextNode = current->next;
            free(current);
            current = nextNode;
        }

        free(doublyLinkedPointer);
    }
}
void doublyLinked(int operation) {

    // Função faz a inserção, remoção e busca de elementos na estrutura de dados

    int value;

    validateInput(operation); // Valida as entradas, caso operation for diferente de 1, 2 ou 3 retornamos ao menu

    // Lista vazia ? então inicializamos o nó cabeça
    if(doublyLinkedPointer == NULL)
        initDoublyLinkedList(&doublyLinkedPointer);


    // operation = 1, buscamos por um valor que o usuario deseja
    if(operation == 1) {
        value = searchOptions(); // Retorna o valor que o usuario ira procurar na lista
        int findValue = doublyLinkedList_searchData(&doublyLinkedPointer, value);

        messageSearch(findValue, value); // mensagem de retorno, sucesso ou falha para o valor buscado
    }



    // Operation = 2, removes enserimos no inicio, fim ou meio
    if(operation == 2) {

        int option =  insertOptions();

        // Insere inicio
        if(option == 1) {
            doubleLinked_insertStart(&doublyLinkedPointer, getValue());
            doubleChainedListSize++;
        }

        // insere fim
        if(option == 2) {
            doubleLinked_insertEnd(&doublyLinkedPointer, getValue());
            doubleChainedListSize++;
        }

        // Insere meio
        if(option == 3) {
            if(doubleChainedListSize == 0) { // Lista vazia, inserimos no inicio
                printf("Lista vazia, nó será inserido no inicio\n");
                doubleLinked_insertStart(&doublyLinkedPointer, getValue());
                doubleChainedListSize++;
            } else {
                value = getPosition(doubleChainedListSize, (char *)"inserir"); // pega posiçõa a ser inserido novo nó

                if(value > 0 && value <= doubleChainedListSize) {
                    doubleLinked_insert(&doublyLinkedPointer, value, getValue());
                    doubleChainedListSize++;
                } else
                    printf("\nTamanho incorreto, só pode ser removido no intervalo: [1, %d]\n", doubleChainedListSize);

            }
        }

    }


    // operation = 3, removemos do inicio, fim ou meio
    if(operation == 3) {
        int option = removeOptions();

        // doubleChainedListSize > 0, = lista não vazia
        if(doubleChainedListSize > 0) {

            // remove do inicio
            if(option == 1) {
                doubleLinked_remove(&doublyLinkedPointer, option);
                doubleChainedListSize--;
            }

            // remove do fim
            if(option == 2) {
                doubleLinked_removeEnd(&doublyLinkedPointer);
                doubleChainedListSize--;
            }

            // remove do meio
            if(option == 3) {
                value = getPosition(doubleChainedListSize, (char *)"remover");

                if(value > 0 && value <= doubleChainedListSize) {
                    doubleLinked_remove(&doublyLinkedPointer, value);
                    doubleChainedListSize--;
                } else
                    printf("\nTamanho incorreto, só pode ser removido no intervalo: [1, %d]\n", doubleChainedListSize);

            }
        } else
            printf("Lista vazia uai sô '-'\n");

    }


    drawDoublyLinked(doublyLinkedPointer); // Chama função para desenhar lista duplamente encadeada com nó cabeça não ordenada
    messageContinue();
}
int options(void) {
    int opt;
    printf("Operação da lista: \n");
    printf("1 - Busca\n");
    printf("2 - Inserção\n");
    printf("3 - Remoção\n");
    printf(">> "); scanf("%d", &opt);
    return opt;
}
int getPosition(int size, char *method) {
    int pos;
    printf("Numa posicao de [1, %d], de onde voce deseja %s ? \n", size, method);
    scanf("%d", &pos);

    return pos;
}
void messageSearch(int boolean, int value) {

    if(boolean!= -1) {
        printf("\n\nBusca Realizada!!\n\n");

        boolean ?
            printf("O Numero %d procurado está na lista :)\n", value)
                :
            printf("O Numero %d procurado [NÃO] está na lista :(\n", value);

    } else
        printf("Lista VAZIA :( \n");

}
void validateInput(int operation) {

    if(operation != 1 && operation != 2 && operation != 3) {
        printf("\n\nEscolha uma das opções validas ! ;)\n\n");
        menu();
    }
}
void circularChainedList(int operation) {

    /* Função circularChainedList faz a inserção, remoção ou busca na estrutura de dados*/


    int value;

    validateInput(operation);

    // Operation = 1, procura valor escolhido pelo usuario
    if(operation == 1) {
        value = searchOptions(); // Retorna o valor que o usuario ira procurar na lista
        int findValue = search_circularLinkedList(&circularListPointer, value);
        messageSearch(findValue, value);
    }


    // Operation = 2, chama função para inserir valor na lista de forma ordenada, a funçõa que insere retorna 1 para sucesso e 0 para fracaso
    if(operation == 2) {
        value = getValue();

        int flag = sortedInsert(&circularListPointer, value);

        // se flag vir verdadeira, aumentamos tamanho da lista
        if(flag) {
            chainCircularListSize++;
            printf("\n\nSeu novo nó foi adicionado! ;)\n\n");
        }
    }


    // Operation = 3, remove do inicio, fim ou meio
    if(operation == 3) {
        int option = removeOptions();

        // option = 1, remove do inicio
        if(option == 1) {
            if(chainCircularListSize == 0)
                printf("\nSua lista está vazia uai -.- \n");

            else {
                tmpCircularLinkedList = removeCircularLinkedList(&circularListPointer, option); // Função retorna ponteiro para o elemento removido

                // Tratamento de erros e mensagens
                if(tmpCircularLinkedList != NULL) {
                    printf("O nó %p com valor de %d foi removido com sucesso\n", (void *) tmpCircularLinkedList, tmpCircularLinkedList->value);
                    free(tmpCircularLinkedList);
                    tmpCircularLinkedList = NULL;

                    chainCircularListSize--;
                } else
                    printf("Elemento não foi removido :(\n");
            }

        }

        // option = 2, remove do final
        if(option == 2) {

            if(chainCircularListSize == 0)
                printf("\nSua lista está vazia uai -.- \n");

            else {
                tmpCircularLinkedList = removeCircularLinkedList(&circularListPointer, option);
                // Tratamento de erros e mensagens

                if(tmpCircularLinkedList != NULL) {
                    chainCircularListSize--;
                    printf("O nó %p com valor de %d foi removido com sucesso\n", (void *)tmpCircularLinkedList, tmpCircularLinkedList->value);
                    free(tmpCircularLinkedList);
                    tmpCircularLinkedList = NULL;

                } else
                    printf("Elemento não foi removido :(\n");

            }
        }

        // option = 3, removemos do meio
        if(option == 3) {

            if(chainCircularListSize == 0)
                printf("\nSua lista está vazia uai -.- \n");

            else {

                value = getPosition(chainCircularListSize, (char *)"remover"); // pega o valor (indice) em que o nó será removido, intervalo varia de 1 até TAM_MAX da lista

                if(value > 0 && value <= chainCircularListSize) { // Se o valor a ser removido está compreendido no tamanho da lista
                    tmpCircularLinkedList = removeEndCircularLinkedList(&circularListPointer, value);

                    if(tmpCircularLinkedList != NULL) {
                        printf("O nó %p com valor de %d foi removido com sucesso\n", (void *)tmpCircularLinkedList, tmpCircularLinkedList->value);
                        free(tmpCircularLinkedList);
                        tmpCircularLinkedList = NULL;
                        chainCircularListSize--;
                    }
                } else
                    printf("\nTamanho incorreto, só pode ser removido no intervalo: [1, %d]\n", chainCircularListSize);
            }

        }
    }

    printf("\n\n");
    drawCircularLinkedList(circularListPointer); /// Chama funçõa para desenhar lista encadeada circular ordenada sem nó cabeça
    messageContinue();
}
void linkedList(int operation) {

    /* Função linkedList faz a inserção, remoção ou busca na estrutura de dados*/



    int value;
    validateInput(operation);

    // Operation = 1, Procura na lista encadeada um valor escolhido pelo usuario
    if(operation == 1) {
        value = searchOptions(); // Retorna o valor que o usuario ira procurar na lista
        int findValue = linkedList_searchData(value, &ptr_linkedList);

        messageSearch(findValue, value); // Mostra o resultado da pesquisa, sucesso ou falha
    }

    // Operation  = 2, insere na lista encadeada de maneira ordenada um valor escolhido pelo usuario
    if(operation == 2) {
        value = getValue();

        int flag = linkedList_insert(&ptr_linkedList, value);

        // se flag vir verdadeira ou seja 1, aumentamos tamanho da lista e mostramos mensagme de sucesso
        if(flag) {
            listChainedSize++;
            printf("\n\nSeu novo nó foi adicionado! ;)\n\n");
        }
    }

    // Operation  = 3, remove da lista encadeada, do inicio, fim ou uma posição do intervalo de 1 ate o tamanho maximo da lista
    if(operation == 3) {
        int option = removeOptions(); // Função que printa as opções de remoção e retorna valor escolhido pelo usuario

        // option = 1, remove do inicio
        if(option == 1) {
            if(listChainedSize == 0)
                printf("\nSua lista está vazia uai -.- \n");

            else {
                tmpLinkedList = linkedList_removeStart(&ptr_linkedList);

                // Se remoção for bem sucessedida, retorna um ponteiro diferente de Nulo
                if(tmpLinkedList != NULL) {
                    /* 1 - Mensagem de sucesso
                     * 2 - Desaloação do nó
                     * 3 - Alteramos o tamanho da lista*/
                    printf("O nó %p com valor de %d foi removido com sucesso\n", (void *) tmpLinkedList, tmpLinkedList->value);
                    free(tmpLinkedList);
                    tmpLinkedList = NULL;
                    listChainedSize--;

                } else
                    printf("Elemento não foi removido :(\n");
            }
        }

        // Option = 2, removemos do final
        if(option == 2) {
            if(listChainedSize == 0)
                printf("\nSua lista está vazia uai -.- \n");

            else {
                tmpLinkedList = linkedList_removeEnd(&ptr_linkedList);

                // Se remoção for bem sucessedida, retorna um ponteiro diferente de Nulo
                if(tmpLinkedList != NULL) {
                    listChainedSize--;
                    printf("O nó %p com valor de %d foi removido com sucesso\n", (void *)tmpLinkedList, tmpLinkedList->value);
                    free(tmpLinkedList);
                    tmpLinkedList = NULL;

                } else
                    printf("Elemento não foi removido :(\n");
            }
        }

        // option = 3, removemos de uma posição de 1 até tamanho maximo de lista
        if(option == 3) {

            if(listChainedSize == 0)
                printf("\nSua lista está vazia uai -.- \n");

            else {

                value = getPosition(listChainedSize, (char *)"remover"); // Pega indice para remoção

                if(value > 0 && value <= listChainedSize) { // Se o valor a ser removido está compreendido no tamanho da lista
                    tmpLinkedList = linkedList_remove(&ptr_linkedList, value);

                    // Faz o tratamento e mostra mensagem de sucesso, logo em seguida redimensiona tamanho da lista e desaloca nó esolhido
                    if(tmpLinkedList != NULL) {
                        printf("O nó %p com valor de %d foi removido com sucesso\n", (void *)tmpLinkedList, tmpLinkedList->value);
                        free(tmpLinkedList);
                        tmpLinkedList = NULL;
                        listChainedSize--;
                    }
                } else
                    printf("\nTamanho incorreto, só pode ser removido no intervalo: [1, %d]\n", listChainedSize);
            }

        }
    }

    /// Chama função para desenhar na interfaçe grafica a lista enacadeada sem nó cageça e ordenada
    drawLinkedList(ptr_linkedList);
    messageContinue(); /// Prosegue com a operação do programa
}
void dataStructures(int id, int operation) {
    /* Função que contrala qual estrutura de dados será iniciada apartir de um id, o campo operation
       refere-se a qual operação será realizado na estrutura. */

    switch (id) {
        case 1:
            linkedList(operation);
            break;
        case 2:
            circularChainedList(operation);
            break;

        case 3:
            doublyLinked(operation);
            break;

        case 4:
            queue(operation);
            break;

        case 5:
            stack(operation);
            break;

        case 6:
            deallocate(); // Função ira desalocar todas as estruturas de dados

            // Mostrar mesagem de sucesso
            printf("\n\nListas desalocadas com sucesso\n\n");
            printf("Digite alguma tecla para encerrar programa...\n");
            __fpurge(stdin);
            getchar();
            exit(0);
            break;

        default:
            printf("\nOpção invalida  :| \n");
            break;
    }
}
void messageContinue() {

    /* A Função mostra uma mesagem e pede para que o usuario digite alguma coisa para proseguir com o código,
     * fazemos isso mostrar algum dado ou trocar a parte do código, chamando a função para volter ao menu por
     * exemplo*/

    printf("\n\nDigite alguma coisa para prosseguir com as operações\n\n");
    __fpurge(stdin);
    getchar();
    clearView();
    menu();
}
void menu() {
    /* A função menu mostra ao usuario algumas opções para escolher o tipo de estrutura de dados,
    / apos a escolhe chama as função com os parametros da seleção. */

    int id;

    printf("1 - Lista Encadeada\n");
    printf("2 - Lista Encadeada Circular\n");
    printf("3 - Lista Duplamente Encadeada\n");
    printf("4 - Fila\n");
    printf("5 - Pilha\n");
    printf("6 - Sair\n");


    printf(">> "); scanf("%d", &id);

    /* A Função options gera um id apartir da entrada do usuario para que posssa
    /  ser feito a operação  na estrutura de dados */

    int operation = 0;

    if(id != 6) {
        operation = options();
    }

    clearView();

    /* a função dataStructures define qual a estrutura de dados será usada, a variavel opt contem
    /  o tipo de estrutura indentificado por um ID, já a variavel operation contem o id
    /  da operação que será realizada, podendo ser remoção, insert e busca.
    */

    dataStructures(id, operation);

}
int main(void) {
    gfx_init(1000, 700, "Trabalho 2!");
    menu();
}