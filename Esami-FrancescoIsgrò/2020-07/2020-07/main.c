//
//  main.c
//  2020-07
//
//  Created by Maurizio Minieri on 14/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX 100

void stampaMatrice(int** M,int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
}

void permutazioni(int** A,int n,int m) {
    
    int somma1=0,somma2=0;
    int prodotto1=1,prodotto2=1;
  
    for(int y=0;y<n-1;y++) {
        for(int j=0;j<m;j++) {
            somma1+=A[y][j];
            prodotto1*=A[y][j];
        }
        for(int i=y+1;i<n;i++) {
            for(int j=0;j<m;j++) {
                somma2+=A[i][j];
                prodotto2*=A[i][j];
            }
            if(somma1==somma2 && prodotto1==prodotto2)
                printf("\nrighe permutate: %d & %d",y,i);
            somma2=0;
            prodotto2=1;
        }
        somma1=0;
        prodotto1=1;
    }
}

void dealloca(int** M,int n) {
    for(int i=0;i<n;i++)
        free(M[i]);
    free(M);
}

int minDiag(int** M,int a,int i,int j) {
    int min=M[i-a][j-a];
    for(int y=0;y<a;y++) {
       if(M[i-a+y+1][j-a+y+1]<min)
           min=M[i-a+y+1][j-a+y+1];
    }
    return min;
}

int minAntidiag(int** M,int a,int i,int j) {
    int min=M[i-a][j];
    for(int y=0;y<a;y++) {
       if(M[i-a+y+1][j-y-1]<min)
           min=M[i-a+y+1][j-y-1];
    }
    return min;
}

int maxDiag(int** M,int a,int i,int j) {
    int max=M[i-a][j-a];
    for(int y=0;y<a;y++) {
       if(M[i-a+y+1][j-a+y+1]>max)
           max=M[i-a+y+1][j-a+y+1];
    }
    return max;
}

int maxAntidiag(int** M,int a,int i,int j) {
    int max=M[i-a][j];
    for(int y=0;y<a;y++) {
       if(M[i-a+y+1][j-y-1]>max)
           max=M[i-a+y+1][j-y-1];
    }
    return max;
}

int min(int a,int b) {
    return a > b ? b : a;
}

int max(int a,int b) {
    return a > b ? a : b;
}

int maxSubmatrix(int** M,int n,int i,int j) {
    
    int max=INT_MIN;
    for(int y=0;y<=n;y++)
        for(int x=0;x<=n;x++)
            if(M[i-n+y][j-n+x]>max)
                max=M[i-n+y][j-n+x];
    return max;
}

int minSubmatrix(int** M,int n,int i,int j) {
    
    int min=INT_MAX;
    for(int y=0;y<=n;y++)
        for(int x=0;x<=n;x++)
            if(M[i-n+y][j-n+x]<min)
                min=M[i-n+y][j-n+x];
    return min;
}

void stampaSubmatrix(int** M,int n,int i,int j) {
    for(int y=0;y<n;y++) {
        for(int x=0;x<n;x++)
            printf("%d ",M[i-n+y+1][j-n+x+1]);
        printf("\n");
    }
}

//il trucco per vedere se esistono sottomatrici con tutti elementi uguali è creare T con tutti 0 dove nella prima riga e prima colonna metto tutti 1, poi controllo M1 da (1,1) e lo confronto con l'elemento sopra, sinistra e alto a sinistra.
//Dato che nel nostro caso dobbiamo calcolare minimo e massimo nella sottomatrice allora devo usare più o meno la stessa tecnica creando T, ma poi devo calcolare minimo e massimo via via nelle sottomatrici
void submatrixMin10(int** M,int n,int m) {
    int** T=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        T[i]=calloc(m,sizeof(int));
    
    int r=0,minimo=INT_MAX,massimo=INT_MIN,min_up_left;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0 || j==0)
                T[i][j] = 1;
            else {
                //massimo tra esso stesso, elemento corrente, diagonale, antidiagonale,elemento superiore, elemento sinistro
                min_up_left=min(T[i-1][j],T[i][j-1]);
                /*massimo = max(massimo,
                          max(M[i][j],
                          max(maxDiag(M,min_up_left, i, j),
                          max(maxAntidiag(M,min_up_left,i,j),
                          max(M[i-1][j],
                              M[i][j-1]
                          )))));
                //minimo tra esso stesso, elemento corrente, diagonale, antidiagonale,elemento superiore, elemento sinistro
                minimo = min(minimo,
                         min(M[i][j],
                         min(minDiag(M, min_up_left, i, j),
                         min(minAntidiag(M, min_up_left, i, j),
                         min(M[i-1][j],
                             M[i][j-1]
                         )))));
                */
                massimo = maxSubmatrix(M, min_up_left, i, j);
                minimo = minSubmatrix(M, min_up_left, i, j);
                
                if(massimo - minimo <= 10) {
                    T[i][j] = min(min_up_left,T[i-1][j-1]) + 1;
                }
                else {
                    T[i][j] = 1;
                    minimo=INT_MAX;
                    massimo=INT_MIN;
                }
            }
            r = max(r,T[i][j]);
        }
    }
    
    printf("\n");
    //per gli altopiani massimi
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(T[i][j]==r) {
                printf("\naltopiano di dimensione massima %d x %d identificato in (%d,%d) a (%d,%d)\n",T[i][j],T[i][j],i-T[i][j]+1,j-T[i][j]+1,i,j);
                stampaSubmatrix(M,T[i][j],i,j);
            }
        }
    }
    
    //stampaMatrice(T, n, m);
    dealloca(T, n);
}

int main(int argc, const char * argv[]) {
    
    FILE* fp;
    fp=fopen("input.txt","r");
    
    if(fp==NULL) {
        printf("Errore: impossibile aprire il file input.txt\n");
        return 1;
    }
    
    char riga[MAX];
    int n,m;
    fgets(riga,MAX,fp);
    if(sscanf(riga,"%d %d",&n,&m)!=2) {
        printf("Errore: righe e colonne nel file non trovate\n");
        return 1;
    }
        
    int** A=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        A[i]=malloc(m*sizeof(int));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            fscanf(fp,"%d",&A[i][j]);
    }
    
    stampaMatrice(A,n,m);
    permutazioni(A,n,m);
    submatrixMin10(A,n,m);
    
    dealloca(A,n);
    fclose(fp);
    printf("\n\n");
    return 0;
}
