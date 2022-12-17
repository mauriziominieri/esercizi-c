//
//  main.c
//  Esame_21-03-01_Queue
//
//  Created by Maurizio Minieri on 05/04/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct record {
    float x,y;
} Punto;

typedef struct TCoda {
    unsigned int size;
    unsigned int last;
    Punto *dato;  //array di interi
} Coda;

void CreaCoda(Coda *Q, int n) {
    Q->size = 0;
    Q->last = 0;
    Q->dato = malloc(n * sizeof(Punto));
    if(Q->dato != NULL)
        Q->size = n;
    return;
}

void LiberaCoda(Coda *Q) {
    if(Q != NULL) {
        free (Q->dato);
        Q->dato = NULL;
        Q->last = 0;
        Q->size = 0;
    }
}

int CodaVuota(Coda *Q) {
    return Q == NULL || Q->last == 0;
}

int CodaPiena(Coda *Q) {
    return Q == NULL || Q->last == Q->size;
}

void Enqueue(Coda *Q, Punto dato) {
    if(!CodaPiena(Q))
        Q->dato[Q->last++] = dato;
}

Punto Dequeue(Coda *Q) {
    Punto p;
    if(CodaVuota(Q) || Q->dato == NULL) {
        printf("Errore");
        return p;
    }
    return Q->dato[--Q->last];
}

void StampaCoda(Coda Q){
    int k=0;
    char indici[][10] = {"Primo","Secondo","Terzo"};
    while(!CodaVuota(&Q)){
        Punto p = Dequeue(&Q);
        printf("%s punto P(%g,%g)\n",indici[k++],p.x,p.y);
    }
}

int main(int argc, const char * argv[]) {
    
    Punto P1,P2,P3;
    P1.x = 12; P1.y = 3;
    P2.x = 14; P2.y = 4;
    P3.x = 7; P3.y = 9;
    
    Coda Q;
    CreaCoda(&Q, 10);
    Enqueue(&Q,P1);
    Enqueue(&Q,P2);
    Enqueue(&Q,P3);
    
    StampaCoda(Q);
    LiberaCoda(&Q);
    
    printf("\n\n");
    return 0;
}
