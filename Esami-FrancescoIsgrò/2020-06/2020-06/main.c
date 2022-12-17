//
//  main.c
//  2020-06
//
//  Created by Maurizio Minieri on 12/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 30
#define MAX 101

typedef struct lista {
    char nome[L+1];
    int dipendenti,dipartimenti,sedi;
    struct lista* next;
} *Nodo;

Nodo coda(Nodo top,char nome[],int dipendenti,int dipartimenti,int sedi) {
    Nodo tmp;
    if(top==NULL) {
        tmp=malloc(sizeof(struct lista));
        strcpy(tmp->nome,nome);
        tmp->dipendenti=dipendenti;
        tmp->dipartimenti=dipartimenti;
        tmp->sedi=sedi;
        tmp->next=NULL;
        return tmp;
    }
    else {
        top->next=coda(top->next,nome,dipendenti,dipartimenti,sedi);
        return top;
    }
}

void stampa(Nodo top) {
    if(top==NULL)
        return;
    else {
        if(top->next==NULL)
            printf("(%s %d %d %d)",top->nome,top->dipendenti,top->dipartimenti,top->sedi);
        else
            printf("(%s %d %d %d) -> ",top->nome,top->dipendenti,top->dipartimenti,top->sedi);
        stampa(top->next);
    }
}

Nodo cancella(Nodo top) {
    Nodo tmp;
    if(top==NULL)
        return NULL;
    else if(top->dipendenti<300) {
        tmp=top;
        top=cancella(top->next);
        free(tmp);
    }
    else
        top->next=cancella(top->next);
    return top;
}

/* swap data field of linked list */
void swap(Nodo p1, Nodo p2)
{
    char tmp[L+1];
    char tmp1[L+1];
    strcpy(tmp,p1->nome);
    strcpy(tmp1,p2->nome);
    strcpy(p1->nome,tmp1);
    strcpy(p2->nome,tmp);
    
    int temp = p1->dipendenti;
    p1->dipendenti = p2->dipendenti;
    p2->dipendenti = temp;
    
    int temp1 = p1->dipartimenti;
    p1->dipartimenti = p2->dipartimenti;
    p2->dipartimenti = temp1;
    
    int temp2 = p1->sedi;
    p1->sedi = p2->sedi;
    p2->sedi = temp2;
}

/* To sort the linked list */
void SelectionSort(Nodo head)
{
    Nodo start = head;
    Nodo traverse;
    Nodo min;
    
    while(start->next)
    {
        min = start;
        traverse = start->next;
        
        while(traverse)
        {
            /* Find minimum element from array */
            if( min->dipendenti < traverse->dipendenti )
            {
                min = traverse;
            }
            
            traverse = traverse->next;
        }
        swap(start,min);            // Put minimum element on starting location
        start = start->next;
    }
}


void scrivi(Nodo top) {
    FILE* fp;
    fp=fopen("output.txt","w");
    Nodo nodoMax=top;
    SelectionSort(top);
    printf("\nORDINATA\n");
    stampa(top);
    while(nodoMax) {
        fprintf(fp,"%s %d %d %d\n",nodoMax->nome,nodoMax->dipendenti,nodoMax->dipartimenti,nodoMax->sedi);
        nodoMax=nodoMax->next;
    }
    fclose(fp);
}

int main(int argc, const char * argv[]) {
   
    FILE* fp;
    
    fp=fopen("input.txt","r");
    if(fp==NULL) {
        printf("Errore, impossibile aprire il file input.txt.\n");
        return 1;
    }
    
    Nodo top=NULL;
    char riga[MAX];
    char nome[L+1];
    int dipendenti,dipartimenti,sedi,n=0;
    
    while(fgets(riga,MAX,fp)!=NULL) {
        if(sscanf(riga,"%s %d %d %d",nome,&dipendenti,&dipartimenti,&sedi)==4) {
            top=coda(top,nome,dipendenti,dipartimenti,sedi);
        }
        n++;
    }
    
    printf("\nL: ");
    stampa(top);
    top=cancella(top);
    printf("\nL dopo: ");
    stampa(top);
    
    
    
    
    
    //PUNTO 2
    //scrivi(top);  //metodo ordinando la lista
    FILE* fwp;
    fwp=fopen("output.txt","w");
    int maxPrev = 10000;
    int max=299;
    char maxNome[L+1];
    int maxDipartimenti=0,maxSedi=0;
    
    for(int i=0;i<n;i++) {
        rewind(fp);
        while(fgets(riga,MAX,fp)!=NULL) {
            if(sscanf(riga,"%s %d %d %d",nome,&dipendenti,&dipartimenti,&sedi)==4) {
                if(dipendenti>max && dipendenti<maxPrev) {
                    max=dipendenti;
                    strcpy(maxNome,nome);
                    maxDipartimenti=dipartimenti;
                    maxSedi=sedi;
                }
            }
        }
        if(max<300)
            break;
        fprintf(fwp,"%s %d %d %d\n",maxNome,max,maxDipartimenti,maxSedi);
        maxPrev=max;
        max=299;
    }
    
    fclose(fwp);
    fclose(fp);
    printf("\n\n");
    return 0;
}
