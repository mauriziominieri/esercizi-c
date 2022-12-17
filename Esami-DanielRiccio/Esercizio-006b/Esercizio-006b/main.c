//
//  main.c
//  Esercizio-006b
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende due interi M ed N e alloca una matrice di char di M righe e N colonne
 2) Inserisce nella posizione i,j della matrice il carattere con codice ASCII (i+j)
 modulo 128 (Nota: i caratteri stampabili cominciano dal codice 32-spazio)
 3) stampa la matrice e poi la libera
 Input e Output
 Input: 8 8
 Output:
 La matrice di caratteri M è:
 ! " # $ % & '
 " $ & ( * , .
 # & ) , / 2 5
 $ ( , 0 4 8 <
 % * / 4 9 > C
 & , 2 8 > D J
 ' . 5 < C J Q
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
   
    if(argc!=3) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int M = atoi(argv[1]);
    int N = atoi(argv[2]);
    
    char **Mat = malloc(M*sizeof(char*));
    for(int i=0;i<M;i++)
        Mat[i] = malloc(N*sizeof(char));
    
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            Mat[i][j]=(i*j) % 128 +32;
    
    printf("La matrice di caratteri M è:\n");
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++)
            printf("%c ",Mat[i][j]);
        printf("\n");
    }
    
    for(int i=0;i<M;i++)
        free(Mat[i]);
    free(Mat);
    
    printf("\n");
    return 0;
}
