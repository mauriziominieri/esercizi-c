//
//  main.c
//  2015-07-15
//
//  Created by Maurizio Minieri on 18/07/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//

/*
 Si realizzi un programma in linguaggio C che,
 a) legga un file di testo dove per ogni riga si ha Luogo X Y dove Luogo è il nome di un luogo in un immaginario mondo planare, e X Y sono le coordinate in un sistema di riferimento. I dati vanno immagazzinati in una opportuna lista a singolo link; i dati nella lista devono contenere tutti i dati inclusi nel file di input nello stesso ordine del file di input, o al più un ordine inverso; stampare la lista a schermo dopo la lettura.
 b) elimini dalla lista tutti i duplicati; stampare la lista a schermo al termine dell’operazione.
 c) costruisca una matrice quadrata A di dimensione nxn (n è il numero di città differenti presenti nella lista) dove A(i,j) è la distanza fra la città i-esima e la città j-esima; ricordate che il quadrato della distanza fra due punti (x1, y1), (x2, y2) sul piano è data da (x1-x2)^2 + (y1-y2)^2 ; stampare la matrice a schermo;
 d) scriva un file dove a ognuna delle città presenti nella lista viene associata la città ad essa più vicina e la relativa distanza.
 L’implementazione dei punti c) e d) non deve in alcun modo modificare la lista.
 Ad esempio, supponendo che il file di input contenga
 Gondor   81.4724 9.7540
 Mordor   90.5792 27.8498
 Arnor    12.6987 54.6882
 Gondor   81.4724 9.7540
 Gondor   81.4724 9.7540
 Erebor   91.3376 95.7507
 Harad    63.2359 96.4889
 Gondor   81.4724 9.7540
 
 il file prodotto deve essere, ad esempio,
 Gondor   Mordor   20.2581
 Arnor    Erebor   20.2581
 Harad    Mordor   65.5844
 Gondor   Harad    28.1114
 Harad    Erebor   28.1114
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXLEN 50


struct mondo{
    char luogo[MAXLEN];
    float X;
    float Y;
    struct mondo *next;
};

struct mondo *ins_coda(struct mondo *top, struct mondo *node) {
    
    if (top==NULL) {
       // printf("metto la freccia a NULL di node:%s e faccio top=node\n",node->luogo);
        node->next=NULL;
        top = node;
    }
    else{
       // printf("prima, top:%s\n",top->luogo);
        top->next=ins_coda(top->next, node);
        //printf("dopo, top:%s\n",top->luogo);
    }
    
    //printf("fine, restituisco top:%s\n",top->luogo);
    return top;
}

void printList(struct mondo *top) {
    
    printf("STAMPA TOP\n");
    while(top!=NULL) {
        printf("%s\t%.4f\t%.4f\n", top->luogo, top->X, top->Y);
        top=top->next;
    }
}

struct mondo *freeLista(struct mondo *top) {
    
    struct mondo *tmp;
    
    while(top!=NULL) {
        tmp=top;
        top = top->next;
        free(tmp);
    }
    return top;
}


struct mondo * readFile(struct mondo* top,char *nome){
    
    FILE* fp;
    struct mondo* tmp = NULL;
    
    fp=fopen(nome,"r");
    
    while(!feof(fp)){
        //creo il nodo tmp di tipo struct
        tmp=(struct mondo *)malloc(sizeof(struct mondo));
        //riempio i vari campi
        fscanf(fp,"%s %f %f", tmp->luogo, &tmp->X, &tmp->Y);
        //aggiungo il nodo alla lista
        top = ins_coda(top,tmp);
        //printf("\n");
    }
    
    fclose(fp);
    
    return top;
}

int dimLista(struct mondo* top){
    int n=0;
    
    while(top){
        n++;
        top=top->next;
    }
    
    return n;
}

void deleteDuplic(struct mondo *top) {
    
    struct mondo *curr=top, *tmp, *dup;
    
    while (curr != NULL && curr->next != NULL){
        tmp = curr;
        while (tmp->next != NULL){
            if (strcmp(curr->luogo, tmp->next->luogo)==0){
                dup = tmp->next;
                tmp->next = tmp->next->next;
                free(dup);
            }
            else
                tmp = tmp->next;
        }
        curr = curr->next;
    }
}


float **allocaMatrice(int r, int c)
{
    float **A;
    int i;
    
    A = (float **)malloc(r*sizeof(float *));
    for (i=0; i<c; i++)
        A[i] =(float*)malloc(c*sizeof(float));
    
    return A;
}

void riempiMatrice(struct mondo *lista, float **A)
{
    int i, j;
    struct mondo *ptr1, *ptr2;
    
    for (ptr1=lista, i=0; ptr1!=NULL; ptr1=ptr1->next, i++) {
        for (ptr2=ptr1->next, j=i+1; ptr2!=NULL; ptr2=ptr2->next, j++) {
            A[i][j] = sqrt(pow(ptr1->X - ptr2->X,2) +  pow(ptr1->Y - ptr2->Y,2));
            A[j][i] = A[i][j];
        }
    }
}


void stampaMatrice(float **A, int m, int n)
{
    int i, j;
    
    printf("STAMPA MATRICE\n");
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("%f  ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void freeMatrice(float **A)
{
    free((void *) A[0]);
    free((void *) A);
}


void scriviFile(struct mondo *top, float **A){
    
    FILE* output;
    struct mondo* tmp1,*tmp2;
    char a[MAXLEN],b[MAXLEN];
    float min=0.0;
    int i,j;
    output=fopen("/Users/mauriziominieri/Progetti/Linguaggio-C/Esami-RobertoPrevete/2015-07-15/output.txt","w");
    
    
    for(tmp1=top,i=0;tmp1!=NULL;tmp1=tmp1->next,i++){
        for(tmp2=top,j=0;tmp2!=NULL;tmp2=tmp2->next,j++){
            if(tmp1!=tmp2){
                if(min==0.0){
                    min=A[i][j];
                    strcpy(a,tmp1->luogo);
                    strcpy(b,tmp2->luogo);
                }
                else if(A[i][j]<min){
                    min=A[i][j];
                    strcpy(a,tmp1->luogo);
                    strcpy(b,tmp2->luogo);
                }
            }
        }
        fprintf(output,"%s\t %s\t  %.4f\n",a,b,min);
        min=0.0;
    }
    
    
    fclose(output);
}




int main(int argc, const char * argv[]) {
    
    struct mondo* top=NULL;
    
    top=readFile(top,"/Users/mauriziominieri/Progetti/Linguaggio-C/Esami-RobertoPrevete/2015-07-15/input.txt");
    printList(top);
    deleteDuplic(top);
    printList(top);
    
    int n=dimLista(top);
    float **A=allocaMatrice(n,n);
    riempiMatrice(top,A);
    stampaMatrice(A,n,n);
    scriviFile(top,A);
    
    freeMatrice(A);
    freeLista(top);
    
    return 0;
}
