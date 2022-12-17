//
//  main.c
//  Esame_21-02-05
//
//  Created by Maurizio Minieri on 09/02/21.
//

#include <stdio.h>
#include <stdlib.h>

void stampa_a_scacchi(char** Mat,int M,int N) {
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0))
                printf("%c ",Mat[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
    if(argc != 3) {
        printf("Numero di parametri errato\n");
        return 1;
    }
    
    int M = atoi(argv[1]);  //righe //restituisce 0 se non può trasformarlo in intero
    int N = atoi(argv[2]);  //colonne
    
    if(M <= 0 || N <= 0) {
        printf("Parametri errati\n");
        return 1;
    }
    
    char** Mat = malloc(M * sizeof(char*));
    for(int i=0;i<M;i++)
        Mat[i] = malloc(N * sizeof(char));
    
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            Mat[i][j] = (65 + i + j);
    
    stampa_a_scacchi(Mat,M,N);
    
    for(int i=0;i<M;i++)
        free(Mat[i]);
    free(Mat);
    
    printf("\n");
    return 0;
}
