//
//  main.c
//  Esercizio-30
//
//  Created by Maurizio Minieri on 13/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che acquisisca da standard input una matrice A di n × m interi
 (1 ≤ m ≤ 5 e 2 ≤ n ≤ 5) ed un intero k e fornisca su standard output quante volte k è presente in A.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n=2,m=3,k,conta=0;
    int M[n][m];
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("Inserisci M[%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
    
    printf("\nSTAMPA M\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("[%d]",M[i][j]);
        }
        printf("\n");
    }
    
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
