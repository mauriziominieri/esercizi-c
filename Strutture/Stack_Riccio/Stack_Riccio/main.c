//
//  main.c
//  Stack_Riccio
//
//  Created by Maurizio Minieri on 25/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../liste.h"


/*Stack Lista*/
typedef struct Stack {
    Nodo_SL *next;
} Stack;

void CreaStack(Stack *S){
    if(S)
        S->next = NULL;
}

void StampaStack(Stack S){
    Nodo_SL *tmp = S.next;
    printf("[Stack]-> ");
    while(tmp && tmp->next){
        printf("%d -> ", tmp->dato);
        tmp = tmp->next;
    }
    if(tmp)
        printf("%d -|", tmp->dato);
}

void Push(Stack *S, int dato){
    if(S)
        InserisciInTesta_SL(S, dato);
}
void Pop(Stack *S, int *dato){
    if(S && S->next){
        *dato = S->next->dato;
        CancellaInTesta_SL(S);
    }
}
void Top(Stack *S, int *dato){
    if(S && S->next){
        *dato = S->next->dato;
    }
}

void LiberaStack(Stack *S){
    if(S)
        LiberaLista_SL(S);
}

int StackVuoto(Stack *S) {
    return (!S || S->next == NULL);
}

//stack con array (limitato)
typedef struct AStack {
    unsigned int size;
    unsigned int last;
    int *dato;  //array di interi
} AStack;

void CreaAStack(AStack *S, unsigned int n) {
    S->size = 0;
    S->last = 0;
    S->dato = (int *)malloc(n*sizeof(int));
    if(S->dato != NULL)
        S->size = n;
    return;
}
void LiberaAStack(AStack *S) {
    if(S != NULL) {
        free (S->dato);
        S->dato = NULL ;
        S->last = 0;
        S->size = 0;
    }
}
int AStackVuoto(AStack *S) {
    return S == NULL || S->last == 0;
}
int AStackPieno(AStack *S) {
    return S == NULL || S->last == S->size;
}

int APush(AStack *S, int dato) {
    if(AStackPieno(S))
        return 1;
    else {
        S->dato[S->last++] = dato;
        return 0;
    }
}
int APop(AStack *S, int *dato) {
    if(AStackVuoto(S) || dato == NULL )
        return 1;
    else {
        *dato = S->dato[S->last-- - 1]; //cambierà per riferimento
        return 0;
    }
}
int ATop(AStack *S, int *dato){
    if(AStackVuoto(S) || dato == NULL )
        return 1;
    else {
        *dato = S->dato[S->last - 1];   //cambierà per riferimento
        return 0;
    }
}
void StampaAStack(AStack S){
    int i=0;
    printf("[Stack]-> ");
    if(AStackVuoto(&S)==0){
        for(i=S.last-1; i>0; i--)
            printf("%d -> ", S.dato[i]);
        printf("%d -|", S.dato[0]);
    }
}

void StampaAStackR(AStack S, int n){
    int dato;
    if(AStackVuoto(&S))
        printf("%d -|", S.dato[0]);
    else {
        if(S.last == n)
            printf("[Stack]-> ");
        APop(&S, &dato);
        if(S.last != 0)
            printf("%d -> ", dato);
        StampaAStackR(S,n);
    }
}

int main(int argc, const char * argv[]) {
    //simulo l'esecuzione da linea di comando.
    argc = 6;
    argv[1] = "13"; argv[2] = "23"; argv[3] = "1"; argv[4] = "6"; argv[5] = "45";
    
    //liste
   /* int dato;
    int i;
    Stack S;
    for(i=1; i<argc; i++)
        Push(&S, atoi(argv[i]));
    StampaStack(S);
    Pop(&S, &dato);
    printf("\nElemento estratto: %d\n", dato);
    StampaStack(S);
    LiberaStack(&S);*/
    
    //array
    int dato;
    AStack S;
    CreaAStack(&S, 100);
    for(int i=1; i<argc; i++)
        APush(&S, atoi(argv[i]));
    StampaAStack(S);
    APop(&S, &dato);    //passaggio per riferimento
    printf("\nElemento estratto: %d\n", dato);
    //StampaAStack(S);
    
    StampaAStackR(S,S.last);
    printf("\n");
    StampaAStack(S);
    
    LiberaAStack(&S);
    printf("\n\n");
    return 0;
}
