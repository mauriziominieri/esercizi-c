//
//  main.c
//  Esercizio-8
//
//  Created by Maurizio Minieri on 09/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presi da standard input due numeri interi a e b, calcoli e
 fornisca su standard output
 1. a alla b;
 2. a × 10 alla b;
 3. a + 10 alla b;
 */

#include <stdio.h>

void inserisci(int* x) {
    while(scanf("%d",x)!=1) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

void inserisciMagg0(int* x) {
    while(scanf("%d",x)!=1 || *x<=0) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

int main(int argc, const char * argv[]) {
    
    int a,b;
    
    printf("Inserisci il primo numero: ");
    inserisci(&a);
    
    printf("Inserisci il secondo numero(>0): ");
    inserisciMagg0(&b);
 
    int r1 = 1,r2 = 1;
    
    for(int i=0;i<b;i++) {
        r1 = r1 * a;
        r2 = r2 * 10;  //10 alla b
    }
    
    printf("\na:%d alla b:%d = %d\n",a,b,r1);
    printf("a:%d * 10 alla b:%d = %d\n",a,b,a*r2);
    printf("a:%d + 10 alla b:%d = %d",a,b,a+r2);
    printf("\n\n");
    return 0;
}
