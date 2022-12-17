//
//  main.c
//  2020-09b
//
//  Created by Maurizio Minieri on 06/01/21.
//

/*
 Esercizio 2 Una matrice di interi n × n rappresenta le altezze (in numero di piani) dei grattacieli di un quartiere disposti in modo regolare lungo strade rettilinee che si incrociano perpendicolarmente.
 Guardando dal bordo del quartiere una riga o una colonna di grattacieli, sono visibili solo i grattacieli pi`u alti rispetto a tutti quelli pi`u vicini al punto di osservazione.
 Nella Figura 1 potete vedere un esempio di tale matrice, dove intorno alla matrice sono indicati i numeri dei grattacieli visibili da quel punto di osservazione (verso il basso nella riga in alto, verso l’alto nella riga in basso, verso destra nella colonna a sinistra e verso sinistra nella colonna a destra).
 Scrivere una funzione C di prototipo int** visibili(int** heights,int n) che prende in input una matrice heights di dimensione n×n contenente le altezze dei grattacieli del quartiere e restituisce un vettore di 4 vettori di lunghezza n (o se preferite, una matrice di dimensione 4 × n) contenenti il numero di grattaceli visibili dai bordi (nella figura, i vettori sarebbero le sequenze di numeri fuori dai bordi ingrossati della matrice).
 La matrice risultato va allocata all’interno della funzione heights.
 
    2 1 2 3 2
 
 2  2 5 3 1 4  2
 1  5 4 1 3 2  4
 2  4 3 5 2 1  3
 4  1 2 4 5 3  2
 3  3 1 2 4 5  1
 
    3 5 3 2 1
 */

#include <stdio.h>
#include <stdlib.h>

int** visibili(int** heights,int n);

int** visibili(int** heights,int n) {
    int** M;
    M=malloc(4*sizeof(int*));
    for(int i=0;i<4;i++)
        M[i]=malloc(n*sizeof(int));
    
    int conta,k;
    
    printf("\nANALIZZO (SINISTRA - DESTRA)\n");
    for(int z=0;z<n;z++) {
        conta=1;
        k=heights[z][0];
        printf("k preso in %d %d\n",z,0);
        for(int j=0;j<n-1;j++) {
            printf("k:%d < heights[%d][%d]:%d",k,z,j+1,heights[z][j+1]);
            if(k<heights[z][j+1]) {
                conta++;
                printf("    conta=%d",conta);
                k=heights[z][j+1];
            }
            printf("\n");
        }
        M[0][z] = conta;
        printf("M[%d][%d]:%d\n",0,z,M[0][z]);
        conta=1;
    }
    
    printf("\nANALIZZO (SOPRA - SOTTO)\n");
    for(int z=0;z<n;z++) {
        conta=1;
        k=heights[0][z];
        printf("k preso in %d %d\n",0,z);
        for(int j=0;j<n-1;j++) {
            printf("k:%d < heights[%d][%d]:%d",k,j+1,z,heights[j+1][z]);
            if(k<heights[j+1][z]) {
                conta++;
                printf("    conta=%d",conta);
                k=heights[j+1][z];
            }
            printf("\n");
        }
        M[1][z] = conta;
        printf("M[%d][%d]:%d\n",1,z,M[1][z]);
        conta=1;
    }
    
    printf("\nANALIZZO (DESTRA - SINISTRA)\n");
    for(int z=0;z<n;z++) {
        conta=1;
        k=heights[z][n-1];
        printf("k preso in %d %d\n",z,n-1);
        for(int j=n-2;j>=0;j--) {
            printf("k:%d < heights[%d][%d]:%d",k,z,j+1,heights[z][j+1]);
            if(k<heights[z][j]) {
                conta++;
                printf("    conta=%d",conta);
                k=heights[z][j];
            }
            printf("\n");
        }
        M[2][z] = conta;
        printf("M[%d][%d]:%d\n",2,z,M[2][z]);
        conta=1;
    }
    
    printf("\nANALIZZO (SOTTO - SOPRA)\n");
    for(int z=0;z<n;z++) {
        conta=1;
        k=heights[n-1][z];
        printf("k preso in %d %d\n",n-1,z);
        for(int j=n-2;j>=0;j--) {
            printf("k:%d < heights[%d][%d]:%d",k,j,z,heights[j][z]);
            if(k<heights[j][z]) {
                conta++;
                printf("    conta=%d",conta);
                k=heights[j][z];
            }
            printf("\n");
        }
        M[3][z] = conta;
        printf("M[%d][%d]:%d\n",3,z,M[3][z]);
        conta=1;
    }
        
    return M;
}

void stampa(int** M,int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            printf(" %d",M[i][j]);
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
    int n=5;
    int** M;
    
    M=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        M[i]=malloc(n*sizeof(int));
    
    M[0][0]=2; M[0][1]=5; M[0][2]=3; M[0][3]=1; M[0][4]=4;
    M[1][0]=5; M[1][1]=4; M[1][2]=1; M[1][3]=3; M[1][4]=2;
    M[2][0]=4; M[2][1]=3; M[2][2]=5; M[2][3]=2; M[2][4]=1;
    M[3][0]=1; M[3][1]=2; M[3][2]=4; M[3][3]=5; M[3][4]=3;
    M[4][0]=3; M[4][1]=1; M[4][2]=2; M[4][3]=4; M[4][4]=5;
    
    
    printf("*--- M ---*\n");
    stampa(M,n,n);
    
    int** R=visibili(M,n);
    printf("\n*--- R ---*\n");
    stampa(R,4,n);

    for(int i=0;i<n;i++)
        free(M[i]);
    free(M);
    
    for(int i=0;i<4;i++)
        free(R[i]);
    free(R);
    
    printf("\n");
    return 0;
}
