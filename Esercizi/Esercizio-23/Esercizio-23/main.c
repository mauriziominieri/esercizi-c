//
//  main.c
//  Esercizio-23
//
//  Created by Maurizio Minieri on 11/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presa da standard input una sequenza di n interi, fornisca su
 standard output il valore minimo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

bool checkIntero(float x) {
    int tmp=floor(x);
    if(tmp==x) return true;
    else return false;
}

int inserisciInteroM0(float* x) {
    while(scanf("%f",x)!=1 || *x<=0 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
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
    int n,x;
    int min,null=1;
    
    printf("Inserisci un numero intero n(>0): ");
    n=inserisciInteroM0(&tmp);
    
    for(int i=0;i<n;i++) {
        printf("Inserisci il %d° numero intero: ",i+1);
        x=inserisciIntero(&tmp);
        
        if(null==1) {
            min = x;
            null = 0;
        }
        else if(x<min)
            min = x;
    }
    
    printf("\nIl valore minimo è: %d",min);
    
    printf("\n\n");
    return 0;
}
