#include <stdint.h>

void intercala  (int v[],int aux[],int ini1, int ini2,int fim2) {
    int in1=ini1,in2=ini2,fim1=in2-1,au=0,i;
    while(in1<=fim1 && in2<=fim2)
    {
        if (v[in1]<v[in2])
        {
            aux[au++] = v[in1++];
        }
        else
        {
            aux[au++] = v[in2++];
        }
    }
    while(in1<=fim1)
    {
        aux[au++] = v[in1++];
    }
    while(in2<=fim2)
    {
        aux[au++] = v[in2++];
    }

    for(i=0;i<au;i++){
        v[i+ini1]=aux[i];}
}




void merge_sort(int32_t *a, int32_t *Tmp,  int32_t i, int32_t j) {

    int32_t mid;

    if(i < j) {
        mid = (i + j) / 2;
        merge_sort(a, Tmp, i, mid);
        merge_sort(a, Tmp, mid + 1, j);
        intercala(a, Tmp, i, mid + 1, j);
    }
}

