//
//  main.c
//  ListeDL
//
//  Created by Maurizio Minieri on 22/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista {
    int key;
    struct lista* next;
    struct lista* prev;
} *Nodo;

//ITERATIVA
Nodo creaListaIterativaRandom(int n) {
    Nodo top = NULL;
    Nodo tmp = NULL;
    for(int i=0;i<n;i++) {
        tmp = malloc(sizeof(struct lista));
        tmp->key = rand() % 51;
        tmp->next = top;
        if(top)
            top->prev = tmp;
        top = tmp;
    }
    if(top)
        top->prev = NULL;
    return top;
}

Nodo creaListaInTestaIterativa(int n) {
    Nodo top = NULL;
    Nodo tmp = NULL;
    for(int i=0;i<n;i++) {
        tmp = malloc(sizeof(struct lista));
        printf("Inserisci in testa il valore del %d nodo: ",i+1);
        scanf("%d",&tmp->key);
        tmp->next = top;
        if(top)
            top->prev = tmp;
        top = tmp;
    }
    if(top)
        top->prev = NULL;
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
        tmp->next = NULL;
        if(!top) {
            top = tmp;
            tmp->prev = NULL;
        }
        else {
            curr->next = tmp;
            tmp->prev = curr;
        }
        curr = tmp;
    }
    return top;
}

/*
Nodo creaListaInOrdineIterativa(int n) {
    int k;
    Nodo top = NULL;
    for(int i=0;i<n;i++) {
        printf("Inserisci un valore: ");
        scanf("%d",&k);
        top = InserisciInOrdineIterativa(top,k);
    }
    return top;
}*/

Nodo getTailIterativa(Nodo top) {
    while(top && top->next)
        top = top->next;
    return top;
}

void stampaListaIterativa(Nodo top) {
    if(top)
        printf("\nNULL <- ");
    while(top) {
        if(top->next)
            printf("%d <=> ",top->key);
        else
            printf("%d -> ",top->key);
        top = top->next;
    }
    printf("NULL\n");
}

void stampaListaReverseIterativa(Nodo tail) {
    if(tail)
        printf("NULL <- ");
    while(tail) {
        if(tail->prev)
            printf("%d <=> ",tail->key);
        else
            printf("%d -> ",tail->key);
        tail = tail->prev;
    }
    printf("NULL");
}

int cercaIterativa(Nodo top, int k) {
    int i = 0;
    while(top) {
        if(top->key == k)
            return i;
        top = top->next;
        i++;
    }
    return -1;
}

Nodo cancellaNodoIterativa(Nodo top,int k) {
    Nodo curr = top;
    while(curr) {
        if(curr->key==k) {
            if(curr->prev==NULL) {
                curr = curr->next;
                curr->prev = top->prev;
                free(top);
                top = curr;
            }
            else {
                curr->prev->next = curr->next;
                if(curr->next)
                    curr->next->prev = curr->prev;
                free(curr);
            }
            break;
        }
        curr = curr->next;
    }
    return top;
}

Nodo cancellaAllNodoIterativa(Nodo top,int k) {
    Nodo curr = top;
    while(curr) {
        if(curr->key==k) {
            if(curr->prev==NULL) {
                curr = curr->next;
                curr->prev = top->prev;
                free(top);
                top = curr;
            }
            else {
                curr->prev->next = curr->next;
                if(curr->next)
                    curr->next->prev = curr->prev;
                free(curr);
            }
        }
        curr = curr->next;
    }
    return top;
}

void deallocaIterativa(Nodo* top) {
    Nodo tmp = NULL;
    while(*top) {
        tmp = *top;
        *top = (*top)->next;
        free(tmp);
    }
}



//RICORSIVA
Nodo creaListaRicorsivaRandom(int n) {
    Nodo top = NULL;
    if(n <= 0)
        return NULL;
    else {
        top = malloc(sizeof(struct lista));
        top->key = rand() % 51;
        top->prev = NULL;
        top->next = creaListaRicorsivaRandom(n-1);
        if(top->next)
            top->next->prev = top;
        return top;
    }
}

Nodo creaListaInTestaRicorsiva(int n) {
    Nodo top = NULL;
    if(n <= 0)
        return NULL;
    else {
        top = malloc(sizeof(struct lista));
        top->prev = NULL;
        top->next = creaListaInTestaRicorsiva(n-1);
        printf("Inserisci in testa un valore: ");
        scanf("%d",&top->key);
        if(top->next)
            top->next->prev = top;
        return top;
    }
}

Nodo creaListaInCodaRicorsiva(int n) {
    Nodo top = NULL;
    if(n <= 0)
        return NULL;
    else {
        top = malloc(sizeof(struct lista));
        printf("Inserisci in coda un valore: ");
        scanf("%d",&top->key);
        top->prev = NULL;
        top->next = creaListaInCodaRicorsiva(n-1);
        if(top->next)
            top->next->prev = top;
        return top;
    }
}

