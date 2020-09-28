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

bool cria(int N, unsigned int **P){//Recebe tamanho para alocação e a variavel de alocação do vetor criado 
    (*P) = (unsigned int *)malloc(N * sizeof(unsigned int));
    if(!(*P))//Verifica se a alocação foi realizada com sucesso
        return false;
    return true;
}

void gera_numeros(unsigned int v[], int N){
    for(int i = 0; i < N; i++)
        v[i] = rand()%lim; //Gera número aleatório de zero ao limite máx de unsigned int 
}

//Função para teste (Impressão do vetor para verificação dos números aleatórios e ordenação)
void teste(unsigned int v[], int tam){
    for(int i = 0; i < tam; i++)
        printf(" %d", v[i]);  
}

void copia(unsigned int *original, unsigned int *aux, int tam){
     for(int i = 0; i < tam; i++)
        aux[i] = original[i]; 
}

int main(){
    int N, i; 
    unsigned int *array = NULL, *aux = NULL;//Vetor original e auxiliar 
    srand(time(NULL));//Capta o horário para criação do número aletório
    for(N = 10; N < 1000; N*=10){
        if(!cria(N, &array)){
            printf("\n\tErro de alocação do vetor original de %d posicao.", N);
            exit(0);
        }
        if(!cria(N, &aux)){
            printf("\n\tErro de alocação do vetor auxiliar de %d posicao.", N);
            exit(0);
        }
        gera_numeros(array, N);

        printf("\nVetor original:");
        teste(aux, N);
        
        copia(array, aux, N);
        selection(aux, N);
        //resultados

        printf("\nSelection:");
        teste(aux, N);

        copia(array, aux, N);//Recupera o valor original
        insertion(array, N);
        //resultados

        printf("\nInsertion:");
        teste(array, N);

        copia(array, aux, N);
        Merge_sort(array, 0, N-1);
        //resultados

        printf("Merge:");
        teste(array, N);

        copia(array, aux, N);
        quick_sort(array, 0,N-1);
        //resultados

        printf("\nQuick:");        
        teste(array, N);

        copia(array, aux, N);
        heap_sort(array, N);
        //resultados
        
        printf("\nHeap:");
        teste(array, N);
        
        free(array);
        free(aux);
        array = NULL;
        aux = NULL;
    }

    return 0;
}