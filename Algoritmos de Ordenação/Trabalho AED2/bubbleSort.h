void Swapping(long *array, int i, int inc) {
    long aux;
    aux = array[i];
    array[i] = array[i + inc];
    array[i + inc] = aux;
}


void bubbleSort(long *array, long n) {
  for (int i = 0 ; i < n - 1; i++)  {
    for (int j = 0 ; j < n - 1; j++) {
      if (array[j] > array[j + 1]) 
        Swapping(array, j, 1);
    }
  }
}