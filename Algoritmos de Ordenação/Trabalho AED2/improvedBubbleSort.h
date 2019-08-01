
void Swap(long *array, int i, int inc) {
    long aux;
    aux = array[i];
    array[i] = array[i + inc];
    array[i + inc] = aux;
}



void enhance_bubbleSort(long *array, long n) {
    int boolean = 1,
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