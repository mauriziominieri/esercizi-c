//
//  main.c
//  2019-07-bis
//
//  Created by Maurizio Minieri on 18/07/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//

/*
 #include <stdio.h> #include <string.h> #include <stdlib.h> #define MAX 5
 typedef struct info{
 char stringa[20];
 int dim_stringa; }info;
 //Nuovo tipo di dato
 char * max_parola(char *[]); //determina l’indirizzo della parola più lunga presente nell’array di puntatori a carattere
 info * copia_max(char *); // a partire dall’indirizzo della parola più lunga copia la parola e la sua dimensione in un record di cui restituisce il puntatore
 int main()
 {
 char *data[MAX]={"sole", "tavolo","vetro","finestra","aia"}, *ptr_max;
 info *rec;
 ptr_max=max_parola(data);
 rec=copia_max(ptr_max);
 printf ("%s %d\n", rec->stringa, rec->dim_stringa); //stampa il contenuto del record ossia la parola più lunga e la sua dimensione: nel caso in esame l’output sarà: finestra 8
 }
 A partire dal codice di cui sopra, implementare le seguenti funzioni:
 1. char *max_parola(char *data[]): determina l’indirizzo della parola più lunga presente nell’array di puntatori a carattere e lo restituisce (l’indirizzo);
 2. info * copia_max(char *): ricevuto l’indirizzo della parola più lunga, la copia con la sua dimensione in un record di tipo info di cui restituisce il puntatore.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

typedef struct info{
    char stringa[20];
    int dim_stringa;
} info;




char *max_parola(char *[]);
info *copia_max(char *);

char* max_parola(char *data[]){
    
    char* parola_max=NULL;
    int l_max=0;
    for(int i=0;i<MAX;i++){
        if(l_max<strlen(data[i])){
            l_max=strlen(data[i]);
            parola_max=data[i];
        }
    }
    
    return parola_max;
}

info* copia_max(char *par){
    
    info* i = (info*)malloc(sizeof(info)); //creo un oggetto info allocandogli spazio di memoria
   
    strcpy(i->stringa,par);
    i->dim_stringa=strlen(par);
    
    return i;
}


int main(int argc, const char * argv[]) {
    char *data[MAX]={"sole", "tavolo","vetro","finestra","aia"}, *ptr_max;
    info *rec;
    ptr_max=max_parola(data);
    rec=copia_max(ptr_max);
    printf ("%s %d\n", rec->stringa, rec->dim_stringa);
    return 0;
}
