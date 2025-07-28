#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int numeroSorteado = rand()%100;
    printf("%d\n", numeroSorteado);
    return 1;
}