//
//  main.c
//  ListeC
//
//  Created by Maurizio Minieri on 23/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista {
    int key;
    struct lista* next;
} *Nodo;


/*ITERATIVA*/
Nodo creaListaIterativaRandom(int n) {
    Nodo top = NULL;
    Nodo tmp = NULL;
    Nodo tail = NULL;
    for(int i=0;i<n;i++) {
        tmp = malloc(sizeof(struct lista));
        tmp->key = rand() % 51;
        tmp->next = top;
        if(!top)
            tail = tmp;
        top = tmp;
    }
    if(tail)
        tail->next = top;
    return top;
}

Nodo creaListaInTestaIterativa(int n) {
    Nodo top = NULL;
    Nodo tmp = NULL;
    Nodo tail = NULL;
    for(int i=0;i<n;i++) {
        tmp = malloc(sizeof(struct lista));
        printf("Inserisci in testa il valore del %d nodo: ",i+1);
        scanf("%d",&tmp->key);
        tmp->next = top;
        if(!top)
            tail = tmp;
        top = tmp;
    }
    if(tail)
        tail->next = top;
    return top;
}

Nodo creaListaInCodaIterativa(int n) {
    Nodo top = NULL;
    Nodo tmp = NULL;
    Nodo curr = NULL;
    for(int i=0;i<n;i++) {
        tmp = malloc(sizeof(struct lista));
        printf("Inserisci in coda il valore del %d nodo: ",i+1);
        scanf("%d",&tmp->key);
        if(!top)
            top = tmp;
        else
            curr->next = tmp;
        curr = tmp;
    }
    if(curr)
        curr->next = top;
    return top;
}

void stampaListaIterativa(Nodo top) {
    Nodo curr = top;
    if(top) {
        printf("%d -> ",top->key);
        curr = curr->next;
    }
    while(curr!=top) {
        printf("%d -> ",curr->key);
        curr = curr->next;
    }
}


/*RICORSIVA*/
Nodo creaListaRicorsivaRandom(int n) {
    Nodo top = NULL;
    
    return top;
}

Nodo creaListaInTestaRicorsiva(int n) {
    Nodo top = NULL;
    
    return top;
}

Nodo creaListaInCodaRicorsiva(int n) {
    Nodo top = NULL;
    
    return top;
}

void stampaListaRicorsiva(Nodo top,Nodo curr) {
   
}

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    /*ITERATIVA*/
    Nodo top = creaListaIterativaRandom(3);
    //Nodo top = creaListaInTestaIterativa(3);
    //Nodo top = creaListaInCodaIterativa(3);
    //stampaListaIterativa(top);
    
    /*RICORSIVA*/
    //Nodo top = creaListaRicorsivaRandom(5);
    //Nodo top = creaListaInTestaRicorsiva(5);
    //Nodo top = creaListaInCodaRicorsiva(5);
    stampaListaRicorsiva(top,top->next);
    
    printf("\n\n");
    return 0;
}
