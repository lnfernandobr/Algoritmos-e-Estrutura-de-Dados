#include "Algoritmos/improvedBubbleSort.h"
#include "Algoritmos/bubbleSort.h"
#include "Algoritmos/insertionSort.h"
#include "Algoritmos/heapSort.h"
#include "Algoritmos/mergesort.h"

#include "quicksort.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <sys/time.h>


char *switchValue(int32_t value, char order) {

    switch (value) {
        case 10:
            if(order == 'c')
                return "Files/10/10.c";
            if(order == 'd')
                return "Files/10/10.d";
            if(order == 'a')
                return "Files/10/10.a";

            if(order == 'C')
                return "Orders/10/order-10.c.out";
            if(order == 'D')
                return "Orders/10/order-10.d.out";
            if(order == 'A')
                return "Orders/10/order-10.a.out";

        case 100:
            if(order == 'c')
                return "Files/100/100.c";
            if(order == 'd')
                return "Files/100/100.d";
            if(order == 'a')
                return "Files/100/100.a";

            if(order == 'C')
                return "Orders/100/order-100.c.out";
            if(order == 'D')
                return "Orders/100/order-100.d.out";
            if(order == 'A')
                return "Orders/100/order-100.a.out";

        case 1000:
            if(order == 'c')
                return "Files/1000/1000.c";
            if(order == 'd')
                return "Files/1000/1000.d";
            if(order == 'a')
                return "Files/1000/1000.a";

            if(order == 'C')
                return "Orders/1000/order-1000.c.out";
            if(order == 'D')
                return "Orders/1000/order-1000.d.out";
            if(order == 'A')
                return "Orders/1000/order-1000.a.out";

        case 10000:
            if(order == 'c')
                return "Files/10000/10000.c";
            if(order == 'd')
                return "Files/10000/10000.d";
            if(order == 'a')
                return "Files/10000/10000.a";

            if(order == 'C')
                return "Orders/10000/order-10000.c.out";
            if(order == 'D')
                return "Orders/10000/order-10000.d.out";
            if(order == 'A')
                return "Orders/10000/order-10000.a.out";

        case 100000:
            if(order == 'c')
                return "Files/100000/100000.c";
            if(order == 'd')
                return "Files/100000/100000.d";
            if(order == 'a')
                return "Files/100000/100000.a";

            if(order == 'C')
                return "Orders/100000/order-100000.c.out";
            if(order == 'D')
                return "Orders/100000/order-100000.d.out";
            if(order == 'A')
                return "Orders/100000/order-100000.a.out";


        case 500000:
            if(order == 'c')
                return "Files/500000/500000.c";
            if(order == 'd')
                return "Files/500000/500000.d";
            if(order == 'a')
                return "Files/500000/500000.a";

            if(order == 'C')
                return "Orders/500000/order-500000.c.out";
            if(order == 'D')
                return "Orders/500000/order-500000.d.out";
            if(order == 'A')
                return "Orders/500000/order-500000.a.out";


        case 1000000:
            if(order == 'c')
                return "Files/1000000/1000000.c";
            if(order == 'd')
                return "Files/1000000/1000000.d";
            if(order == 'a')
                return "Files/1000000/1000000.a";

            if(order == 'C')
                return "Orders/1000000/order-1000000.c.out";
            if(order == 'D')
                return "Orders/1000000/order-1000000.d.out";
            if(order == 'A')
                return "Orders/1000000/order-1000000.a.out";


        case 10000000:
            if(order == 'c')
                return "Files/10000000/10000000.c";
            if(order == 'd')
                return "Files/10000000/10000000.d";
            if(order == 'a')
                return "Files/10000000/10000000.a";

            if(order == 'C')
                return "Orders/10000000/order-10000000.c.out";
            if(order == 'D')
                return "Orders/10000000/order-10000000.d.out";
            if(order == 'A')
                return "Orders/10000000/order-10000000.a.out";




        case 100000000:
            if(order == 'c')
                return "Files/100000000/100000000.c";
            if(order == 'd')
                return "Files/100000000/100000000.d";
            if(order == 'a')
                return "Files/100000000/100000000.a";

            if(order == 'C')
                return "Orders/100000000/order-100000000.c.out";
            if(order == 'D')
                return "Orders/100000000/order-100000000.d.out";
            if(order == 'A')
                return "Orders/100000000/order-100000000.a.out";

        default:
            return NULL;

    }

}

int32_t sizeFile(int32_t value, char order) {
    FILE *fp;
    int len;
    char *url = switchValue(value, order);


    printf("Arquivo aberto para calcular tamanho: %s\n", url);
    fp = fopen(url, "r");

    if( fp == NULL )  {
        perror ("Error opening file");
        return (-1);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);

    printf("Tamanho do arquivo aberto: %d\n", (int32_t) (len / sizeof(int32_t)));
    fclose(fp);
    return (int32_t)(len / sizeof(int32_t));
}

