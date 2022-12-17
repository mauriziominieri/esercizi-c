//
//  main.c
//  Esercizio-014
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando 9 interi e li inserisce in una matrice M di dimensioni 3x3
 2) Calcola la media dei valori inseriti in input;
 3) Pone a 1 tutte le posizioni in M il cui valore è maggiore della media e a 0
 quelle, il cui valore è minore della media
 Chiede in input un carattere c e stampa a video una matrice di caratteri dove è
 presente il carattere c se il corrispondente valore in M è 1 e uno spazio altrimenti.
 Input e Output
 Input: 12 1 15 5 10 3 11 0 9
 La matrice binaria è:
 1 0 1
 0 1 0
 1 0 1
 Inserisci un carattere: A
 La matrice di caratteri è:
 A A
  A
 A A
 */

#include <stdio.h>
#include <stdlib.h>

#define n 3

int main(int argc, const char * argv[]) {
    
    if(argc!=10) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int M[n][n];
    int k=0,somma=0;
    float media=0.0;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            M[i][j] = atoi(argv[++k]);
            somma+=atoi(argv[k]);
        }
    }
    
    media=(float)somma/(n*n);
    
    printf("La matrice binaria è:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            M[i][j] = (M[i][j]>media) ? 1 : 0;
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
    
    char c;
    printf("Inserisci un carattere: ");
    scanf(" %c",&c);
   
    printf("La matrice di caratteri e':\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(M[i][j]==1)
                printf("%c ",c);
            else
                printf("  ");
        }
        printf("\n");
    }
    
    printf("\n");
    return 0;
}
