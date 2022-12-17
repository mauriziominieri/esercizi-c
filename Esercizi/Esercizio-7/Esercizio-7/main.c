//
//  main.c
//  Esercizio-7
//
//  Created by Maurizio Minieri on 09/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presi da standard input due numeri interi, determini se i due
 numeri sono uguali o se uno sia maggiore dell’altro e fornisca su standard output il messaggio “I due numeri
 sono uguali” nel primo caso, mentre nel secondo caso, il maggiore tra i due numeri.
 */

#include <stdio.h>

void inserisci(int* x) {
    while(scanf("%d",x)!=1) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

int main(int argc, const char * argv[]) {
    
    int a,b;
    
    printf("Inserisci il primo numero: ");
    inserisci(&a);
    printf("Inserisci il secondo numero: ");
    inserisci(&b);
    
    printf("\n");
    if(a==b) printf("I due numeri sono uguali");
    else if (a>b) printf("Il maggiore è a: %d",a);
    else printf("Il maggiore è b: %d",b);
    
    printf("\n\n");
    return 0;
}
