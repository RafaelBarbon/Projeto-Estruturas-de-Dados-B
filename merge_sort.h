/*
Alcides Gomes Beato Neto 						19060987
Henrique Sartori Siqueira 						19240472
Rafael Silva Barbon 							19243633
*/

#ifndef MERGE_SORT_H_ 
#define MERGE_SORT_H_

// Função que ordena e realiza o merge dos subvetores em um auxiliar e repassa para o vetor principal
void Merge(unsigned int vet[], int comeco, int meio, int fim);

// Função que realiza a divisão (determinação dos intervalos (recursão))
void Merge_sort(unsigned int vet[], int comeco, int fim);

#endif