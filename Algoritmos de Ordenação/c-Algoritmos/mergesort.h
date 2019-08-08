#include <stdint.h>


void intercala(int32_t L[], int32_t tmp[], int32_t ini1, int32_t ini2, int32_t fim2) {

    int32_t fim1 = ini2 - 1,
            ind = ini1,
            aux = ini1;

	while(ini1 <= fim1 && ini2 <= fim2) {
        tmp[ind] = L[ini1] < L[ini2] ? L[ini1++] : L[ini2++];
        ind++;
	}

	while(ini1 <= fim1)
		tmp[ind++] = L[ini1++];


	while(ini2 <= fim2)
		tmp[ind++] = L[ini2++];


    for (int32_t i = aux; i <= fim2; i++)
        L[i] = tmp[i];

}

void mergeSort(int32_t *L, int32_t *Tmp,  int32_t esq, int32_t dir) {

    int32_t centro;

    if(esq < dir) {

        centro = (esq + dir) / 2;

        mergeSort(L, Tmp, esq, centro);
        mergeSort(L, Tmp, centro + 1, dir);

        intercala(L, Tmp, esq, centro + 1, dir);
    }
}

