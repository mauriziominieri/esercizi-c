//
//  main.c
//  Esercizio-30F
//
//  Created by Maurizio Minieri on 13/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che acquisisca da standard input una matrice A di n × m interi
 (1 ≤ m ≤ 5 e 2 ≤ n ≤ 5) ed un intero k e fornisca su standard output quante volte k è presente in A.
 */

#include <stdio.h>
#include <stdlib.h>

//con dimensione fissata
/*
 void stampa(int M[][3],int n,int m) {
 printf("\nSTAMPA M\n");
 for(int i=0;i<n;i++) {
 for(int j=0;j<m;j++) {
 printf("[%d]",M[i][j]);
 }
 printf("\n");
 }
 }
 */
//con puntatori
void stampa(int** M,int n,int m) {
    printf("\nSTAMPA M\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("[%d]",M[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
    int n,m,k,conta=0;
    
    do {
        printf("Inserisci n: ");
        scanf("%d",&n);
    }
    while((n<1 || n>5) && printf("Errore, deve essere compreso fra 1 e 5\n"));
    
    do {
        printf("Inserisci m: ");
        scanf("%d",&m);
    }
    while((m<2 || m>5) && printf("Errore, deve essere compreso fra 2 e 5\n"));
    
    /*int M[n][m];*/ //senza puntatore
    
    int **M = (int**) malloc(n * sizeof(int *)); //creo n celle di memoria adatte a contenere interi
    for(int i=0;i<n;i++)
        M[i] = (int*) malloc(m * sizeof(int));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("Inserisci M[%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
    
    stampa(M,n,m);
    
    printf("\nInserisci k: ");
    scanf("%d",&k);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(M[i][j]==k)
                conta++;
        }
    }
    
    char s = conta == 1 ? 'a' : 'e';
    printf("\n%d è presente %d volt%c",k,conta,s);
    
    printf("\n\n");
    return 0;
}
