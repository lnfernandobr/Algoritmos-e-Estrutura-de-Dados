void Swapping(int32_t  *array, int32_t  i, int32_t  inc) {
    int32_t  aux;
    aux = array[i];
    array[i] = array[i + inc];
    array[i + inc] = aux;
}


void bubbleSort(int32_t *array, int32_t  n) {
  for (int32_t  i = 0 ; i < n - 1; i++)  {
    for (int32_t  j = 0 ; j < n - 1; j++) {
      if (array[j] > array[j + 1])
        Swapping(array, j, 1);
    }
  }
}