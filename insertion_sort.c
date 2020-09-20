#include <stdlib.h>
#include <stdio.h>
#include "insertion_sort.h"

void swap_insertion(unsigned int V[], int x, int y){
    unsigned int aux = V[x];
    V[x] = V[y];
    V[y] = aux;
}

void insertion_sort (unsigned int V[], int tam){
    int i, auxp;
    for (i = 1; i < tam; i++){//Inicia na posição 1, já que a comparação será entre auxp e v[auxp-1]
        auxp = i;// Percorrer o vetor para as posições enteriores de i
        while(V[auxp -1] > V[auxp] && auxp > 0){ //Fazendo o shift dos valores com trocas sucessivas enquanto o de v[auxp] for maior que v[auxp - 1] e auxp > 0 evitando acessos em posições inexistentes 
            swap_insertion(V, auxp-1, auxp);
            auxp--;//Vai p posição anterior de auxp
        }
    }
}
