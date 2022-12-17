//
//  main.c
//  Esercizio-16
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che calcoli e fornisca su standard output il prodotto dei primi 10
 numeri interi positivi (ovvero calcoli 10!).
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int fattoriale = 1;
    
    for(int i=2;i<=10;i++)
        fattoriale=fattoriale*i;
    
    printf("Il fattoriale di 10 è: %d",fattoriale);
    printf("\n\n");
    return 0;
}
