#include <stdlib.h>
#include <stdio.h>
#include "selection_sort.h"

void swap(unsigned int V[], int x, int y){
    int aux = V[x];
    V[x] = V[y];
    V[y] = aux;
}

void selection(unsigned int vet[], int tam){
    int i, j, menor;
    for(i=0; i < tam ; i++){
        menor = i;
        for(j = i; j < tam; j++ )
            if(vet[j] < vet[menor])
                menor =  j;
        swap(vet, menor, i);
    }   
}
