//
//  main.c
//  Esercizio-13.2
//
//  Created by Maurizio Minieri on 16/01/21.
//

/*
 Ricerca sottomatrice
 Date due matrici A e B acquisite da tastiera, scrivere un programma in linguaggio C per determinare se una di esse è sottomatrice dell’altra. Le dimensioni delle matrici devono anch’esse essere acquisite da tastiera.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** creaMatrice(int n,int m) {
    int** M=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        M[i]=calloc(m,sizeof(int));
    return M;
}

void stampaMatrice(int** M,int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
}

bool isSubmatrix1(int** M1,int** M2,int n,int m,int x,int y) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(M2[i][j]!=M1[x+i][y+j]) {
                return false;
            }
        }
    }
    return true;
}

int isSubmatrix(int** M1,int** M2,int n1,int m1,int n2,int m2) {
    int conta=0;
    for(int i=0;i<n1;i++) {
        for(int j=0;j<m1;j++) {
            if(j<=(m1-m2) && i<=(n1-n2))
                if(isSubmatrix1(M1,M2,n2,m2,i,j))
                    conta++;
        }
    }
    return conta;
}

int main(int argc, const char * argv[]) {
    
    int** M1,**M2;
    int n1=3,m1=4,n2=2,m2=1;
    M1=creaMatrice(n1,m1);
    M2=creaMatrice(n2,m2);
    
    M1[0][0] = 3;M1[0][1] = 1;M1[0][2] = 2;M1[0][3] = 1;
    M1[1][0] = 8;M1[1][1] = 9;M1[1][2] = 1;M1[1][3] = 1;
    M1[2][0] = 1;M1[2][1] = 1;M1[2][2] = 2;M1[2][3] = 2;
    
    M2[0][0] = 1;
    M2[1][0] = 2;
    
    printf("M1\n");
    stampaMatrice(M1,n1,m1);
    printf("\nM2\n");
    stampaMatrice(M2,n2,m2);
    
    printf("\nTrovata la matrice M2 %d volte in M1\n",isSubmatrix(M1,M2,n1,m1,n2,m2));
    
    printf("\n");
    return 0;
}
