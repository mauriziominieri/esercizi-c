//
//  main.c
//  Esercizio-12
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presa da standard input una sequenza di numeri interi terminata da un numero negativo, calcoli la media aritmetica dei numeri non negativi letti, e fornisca su standard output
 il risultato.
 Il programma deve controllare anche che la sequenza non sia vuota, nel qual caso deve informare l’utente con
 opportuno messaggio in output.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkIntero(float x) {
    int tmp = floor(x);
    if(tmp==x) return true;
    else return false;
}

int inserisciIntero(float* x) {
    while(scanf("%f",x)!=1 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}

int main(int argc, const char * argv[]) {
    
    float tmp;
    int n,conta=0,somma=0;
    
    printf("Inserisci una sequenza di numeri interi terminata da un numero negativo\n");
    do {
        n=inserisciIntero(&tmp);
        if(n>=0) {
            somma = somma + n;
            conta++;
        }
    }
    while(n>=0);
    
    if(conta==0)
        printf("Sequenza vuota");
    else {
        float media = (float)somma/conta;
        printf("La media è: %f",media);
    }
    
    printf("\n\n");
    return 0;
}
