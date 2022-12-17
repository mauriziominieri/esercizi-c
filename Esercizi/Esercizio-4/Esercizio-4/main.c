//
//  main.c
//  Esercizio-4
//
//  Created by Maurizio Minieri on 09/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presi da standard input tre numeri interi x, y e z, calcoli e
 fornisca in output la loro media aritmetica.
 */

#include <stdio.h>

//controlla che la variabile sia effettivamente int
void inserisci(int *x) {
    while (scanf("%d",x)!=1) {
        printf("Riprova: ");
        while (getchar() != '\n');
    }
}

int main(int argc, const char * argv[]) {
    
    int x,y,z;
    
    printf("Inserisci il primo numero: ");
    inserisci(&x);
    printf("Inserisci il secondo numero: ");
    inserisci(&y);
    printf("Inserisci il terzo numero: ");
    inserisci(&z);
    
    printf("\nLa media tra %d, %d e %d e': %.2f",x,y,z,(float)(x+y+z)/3);
    
    printf("\n\n");
    return 0;
}
