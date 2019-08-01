struct NodeCircularLinkedList {
    int value;
    struct NodeCircularLinkedList *next;
};

typedef struct NodeCircularLinkedList nodeCircular;


int sortedInsert(nodeCircular **head_ref, int data);
int search_circularLinkedList(nodeCircular **head_ref, int data);
nodeCircular *removeEndCircularLinkedList(nodeCircular **head_ref, int index);
nodeCircular *removeCircularLinkedList(nodeCircular **head_ref, int index);


int sortedInsert(nodeCircular **head_ref, int data) {

    nodeCircular *new_node = (nodeCircular *) malloc(sizeof(nodeCircular));
    new_node->value = data;

    nodeCircular *current = *head_ref;

    if (current == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return 1;
    }

    else if (current->value >= new_node->value) {

        /*  Se o valor for menor que o valor da cabeça, então
          precisamos mudar o próximo do último nó*/

        while(current->next != *head_ref)
            current = current->next;

        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
        return 1;
    }

    else {
        /* Localize o nó antes do ponto de inserção*/
        while (current->next!= *head_ref && current->next->value < new_node->value)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
        return 1;
    }
}

int search_circularLinkedList(nodeCircular **head_ref, int data) {

    if(*head_ref == NULL) {
        return  -1;
    }

    nodeCircular *tmp = (*head_ref)->next;

    if((*head_ref)->value == data) {
        return 1;
    }

    while (tmp != *head_ref) {

        if(tmp->value == data)
            return 1;

        tmp = tmp->next;
    }

    return 0;
}
nodeCircular *removeEndCircularLinkedList(nodeCircular **head_ref, int index) {


    if((*head_ref) == NULL) {
        printf("Sua lista está vazia :|\n");
        return NULL;
    }

    if((*head_ref)->next == *head_ref) {
        nodeCircular *aux = *head_ref;
        *head_ref = NULL;
        return aux;
    }


    nodeCircular *prev = *head_ref;
    nodeCircular *tmp = *head_ref;
    int count = 1;

    while (count != index) {
        prev = tmp;
        tmp = tmp->next;
        count++;
    }

    prev->next = tmp->next;
    tmp->next = NULL;
    return tmp;
}
nodeCircular *removeCircularLinkedList(nodeCircular **head_ref, int index) {


    if((*head_ref) == NULL) {
        printf("Sua lista está vazia :|\n");
        return NULL;
    }

    if((*head_ref)->next == *head_ref) {
        nodeCircular *aux = *head_ref;
       *head_ref = NULL;
        return aux;
    }

    // Remover nó do inicio da lista
    if(index == 1) {
        nodeCircular *aux = (*head_ref)->next;
        nodeCircular *tmp = *head_ref;
        *head_ref = aux;

        tmp->next = NULL;

        while (aux->next != tmp) {
            aux = aux->next;
        }

        aux->next = *head_ref;

        return tmp;

    }

    // Remover nó do fim da lista
    if(index == 2) {
        nodeCircular *last = *head_ref;
        nodeCircular *prev = *head_ref;

        while (last->next != *head_ref) {
            prev = last;
            last = last->next;
        }

        prev->next = last->next;
        return last;
    }

    return NULL;
}