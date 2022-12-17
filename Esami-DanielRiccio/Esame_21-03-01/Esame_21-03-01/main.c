//
//  main.c
//  Esame_21-03-01
//
//  Created by Maurizio Minieri on 04/04/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct record {
    float x,y;
} Punto;

typedef struct TStack {
    int size;
    int last;
    Punto *dato;
} Stack;

void CreaStack(Stack *S, int n) {
    S->size = 0;
    S->last = 0;
    S->dato = malloc(n * sizeof(Punto));
    if(S->dato != NULL)
        S->size = n;
    return;
}

void LiberaStack(Stack *S) {
    if(S != NULL) {
        free (S->dato);
        S->dato = NULL ;
        S->last = 0;
        S->size = 0;
    }
}
int StackVuoto(Stack *S) {
    return S == NULL || S->last == 0;
}

int StackPieno(Stack *S) {
    return S == NULL || S->last == S->size;
}

void Push(Stack *S, Punto punto) {
    if(!StackPieno(S)) {
        S->dato[S->last++] = punto;
    }
}

Punto Pop(Stack *S) {
    Punto p;
    if(StackVuoto(S) || S->dato == NULL ) {
        printf("Errore");
        return p;
    }
    return S->dato[--S->last];
}

void StampaStack(Stack S){
    int k=0;
    char indici[][10] = {"Primo","Secondo","Terzo"};
    while(!StackVuoto(&S)){
        Punto p = Pop(&S);
        printf("%s punto P(%g,%g)\n",indici[k++],p.x,p.y);
    }
}

int main(int argc, const char * argv[]) {
    
    Punto P1,P2,P3;
    P1.x = 12; P1.y = 3;
    P2.x = 14; P2.y = 4;
    P3.x = 7; P3.y = 9;
    
    Stack S;
    CreaStack(&S,10);
    
    Push(&S,P1);
    Push(&S,P2);
    Push(&S,P3);
    
    StampaStack(S);
    LiberaStack(&S);
    
    printf("\n\n");
    return 0;
}
