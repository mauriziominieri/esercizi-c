//
//  main.c
//  Esercizio-29
//
//  Created by Maurizio Minieri on 13/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, lette da standard input una sequenza di n interi ordinati in
 senso non decrescente ed una sequenza di m interi ordinati in senso non decrescente, fornisca su standard output
 una sequenza che sia fusione delle due sequenze in input ed i cui elementi siano ordinati in senso non decrescente.
 Esempio:
 Input: 1 5 5 13 22 e 1 2 5 15 44 88.
 Output: 1 1 2 5 5 5 13 15 22 44 88.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n,m;
    
    do{
        printf("Inserisci n: ");
        scanf("%d",&n);
    }
    while(n<1 && printf("Errore, deve essere un numero > 0\n"));
    
    do{
        printf("Inserisci m: ");
        scanf("%d",&m);
    }
    while(n<1 && printf("Errore, deve essere un numero > 0\n"));
    
    int A[n],B[m];
    
    printf("\nInserimento prima sequenza\n");
    printf("Inserisci il %d° intero: ",1);
    scanf("%d",&A[0]);
    int prev = A[0];
    
    for(int i=1;i<n;i++) {
        do {
            printf("Inserisci il %d° intero: ",i+1);
            scanf("%d",&A[i]);
        }
        while(A[i]<prev && printf("Errore, devi inserire un numero >= del precedente\n"));
        
        prev = A[i];
    }
    
    printf("\nInserimento seconda sequenza\n");
    printf("Inserisci il %d° intero: ",1);
    scanf("%d",&B[0]);
    prev = B[0];
    
    for(int i=1;i<m;i++) {
        do {
            printf("Inserisci il %d° intero: ",i+1);
            scanf("%d",&B[i]);
        }
        while(B[i]<prev && printf("Errore, devi inserire un numero >= del precedente\n"));
        
        prev = B[i];
    }
    
    printf("\nSTAMPA prima sequenza\n");
    for(int i=0;i<n;i++) {
        printf("[%d]",A[i]);
    }
    
    printf("\nSTAMPA seconda sequenza\n");
    for(int i=0;i<m;i++) {
        printf("[%d]",B[i]);
    }
    
    int k=0,z = n + m;
    int C[z];
    
    for(int i=0,j=0;i<n||j<m;) {
        if(i>=n) {
            C[k] = B[j];
            j++;
        }
        else if(j>=m) {
            C[k] = A[i];
            i++;
        }
        else if(A[i]<B[j]) {
            C[k] = A[i];
            i++;
        }
        else {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    
    printf("\nSTAMPA terza sequenza\n");
    for(int i=0;i<z;i++) {
        printf("[%d]",C[i]);
    }
    
    printf("\n\n");
    return 0;
}
