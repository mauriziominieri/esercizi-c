//
//  main.c
//  Esercizio-9
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, preso da standard input un numero intero N, controlli che
 N ≥ 0 e in tal caso calcoli e fornisca su standard output tutti i quadrati perfetti da 0 ad N.
 Nota: Dato un numero a, il suo quadrato perfetto è a alla 2.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkIntero(float n) {
    int tmp=floor(n);
    if(tmp==n) return true;
    else return false;
}

void inserisciInteroMU0(float* x) {
    while(scanf("%f",x)!=1 || checkIntero(*x)==false || *x<0 ) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

int main(int argc, const char * argv[]) {
    
    float N;
    
    //do {
    printf("Inserisci un numero intero(>=0): ");
    inserisciInteroMU0(&N);
    //} while(N<0 && printf("N deve essere >= 0 \n"));
    
    printf("\n");
    for(int i=0;i<N;i++)
        printf("Quadrato perfetto di %d: %d\n",i,i*i);
    
    printf("\n");
    return 0;
}
