/*
Alcides Gomes Beato Neto 						19060987
Henrique Sartori Siqueira 						19240472
Rafael Silva Barbon 							19243633
*/

#ifndef HEAP_SORT_H_ 
#define HEAP_SORT_H_

//Realiza a troca entre as posição do vetor 
void swap_heap(unsigned int v[], int x, int y);

//Função responsável pela ordenação 
void heap_sort(unsigned int v[], int tam);

//Função reponsável pela flutuação do maior elemento 
void flutua(unsigned int v[], int i, int tam);

#endif