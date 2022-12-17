//
//  main.c
//  Esercizio-012c
//
//  Created by Maurizio Minieri on 07/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando 16 valori e li inserisce in una matrice M di dimensioni 4x4.
 2) Implementa la funzione void mat_swap_row_col(int M[4][4], int i, int j, int rc), che per rc==0 scambia la riga i con la riga j, per rc==1 scambia la colonna i con la colonna j.
 3) Stampa a video la matrice prima e dopo lo scambio.
 Input e Output
 Input: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 La matrice inserita è:
 1  2  3  4
 5  6  7  8
 9  10 11 12
 13 14 15 16
 Vuoi scambiare righe (0) o colonne (1): 1
 Inserisci gli indici (i,j) da scambiare: 0 3
 La nuova matrice è:
 4  2  3  1
 8  6  7  5
 12 10 11 9
 16 14 15 13
 */

#include <stdio.h>
#include <stdlib.h>

void mat_swap_row_col(int M[4][4], int i, int j, int rc) {
    int tmp;
    if(rc==0) {
        for(int z=0;z<4;z++) {
            tmp = M[i][z];
            M[i][z] = M[j][z];
            M[j][z] = tmp;
        }
    }
    else {
        for(int z=0;z<4;z++) {
            tmp = M[z][i];
            M[z][i] = M[z][j];
            M[z][j] = tmp;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    if(argc!=17) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int M[4][4];
    int k=0;
    
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            M[i][j]=atoi(argv[++k]);
    
    printf("La matrice inserita è:\n");
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
    
    int rc,i,j;
    printf("Vuoi scambiare righe (0) o colonne (1): ");
    do {
        scanf("%d",&rc);
    } while(rc!=0 && rc!=1 && printf("Riprova: "));
    
    printf("Inserisci gli indici (i,j) da scambiare: ");
    do {
        scanf("%d %d",&i,&j);
    } while((i<0 || i>4 || j<0 || j>4 || i==j) && printf("Riprova: "));
    
    mat_swap_row_col(M,i,j,rc);
    
    printf("La nuova matrice è:\n");
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
    
    printf("\n");
    return 0;
}
