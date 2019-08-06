
void goDown(int *heap, int i, int n) {
    int j = (2 * i);
    int aux;

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
            goDown(heap, j, n);
        }
    }

}



void heapSort(int *vet, int n) {
    int i, tmp;

    for (i = (n / 2); i >= 0; i--) {
        goDown(vet, i, n - 1);
    }

    int m = n - 1;

    while (m >= 1) {

        tmp = vet[0];
        vet[0] = vet[m];
        vet[m] = tmp;

        goDown(vet, 0, m-1);

        m--;
    }
}
