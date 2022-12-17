//
//  main.c
//  Esercizio-019
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando una parola
 2) Definisce un nodo Carattere con un record che contiene un carattere e un puntatore
 al nodo successivo
 Implementa la funzione Carattere *CreaLista(char parola[]) che prende in input una
 stringa e restituisce il puntatore alla testa di una lista di caratteri
 Input e Output
 Input: costantinopoli
 La lista è: i->l->o->p->o->n->i->t->n->a->t->s->o->c->
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carattere{
    char c;
    struct Carattere* next;
} Carattere;

Carattere* CreaLista(char parola[]) {
    Carattere *curr=NULL,*top=NULL;
    
    for(int i=0;i<strlen(parola);i++) {
        curr = malloc(sizeof(Carattere));
        curr->c = parola[i];
        curr->next = NULL;
        if(!top)
            top=curr;
        else {
            curr->next=top;
            top=curr;
        }
    }
    
    return top;
}

void StampaLista(Carattere *top) {
    if(top==NULL) {
        printf("NULL\n");
        return;
    }
    else {
        printf("%c->", top->c);
        StampaLista(top->next);
    }
}

Carattere* DeallocaLista(Carattere* top) {
    Carattere* tmp=top;
    while(top) {
        tmp=top;
        top=top->next;
        free(tmp);
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
   
    if(argc!=2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    char parola[strlen(argv[1])+1];
    strcpy(parola,argv[1]);
    Carattere *curr,*top = CreaLista(parola);
    curr=top;
    printf("La lista è: ");
    /*while(curr) {
        printf("%c->",curr->c);
        curr=curr->next;
    }*/
    StampaLista(curr);
    curr=DeallocaLista(curr);
    StampaLista(curr);
    
    printf("\n");
    return 0;
}
