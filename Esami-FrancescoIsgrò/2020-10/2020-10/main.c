//
//  main.c
//  2020-10
//
//  Created by Maurizio Minieri on 16/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int i,j,key;
    struct lista* next;
} *Nodo;

int** allocaMatrice(int n,int m) {
    int **M;
    M = malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        M[i] = malloc(m*sizeof(int));
    return M;
}

void stampaMatrice(int** M,int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            printf("%d ",M[i][j]);
        printf("\n");
    }
}

int sequenzaMax(int** M,int n,int m,int k) {
    int conta=0,max=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            if(M[i][j]==k)
                conta++;
            else {
                if(conta>max)
                    max=conta;
                conta=0;
            }
        }
    
    return max;
}

Nodo coda(Nodo top,int i,int j,int key) {
    
    if(!top) {
        top=malloc(sizeof(struct lista));
        top->i = i;
        top->j = j;
        top->key = key;
        top->next = NULL;
    }
    else
        top->next = coda(top->next,i,j,key);
    return top;
}

Nodo creaL(int** M,int n,int m) {
    Nodo top = NULL;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(M[i][j]!=0)
                top=coda(top,i,j,M[i][j]);
    return top;
}

void stampaLista(Nodo top) {
    if(!top)
        printf("NULL\n");
    else {
        printf("(%d, %d, %d)\n",top->i,top->j,top->key);
        stampaLista(top->next);
    }
}

Nodo modificaLista(Nodo top,int k) {
    if(!top)
        return NULL;
    else {
        if(top->key<k)
            top->key = 0;
        top->next = modificaLista(top->next, k);
        return top;
    }
}

void modificaMatrice(int** M,int n,int m,Nodo top) {
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            if(top && (i==top->i && j==top->j)) {
                M[i][j] = top->key;
                top=top->next;
            }
            else
                M[i][j] = 0;
        }
}

int main(int argc, const char * argv[]) {
    
    FILE* fp;
    fp=fopen("input.txt","r");
    
    if(!fp) {
        printf("Errore: impossibile aprire il file input.txt");
        return 1;
    }
    
    int n=0,m=0;
    int** M = NULL;
    while(!feof(fp)) {
        fscanf(fp,"%d %d",&n,&m);
        M = allocaMatrice(n,m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                fscanf(fp,"%d",&M[i][j]);
    }
    stampaMatrice(M,n,m);
    
    int k=8;
    printf("La più lunga sequenza di %d è: %d",k,sequenzaMax(M,n,m,k));
    Nodo top=creaL(M,n,m);
    printf("\nTOP: ");
    stampaLista(top);
    
    k=6;
    top=modificaLista(top,k);
    printf("\nTOP: ");
    stampaLista(top);
    
    modificaMatrice(M,n,m,top);
    stampaMatrice(M,n,m);
    
    fclose(fp);
    printf("\n\n");
    return 0;
}
