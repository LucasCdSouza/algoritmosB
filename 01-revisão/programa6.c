#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int x, y;
    printf("digite um valor para x (entre -50 e 50)");
    scanf("%d", &x);
    printf("digite um valor para y (entre -50 e 50)");
    scanf("%d", &y);
    
    if (x > 0 && y > 0) {
        printf("Ponto no Primeiro Quadrante\n");
    }
    if (x < 0 && y > 0) {
        printf("Ponto no Segundo Quadrante\n");
    }
    if (x < 0 && y < 0) {
        printf("Ponto no Terceiro Quadrante\n");
    }
    if (x > 0 && y < 0) {
        printf("Ponto no Quarto Quadrante\n");
    }
    if (x == 0 && y > 0) {
        printf("Ponto de Origem em x e y positivo\n");
    }
    if (x == 0 && y < 0) {
        printf("Ponto de Origem em x e y negativo\n");
    }
    if (x > 0 && y == 0) {
        printf("Ponto de origem em y e x positivo\n");
    }
    if (x < 0 && y == 0) {
        printf("Ponto de origem em y e x negativo\n");
    }
    return 1;
}