//
//  main.c
//  Esercizio-13.5
//
//  Created by Maurizio Minieri on 17/01/21.
//

/*
 Stampa matrice a spirale
 Si scriva un programma in linguaggio C che, data una matrice quadrata NxN, stampi gli elementi di tale matrice secondo un ordinamento a spirale, partendo dalla cornice più esterna e procedendo verso l’interno.
 */

#include <stdio.h>
#include <stdlib.h>

#define N 5

void stampaMatrice(int mat[][N]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}

void stampaSpirale(int mat[][N]) {
   
    int a=0;
    printf("\nSPIRALE\n");
    while(a<N/2) {
        for(int i=a;i<N-1-a;i++)
            printf("%d ",mat[a][i]);
        for(int i=a;i<N-1-a;i++)
            printf("%d ",mat[i][N-1-a]);
        for(int i=N-1-a;i>a;i--)
            printf("%d ",mat[N-1-a][i]);
        for(int i=N-1-a;i>a;i--)
            printf("%d ",mat[i][a]);
        a++;
    }
    
    if(N%2!=0)
        printf("%d ",mat[N/2][N/2]);
}

int main(int argc, const char * argv[]) {
    
    int mat[N][N] = {
        {1,2,3,4,6},
        {6,7,8,9,1},
        {2,3,4,5,2},
        {7,8,9,1,3},
        {0,0,9,1,1}
    };

    stampaMatrice(mat);
    stampaSpirale(mat);
    
    printf("\n");
    return 0;
}
