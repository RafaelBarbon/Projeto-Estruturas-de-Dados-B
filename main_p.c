/*
Alcides Gomes Beato Neto 						19060987
Henrique Sartori Siqueira 						19240472
Rafael Silva Barbon 							19243633
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#define lim 4294967296 //Limite_do_unsigned_int

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
        v[i] = rand() % lim; // Caso médio (aleatório)
		//v[i] = i; // Melhor caso
		//v[i] = N - i; // Pior caso
}

// Função para teste (Impressão do vetor para verificação dos números aleatórios e ordenação)
void teste(unsigned int v[], int tam){
    for(int i = 0; i < tam; i++)
        printf(" %u", v[i]);  
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

// Função que calcula o tempo em ms
void calcular(struct timeval comeco, struct timeval fim, long int *mili){
	long int seg;
	seg = fim.tv_sec - comeco.tv_sec;
	seg *= 1000;
	*mili = fim.tv_usec - comeco.tv_usec; 
	*mili /= 1000;
	*mili += seg;
}

int main(){
    int N, i; /*cont = 0,*/ 
	long int mili; 
    unsigned int *array = NULL, *aux = NULL;//Vetor original e auxiliar 
	struct timeval start,end;
    srand(time(NULL));//Capta o horário para criação do número aletório

	printf("\n\tN\t\tSelectionsort\t\tInsertionsort\t\tMergesort\t\tQuicksort\t\tHeapsort");

    for(N = 10; N <= 1000000; N*=10){
        if(!cria(N, &array)){
            printf("\n\tErro de alocacao do vetor original de %d posicao.", N);
            exit(0);
        }
        if(!cria(N, &aux)){
            printf("\n\tErro de alocacao do vetor auxiliar de %d posicao.", N);
            exit(0);
        }
        gera_numeros(array, N); // atribui valores para o vetor principal
		printf("\n%7d",N);
		/*
        printf("\nVetor original:");
        teste(array, N);
		printf("\n\n\ti = %d\n",N);
		*/

        copia(array, aux, N); // copia os valores do vetor principal para o auxiliar
		gettimeofday(&start,NULL); // início
        selection(aux, N); // Para selection sort
		gettimeofday(&end,NULL); // fim
		calcular(start,end,&mili); // tempo execução = fim - início
        //resultados
		if(!check(aux,N))
			exit(0);
		printf("\t\t%10ld ms",mili);

		//!check(aux,N) ? printf("\n\tErro no selection sort.") : (printf("\n\tSelection sort OK."),cont++);

		/*
        printf("\n\nSelection:");
        teste(aux, N);
		*/

		
        copia(array, aux, N); // Recupera o valor original do vetor auxiliar
		gettimeofday(&start,NULL); // início
        insertion(aux, N); // Para insertion sort
		gettimeofday(&end,NULL); // fim
		calcular(start,end,&mili); // tempo execução = fim - início
        //resultados
		if(!check(aux,N))
			exit(0);
		printf("\t\t%10ld ms",mili);

		//!check(aux,N) ? printf("\n\tErro no insertion sort.") : (printf("\n\tInsertion sort OK."),cont++);
		

		/*
        printf("\n\nInsertion:");
        teste(aux, N);
		*/

		
        copia(array, aux, N); // Recupera o valor original do vetor auxiliar
		gettimeofday(&start,NULL); // início
        Merge_sort(aux, 0, N-1); // Para merge sort
		gettimeofday(&end,NULL); // fim
		calcular(start,end,&mili); // tempo execução = fim - início
        //resultados
		if(!check(aux,N))
			exit(0);
		printf("\t\t%10ld ms",mili);

		//!check(aux,N) ? printf("\n\tErro no merge sort.") : (printf("\n\tMerge sort OK."),cont++);
		

		/*
        printf("\n\nMerge:");
        teste(aux, N);
		*/

		
        copia(array, aux, N); // Recupera o valor original do vetor auxiliar
		gettimeofday(&start,NULL); // início
        quick_sort(aux, 0,N-1); // Para quick sort
		gettimeofday(&end,NULL); // fim
		calcular(start,end,&mili); // tempo execução = fim - início
        //resultados
		if(!check(aux,N))
			exit(0);
		printf("\t\t%10ld ms",mili);

		//!check(aux,N) ? printf("\n\tErro no quick sort.") : (printf("\n\tQuick sort OK."),cont++);
		

		/*
        printf("\n\nQuick:");        
        teste(aux, N);
		*/

		
        copia(array, aux, N); // Recupera o valor original do vetor auxiliar
		gettimeofday(&start,NULL); // início
        heap_sort(aux, N); // Para heap sort
		gettimeofday(&end,NULL); // fim
		calcular(start,end,&mili); // tempo execução = fim - início
        //resultados
		if(!check(aux,N))
			exit(0);
		printf("\t\t%10ld ms",mili);
        
		//!check(aux,N) ? printf("\n\tErro no heap sort.") : (printf("\n\tHeap sort OK."),cont++);
		

		/*
        printf("\n\nHeap:");
        teste(aux, N);
		*/
		/*
		if(cont == 30)
			printf("\nPrograma funcionando corretamente.\n");
        */

        free(array);
        free(aux);
        array = NULL;
        aux = NULL;
    }

    return 0;
}