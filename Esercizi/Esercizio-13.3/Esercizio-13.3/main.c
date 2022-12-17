//
//  main.c
//  Esercizio-13.3
//
//  Created by Maurizio Minieri on 17/01/21.
//

/*
Elemento di media massima
Si realizzi un programma in linguaggio C che, data una matrice NxM di interi, trovi l’elemento per cui la media degli elementi ad esso adiacenti sia massima. Si stampino le coordinate di tale elemento ed il suo valore.
Si considerino come adiacenti a ciascun elemento i quattro elementi nelle quattro direzioni cardinali. Si tratti inoltre l’ultima colonna come adiacente alla prima, e l’ultima riga come adiacente alla prima. Si supponga che N ed M possano variare tra 1 e 100. I valori di N ed M, così come i valori degli elementi della matrice, vengono acquisiti da tastiera.
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 3
#define M 4

void stampaMatrice(int mat[][M]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}

void mediaAdiacente(int mat[][M]) {
    int up,down,left,right,iMax=0,jMax=0;
    float media = 0.0,maxMedia = INT_MIN;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(i==0)
                up = mat[N-1][j];
            else
                up = mat[i-1][j];
            if(j==0)
                left = mat[i][M-1];
            else
                left = mat[i][j-1];
            if(i==N-1)
                down = mat[0][j];
            else
                down = mat[i+1][j];
            if(j==M-1)
                right = mat[i][0];
            else
                right = mat[i][j+1];
           
            media = (float)(up + down + left + right)/4;
            if(media>maxMedia) {
                iMax = i;
                jMax = j;
                maxMedia = media;
            }
        }
    }
    printf("\nL’elemento per cui la media degli elementi ad esso adiacenti è massima è in posizione (%d,%d): %g\n",iMax,jMax,maxMedia);
}

int main(int argc, const char * argv[]) {

    int mat[N][M] = {
        {100,2,3,4},
        {5,6,7,8},
        {9,10,13,12}
    };

    stampaMatrice(mat);
    mediaAdiacente(mat);
    
    printf("\n");
    return 0;
}
