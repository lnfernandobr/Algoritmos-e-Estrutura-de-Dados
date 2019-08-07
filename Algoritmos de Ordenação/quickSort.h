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

void MedianaDe3(int32_t L[], int32_t ini,int32_t fim, int32_t *med) {
	int meio;
	meio = (fim + ini) / 2;
	int32_t v[3] = { L[ini], L[meio], L[fim] };

	insertionSort(v, 3);

	if(v[1] == L[ini]) 
		*med = ini;
	else {
		if(v[1] == L[meio]) 
			*med = meio;
		else
			*med = fim;
	}
}

/*QuickSort*/
void quickSort(int32_t L[], int32_t ini, int32_t fim, int32_t tipo) {
	int32_t key, i, j, pivo, aux;

	if((fim - ini) < 2) {
		if((fim - ini) == 1) {
			if(L[ini] > L[fim]) {
				aux = L[ini];
				L[ini] = L[fim];
				L[fim] = aux;
			}
		}
	}

	else {	

		if(tipo == 1) {
			pivo = ini + (rand() % (fim-ini));
			aux = L[pivo];
			L[pivo] = L[fim];
			L[fim] = aux;
		}

		if(tipo == 2) {
			MedianaDe3(L, ini, fim, &pivo);
			aux = L[pivo];
			L[pivo] = L[fim];
			L[fim] = aux;
		}

		
		i = ini;
		j = fim - 1;
		key = L[fim];

		while(j >= i) {
			while(L[i] < key)
				i++;

			while(L[j] > key && j >= 0)
				j--;

			if(j > i) {
				aux = L[i];
				L[i] = L[j];
				L[j] = aux;

				i++;
				j--;
			}
		}

		aux = L[i];
		L[i] = L[fim];
		L[fim] = aux;
		
		quickSort(L, ini, i - 1, tipo);
		quickSort(L, i + 1, fim, tipo);
	}
}

