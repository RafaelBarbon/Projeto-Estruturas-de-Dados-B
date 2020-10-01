#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

void swap_heap(unsigned int v[], int x, int y){
	unsigned aux = v[x];
	v[x] = v[y];
	v[y] = aux;
}

void heap_sort(unsigned int v[], int tam){
	int meio = (tam/2)-1, i;
	for(i=meio; i >= 0; i--)//Reorganização para a raiz possuir o maior elemento 
		flutua(v, i, tam);
	
	for(i = tam-1; i > 0; i--){
		swap_heap(v, 0, i);//Troca a raiz com  ultima folha do vetor(árvore) (i)
		flutua(v, 0, i);//Vai da raiz(posição 0) ate i
	}
}

void flutua(unsigned int v[], int i, int tam){
	int maior = i;
	if(i < tam){ //Parada da recursão 
		if(((i*2) + 2) < tam && v[(i*2) + 2] > v[maior] ){//Confere com o filho da direita
			maior = (i*2) + 2;//Acesso do filho da direita
		}
		if((i*2+1) < tam && v[(i*2) + 1] > v[maior]){//Confere com o filho da esquerda
			maior = i*2+1;//Acesso do filho da esquerda
		}
		if(maior!= i){//Se for igual não chama recursão, pois ja esta na posição correta
			swap_heap(v, maior, i);
			flutua(v, maior,tam);
		}
	}
}

/*
int main(){
    //unsigned int v[] = {3,67,31,90,1,44,654,89,21,20};
	unsigned int v[] = {65,20,25,68,32,24,21,24,98,80}; // teste realizado apos o make file
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    printf("\n\n");
    
    heap_sort(v,10);
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    return 0;
}
*/
/*
				3
		67					31
	90			1		44		654
89		21	20
*/