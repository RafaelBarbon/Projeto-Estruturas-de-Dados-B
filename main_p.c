#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#define lim 4294967295 //Limite_do_unsigned_int

// Função de alocação
bool cria(int N, unsigned int **P){//Recebe tamanho para alocação e a variavel de alocação do vetor criado 
    (*P) = (unsigned int *)malloc(N * sizeof(unsigned int));
    if(!(*P))//Verifica se a alocação foi realizada com sucesso
        return false;
    return true;
}

// Função que gera número aleatório de zero ao limite máx de unsigned int 
void gera_numeros(unsigned int v[], int N){
    for(int i = 0; i < N; i++)
        v[i] = rand()%lim; 
}

// Função para teste (Impressão do vetor para verificação dos números aleatórios e ordenação)
void teste(unsigned int v[], int tam){
    for(int i = 0; i < tam; i++)
        printf(" %d", v[i]);  
}

// Função que copia para o vetor auxiliar
void copia(unsigned int *original, unsigned int *aux, int tam){
     for(int i = 0; i < tam; i++)
        aux[i] = original[i]; 
}

// Função que chega se o vetor encontra-se ordenado
bool check(unsigned int v[], int tam){
	for(int i = 0; i < tam-1; i++){
		if(v[i] > v[i+1])
			return false;
	}
	return true;
}

int main(){
    int N, i, cont = 0; 
    unsigned int *array = NULL, *aux = NULL;//Vetor original e auxiliar 
    srand(time(NULL));//Capta o horário para criação do número aletório
    for(N = 10; N <= 1000000; N*=10){
        if(!cria(N, &array)){
            printf("\n\tErro de alocação do vetor original de %d posicao.", N);
            exit(0);
        }
        if(!cria(N, &aux)){
            printf("\n\tErro de alocação do vetor auxiliar de %d posicao.", N);
            exit(0);
        }
        gera_numeros(array, N);

		/*
        printf("\nVetor original:");
        teste(array, N);
		*/
        
		printf("\n\n\ti = %d\n",N);

        copia(array, aux, N);
        selection(aux, N);
        //resultados
		!check(aux,N) ? printf("\n\tErro no selection sort.") : (printf("\n\tSelection sort OK."),cont++);

		/*
        printf("\n\nSelection:");
        teste(aux, N);
		*/

		
        copia(array, aux, N);//Recupera o valor original
        insertion(aux, N);
        //resultados

		!check(aux,N) ? printf("\n\tErro no insertion sort.") : (printf("\n\tInsertion sort OK."),cont++);
		

		/*
        printf("\n\nInsertion:");
        teste(aux, N);
		*/

		
        copia(array, aux, N);
        Merge_sort(aux, 0, N-1);
        //resultados

		!check(aux,N) ? printf("\n\tErro no merge sort.") : (printf("\n\tMerge sort OK."),cont++);
		

		/*
        printf("\n\nMerge:");
        teste(aux, N);
		*/

		
        copia(array, aux, N);
        quick_sort(aux, 0,N-1);
        //resultados

		!check(aux,N) ? printf("\n\tErro no quick sort.") : (printf("\n\tQuick sort OK."),cont++);
		

		/*
        printf("\n\nQuick:");        
        teste(aux, N);
		*/

		
        copia(array, aux, N);
        heap_sort(aux, N);
        //resultados
        
		!check(aux,N) ? printf("\n\tErro no heap sort.") : (printf("\n\tHeap sort OK."),cont++);
		

		/*
        printf("\n\nHeap:");
        teste(aux, N);
		*/

		if(cont == 30)
			printf("\nPrograma funcionando corretamente.\n");
        
        free(array);
        free(aux);
        array = NULL;
        aux = NULL;
    }

    return 0;
}