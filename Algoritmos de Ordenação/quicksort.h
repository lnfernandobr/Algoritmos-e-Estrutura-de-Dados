#include <stdio.h>

void quickSort(int32_t *L, int32_t ini, int32_t fim);
void pivo(int32_t ini, int32_t fim, int32_t *mediana, unsigned int tipo);



void pivo(int32_t ini, int32_t fim, int32_t *mediana, unsigned int tipo) {
        if(tipo == 1) {
            *mediana = fim;
        }

        *mediana = fim;
}

void quickSort(int32_t *L, int32_t ini, int32_t fim) {

    int32_t aux;
//    int32_t mediana;
    if((fim - ini) < 2) {
        if((fim - ini) == 1) {
            if(L[ini] > L[fim]) {
                aux = L[ini];
                L[ini] = L[fim];
                L[fim] = aux;
            }
        }
    } else {
//        pivo(ini, fim, &mediana, 1);
//        aux = L[fim];
//        L[fim] = L[fim];
//        L[fim] = aux;

        int32_t i = ini;
        int32_t j = fim - 1;

        int32_t key = L[fim];

        while (j > i) {

            while (L[i] < key) {
                i++;
            }

            while (L[j] > key && j >= ini) {
                j--;
            }


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

        quickSort(L, ini, i - 1);
        quickSort(L, i + 1, fim);

    }
}