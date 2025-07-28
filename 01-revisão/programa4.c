#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define TAM 10

int main (){
    int vetor[TAM];

    srand(time(NULL));
    for (int i = 0; i < TAM; i++){
        vetor[i]= rand()% 100;
        printf("%d\t", vetor[i]);
    }
    printf("\n");
    return 1;
}