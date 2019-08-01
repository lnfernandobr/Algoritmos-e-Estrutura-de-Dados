struct NodeDoublyLinked {
    int value;
    struct NodeDoublyLinked *prev;
    struct NodeDoublyLinked *next;
};

typedef struct NodeDoublyLinked nodeDoublyLinked;


int emptyDoublyList(nodeDoublyLinked *doubleLinkedPointer);
void doubleLinked_insert(nodeDoublyLinked **doubleLinkedPointer, int pos, int data);
void doubleLinked_insertStart(nodeDoublyLinked **doubleLinkedPointer, int data);
void doubleLinked_insertEnd(nodeDoublyLinked **doubleLinkedPointer, int data);
void printList(nodeDoublyLinked *doubleLinkedPointer);
void initDoublyLinkedList(nodeDoublyLinked **doublyLinkedPointer);
void doubleLinked_removeEnd(nodeDoublyLinked **doublyLinkedPointer);
void doubleLinked_remove(nodeDoublyLinked **doublyLinkedPointer, int pos);
int doublyLinkedList_searchData(nodeDoublyLinked **doublyLinkedPointer, int data);


int emptyDoublyList(nodeDoublyLinked *doubleLinkedPointer) {
    return  doubleLinkedPointer->next == NULL ? 1 : 0;
}
void doubleLinked_insert(nodeDoublyLinked **doubleLinkedPointer, int pos, int data) {

    if(emptyDoublyList(*doubleLinkedPointer)) {
        // Aloca novo nó e insere o campo data passado pelo usuario
        nodeDoublyLinked *newNode = (nodeDoublyLinked *) malloc(sizeof(nodeDoublyLinked));
        newNode->value = data;
        newNode->prev = *doubleLinkedPointer;
        newNode->next = NULL;
        (*doubleLinkedPointer)->next = newNode;
        return;
    }

    if(pos == 1)  {
        doubleLinked_insertStart(doubleLinkedPointer, data); // Insere no inicio da lista
        return;
    }
//    if(pos == 1) doubleLinked_insertEnd(doubleLinkedPointer, data);   // Insere no fim da lista

    int count = 1;
    nodeDoublyLinked *tmp = (*doubleLinkedPointer)->next;

    // Laço while para encontrar a posição que o usuario deseja inserir o nó
    while (count != pos) {
        tmp = tmp->next;
        count++;
    }

    // Aloca novo nó e insere o campo data passado pelo usuario
    nodeDoublyLinked *newNode = (nodeDoublyLinked *) malloc(sizeof(nodeDoublyLinked)), *aux;
    newNode->value = data;

    // Insere o nó na posição escolhida
    aux = tmp->prev;
    newNode->prev = aux;
    aux->next = newNode;
    newNode->next = tmp;
    tmp->prev = newNode;
}
void doubleLinked_insertStart(nodeDoublyLinked **doubleLinkedPointer, int data) {

    if(emptyDoublyList(*doubleLinkedPointer)) {
        // Aloca novo nó e insere o campo data passado pelo usuario
        nodeDoublyLinked *newNode = (nodeDoublyLinked *) malloc(sizeof(nodeDoublyLinked));
        newNode->value = data;
        newNode->prev = *doubleLinkedPointer;
        newNode->next = NULL;
        (*doubleLinkedPointer)->next = newNode;
        return;
    }

    // Aloca novo nó e insere o campo data passado pelo usuario
    nodeDoublyLinked *newNode = (nodeDoublyLinked *) malloc(sizeof(nodeDoublyLinked)), *aux;
    newNode->value = data;

    newNode->next = (*doubleLinkedPointer)->next;
    aux = (*doubleLinkedPointer)->next;
    aux->prev = newNode;
    newNode->prev = *doubleLinkedPointer;
    (*doubleLinkedPointer)->next = newNode;
}
void doubleLinked_insertEnd(nodeDoublyLinked **doubleLinkedPointer, int data) {

    if(emptyDoublyList(*doubleLinkedPointer)) {
        // Aloca novo nó e insere o campo data passado pelo usuario
        nodeDoublyLinked *newNode = (nodeDoublyLinked *) malloc(sizeof(nodeDoublyLinked));
        newNode->value = data;
        newNode->prev = *doubleLinkedPointer;
        newNode->next = NULL;
        (*doubleLinkedPointer)->next = newNode;
        return;
    }

    // Aloca novo nó e insere o campo data passado pelo usuario
    nodeDoublyLinked *newNode = (nodeDoublyLinked *) malloc(sizeof(nodeDoublyLinked)), *tmp;
    newNode->value = data;

    newNode->next = NULL;
    tmp = (*doubleLinkedPointer)->next;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
    newNode->prev = tmp;
}
void printList(nodeDoublyLinked *doubleLinkedPointer) {
    printf("\nLista Duplamente encadeada: \n");

    doubleLinkedPointer = doubleLinkedPointer->next;

    while (doubleLinkedPointer  != NULL) {
        printf(" %d ", doubleLinkedPointer->value);
        doubleLinkedPointer = doubleLinkedPointer->next;
    }


}
void initDoublyLinkedList(nodeDoublyLinked **doublyLinkedPointer) {
    *doublyLinkedPointer = (nodeDoublyLinked *) malloc(sizeof(nodeDoublyLinked));
    (*doublyLinkedPointer)->next = NULL;
    (*doublyLinkedPointer)->prev = NULL;
    (*doublyLinkedPointer)->value = -999;

}
void doubleLinked_removeEnd(nodeDoublyLinked **doublyLinkedPointer) {


    if(emptyDoublyList(*doublyLinkedPointer)) {
        printf("LISTA VAZIA\n");
        return;
    }


    nodeDoublyLinked *tmp = (*doublyLinkedPointer)->next, *aux;

    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    aux = tmp->prev;
    aux->next = NULL;
    printf("Nó %p com valor %d foi removido com sucesso, \n", (void *)tmp, tmp->value);
    free(tmp);

}
void doubleLinked_remove(nodeDoublyLinked **doublyLinkedPointer, int pos) {


    if(emptyDoublyList(*doublyLinkedPointer)) {
        printf("LISTA VAZIA\n");
        return;
    }


    nodeDoublyLinked *tmp, *current, *aux;
    int count = 1;

    if((*doublyLinkedPointer)->next == NULL) {
        printf("LIsta VAZIA NÃO PODO REMOVER\n");
        return;
    }

    if(pos == 1)  { /* caso o no a ser retirado seja o do inicio */
        tmp = (*doublyLinkedPointer)->next;

        if(tmp->next == NULL) {
            (*doublyLinkedPointer)->next = NULL;
        } else {
            printf("Nó %p com valor %d foi removido com sucesso, \n", (void *)tmp, tmp->value);
            (*doublyLinkedPointer)->next = tmp->next;
            aux = tmp->next;
            aux->prev = *doublyLinkedPointer;
            free(tmp);
        }
        return;
    }


    current = (*doublyLinkedPointer)->next;
    while(count != pos) {
        current = current->next; /*passa para o próximo*/
        count++;
    }

    if(current->next == NULL) {

        aux = current->prev;
        aux->next = NULL;
        current->prev = NULL;
        free(current);
        return;
    }

    tmp = current->prev;
    aux =  current->next;
    tmp->next = current->next;
    aux->prev = tmp;

    printf("Nó removido com sucesso, endereço %p com valor %d", (void *)current, current->value);

    free(current);

}
int doublyLinkedList_searchData(nodeDoublyLinked **doublyLinkedPointer, int data) {

    if(emptyDoublyList(*doublyLinkedPointer)) {
        return -1;
    }

    nodeDoublyLinked *tmp = (*doublyLinkedPointer)->next;

    while(tmp != NULL) {
        if(tmp->value == data) return 1;
        tmp = tmp->next;
    }

    return 0;
}