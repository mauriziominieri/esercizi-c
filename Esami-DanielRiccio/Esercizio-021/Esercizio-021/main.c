//
//  main.c
//  Esercizio-021
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando 25 interi e li inserisce in una matrice 5x5
 2) Implementa la funzione int *PartizionaMatrice(int M[5][5]) che prende in input una
 matrice di 5x5 interi restituisce un vettore V, in cui sono accodati prima tutti i
 valori minori della media e poi tutti quelli maggiori o uguali della media.
 Input e Output
 Input: 12 5 23 65 43 13 61 74 39 81 33 63 18 90 22 37 46 49 11 31 78 69 44 68 86
 La matrice inserita è:
 12 05 23 65 43
 13 61 74 39 81
 33 63 18 90 22
 37 46 49 11 31
 78 69 44 68 86
 La media è: 46.439999
 Il vettore di interi è: 12 05 23 43 13 39 33 18 22 37 46 11 31 44 65 61 74 81 63 90 49 78 69 68 86
 */

#include <stdio.h>
#include <stdlib.h>

int *PartizionaMatrice(int M[5][5]) {
    
    int somma=0,k=0;
    printf("La matrice inserita è:\n");
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            somma+=M[i][j];
            printf("%.2d ",M[i][j]);
        }
        printf("\n");
    }
    
    float media = (float)somma/25;
    printf("La media è: %f\n",media);
    
    int* V = malloc(25*sizeof(int));
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(M[i][j]<media)
                V[k++]=M[i][j];
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(M[i][j]>=media)
                V[k++]=M[i][j];
    
    return V;
}

int main(int argc, const char * argv[]) {
   
    if(argc!=26) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int M[5][5],k=0;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            M[i][j]=atoi(argv[++k]);
        }
    }
    
    int* V = PartizionaMatrice(M);
    printf("Il vettore di interi è: ");
    for(int i=0;i<25;i++)
        printf("%.2d ",V[i]);
    
    printf("\n\n");
    return 0;
}
