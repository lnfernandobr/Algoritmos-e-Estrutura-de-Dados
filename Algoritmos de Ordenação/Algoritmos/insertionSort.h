#include <stdint.h>

void insertionSort(int32_t *array, int32_t n) {
    int32_t value, j;
    
    for(int32_t i = 1; i < n; ++i) {

        value = array[i],
        j = i - 1;

        while(j >= 0 && value < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
    
        array[j + 1] = value;
    }

}
