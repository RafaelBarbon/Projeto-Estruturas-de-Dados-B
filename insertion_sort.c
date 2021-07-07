/*
Alcides Gomes Beato Neto 						19060987
Henrique Sartori Siqueira 						19240472
Rafael Silva Barbon 							19243633
*/

#include <stdlib.h>
#include <stdio.h>
#include "insertion_sort.h"

void swap_insertion(unsigned int V[], int x, int y){
    unsigned int aux = V[x];
    V[x] = V[y];
    V[y] = aux;
}

void insertion(unsigned int V[], int tam){
    int i, auxp;
    for (i = 1; i < tam; i++){//Inicia na posição 1, já que a comparação será entre auxp e v[auxp-1]
        auxp = i;// Percorrer o vetor para as posições enteriores de i
        while(V[auxp -1] > V[auxp] && auxp > 0){ //Fazendo o shift dos valores com trocas sucessivas enquanto o de v[auxp] for maior que v[auxp - 1] e auxp > 0 evitando acessos em posições inexistentes
            swap_insertion(V, auxp-1, auxp);
            auxp--;//Vai p posição anterior de auxp
        }
    }
}
/*
int main(){
    unsigned int v[] = {3,67,31,90,1,44,654,89,21,20};

    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);

    printf("\n\n");

    insertion(v,10);

    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);

    return 0;
}
*/
/*
[8,2,60,20,4]
[2,8,60,20,4]
[2,8,60,20,4]
[2,8,20,60,4]
[2,4,8,20,60]
*/