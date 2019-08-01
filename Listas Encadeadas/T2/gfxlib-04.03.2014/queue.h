#include <stdio.h>
#include <stdlib.h>

struct NodeQueue {
  int value;
  struct NodeQueue *next;
};

typedef struct NodeQueue nodeQueue;


void initQueue(nodeQueue **queuePointer);
int emptyQueue(nodeQueue *queuePointer);
int insertQueue(nodeQueue **queuePointer, int data);
void printQueue(nodeQueue **queuePointer, int end);
int remove_queue(nodeQueue **queuePointer);
int search_queue(int x, nodeQueue **queuePointer);
nodeQueue *aloca();
nodeQueue *aloca();


void initQueue(nodeQueue **queuePointer) {
  *queuePointer = (nodeQueue *) malloc(sizeof(nodeQueue));
}
int emptyQueue(nodeQueue *queuePointer) {
 return queuePointer->next == NULL ? 1 : 0;
}
int insertQueue(nodeQueue **queuePointer, int data) {
  nodeQueue *newNode = aloca();
  newNode->value = data;

  if(emptyQueue((*queuePointer))) {
    (*queuePointer)->next = newNode;
    return 1;
  }

  else {
    nodeQueue *tmp = (*queuePointer)->next;

    while(tmp->next != NULL)
      tmp = tmp->next;

    tmp->next = newNode;

    return 1;
  }
}

void printQueue(nodeQueue **queuePointer, int end) {
    if(emptyQueue(*queuePointer)){
        printf("Fila vazia!\n\n");
        return ;
    }

    nodeQueue *tmp;
    tmp = (*queuePointer)->next;
    printf("Fila :");
    while( tmp != NULL){
        printf("%5d", tmp->value);
        tmp = tmp->next;
    }

    printf("\n        ");

    for(int count=0 ; count < end ; count++)
        printf("  ^  ");

    printf("\nOrdem:");

    for(int count=0 ; count < end; count++)
        printf("%5d", count + 1);


    printf("\n\n");
}

int remove_queue(nodeQueue **queuePointer) {

    if((*queuePointer)->next == NULL) {
        printf("Fila ja esta vazia\n");
        return 0;
    }

    nodeQueue *tmp = (*queuePointer)->next;
    (*queuePointer)->next = tmp->next;

    printf("O Valor %d do endereço %p foi removido com sucesso :)\n", tmp->value, (void *)tmp);
    free(tmp);

    return 1;
}

int search_queue(int x, nodeQueue **queuePointer) {
    nodeQueue *tmp = (*queuePointer)->next;

    if(tmp == NULL) {
        return -1; /// Lista vazia, retorna -1
    }

    /// Retorna 1 caso tenha encontrado o valor procurado na estrutura de dados
    while(tmp != NULL) {
        if(tmp->value == x) return 1;
        tmp = tmp->next;
    }

    /// se não encontrou nada, retorne 0
    return 0;

}

nodeQueue *aloca() {
    nodeQueue *newNode = (nodeQueue  *) malloc(sizeof(nodeQueue ));

    if(newNode == NULL) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    newNode->next = NULL;
    return newNode;
}

