//
//  main.c
//  Esame_21-01-26
//
//  Created by Maurizio Minieri on 09/02/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct TStack{
    int* V;
} Stack;

void Push(Stack* S, int val) {
    S->V[0]++;
    S->V[S->V[0]] = val;
}

int Pop(Stack* S) {
    S->V[0]--;
    return S->V[S->V[0]+1];
}

void stampa(Stack* S) {
    int k;
    if(S->V[0]>0) {
        k = Pop(S);
        printf("%d ",k);
        stampa(S);
        Push(S,k);
    }
    else
        printf("\n");
}

int main(int argc, const char * argv[]) {
   
    if(argc <= 1 || (atoi(argv[1]) + 2) != argc) {
        printf("Numero di parametri errato\n");
        return 1;
    }
    int m = atoi(argv[1]);
    if(m<=0) {
        printf("Parametri errati\n");
        return 1;
    }
    
    Stack* S;
    S = malloc(sizeof(struct TStack));
    S->V = malloc(m * sizeof(int));
    S->V[0] = 0;
    
    for(int i=0;i<m;i++)
        Push(S,atoi(argv[i+2]));
    
    printf("Il contenuto dello stack e': ");
    stampa(S);
    
    free(S->V);
    free(S);
    printf("\n");
    return 0;
}
