//
//  main.c
//  Esercizio-25
//
//  Created by Maurizio Minieri on 12/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che legga da standard input una sequenza di n interi ed un intero
 N e che controlli se N è presente nella sequenza, fornendo su standard output la risposta.
 */

#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
   
    int n=5,N=42;
    bool trovato=false;
    
    //SENZA ARRAY
    /*int x;
    
    for(int i=0;i<n;i++) {
        printf("Inserisci il %d° numero: ",i+1);
        scanf("%d",&x);
        if(x==N)
            trovato = true;
    }
    */
    
    //CON ARRAY
    int A[n];
    
    for(int i=0;i<n;i++) {
        printf("Inserisci A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    
    printf("\nSTAMPA ARRAY\n");
    for(int i=0;i<n;i++) {
        printf("[%d]",A[i]);
    }
    
    printf("\n");
    
    for(int i=0;i<n;i++) {
        if(A[i]==N) {
            trovato = true;
            break;
        }
    }
    
    if(trovato==true)
        printf("\n%d è presente nella sequenza",N);
    else
        printf("\n%d NON è presente nella sequenza",N);
    
    printf("\n\n");
    return 0;
}