Nodo InserisciInOrdineRicorsiva(Nodo top, int k) {
    Nodo tmp;
    if(!top||top->key>k) {
        tmp = malloc(sizeof(struct lista));
        tmp->key=k;
        tmp->next = top;
        tmp->prev = NULL;
        return tmp;
    }
    else {
        
        top->next=InserisciInOrdineRicorsiva(top->next,k);
        if(top->next)
            top->next->prev = top;
        return top;
    }
}

Nodo creaListaInOrdineRicorsiva(int n) {
    /*Nodo top = NULL;
    int k;
    for(int i=0;i<n;i++) {
        printf("Inserisci un valore: ");
        scanf("%d",&k);
        top = InserisciInOrdineRicorsiva(top,k);
    }
    return top;*/
    Nodo top = NULL;
    int k;
    if(n == 0)
        return top;
    else {
        printf("Inserisci un valore: ");
        scanf("%d",&k);
        top = InserisciInOrdineRicorsiva(top,k);
        creaListaInOrdineRicorsiva(n-1);
        return top;
    }
}

Nodo getTailRicorsiva(Nodo top) {
    if(!top || !top->next)
        return top;
    else
        return getTailRicorsiva(top->next);
}

void stampaListaRicorsiva(Nodo top) {
    if(!top)
        printf("NULL\n");
    else {
        if(!top->prev)
            printf("\nNULL <- ");
        if(top->next)
            printf("%d <=> ",top->key);
        else
            printf("%d -> ",top->key);
        stampaListaRicorsiva(top->next);
    }
}

void stampaListaReverseRicorsiva(Nodo tail) {
    if(!tail)
        printf("NULL\n");
    else {
        if(!tail->next)
            printf("NULL <- ");
        if(tail->prev)
            printf("%d <=> ",tail->key);
        else
            printf("%d -> ",tail->key);
        stampaListaReverseRicorsiva(tail->prev);
    }
}

int cercaRicorsiva(Nodo top, int k) {
    int i = 0;
    if(!top)
        return -1;
    if(top->key == k)
        return i;
    else {
        i = cercaRicorsiva(top->next, k);
        if(i != -1)
            i++;
        return i;
    }
}

Nodo cancellaNodoRicorsiva(Nodo top,int k) {
    if(!top)
        return NULL;
    else if(top->key == k) {
        if(top->next)
            top->next->prev = top->prev;
        if(top->prev)
            top->prev->next = top->next;
        free(top);
        return top->next;
    }
    else {
        top->next = cancellaNodoRicorsiva(top->next,k);
        return top;
    }
}

//tutti
Nodo cancellaAllNodoRicorsiva(Nodo top,int k) {
    Nodo tmp;
    if(top==NULL)
        return top;
    if(top->key==k) {
        tmp=top;
        top=cancellaAllNodoRicorsiva(top->next,k);
        if(tmp->next)
            tmp->next->prev = tmp->prev;
        free(tmp);
    }
    else
        top->next=cancellaAllNodoRicorsiva(top->next,k);
    return top;
}

void deallocaRicorsiva(Nodo* top) {
    if(!(*top))
        return;
    else {
        deallocaRicorsiva(&(*top)->next);
        *top = NULL;
        free(*top);
    }
}

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    /*ITERATIVA*/
    //Nodo top = creaListaIterativaRandom(5);
    //Nodo top = creaListaInTestaIterativa(-1);
    //Nodo top = creaListaInCodaIterativa(5);
    //Nodo top = creaListaInOrdineIterativa(5);
    //stampaListaIterativa(top);
    //Nodo tail = getTailIterativa(top);
    //stampaListaReverseIterativa(tail);
    //top = cancellaNodoIterativa(top,3);
    //deallocaIterativa(&top);
    //stampaListaIterativa(top);
    //tail = getTailIterativa(top);
    //stampaListaReverseIterativa(tail);
    //int r = cercaIterativa(top,9);
    //printf( (r == -1) ? "Elemento non trovato\n" : "Trovato in posizione: %d\b",r);
    
    /*RICORSIVA*/
    //Nodo top = creaListaRicorsivaRandom(5);
    //Nodo top = creaListaInTestaRicorsiva(5);
    //Nodo top = creaListaInCodaRicorsiva(5);
    Nodo top = creaListaInOrdineRicorsiva(5);
    stampaListaRicorsiva(top);
    Nodo tail = getTailRicorsiva(top);
    stampaListaReverseRicorsiva(tail);
    //top = cancellaNodoRicorsiva(top,3);
    //stampaListaRicorsiva(top);
    //deallocaRicorsiva(&top);
    //stampaListaRicorsiva(top);
    //tail = getTailRicorsiva(top);
    //stampaListaReverseRicorsiva(tail);
    //int r = cercaRicorsiva(top,9);
    //printf( (r == -1) ? "Elemento non trovato\n" : "Trovato in posizione: %d\b",r);
    
    printf("\n\n");
    return 0;
}
