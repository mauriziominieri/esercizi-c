//
//  main.c
//  Esercizio-10
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che fornisca su standard output i quadrati dei primi 10 numeri interi positivi.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    for(int i=1;i<=10;i++)
        printf("Quadrato di %d: %d\n",i,i*i);
    
    printf("\n\n");
    return 0;
}
