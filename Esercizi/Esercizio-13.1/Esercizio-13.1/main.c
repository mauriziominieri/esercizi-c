//
//  main.c
//  Esercizio-13.1
//
//  Created by Maurizio Minieri on 16/01/21.
//

/*
 Elementi negativi
 Data una matrice di dimensione uguale a 10 righe per 10 colonne contenente elementi
 reali, scrivere un programma in linguaggio C per individuare se esistono righe o colonne
 composte solo da elementi negativi.
 */

#include <stdio.h>
#include <stdlib.h>

void check(float M[][10]) {
    int j;
    for(int i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            if(M[i][j]>=0)
                break;
        }
        if(j==10)
            printf("riga %d con solo elementi negativi\n",i);
    }
    
    for(int i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            if(M[j][i]>=0)
                break;
        }
        if(j==10)
            printf("colonna %d con solo elementi negativi\n",i);
    }
}

int main(int argc, const char * argv[]) {
  
    float M[10][10] = {
        {-11,-55,-9,-1,-31,-21,-1,-1,-11,-1},
        {1,1,1,-1,1,1,1,1,1,1},
        {21,1,1,-1,1,1,1,1,1,1},
        {-1,1,1,-1,1,1,1,1,1,-10},
        {1,1,1,-1,1,1,1,1,1,1},
        {1,1,1,-1,1,1,1,1,1,1},
        {1,1,1,-1,1,1,1,1,1,1},
        {1,1,1,-1,1,1,1,1,1,1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {1,1,1,-1,1,1,1,1,1,1},
    };
    
    check(M);
    
    printf("\n");
    return 0;
}
