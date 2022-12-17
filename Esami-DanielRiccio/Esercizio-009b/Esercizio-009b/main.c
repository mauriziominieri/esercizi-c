//
//  main.c
//  Esercizio-009b
//
//  Created by Maurizio Minieri on 06/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando un elenco di valori interi
 2) Implementa la funzione int elimina_repliche(int A[], int B[], int nA) che copia nel vettore B i valori contenuti in A, una ed una sola volta e restituisce il numero di elementi copiati in B.
 3) Stampa a video i valori contenuti in B.
 Input e Output
 Input: 1 3 2 1 5 3 2 7 5 1 5
 I 5 valori in A senza repliche sono:
 1 3 2 5 7
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int elimina_repliche(int A[], int B[], int nA) {
    
    int nB=0,j=0;
    
    for(int i=0;i<nA;i++) {
        for(j=0;j<nB;j++)
            if(A[i]==B[j])
                break;
        if(j==nB)
            B[nB++]=A[i];
    }
    return nB;
}

int main(int argc, const char * argv[]) {
    
    if(argc<2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int n = argc-1;
    int A[n],B[n];
    for(int i=0;i<n;i++)
        A[i]=atoi(argv[i+1]);
    
    int nB=elimina_repliche(A,B,n);
    printf("I %d valori in A senza repliche sono:\n",nB);
    for(int i=0;i<nB;i++)
        printf("%d ",B[i]);
   
    printf("\n");
    return 0;
}
