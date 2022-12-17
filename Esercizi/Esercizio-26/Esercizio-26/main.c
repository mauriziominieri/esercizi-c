//
//  main.c
//  Esercizio-26
//
//  Created by Maurizio Minieri on 12/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che legga da standard input una sequenza di n interi e che verifichi
 se gli elementi acquisiti sono tutti uguali tra loro.
 */

#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    
    int n=5;
    int A[n];
    bool flag = true;
    
    for(int i=0;i<n;i++) {
        printf("Inserisci A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    
    printf("\nSTAMPA ARRAY\n");
    for(int i=0;i<n;i++) {
        printf("[%d]",A[i]);
    }
    
    int primo = A[0];
    for(int i=1;i<n;i++) {
        if(primo != A[i]) {
            flag = false;
            break;
        }
    }
    
    if(flag==true)
        printf("\n\nTutti uguali");
    else
        printf("\n\nNon tutti uguali");
    
    printf("\n\n");
    return 0;
}
