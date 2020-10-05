/*
Alcides Gomes Beato Neto 						19060987
Henrique Sartori Siqueira 						19240472
Rafael Silva Barbon 							19243633
*/

#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"

void swap_quick(unsigned int V[], int x, int y){
    unsigned int aux = V[x]; // Realiza a troca entre os elementos
    V[x] = V[y];
    V[y] = aux;
} 

void quick_sort(unsigned int V[], int comeco, int fim){
    int pivo = V[(comeco + fim) / 2], i = comeco, j = fim;
    while(i <= j){ //while para percorrer todo o vetor
        while(V[i] < pivo && i < fim) // Caso o elemento da esquerda for maior que o pivo, ele não atualiza o valor
            i++;
        while(V[j] > pivo && j > comeco) // Caso o elemento da direita for menor que o pivo, ele não atualiza o valor
            j--;
		if(i <= j){ // Verifica se permanece no loop para poder fazer um swap
			swap_quick(V,i,j); // Realiza o swap e atualiza os valores das posições
			i++; 
			j--;
		}
	}
    if(i < fim) // Ordena o subvetor da esquerda
       	quick_sort(V, i, fim);
    if(j > comeco) // Ordena o subvetor da direita
       	quick_sort(V, comeco, j);    
}

/*
int main(){
    unsigned int v[] = {3,67,31,90,1,44,654,89,21,20};
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    printf("\n\n");
    
    quick_sort(v,0,9);
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    return 0;
}
*/
/*
[8,2,60,20,4]
[8,2,20,4,60]
[2,8,20,4,60]
[2,8,4,20,60]
[2,4,8,20,60]
*/
// esquerda = menor, direita = maior