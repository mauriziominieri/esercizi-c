//
//  main.c
//  regni
//
//  Created by Maurizio Minieri on 14/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define L 30
#define MAX 101

typedef struct lista {
    char nome[L];
    float X,Y;
    struct lista* next;
} *Nodo;

Nodo coda(Nodo top,char nome[],float X,float Y) {
    if(top==NULL) {
        top=malloc(sizeof(struct lista));
        strcpy(top->nome,nome);
        top->X=X;
        top->Y=Y;
        top->next = NULL;
    }
    else
        top->next=coda(top->next,nome,X,Y);
    return top;
}

void stampa(Nodo top) {
    if(top==NULL)
        return;
    else {
        printf("%s %f %f\n",top->nome,top->X,top->Y);
        stampa(top->next);
    }
}

void removeDuplicates(Nodo top) {
  
    Nodo curr,previous,runner,tmp;
    
    curr = top->next;
    previous = top;

    while(curr != NULL){
        runner = top;
        while(runner != curr){
            if(strcmp(runner->nome,curr->nome)==0 && runner->X==curr->X && runner->Y==curr->Y){
                tmp = curr;
                curr = curr->next;
                previous->next = curr;
                free(tmp);
                break;
            }
            runner = runner->next;
        }

        if(runner == curr){
            curr = curr->next;
            previous = previous->next;
        }
    }
}

int dimLista(Nodo top) {
    int n=0;
    if(top==NULL)
        return n;
    else {
        n=dimLista(top->next);
        return ++n;
    }
}

void stampaMatrice(float** M,int n) {
    printf("\nMATRICE:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%.4f ",M[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
   
    FILE* fp;
    fp=fopen("input.txt","r");
    
    if(fp==NULL) {
        printf("Errore: impossibile aprire il file input.txt");
        return 1;
    }
    
    char riga[MAX];
    char nome[L];
    float X,Y;
    Nodo top=NULL;
    
    while(fgets(riga,MAX,fp)!=NULL) {
        if(sscanf(riga,"%s %f %f",nome,&X,&Y)==3) {
            top=coda(top,nome,X,Y);
        }
    }
    stampa(top);
    removeDuplicates(top);
    printf("\n\n");
    stampa(top);
    
    int n=dimLista(top);
    float** A;
    A=malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        A[i]=malloc(n*sizeof(float));
    
    Nodo curr1=top,curr2=top;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            A[i][j] = sqrt(pow((curr1->X - curr2->X),2)+pow((curr1->Y - curr2->Y),2));
            curr2=curr2->next;
        }
        curr2=top;
        curr1=curr1->next;
    }
    
    stampaMatrice(A,n);
    
    FILE* fwp;
    fwp=fopen("output.txt","w");
    curr1=top;curr2=top;
    float min=INT_MAX;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(A[i][j]>0 && A[i][j]<min) {
                min=A[i][j];
                strcpy(nome,curr2->nome);
            }
            curr2=curr2->next;
        }
        fprintf(fwp,"%s\t\t%s\t\t%.4f\n",curr1->nome,nome,min);
        curr2=top;
        curr1=curr1->next;
        min=INT_MAX;
    }
    
    for(int i=0;i<n;i++)
        free(A[i]);
    free(A);
    fclose(fwp);
    fclose(fp);
    printf("\n");
    return 0;
}
