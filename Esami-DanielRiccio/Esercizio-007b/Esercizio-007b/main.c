//
//  main.c
//  Esercizio-007b
//
//  Created by Maurizio Minieri on 05/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Definisce un tipo Stack come un record che include un vettore di interi
 2) Implementa le funzioni void Push(Stack *S, int val) e int Pop(Stack *S)
 3) Legge da riga di comando un intero m e alloca dinamicamente il vettore dello stack con dimensione m. Legge da riga di comando m valori interi e li inserisce nello stack con la funzione Push. Stampa a video i valori estratti dallo stack con la funzione Pop finché lo stack non è vuoto.
 Input e Output
 Input: 6 1 2 3 4 5 6
 Output:
 Il contenuto dello stack è: 6 5 4 3 2 1
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* v;
} Stack;

void Push(Stack *S, int val) {
    S->v[0] += 1;
    S->v[S->v[0]]= val;
}

int Pop(Stack *S) {
    S->v[0] -= 1;
    return S->v[S->v[0]+1];
}

int main(int argc, const char * argv[]) {
    
    if(argc<=1) {
        printf("Numero parametri errato\n");
        return 1;
    }
    int m=atoi(argv[1]);
    int val=0;
    if(m!=argc-2) {
        printf("Numero interi non corrispondente con M (primo argomento)\n");
        return 1;
    }
    
    Stack* S=malloc(sizeof(Stack));
    S->v=malloc(m*sizeof(int));
    S->v[0] = 0;
    
    for(int i=0;i<m;i++)
        Push(S,atoi(argv[i+2]));
    
    printf("Il contenuto dello stack è: ");
    while ((val = Pop(S)) > 0)
        printf("%d ", val);
    free(S->v);
    
    printf("\n");
    return 0;
}
