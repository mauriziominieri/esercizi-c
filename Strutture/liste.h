//
//  main.c
//  Stack_Riccio
//
//  Created by Maurizio Minieri on 25/02/21.
//

#include <stdio.h>
#include <stdlib.h>

/*Lista*/
typedef struct Nodo_SL {
    int dato;
    struct Nodo_SL *next;
} Nodo_SL;

typedef struct Lista_SL {
    Nodo_SL *next;
} Lista_SL;

Nodo_SL *CreaNodo_SL(int dato) {
    Nodo_SL *tmp;
    tmp = (Nodo_SL *)malloc(sizeof(Nodo_SL));
    if(!tmp)
        return NULL;
    else {
        tmp->next = NULL;
        tmp->dato = dato;
    }
    return tmp;
}

void InserisciInTesta_SL(Lista_SL *Testa, int dato)
{
    Nodo_SL *temp = NULL;
    if(!Testa->next){
        temp = CreaNodo_SL(dato);
        if(temp){
            Testa->next = temp;
            return;
        }
    }
    else {
        temp = CreaNodo_SL(dato);
        if(temp){
            temp->next = Testa->next;
            Testa->next = temp;
        }
    }
    return;
}

void CancellaInTesta_SL(Lista_SL *Testa) {
    Nodo_SL *q = Testa->next;
    if(!q)
        return;
    else {
        if(q->next)
            Testa->next = q->next;
        else
            Testa->next = NULL;
        free(q);
    }
}

void LiberaLista_SL(Lista_SL *Testa) {
    Nodo_SL *tmp = Testa->next;
    while(Testa->next){
        tmp = Testa->next;
        Testa->next = tmp->next;
        free(tmp);
    }
    Testa->next = NULL;
}
