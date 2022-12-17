//
//  main.c
//  Esercizio-27
//
//  Created by Maurizio Minieri on 12/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che legga da standard input una sequenza di n interi e che verifichi
 se gli elementi acquisiti sono ordinati in senso non decrescente.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n;
    
    do {
        printf("Inserisci la dimensione dell'array: ");
        scanf("%d",&n);
    }
    while(n<1 && printf("Errore, deve essere un numero > 0\n"));
    
    int A[n];
    
    for(int i=0;i<n;i++) {
        printf("Inserisci A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    
    printf("\nSTAMPA ARRAY\n");
    for(int i=0;i<n;i++) {
        printf("[%d]",A[i]);
    }
    
    int curr = A[0];
    int crescente = 1,decrescente = 1;
    
    for(int i=1;i<n;i++) {
        if(curr < A[i])
            crescente++;
        else if(curr > A[i])
            decrescente++;
        
        curr = A[i];
    }
    
    printf("\n\n");
    
    if(decrescente == n)
        printf("L'array è ordinato in senso decrescente");
    else
        printf("L'array è ordinato in senso NON decrescente");
    
    /*if(decrescente == n)
        printf("L'array è ordinato in senso decrescente");
    else if(crescente == n)
        printf("L'array è ordinato in senso crescente");
    else
        printf("L'array non è ordinato");*/
    
    printf("\n\n");
    return 0;
}
