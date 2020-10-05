/*
Alcides Gomes Beato Neto 						19060987
Henrique Sartori Siqueira 						19240472
Rafael Silva Barbon 							19243633
*/

#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"


void Merge(unsigned int vet[], int comeco, int meio, int fim){
	int i = comeco, j = meio+1, k = 0;
	unsigned int array[fim+1-comeco]; // vetor auxiliar que tem tamanho de dois subarrays

	while(i <= meio && j <= fim){ // Verifica o inicio dos subvetores (já ordenados) e realiza o merge ordenadamente
		if(vet[i] < vet[j])
			array[k++] = vet[i++]; // Só avança com oq foi manipulado
		else
			array[k++] = vet[j++]; // Só avança com oq foi manipulado
	}
	while(i <= meio)
		array[k++] = vet[i++]; // Só avança com oq foi manipulado
	while(j <= fim)
		array[k++] = vet[j++]; // Só avança com oq foi manipulado

	for(i = comeco, k = 0; i <= fim; i++,k++) // Transfere os valores do vetor auxiliar para o principal ordenadamente
		vet[i] = array[k];
}

void Merge_sort(unsigned int vet[], int comeco, int fim){
	if(comeco < fim){
		int meio = (comeco + fim) / 2;

		Merge_sort(vet, comeco, meio); // Primeira metade de subvetores
		Merge_sort(vet, meio+1, fim); // Segunda metade de subvetores
		Merge(vet, comeco, meio, fim); // Junção dos subvetores
	}
}
/*
int main(){
    unsigned int v[] = {3,67,31,90,1,44,654,89,21,20};
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    printf("\n\n");
    
    Merge_sort(v,0,9);
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    return 0;
}
*/
/*
[9,1,50,0,12,20,55,46]
[9,1,50,0] [12,20,55,46]
[9,1][50,0] [12,20][55,46]

[9][1][50][0][12][20][55][46]
[1,9][0,50][12,20][46,55]
[0,1,9,50][12,20,46,55]
[0,1,9,12,20,46,50,55]
*/