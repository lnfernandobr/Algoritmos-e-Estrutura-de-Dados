#include "Algoritmos/improvedBubbleSort.h"
#include "Algoritmos/bubbleSort.h"
#include "Algoritmos/insertionSort.h"
#include "Algoritmos/mergesort.h"
#include "Algoritmos/quickSort.h"
#include "Algoritmos/heapSort.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <sys/time.h>

/* Retorna tamanho do arquivo, parametro path recebe o caminho do arquivo */
int32_t sizeFile(const char *path) {
    FILE *fp;


    printf("Arquivo aberto para calcular tamanho: %s\n", path);
    fp = fopen(path, "r");

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

/*  Retorna um endereço do vetor alocado dinamicamente,
    recebe o parametro path recebe o caminho do arquivo 
    ao qual deve carregar no vetor.
*/
int32_t *loadArray(const int32_t len, const char *path) {


    FILE *file;

    file = fopen(path, "r");
    if(file == NULL) {
        perror("\nErro na abertura do arquivo - O Caminho para o arquivo pode estar incorreto \n");
        exit (-3);
    }

    int32_t *arr = malloc(len * sizeof(int32_t));

    fseek(file, 0, SEEK_SET);
    fread(arr, len * sizeof(int32_t), 1, file);
    fclose(file);


    return arr;
}

/*  Salva o vetor passado no primeiro argumento, o parametro name_file
     indica o nome que sera salvo o arquivo de saida, o arquivo sera salvo no diretorio 
    em que o programa se encontra 
*/
void saveFile(const int32_t *array, const int32_t length, const char *name_file) {

    FILE *file_save;

    file_save = fopen(name_file, "wb");
    if(file_save == NULL) {
        perror("Erro, não foi possivel abrir o arquivo para salvar\n");
        exit (-4);
    }

    fwrite(array, 1, length * sizeof(int32_t), file_save);
    fclose(file_save);
}



/*  Função principal - recebe os argumentos por linha de comando, ordena seguido
    do algoritmo escolhido, salva o arquivo ordenado na pasta do programa e
    com o nome passado porargumento printa o tempo de execução em MILISEGUNDOS.
    Desaloca a memoria utilizada e termina a execução.
*/
int main(int argc, char **argv) {
    srand(time(NULL));

    if(argc != 4)  {
        printf("\nArgumentos invalidos, formato: ./name [cod-programa] nome-entrada nome-saida\n\n");
        return -1;
    }

    struct timeval  tv1, tv2;
    double time_spent;

    const unsigned int algorithm = atoi(argv[1]); 
    int32_t length = sizeFile(argv[2]); // calcular tamanho do arquivo

    printf("Algoritmo: %d\n", algorithm);
    printf("Arquivo de Entrada: %s\n", argv[2]);
    printf("Arquivo de Saida: %s\n", argv[3]);



    int32_t *array = loadArray(length, argv[2]); // load array
    int32_t *Tmp = (int32_t*) malloc(length * sizeof(int32_t)); // Aloca temporario para o uso do mergesort
   
    /* gettimeofday: utilizada para obter o tempo de execução de cada algoritmo*/
    switch (algorithm) {
        case 1:
            gettimeofday(&tv1, NULL);
                bubbleSort(array, length);
            gettimeofday(&tv2, NULL);
            
            saveFile(array, length, argv[3]);
            break;  

        case 2:
            gettimeofday(&tv1, NULL);
                enhance_bubbleSort(array, length);
            gettimeofday(&tv2, NULL);

            saveFile(array, length, argv[3]);
            break;

        case 3:
            gettimeofday(&tv1, NULL);
                insertionSort(array, length);
            gettimeofday(&tv2, NULL);

            saveFile(array, length, argv[3]);
            break;

        case 4:
            gettimeofday(&tv1, NULL);
                mergeSort(array,Tmp, 0, length - 1);
            gettimeofday(&tv2, NULL);

            saveFile(array, length, argv[3]);
            break;

        case 5:
            gettimeofday(&tv1, NULL);
                quickSort(array,0, length - 1, 3);
            gettimeofday(&tv2, NULL);

            saveFile(array, length, argv[3]);
            break;

        case 6:
            gettimeofday(&tv1, NULL);
                quickSort(array,0, length - 1, 1);
            gettimeofday(&tv2, NULL);

            saveFile(array, length, argv[3]);
            break;

        case 7:
            gettimeofday(&tv1, NULL);
                quickSort(array,0, length - 1, 2);
            gettimeofday(&tv2, NULL);

            saveFile(array, length, argv[3]);
            break;

        case 8:
            gettimeofday(&tv1, NULL);
                heapSort(array, length - 1);
            gettimeofday(&tv2, NULL);

            saveFile(array, length, argv[3]);
            break;

        default:
            printf("\nVocê escolheu uma opção invalida\n\n");
            exit(-2);
    }

    /* Liberando alocação */
    free(array);
    free(Tmp);
    
    /* Faz o calculo do tempo gasto do algoritmo*/
    time_spent = (double) ((double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec)) * 1000;
    printf("\n\nTempo de execução do algoritmo em [Milisegundos]: %.3lf\n\n", time_spent);

    return 0;
}