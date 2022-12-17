//
//  main.c
//  Esercizio-13.4
//
//  Created by Maurizio Minieri on 17/01/21.
//

/*
 Sottomatrici a somma nulla
 Si scriva un programma in linguaggio C in grado di determinare se in una matrice NxM acquisita da tastiera vi sono sottomatrici quadrate in cui la somma degli elementi è nulla.
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

void stampaMatrice(int mat[][M]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}

void submatrix1(int mat[][M],int x,int y) {
    int a=2,i=0,j=0,somma=0;
    while(a<=(N-x) && a<=(M-y)) {
        for(i=0;i<a;i++) {
            for(j=0;j<a;j++)
                somma+=mat[x+i][y+j];
        }
        if(somma==0) {
            printf("\nSottomatrice %dx%d trovata\n",a,a);
            for(i=0;i<a;i++) {
                for(j=0;j<a;j++)
                    printf("%d ",mat[x+i][y+j]);
                printf("\n");
            }
        }
        somma=0;
        a++;
    }
}

void submatrix(int mat[][M]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(i<=(N-i) && j<=(M-j))
                submatrix1(mat,i,j);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int mat[N][M] = {
        {50,-50,50,4},
        {3,-3,3,88},
        {9,-9,-53,12}
    };
    
    stampaMatrice(mat);
    submatrix(mat);
    
    printf("\n");
    return 0;
}
