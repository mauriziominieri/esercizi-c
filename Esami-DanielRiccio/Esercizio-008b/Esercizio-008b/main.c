//
//  main.c
//  Esercizio-008b
//
//  Created by Maurizio Minieri on 05/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando un valore intero dispari H
 2) Implementa la funzione char **GeneraTriangolo(int H) che alloca una matrice M di
 dimensione HxH e inserisce al suo interno il carattere * disegnando la forma di un
 triangolo di altezza H/2+1 (vedi Output)
 Input e Output
 Input: 7
 Output:
       *
     *   *
   *       *
 * * * * * * *
 
 
 
 */

#include <stdio.h>
#include <stdlib.h>

char **GeneraTriangolo(int H) {
    char **M = NULL;
    M=malloc(H*sizeof(char*));
    for(int i=0;i<H;i++)
        M[i] = malloc(H*sizeof(char));
    
    for(int i=0;i<H;i++)
        for(int j=0;j<H;j++)
            M[i][j]=' ';
    
    for(int i=0;i<H/2;i++)
        M[i][H/2-i] = M[i][H/2+i] = '*';
    
    for(int i=0;i<H;i++)
        M[H/2][i] = '*';
    
    return M;
}

int main(int argc, const char * argv[]) {
   
    if(argc!=2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    int H = atoi(argv[1]);
    if(H%2==0) {
        printf("Numero H non dispari\n");
        return 1;
    }
    
    char** M=GeneraTriangolo(H);
    for(int i=0;i<H;i++) {
        for(int j=0;j<H;j++) {
            printf("%c ",M[i][j]);
        }
        printf("\n");
    }
           
    for(int i=0;i<H;i++)
        free(M[i]);
    free(M);
    
    printf("\n");
    return 0;
}
