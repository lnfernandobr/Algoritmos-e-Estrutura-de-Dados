#include <stdio.h>
#include <stdlib.h>

struct NodeStack {
    int value;
    struct NodeStack *next;
};

typedef struct NodeStack nodeStack;


int stack_search(int data, nodeStack **stackPointer);
void init(nodeStack **stackPointer);
int emptyStack(nodeStack *stackPointer);
int push(nodeStack **stackPointer, int data);
nodeStack* pop(nodeStack **stackPointer);
nodeStack *alloc();


int stack_search(int data, nodeStack **stackPointer) {

    /// Se o ponteiro passado para funções [stack_search] for nulo, alocamos um nó para ele
    if(*stackPointer == NULL) {
        init(stackPointer);
    }

    /// Se a pilha estiver vazia, retornamos -1 indicando pilha vazia
    if(emptyStack(*stackPointer)) {
        return -1;
    }

    nodeStack *tmp = (*stackPointer)->next;

    /// Retorna 1 caso tenha encontrado o valor procurado na estrutura de dados
    while(tmp != NULL) {
        if(tmp->value == data) return 1;
        tmp = tmp->next;
    }

    /// se não encontrou nada, retorne 0
    return 0;
}
void init(nodeStack **stackPointer) {
    *stackPointer = (nodeStack *) malloc(sizeof(nodeStack));
    (*stackPointer)->value = -999;
    (*stackPointer)->next = NULL;
}
int emptyStack(nodeStack *stackPointer) {
    return stackPointer->next == NULL ? 1 : 0;
}
int push(nodeStack **stackPointer, int data) {
    
    /// Se o ponteiro passado para funções push for nulo, alocamos um nó para ele
    if(*stackPointer == NULL) {
        init(stackPointer);
    }

    /// Faz a alocação de um novo nó 
    nodeStack *newNode = alloc(); 
    newNode->value = data;

    // Se a pilha estiver vazia, ou seja, está somente com o nó cabeça, fazemos com que a cabeça
    // aponte para o proximo nó que acabará de ser alocado, e logo retornamos
    if(emptyStack(*stackPointer)) {
        (*stackPointer)->next = newNode;
        return 1;
    }

    else { 

        nodeStack *tmp = (*stackPointer)->next; // Pilha com cabeça, logo apontados tmp para o proximo nó

        /// Enquanto o nó atual for diferente de nulo, apontados para o proximo nó 
        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = newNode; /// Ultimo nó recebe o nó alocado e retornamos 1 para indicar sucesso

        return 1;
    }

}
nodeStack* pop(nodeStack **stackPointer) {
   
    /// Se o ponteiro passado para funções push for nulo, alocamos um nó para ele
    if(*stackPointer == NULL) {
        init(stackPointer);
    }

    // Se a pilha estiver vazia, ou seja, está somente com o nó cabeça, retornamos -1 para indicar pilha
    // vazia
    if(emptyStack(*stackPointer)) {
        return NULL;
    } 
    
    /// Dois ponteiros que apontaram apos percorrer a pilha, para ultimo e penultimo respectivamente
    nodeStack *last = (*stackPointer)->next, *penultimo = *stackPointer;

    /// Enquanto o proximo nó for diferente de nullo, fazmos o ponteiro last e penultimo avançar 
    while(last->next != NULL) {
        penultimo = last;
        last = last->next;
    }

    penultimo->next = NULL; /// Penultimo aponta para nullo, indicando novo fim de pilha
    
    return last;
}
nodeStack *alloc() {
    nodeStack *newNode = (nodeStack *) malloc(sizeof(nodeStack));

    if(newNode == NULL) {
        perror("ERRO, SEU COMPUTADOR ESTÁ SEM MEMÓRIA.\n");
        exit(1);
    }

    newNode->next = NULL;
    return newNode;
}
