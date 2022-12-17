//
//  main.c
//  2019-10
//
//  Created by Maurizio Minieri on 12/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define L 30
#define MAX 101

typedef struct lista {
    int i,j;
    int key;
    struct lista* next;
} *Nodo;

bool quadratoMagico(int** M,int N) {
    
    int sommaDiag=0, sommaAntidiag=0;
    for (int i = 0; i < N; i++)
        sommaDiag += M[i][i];
    for (int i = 0; i < N; i++)
        sommaAntidiag += M[i][N-1-i];
    
    if(sommaDiag!=sommaAntidiag)
        return false;
    
    int sommaRiga=0;
    for (int i = 0; i < N; i++) {
        sommaRiga = 0;
        for (int j = 0; j < N; j++)
            sommaRiga += M[i][j];
        if (sommaRiga != sommaDiag)
            return false;
    }
    
    int sommaCol=0;
    for (int i = 0; i < N; i++) {
        sommaCol=0;
        for (int j = 0; j < N; j++)
            sommaCol += M[j][i];
        if (sommaCol != sommaDiag)
            return false;
    }
    return true;
}

struct lista* coda(struct lista* top, int i, int j, int k) {
    struct lista* tmp;
    if(top==NULL) {
        tmp=malloc(sizeof(struct lista));
        tmp->i=i;
        tmp->j=j;
        tmp->key=k;
        tmp->next=NULL;
        return tmp;
    }
    else {
        top->next=coda(top->next,i,j,k);
        return top;
    }
}

void stampaLista(struct lista* top) {
    if(top==NULL)
        return;
    else {
        if(top->next==NULL)
            printf("(%d,%d,%d)",top->i,top->j,top->key);
        else
            printf("(%d,%d,%d)->",top->i,top->j,top->key);
        stampaLista(top->next);
    }
}

struct lista* cancellaDispari(struct lista* top) {
    struct lista* tmp;
    if(top==NULL)
        return top;
    if(top->key%2!=0) {
        tmp=top;
        top=cancellaDispari(top->next);
        free(tmp);
    }
    else
        top->next=cancellaDispari(top->next);
    return top;
}

void riempiMatrice(int** M,Nodo top,int n,int m) {
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            if(top!=NULL && M[i][j]==top->key) {
                M[i][j]=top->key;
                top=top->next;
            }
            else
                M[i][j]=0;
        }
}

void scriviFile(int** M,int n,int m) {
    FILE* fp;
    fp=fopen("output.txt","w");
    fprintf(fp,"%d %d\n",n,m);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            fprintf(fp,"%d ",M[i][j]);
        fprintf(fp,"\n");
    }
    
    fclose(fp);
}

int main(int argc, const char * argv[]) {
    
    int n,m;
    char nomeFile[L] = "input.txt";
    FILE* fp;
    fp=fopen(nomeFile,"r");
    if(fp==NULL) {
        printf("Errore, impossibile aprire il file %s.\n",nomeFile);
        return 1;
    }
    
    char riga[MAX];
    fgets(riga,MAX,fp);
    int r=sscanf(riga,"%d %d",&n,&m);
    if(r!=2) {
        printf("Errore in %s: la prima riga deve contenere righe e colonne.\n",nomeFile);
        return 1;
    }
    
    int** M;
    M=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    M[i]=malloc(m*sizeof(int));
    
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    fscanf(fp,"%d",&M[i][j]);
    
    
    printf("\nMAT\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
        printf("%d ",M[i][j]);
        printf("\n");
    }
    
    if(n!=m || !quadratoMagico(M,n))
        printf("\nLa matrice non è un quadrato magico\n");
    else
        printf("\nLa matrice è un quadrato magico\n");
    
    struct lista* top = NULL;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            top=coda(top,i,j,M[i][j]);
    
    printf("\nLa lista è ");
    stampaLista(top);
    
    top=cancellaDispari(top);
    printf("\n\nLa lista senza i dispari è ");
    stampaLista(top);
    
    riempiMatrice(M,top,n,m);
    scriviFile(M, n, m);
    
    for(int i=0;i<n;i++)
        free(M[i]);
    free(M);
    fclose(fp);
    printf("\n\n");
    return 0;
}