void saveFile(int32_t value, char type, int32_t *array, int32_t lenght) {

    const char *url_save = switchValue(value, type);

    printf("Salvando arquivo em: %s\n", url_save);

    FILE *file_save;

    file_save = fopen(url_save, "wb");
    if(file_save == NULL) {
        perror("Erro, não foi possivel abrir o arquivo para salvar\n");
        exit (-1);
    }

    fwrite(array, 1, lenght, file_save);
    fclose(file_save);
}

int32_t* loadArray(int32_t len, const int32_t value, char order) {

    char *url = switchValue(value, order);

    printf("Arquivo aberto para carregamento: %s\n",url);

    FILE *file;

    file = fopen(url, "r");
    if(file == NULL) {
        perror("Erro na abertura do arquivo");
        exit (-1);
    }


    int32_t *vetor = malloc(len * sizeof(int32_t));

    fseek(file, 0, SEEK_SET);
    fread(vetor, len * sizeof(int32_t), 1, file);
    fclose(file);

    return vetor;
}

void saveTime(int32_t value, int type, int alg,  double time) {
    char message[100];


    snprintf(message, 100, "%c %d %.3lf\n", type, value, time);

    FILE *file_save = NULL;

    switch (alg) {
        case 1:
            file_save = fopen("Orders/insertionSort", "a");
            break;

        case 2:
            file_save = fopen("Orders/bubbleSort", "a");
            break;

        case 3:
            file_save = fopen("Orders/enhance_bubbleSort", "a");
            break;

        case 4:
            file_save = fopen("Orders/heapSort", "a");
            break;

        case 5:
            file_save = fopen("Orders/merge", "a");
            break;

        case 6:
            file_save = fopen("Orders/quickSort", "a");
            break;



        default:
            printf("Passou parametro errado na função saveTime, arquivo não foi salvo!\n");
            return;

    }



    if(file_save == NULL) {
        perror("Erro Em salvar tempo\n");
        exit (-1);
    }

    fprintf(file_save, "%s", message);


    fclose(file_save);
}


int main(void) {


    struct timeval  tv1, tv2;
    char TYPES[3] = {'a', 'd', 'c'};
    char TYPES_SAVE[3] = {'A', 'D', 'C'};
    double time_spent;
    int32_t numbers[9] = {10, 100, 1000, 10000, 100000, 500000, 1000000, 10000000, 100000000};
    int32_t length;
    int32_t *array, *Tmp;

//    int vetor[10] = {10,9,8,7,6,5,4, 3, 2, 1};
//    int len = 10;

//    length = sizeFile(500000, 'd');
//    array = loadArray(length, 500000, 'd'); // load array

//    printf("[NÃO] Ordenado: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", array[i]);
//    } printf("\n");

//    quickSort(array, 0, length-1);




// gcc main.c  -fsplit-stack -o ordena
//
    length = sizeFile(500000, 'd');
    array = loadArray(length, 500000, 'd'); // load array
    Tmp = (int32_t*) malloc(length * sizeof(int32_t));


    gettimeofday(&tv1, NULL);
//        merge_sort(array, Tmp, 0, length - 1);
        quickSort(array, 0, length-1);
    gettimeofday(&tv2, NULL);
//    printf("Ordenado: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", array[i]);
//    } printf("\n");


    time_spent = (double) ((double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec)) * 1000;

//    saveFile(500000, 'D', array, length * sizeof(int32_t)); // Salva array
    printf("Será salvo o valor de %d com tipo %c e tempo de execução: %lf\n",500000, 'D', time_spent);
//    saveTime(500000, 'D', 5, time_spent);

//    free(array);
//    free(Tmp);
//
//    printf("\n\n\n");

//
//     for (int i = 0; i < 6; ++i) {
//         printf("quickSort: \n");
//        for (int j = 0; j < 3; ++j) {
//
//            length = sizeFile(numbers[i], TYPES[j]);
//            array = loadArray(length, numbers[i], TYPES[j]); // load array
//
//            gettimeofday(&tv1, NULL);
//                quickSort(array, 0, length-1);
//            gettimeofday(&tv2, NULL);
//
//            time_spent = (double) ((double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec)) * 1000;
//
//            saveFile(numbers[i], TYPES_SAVE[j], array, length * sizeof(int32_t)); // Salva array
//            printf("Será salvo o valor de %d com tipo %c e tempo de execução: %lf\n", numbers[i], TYPES_SAVE[j], time_spent);
//            saveTime(numbers[i], TYPES_SAVE[j], 6, time_spent);
//            free(array);
//            printf("\n\n\n");
//        }
//     }

    return 0;

}