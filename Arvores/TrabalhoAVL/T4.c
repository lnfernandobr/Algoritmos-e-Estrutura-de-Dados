
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "gfx/gfx.h"
#include "avl.h"

#define width 1300
#define height 700

void drawNode(AVL *arv, int x, int y) {
    int32_t w,z;
    w = arv->chave;
    z = arv->bal;

    char str[10], str1[10];

    sprintf(str,"%d", w);
    sprintf(str1,"%d", z);
    gfx_set_color(115, 109, 188);

    gfx_filled_ellipse(x, y,30,30);

    gfx_set_color(255, 255, 255);
    gfx_text(x - 8,y - 10, str);
    gfx_set_color(1, 255, 255);
    gfx_text(x,y + 5, str1);
}
void drawScene(AVL *root,int x, int y,int z) {
    AVL *pt;
    int32_t k;


    if(root != NULL) {
        pt = root;

        k = (z - x) / 2;

        if(k < 0)
            k *= -1;

        drawNode(pt, x, y);

        gfx_set_color(255, 255, 255);

        if(pt->esq != NULL) {
            gfx_line(x - 30, y,x - k,y + 50);
            drawScene(pt->esq,x - k,y + 50, x);
        }

        if(pt->dir != NULL) {
            gfx_line(x + 30, y,x + k,y + 50);
            drawScene(pt->dir,x + k,y + 50, x);
        }
    } else
        gfx_clear();
}
void search(AVL *root, int x, unsigned int *isChange) {

    if(root == NULL) {
        printf("Arvore vazia\n");
        return;
    }

    if(root->chave == x) {
        *isChange = 1;
        printf("Valor %d encontrado na arvore\n", x);
        return;
    }

    if(root->esq != NULL)
        search(root->esq, x, isChange);

    if(root->dir != NULL)
        search(root->dir, x, isChange);

}
/* Retorna tamanho do arquivo, parametro path recebe o caminho do arquivo */
int32_t sizeFile(const char *path) {
    FILE *fp;

    printf("Arquivo aberto para calcular tamanho: %s\n", path);
    fp = fopen(path, "rb");
    printf("in size p:%p\n", (void*)fp);

    if( fp == NULL )  {
        perror ("Error opening file");
        return (-1);
    }

    fseek(fp, 0, SEEK_END);
    int32_t len = ftell(fp);

    printf("Tamanho do arquivo aberto: %d\n", (int32_t) (len / sizeof(int32_t)));
    fclose(fp);

    return (int32_t)(len / sizeof(int32_t));
}
unsigned int menu(void) {

    int num;
    puts("------------------------- MENU -------------------------\n");
    puts("1 - Inserir ");
    puts("2 - Buscar ");
    puts("3 - Remover  ");
    puts("4 - Sair    ");
    puts("5 - Ler arvore do arquivo");
    puts("6 - Gravar arvore no arquivo");
    scanf("%d", &num);

    return num;
}
int getValue(const char *msg) {
    int num;
    system("clear");
    puts(msg);
    scanf("%d", &num);
    return num;
}
void salvarArvore(AVL **root) {

    char path[100];
    FILE *lerArq = NULL;

    printf("Nome do arquivo para ser salvo: \n");
    scanf("%s", path);
    printf("Arquivo a ser salvo: %s\n", path);

    lerArq = fopen(path, "wb");
    if(lerArq == NULL) {
        printf("\nErro na abertura do arquivo - O Caminho para o arquivo pode estar incorreto \n");
        exit (-3);
    }

    printf("p: %p\n",(void*) lerArq);
    printf("root: %p\n",(void*) *root);
    writeFile(*root, lerArq);


    fclose(lerArq);

}

int main(void) {
    unsigned int operation = 0, isChange = 0;


    char h, path[100];

    AVL *root = NULL;

    gfx_init(width, height, "teste");

    while(1) {

        operation = menu();

        if(operation == 5) {

            gfx_clear();

            destruirArvore(&root);

            printf("Nome do arquivo a ser lido: \n");
            scanf("%s", path);

            FILE *arq = fopen(path, "r+b");
            if(arq == NULL) {
                printf("SEM MEMORIA\n");
                exit(-3);
            }

            fseek(arq, 0, SEEK_END);
            int32_t len = ftell(arq) / sizeof(int32_t);
            rewind(arq);
            readyFile(&root, len, arq);

            fclose(arq);
        }


        if(operation == 1)
            insere(&root, getValue("Inserir >> "), &h);

        if(operation == 2) {
            search(root, getValue("Buscar >>"), &isChange);
            if(!isChange)
                printf("Valor não encontrado na arvore :(\n");

            isChange = 0;
        }

        if(operation == 3) {
            int status = 0;
            removeNode(&root, getValue("Remover >>"), &status);
        }


        if(operation == 4) {
            gfx_quit();
            puts("Bye\n");
            exit(0);
        }

        if(operation == 6)
            salvarArvore(&root);


        drawScene(root, width / 2, 50, width);
        gfx_paint();
    }

}