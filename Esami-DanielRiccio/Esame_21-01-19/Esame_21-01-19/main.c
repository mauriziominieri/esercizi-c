//
//  main.c
//  Esame_21-01-19
//
//  Created by Maurizio Minieri on 09/02/21.
//

/*
 Data una parola da linea di comando inserirla in una lista e stamparla
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char key;
    struct lista* next;
} Carattere;

Carattere* crea_lista(const char parola[]) {
    Carattere* top = NULL, *tmp = NULL;
    
    for(int i=strlen(parola)-1;i>=0;i--) {
        tmp = malloc(sizeof(struct lista));
        tmp->key = parola[i];
        tmp->next = top;
        top = tmp;
    }
    tmp = top;
    while(tmp) {
        printf("%c -> ",tmp->key);
        tmp = tmp->next;
    }
    printf("NULL");
    
    return tmp;
}

int main(int argc, const char * argv[]) {
    
    if(argc != 2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    Carattere* top = crea_lista(argv[1]);
    Carattere* tmp = NULL;
    while(top) {
        tmp = top;
        top = top->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
