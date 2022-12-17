//
//  main.c
//  Esercizio-2
//
//  Created by Maurizio Minieri on 09/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presi da standard input due numeri reali a e b, determini
 1. se b è un numero nonnegativo (≥ 0) o negativo;
 2. se a è un numero compreso fra 0 e 100;
 3. se a e b hanno lo stesso segno.
 L’algoritmo deve fornire su standard output le informazioni elaborate.
 */

#include <stdio.h>

//controlla che la variabile sia effettivamente double
void inserisci(double *x) {
    while (scanf("%lf",x)!=1)
    {
        printf("Riprova: ");
        while (getchar() != '\n');
    }
}

int main(int argc, const char * argv[]) {
    
    double a,b;
    
    printf("Inserisci il primo numero (a): ");
    inserisci(&a);
    printf("Inserisci il secondo numero (b): ");
    inserisci(&b);
    
    printf("\n");
    if(b >= 0) printf("b:%lf e' positivo",b);
    else printf("b:%lf e' negativo",b);
    
    printf("\n");
    if(a>=0 && a<=100) printf("a:%lf e' un numero compreso fra 0 e 100",a);
    else printf("a:%lf NON e' un numero compreso fra 0 e 100",a);
    
    printf("\n");
    if( (a>=0 && b>=0) || (a<0 && b<0) )
        printf("a:%lf e b:%lf hanno lo stesso segno",a,b);
    else
        printf("a:%lf e b:%lf NON hanno lo stesso segno",a,b);
    
    printf("\n\n");
    return 0;
}
