#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"


void swap_quick(unsigned int V[], int x, int y){
    unsigned int aux = V[x];
    V[x] = V[y];
    V[y] = aux;
} 

void quick (unsigned int V[], int comeco, int fim){
    int pivo=(comeco+fim)/2;
    int i=comeco,j=fim;
    while(i<j) { //while para percorrer todo o vetor
        while(V[i]<V[pivo] && i<j) {
            i++;}
        while(V[j]<V[pivo] && j<i) {
            j--;}
        swap_quick(V,i,j);
        i++; j--;
    }
    if(i<fim){
        quick(V,i,fim);
    }
    if(j>comeco){
        quick(V,comeco,j);
    }
}


int main(){
    
    return 0;
}

/*
[8,2,60,20,4]
[8,2,20,4,60]
[2,8,20,4,60]
[2,8,4,20,60]
[2,4,8,20,60]
*/
// esquerda = menor, direita = maior