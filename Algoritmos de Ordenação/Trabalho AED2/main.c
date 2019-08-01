#include "improvedBubbleSort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include "insertionSort.h"

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

    }    

}

int32_t sizeFile(long int value, char order) {
    FILE *fp;
    int len;
    char *url = switchValue(value, order);
    fp = fopen(url, "r");

    if( fp == NULL )  {
        perror ("Error opening file");
        return -1;
    }
  
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    
    printf("Tamanho do arquivo: %d\n", (int32_t) (len / sizeof(int32_t)));
    fclose(fp);
    return (int32_t)(len / sizeof(int32_t));
}



void saveFile(int32_t value, char type, int32_t *array, int32_t lenght) {
    
    const char *url_save = switchValue(value, type);
    FILE *file_save;
    
    file_save = fopen(url_save, "wb");
    if(file_save == NULL) {
        perror("Erro, não foi possivel abrir o arquivo para salvar\n");
        exit -1;
    }
    
    fwrite(array, 1, lenght, file_save);
    fclose(file_save);
}

int32_t* loadArray(int32_t len) {
    const char *url = "Files/10000/10000.a";
    FILE *file;
    
    file = fopen(url, "r");
    if(file == NULL) {
        perror("Erro na abertura do arquivo");
        exit -1;
    }
    

    int32_t *vetor = malloc(len * sizeof(int32_t));

    fseek(file, 0, SEEK_SET);
    fread(vetor, len * sizeof(int32_t), 1, file);
    fclose(file);

    return vetor;
}
int main(void) {

    

    int32_t lenght = sizeFile(100000000, 'a');
    

    int32_t *array = loadArray(lenght); // Carrega array
    insertionSort(array, 100000000); // Ordena
    saveFile(100000000, 'a', array, lenght * sizeof(int32_t)); // Salva array
    
    return 0;
}