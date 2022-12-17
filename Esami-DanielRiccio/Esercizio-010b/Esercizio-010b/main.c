//
//  main.c
//  Esercizio-010b
//
//  Created by Maurizio Minieri on 06/01/21.
//

/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando un elenco di 18 valori interi
 2) Implementa la funzione void mat_prod(int A[3][3], int B[3][3], int C[3][3]) che prende in input tre matrici A, B e C di dimensioni 3x3 e memorizza in C il prodotto riga per colonna di A e B.
 3) Implementa la funzione void stampa_matrice(int M[3][3], char Nome[]) che prende in input una matrice M ed il suo nome come stringa e stampa a video la matrice
 Input e Output
 Input: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
 La matrice A è:
 1 2 3
 4 5 6
 7 8 9

 La matrice B è:
 10 11 12
 13 14 15
 16 17 18

 La matrice C è:
 84 90 96
 201 216 231
 318 342 366
 */

#include <stdio.h>
#include <stdlib.h>

void mat_prod(int A[3][3], int B[3][3], int C[3][3]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            C[i][j]=0;
            for(int k=0;k<3;k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void stampa_matrice(int M[3][3], char Nome[]) {
    printf("La matrice %s e':\n",Nome);
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
    if(argc!=19) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int A[3][3],B[3][3],C[3][3];
    int k=1;
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) {
            A[i][j] = atoi(argv[k]);
            B[i][j] = atoi(argv[k+9]);
            k++;
        }
    
    mat_prod(A, B, C);
    
    stampa_matrice(A, "A");
    stampa_matrice(B, "B");
    stampa_matrice(C, "C");
    
    printf("\n");
    return 0;
}
