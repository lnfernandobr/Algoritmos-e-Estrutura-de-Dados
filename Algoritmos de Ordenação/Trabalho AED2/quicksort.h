#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

unsigned int pivoFunction(int32_t start, int32_t end) {
    return end;
}

// gettimeofday(timeval, NULL);


void quicksort(int32_t *array, int32_t start, int32_t end) {
    int32_t aux, pivo, i, j, key;

    if((end - start) < 2) {
        if((end - start) == 1) {
            if(array[start] > array[end]) {
                aux = array[start];
                array[start] = array[end];
                array[end] = aux;
            }
        }
    } else {
        pivo = pivoFunction(start, end);
        
        aux = array[pivo];
        array[pivo] = array[end];
        array[end] = aux;

        i = start;
        j = end - 1;

        key = array[end];

        while (j >= i) {
            while (array[i] < key) i++;
            
            while (array[j] > key) i--;
            
            if(j >= 1) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                
                i++, j--;
            }
            
        }

        aux = array[i];
        array[i] = array[end];
        array[end] = aux;
        
        quicksort(array, start, i - 1);
        quicksort(array, i + 1, end);
    }
}
