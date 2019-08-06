#include <stdint.h>

void Swap(int32_t *array, int32_t i, int32_t inc) {
    int32_t aux;
    aux = array[i];
    array[i] = array[i + inc];
    array[i + inc] = aux;
}



void enhance_bubbleSort(int32_t *array, int32_t n) {
    int32_t boolean = 1,
        nFlag = n,
        guard = n, 
        j;
    
    while(boolean) {
        j = 0;
        boolean = 0;
    
        while(j < nFlag - 1) {
            if(array[j] > array[j + 1]) {
                Swap(array, j, 1);
                boolean = 1;
                guard = j;
            }
            j++;
        }  
        nFlag = guard + 1;
    }
}