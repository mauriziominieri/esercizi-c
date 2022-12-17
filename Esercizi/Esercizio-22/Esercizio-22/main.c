//
//  main.c
//  Esercizio-22
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presi da standard input tre numeri reali a, b e c, risolva
 l’equazione di secondo grado
 ax2 + bx + c = 0.
 Nota: Si identifichino tutti i casi particolari (a = 0, ∆ ≤ 0,...) e si stampino gli opportuni messaggi informativi.
 */

#include <stdio.h>
#include <math.h>

void inserisci(float* x) {
    while(scanf("%f",x)!=1) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

int main(int argc, const char * argv[]) {
    
    float a,b,c;
    
    printf("Inserisci il numero reale a: ");
    inserisci(&a);
    printf("Inserisci il numero reale b: ");
    inserisci(&b);
    printf("Inserisci il termine noto c: ");
    inserisci(&c);
    
    printf("\nEQUAZIONE: %.2fx^2 %.2fx %.2f = 0",a,b,c);
    float delta = (b*b)-4*(a*c);
    float x1,x2;
    
    if(a==0&&b!=0) {
        printf("\nSi tratta di un'equazione di primo grado");
        x1 = -(c/b);
        printf("\nx = %f",x1);
    }
    else if(a==0&&b==0)
        printf("\nSi tratta di un'equazione senza incognita");
    else {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        if(b==0&&c==0)
            printf("\nSi tratta di un'equazione di secondo grado monomia");
        else if(b==0)
            printf("\nSi tratta di un'equazione di secondo grado pura");
        else if(c==0)
            printf("\nSi tratta di un'equazione di secondo grado spuria");
        else
            printf("\nSi tratta di un'equazione di secondo grado completa");
        
        if(delta>0) {
            printf("\nIl discriminante è positivo, l'equazione fornisce due soluzioni reali e distinte");
            printf("\nx1 = %f\n",x1);
            printf("x2 = %f",x2);
        }
        else if(delta==0) {
            printf("\nIl discriminante è 0, l'equazione fornisce due soluzioni reali e coincidenti");
            printf("\nx1 = x2 = %f",x1);
        }
        else
            printf("\nIl discriminante è negativo, l'equazione fornisce due soluzioni non reali");
    }
  
    printf("\n\n");
    return 0;
}
