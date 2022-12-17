//
//  main.c
//  Esercizio-18
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che fornisca su standard output
 1. in ordine decrescente tutti i numeri interi compresi tra 0 e 9;
 2. in ordine crescente tutti i numeri pari compresi tra -10 e 10.
 3. in ordine decrescente tutti i numeri pari compresi tra 1 e 10.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    for(int i=9;i>=0;i--)
        printf("%d ",i);
    printf("\n");
    for(int i=-10;i<=10;i++)
        if(i%2==0)
            printf("%d ",i);
    printf("\n");
    for(int i=10;i>=1;i--)
        if(i%2==0)
            printf("%d ",i);
    
    printf("\n\n");
    return 0;
}
