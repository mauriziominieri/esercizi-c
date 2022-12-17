//
//  main.c
//  Esercizio-002
//
//  Created by Maurizio Minieri on 02/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende in input da linea di comando 9 interi e li inserisce in una matrice 3x3.
 2) Calcola la traccia della matrice (prodotto degli elementi sulla diagonale).
 3) Sottrae il valore minimo a tutti gli elementi nella matrice.
 Input e Output
 Input: 5 7 6 2 3 4 8 9 7
 La matrice è:
 5 7 6
 2 3 4
 8 9 7
 La traccia della matrice è: 105
 Il minimo è 2 e la nuova matrice è:
 3 5 4
 0 1 2
 6 7 5
 */

#include <stdio.h>
#include <stdlib.h>

const int n=3;
const int m=3;

int main(int argc, const char * argv[]) {
    
    if(argc!=10) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int M[n][m];
    int k=0,min;
    
    /*for(int i=0;i<n*m;i++) {
        M[i/n][i%m]=atoi(argv[i+1]);
    }*/
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            M[i][j] = atoi(argv[++k]);   //prende i numeri (stringhe) e li trasforma in interi
            if(i==0&&j==0)
                min=M[i][j];
            else if(M[i][j]<min)
                min=M[i][j];
        }
    }
    
    printf("La matrice è:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
    
    int traccia=1;
    for (int i = 0; i < 3; i++)
        traccia*=M[i][i];
    printf("La traccia della matrice e': %d\n",traccia);
    printf("La nuova matrice è:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ",M[i][j]-min);
        }
        printf("\n");
    }
   
    printf("\n");
    return 0;
}
