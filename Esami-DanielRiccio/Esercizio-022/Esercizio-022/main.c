//
//  main.c
//  Esercizio-022
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando una parola
 2) Implementa la funzione char **MappaCroce(char parola[]) che prende in input una
 stringa e restituisce una matrice di caratteri dove la parola compare in orizzontale
 e in verticale a forma di croce con centro nel carattere centrale della parola (vedi esempio)
 Input e Output
 Input: yamamay
 La parola inserita è: yamamay
 La matrice di caratteri è:
       y
       a
       m
 y a m a m a y
       m
       a
       y
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **MappaCroce(char parola[]) {
   
    int n=(int)strlen(parola);
    int k1=0,k2=0;
    
    char** M=malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
        M[i]=malloc(n*sizeof(char));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            if(i==n/2 || j==n/2) {
                M[i][j] = (i==n/2) ? parola[k1++] : parola[k2++];
                if(i==n/2 && j==n/2)
                    k2++;
            }
            else
                M[i][j]=' ';
        }
    
    return M;
}

int main(int argc, const char * argv[]) {
    
    if(argc!=2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int n=(int)strlen(argv[1]);
    char parola[n+1];
    strcpy(parola,argv[1]);
    printf("La parola inserita è: %s\n",parola);
    char **M=MappaCroce(parola);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            printf("%c ",M[i][j]);
        printf("\n");
    }
    
    for(int i=0;i<n;i++)
        free(M[i]);
    free(M);
    
    printf("\n");
    return 0;
}
