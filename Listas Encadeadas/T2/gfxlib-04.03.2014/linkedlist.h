struct NodeLinkedList {
    int value;
    struct NodeLinkedList *next;
};

typedef struct NodeLinkedList nodeLinkedList;


/// ########## Declaração de Funções  ########## ///
int emptyLinkedList(nodeLinkedList *pointer_linkedList);
int linkedList_insert(nodeLinkedList **pointer_linkedList, int data);
int linkedList_searchData(int data, nodeLinkedList **pointer_linkedList);
void linkedList_search(int data, nodeLinkedList *pointer_linkedList, nodeLinkedList **pont, nodeLinkedList **ptr_prev);
nodeLinkedList *allocate();
nodeLinkedList* linkedList_removeStart(nodeLinkedList **pointer_linkedList);
nodeLinkedList* linkedList_removeEnd(nodeLinkedList **pointer_linkedList);
nodeLinkedList* linkedList_remove(nodeLinkedList **pointer_linkedList, int index);
nodeLinkedList *initLinkedList();


/// Função para alocar um novo nó e inicializa-lo
nodeLinkedList *allocate() {
    nodeLinkedList *newNode = (nodeLinkedList *) malloc(sizeof(nodeLinkedList));

    if(newNode == NULL) {
        printf("ERRO, SEU COMPUTADOR ESTÁ SEM MEMÓRIA.\n");
        exit(1);
    }

    newNode->next = NULL;
    return newNode;
}

/// Função para ver se lista está vazia, retorna 1 para verdadeiro, 0 para falso
int emptyLinkedList(nodeLinkedList *pointer_linkedList) {
    return pointer_linkedList == NULL ? 1 : 0;
}
int linkedList_insert(nodeLinkedList **pointer_linkedList, int data) {

    // Se lista for vazia inicializamos e retornamos com código de bem sucedido

    if(emptyLinkedList(*pointer_linkedList)) {
        nodeLinkedList *newNode = allocate();
        newNode->value = data;
        *pointer_linkedList = newNode;
        return 1;
    }


    // ALocação de memoria e ponteiros para auxilio das operações
    nodeLinkedList *pont = allocate(), *prev = NULL, *aux, *newNode = allocate();


    newNode->value = data;

    if((*pointer_linkedList)->value > newNode->value) {
        newNode->next = (*pointer_linkedList);
        *pointer_linkedList = newNode;
        return 1;
    }

    linkedList_search(newNode->value,  *pointer_linkedList, &pont, &prev);

    /// Caso o elemento não esteja na lista
    if(pont == NULL) {
        newNode->next = prev->next;
        prev->next = newNode;
        return 1;
    }

    /// Se o elemento já está na lista, adiciona o mesmo na frente do que já estava inserido
    aux = pont->next;
    pont->next = newNode;
    newNode->next = aux;
    return 1;
}
int linkedList_searchData(int data, nodeLinkedList **pointer_linkedList) {

    if(*pointer_linkedList == NULL)
        return -1; // Retorne -1 indicando lista vazia


    nodeLinkedList *tmp = *pointer_linkedList;

    /// Retorna 1 caso tenha encontrado o valor procurado na estrutura de dados
    while(tmp != NULL) {
        if(tmp->value == data) return 1;
        tmp = tmp->next;
    }

    /// se não encontrou nada, retorne 0
    return 0;
}
void linkedList_search(int data, nodeLinkedList *pointer_linkedList, nodeLinkedList **pont, nodeLinkedList **ptr_prev) {

    *ptr_prev = pointer_linkedList;
    nodeLinkedList *ptr = pointer_linkedList;

    int flag = 0;

    while (ptr != NULL) {
        if(ptr->value < data) {
            *ptr_prev = ptr;
            ptr = ptr->next;
        } else {
            if(ptr->value == data) {
                *pont = ptr;
                flag = 1;
            }
            ptr = NULL;
        }
    }

    if(!flag) {
        *pont = NULL;
    }
}
nodeLinkedList* linkedList_removeStart(nodeLinkedList **pointer_linkedList) {
    if(emptyLinkedList(*pointer_linkedList)) {
        printf("\n\nSua lista está vazia :( \n\n");
        return NULL;
    }

    nodeLinkedList *tmp = *pointer_linkedList;
    *pointer_linkedList = tmp->next;
    return tmp;
}
nodeLinkedList* linkedList_removeEnd(nodeLinkedList **pointer_linkedList) {
    
    if(emptyLinkedList(*pointer_linkedList))
        return NULL;
    
    // Caso tenhamos uma estrutura, e ela ponte para nullo, fazemos com que ela seja desalocada e retornamos o novo tamanho de lista
    if((*pointer_linkedList)->next == NULL) {
        nodeLinkedList *aux = (*pointer_linkedList);
        (*pointer_linkedList) = NULL;
        return aux;
    }

    nodeLinkedList *last = (*pointer_linkedList)->next, *penultimate = *pointer_linkedList;

    // Laço while para percorrer a lista, deixando um ponteiro apontando para o ultimo elemento da lista, e um para o penultimo nó da lista
    while(last->next != NULL) {
        penultimate = last;
        last = last->next;
    }

    penultimate->next = NULL; // Penultimo nó aponta para NULLO, assim informando o novo fim de lista

    return last;
}
nodeLinkedList* linkedList_remove(nodeLinkedList **pointer_linkedList, int index) {
 
    if(emptyLinkedList(*pointer_linkedList))
        return NULL;

    if(index > 0) { // se a posição para remover o elemento for maior que o tamanho da lista, cai no else com uma mensagme informando que foi invalido

        if(index == 1) /// Posição 1 a ser removida na lista, chamamos a função para remover do inicio
            return linkedList_removeStart(pointer_linkedList);

        nodeLinkedList *current = (*pointer_linkedList), *prev = *pointer_linkedList;

        // um [FOR] para percorer a lista e deixar os ponteiros um apontado para o nó atual e e um para o anterior;
        for(int count = 1 ; count < index ; count++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next; // Aqui fazemos que o anterior aponte para o proximo do atual, assim removendo o "atual" da lista
        
        return current;
    }

    printf("Posição invalida\n\n");
    return NULL;
}
nodeLinkedList *initLinkedList() {
    nodeLinkedList *newNode = allocate();
    newNode->next = NULL;
    return newNode;
}


