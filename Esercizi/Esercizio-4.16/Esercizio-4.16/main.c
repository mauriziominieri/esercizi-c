//
//  main.c
//  Esercizio-4.16
//
//  Created by Maurizio Minieri on 20/12/20.
//
/*
 Scrivere un programma in linguaggio C che calcoli e stampi i primi N numeri della serie di
 Fibonacci, con N inserito da tastiera. La serie di Fibonacci inizia con 1, 1 ed ogni numero
 successivo è dato dalla somma dei due precedenti: 1, 1, 2, 3, 5, 8, 13, 21 . . .
 */

#include <stdio.h>

//controlla che la variabile sia effettivamente int e > 0
void inserisci(int *x) {
    while (scanf("%d",x)!=1 || *x<=0) {
        printf("Riprova: ");
        while (getchar() != '\n');
    }
}

int main(int argc, const char * argv[]) {

    int N,n=1,prev1=1,prev2=1;
    char c=',';

    printf("Inserisci N(>0): ");
    inserisci(&N);
    printf("\n");
    for(int i=0;i<N;i++) {
        if(i>=2) {
            n = prev1 + prev2;
            prev2 = prev1;
            prev1 = n;
        }
        if(i==N-1)
            c=' ';
        printf("%d%c ",n,c);
    }
    
    printf("\n\n");
    return 0;
}
