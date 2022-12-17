//
//  main.c
//  2020-09
//
//  Created by Maurizio Minieri on 15/01/21.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct lista {
    int** M;
    int m;
    int n;
    struct lista* next;
} *Nodo;

int** letturaMatrice(FILE* fp, int m, int n);
Nodo generaLista(char* fileName);
void stampaLista(Nodo top);
int sommaMatrice(int** M,int m,int n);
Nodo creaL2Iterativa(Nodo top,int k);
Nodo creaL2Ricorsiva(Nodo top,int k);

int** letturaMatrice(FILE* fp, int m, int n) {
    int** M = (int**) malloc(m*sizeof(int*));
    for (int i=0; i<m; i++)
        M[i] = (int*) malloc(n*sizeof(int));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            fscanf(fp,"%d",&M[i][j]);
    
    return M;
}

Nodo generaLista(char* fileName) {
    Nodo top = NULL;
    Nodo tmp = NULL;
    FILE * fp= fopen(fileName,"r");
    int m,n;

    if( !fp ) return NULL;
    
    while(!feof(fp)) {
        if(fscanf(fp,"%d %d",&m,&n) == 2) {
            if(!top) {
                top = malloc(sizeof(struct lista));
                top->m = m;
                top->n = n;
                top->M = letturaMatrice(fp,m,n);
                top->next = NULL;
                tmp = top;
            }
            else {
                Nodo new_nod = malloc(sizeof(struct lista));
                new_nod->m = m;
                new_nod->n = n;
                new_nod->M = letturaMatrice(fp,m,n);
                new_nod->next = NULL;
                tmp->next = new_nod;
                tmp = tmp->next;
            }
        }
    }
    
    fclose(fp);
    return top;
}

void stampaLista(Nodo top) {

    if(!top) printf("Lista vuota\n");

    int k=0;
    while(top) {
        printf("NODO %d:\n",k++);
        for(int i=0; i<top->m; i++) {
            for( int j = 0; j<top->n; j++)
                printf("%d ",top->M[i][j]);
            printf("\n");
        }
        top = top->next;
    }
}

int sommaMatrice(int** M,int m,int n) {
    int somma=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            somma+=M[i][j];
    return somma;
}

Nodo creaL2Iterativa(Nodo top,int k) {
    Nodo top2 = NULL;
    Nodo tmp = NULL;
    while(top) {
        if(sommaMatrice(top->M,top->m,top->n)<=k) {
            if(!top2) {
                top2 = malloc(sizeof(struct lista));
                *top2 = *top;
                top2->next = NULL;
                tmp = top2;
            }
            else {
                Nodo new_node = malloc(sizeof(struct lista));
                *new_node = *top;
                new_node->next = NULL;
                while(tmp->next)
                    tmp=tmp->next;
                tmp->next = new_node;
                tmp = new_node;
            }
        }
        top=top->next;
    }
    
    return top2;
}

Nodo creaL2Ricorsiva(Nodo top,int k) {
    Nodo top2 = NULL;
    if(!top)
        return NULL;
    
    top2=creaL2Ricorsiva(top->next, k);
    
    if(sommaMatrice(top->M, top->m, top->n)<=k) {
        Nodo tmp = malloc(sizeof(struct lista));
        *tmp = *top;
        tmp->next = top2;
        return tmp;
    }
    else
        return top2;
}

int main(int argc, const char * argv[]) {
    
    Nodo top = generaLista("input.txt");
    printf("\nL\n");
    stampaLista(top);
    //Nodo top2 = creaL2Iterativa(top,20);
    Nodo top2 = creaL2Ricorsiva(top,0);
    printf("\nL2\n");
    stampaLista(top2);

    printf("\n\n");
    return 0;
}
