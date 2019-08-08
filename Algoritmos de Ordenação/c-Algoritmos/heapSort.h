
void arranjar(int32_t *L, int32_t n);
void descer(int32_t *heap, int32_t i, int32_t n);
void heapSort(int32_t *L, int32_t n);


void descer(int32_t *heap, int32_t i, int32_t n) {
    int32_t j = (2 * i);
    int32_t aux;

    if(j < n) {

        if(j < n) {
            if(heap[j + 1] > heap[j]) {
                j++;
            }
        }

        if(heap[i] < heap[j]) {
            aux = heap[i];
            heap[i] = heap[j];
            heap[j] = aux;
            descer(heap, j, n);
        }
    }

}


void arranjar(int32_t *L, int32_t n) {
    for (int32_t i = (n/2); i >= 0; i--) 
        descer(L, i, n);
}


void heapSort(int32_t *L, int32_t n) {
    
    int32_t m, aux;

    arranjar(L, n);
    
    m = n;

    while (m > 0) {
        aux = L[0];
        L[0] = L[m];
        L[m] = aux;

        m--;
        descer(L, 0, m) ;
    }
}
