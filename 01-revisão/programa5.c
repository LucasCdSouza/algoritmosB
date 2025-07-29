#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define TAM 10

int main (){
    int vetor[TAM];
    srand(time(NULL));
    int numero;
    int posicaoDoUltimoNumeroIserido = 0;
    int jaInserido;
    for (int i = 0; i < TAM; i++){
        numero = rand()% 100;
        jaInserido = 0;
        for (int j = 0; j <= posicaoDoUltimoNumeroIserido; j++){
            if (numero == vetor [j]){
                jaInserido=1;
                printf("numero repetido gerado..\n");
                break;    
            }
        } 
        if(!jaInserido){
            vetor[posicaoDoUltimoNumeroIserido] = numero;
            posicaoDoUltimoNumeroIserido++;
        }
    }

    for (int i = 0; i < posicaoDoUltimoNumeroIserido; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
    return 1;
}