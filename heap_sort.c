#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

void swap_heap(unsigned int v[], int x, int y){
	unsigned aux = v[x];
	v[x] = v[y];
	v[y] = aux;
}

void heap_sort(unsigned int v[], int i, int tam){
	int menor = i;

	if(i < tam){
		if(v[i*2] < v[menor] && (i*2) < tam){
			menor = i*2;
			
		}
		if(v[i*2+1] < v[menor] && (i*2+1) < tam){
			menor = i*2+1;
			
		}
		if(menor != i)
			swap_heap(v, menor, i);
		heap_sort(v,i*2+1,tam);
		heap_sort(v,i*2,tam);
	}
}

int main(){
    int v[] = {3,67,31,90,1,44,654,89,21,20};
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    printf("\n\n");
    
    heap_sort(v,0,10);
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    return 0;
}

/*
				3
		67					31
	90			1		44		654
89		21	20
*/