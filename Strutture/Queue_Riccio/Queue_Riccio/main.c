//
//  main.c
//  Queue_Riccio
//
//  Created by Maurizio Minieri on 25/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../liste.h"


/*coda con lista (illimitata)*/
typedef struct Coda {
    Nodo_SL *head;
    Nodo_SL *tail;
} Coda;

int CodaVuota(Coda *Q) {
    return (Q-> head == NULL);
}

void CreaCoda(Coda *Q){
    if(Q){
        Q->head = NULL;
        Q->tail = NULL;
    }
}

void enqueue(Coda *Q, int dato){
    Nodo_SL *tmp;
    if(Q == NULL){
        return;
    }
    else if(CodaVuota(Q)){
        Q->head = CreaNodo_SL(dato);
        Q-> tail = Q->head;
        return;
    }
    else {
        tmp = CreaNodo_SL(dato);
        if(tmp != NULL) {
            Q->tail->next = tmp;
            Q->tail = tmp;
        }
        return;
    }
}

void dequeue(Coda *Q, int *dato ){
    Nodo_SL *tmp;
    if(CodaVuota(Q) || dato == NULL ){
        return;
    }
    else if(Q->head == Q->tail) {
        *dato = Q->head->dato;
        free(Q->head);
        Q->head = Q->tail = NULL ;
        return;
    }
    else {
        tmp = Q->head;
        *dato = Q->head->dato;
        Q->head = Q->head->next;
        free(tmp);
        return;
    }
}

void StampaCoda(Coda Q){
    Nodo_SL *tmp = Q.head;
    printf("[Coda]-> ");
    while(tmp && tmp->next){
        printf("%d -> ", tmp->dato);
        tmp = tmp->next;
    }
    if(tmp)
        printf("%d -|", tmp->dato);
}

void LiberaCoda(Coda *Q) {
    Nodo_SL *tmp;
    if(Q != NULL ) {
        while(Q->head != NULL ) {
            tmp = Q->head;
            Q->head = Q->head->next;
            free(tmp);
        }
        Q->head = Q->tail = NULL ;
    }
}

void LeggiInTesta(Coda *Q, int *dato){
    if(CodaVuota(Q) || dato == NULL){
        return;
    }
    else {
        *dato = Q->head->dato;
        return;
    }
}


//coda con array (limitato)
typedef struct ACoda {
    unsigned int size;
    unsigned int first;
    unsigned int last;
    int *dato;  //array di interi
} ACoda;

void CreaACoda(ACoda *Q, unsigned int n) {
    Q->size = 0;
    Q->first = 0;
    Q->last = 0;
    Q->dato = (int *)malloc(n*sizeof(int));
    if(Q->dato != NULL)
        Q->size = n;
    return;
}

void LiberaACoda(ACoda *Q) {
    if(Q != NULL) {
        free (Q->dato);
        Q->dato = NULL;
        Q->first = 0;
        Q->last = 0;
        Q->size = 0;
    }
}

int ACodaVuota(ACoda *Q) {
    return Q == NULL || Q->last == 0;
}

int ACodaPiena(ACoda *Q) {
    return Q == NULL || Q->last == Q->size;
}

int AEnqueue(ACoda *Q, int dato) {
    if(ACodaPiena(Q))
        return 1;
    else {
        Q->dato[Q->last++] = dato;
        return 0;
    }
}

int ADequeue(ACoda *Q, int *dato) {
    if(ACodaVuota(Q) || dato == NULL )
        return 1;
    else {
        *dato = Q->dato[Q->first++];
        return 0;
    }
}

int ATop(ACoda *Q, int *dato){
    if(ACodaVuota(Q) || dato == NULL )
        return 1;
    else {
        *dato = Q->dato[Q->first];
        return 0;
    }
}

void StampaACoda(ACoda Q){
    int i=0;
    printf("[Coda]-> ");
    if(ACodaVuota(&Q)==0){
        for(i=Q.first; i<Q.last-1; i++)
            printf("%d -> ", Q.dato[i]);
        printf("%d -|", Q.dato[Q.last-1]);
    }
}

int main(int argc, const char * argv[]) {
    //simulo l'esecuzione da linea di comando.
    argc = 6;
    argv[1] = "13"; argv[2] = "23"; argv[3] = "1"; argv[4] = "6"; argv[5] = "45";
    
    //lista
    int i;
    int dato=0;
    Coda Q;
    CreaCoda(&Q);
    for(i=1; i<argc; i++)
        enqueue(&Q, atoi(argv[i]));
    StampaCoda(Q);
    dequeue(&Q, &dato);
    printf("\nElemento estratto: %d\n", dato);
    enqueue(&Q, 99);
    StampaCoda(Q);
    LiberaCoda(&Q);
    
    printf("\n\n");
    //array
    int datoA;
    int iA;
    ACoda QA;
    CreaACoda(&QA, 100);
    for(iA=1; iA<argc; iA++)
        AEnqueue(&QA, atoi(argv[iA]));
    StampaACoda(QA);
    ADequeue(&QA, &datoA);
    //ATop(&QA, &datoA);
    printf("\nElemento estratto: %d\n", datoA);
    AEnqueue(&QA, 99);
    StampaACoda(QA);
    LiberaACoda(&QA);
    
    printf("\n\n");
    return 0;
}
