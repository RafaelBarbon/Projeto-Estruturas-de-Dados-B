/*
Alcides Gomes Beato Neto 						19060987
Henrique Sartori Siqueira 						19240472
Rafael Silva Barbon 							19243633
*/

#include <stdlib.h>
#include <stdio.h>
#include "selection_sort.h"

void swap_selection(unsigned int V[], int x, int y){
    unsigned int aux = V[x];
    V[x] = V[y];
    V[y] = aux;
}

void selection(unsigned int vet[], int tam){
    int i, j, menor;
    for(i=0; i < tam; i++){
        menor = i;
        for(j = i; j < tam; j++ )
            if(vet[j] < vet[menor])
                menor = j;
        swap_selection(vet, menor, i);
    }
}

/*
int main(){
    unsigned int v[] = {3,67,31,90,1,44,654,89,21,20};

    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);

    printf("\n\n");

    selection(v,10);

    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);

    return 0;
}
*/
