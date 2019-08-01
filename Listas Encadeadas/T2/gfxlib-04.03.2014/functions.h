int searchOptions(void);
int removeOptions(void);
int insertOptions(void);
void clearView(void);


void clearView(void) {
    system("clear");
}

/// Função para escolha do usuario de onde ele deseja inserir um nó da lista, inicio, fim ou
/// qualquer posição da lista.
int insertOptions() {
    int opt;

    printf("1 - Inserir no Inicio\n");
    printf("2 - Inserir no Fim\n");
    printf("3 - Inserir em outra posição \n");
    __fpurge(stdin);
    scanf("%d", &opt);

    return opt;
}

int getValue(void) {
    int element;
    printf("Digite o elemento a ser inserido: \n");
    scanf("%d", &element);
    return element;
}

/// Função para pegar o elemento que o usuario deseja buscar na lista.
int searchOptions(void) {
    int element;
    printf("Digite o elemento que voce deseja buscar na estrutura: ");

    scanf("%d", &element);
    return element;
}

/// Função para escolha do usuario de onde ele deseja remover um nó da lista, inicio, fim ou
/// qualquer posição da lista.
int removeOptions(void) {
    int opt;

    printf("1 - Remover do Inicio\n");
    printf("2 - Remover do Fim\n");
    printf("3 - Remover de outra posição \n");
    scanf("%d", &opt);

    return opt;
}

