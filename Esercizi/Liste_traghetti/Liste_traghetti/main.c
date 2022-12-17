//
//  main.c
//  Liste_traghetti
//
//  Created by Maurizio Minieri on 19/01/21.
//

/*
 Una compagnia di traghetti offre 12 viaggi giornalieri per un'isola (ad es., uno
 ogni ora dalle 8 alle 19), ciascuno identificato da un codice intero compreso tra 0
 e 11.Ogni traghetto della compagnia può trasportare autoveicoli per una lunghezza
 complessiva massima fissata. Il numero di autoveicoli già assegnati e la
 disponibilità residua in metri per ciascuno dei 12 viaggi sono memorizzati in una
 opportuna struttura di dati in memoria centrale.
 Si richiede di risolvere i seguenti punti:
 1. Progettare le strutture di dati da utilizzarsi per risolvere i punti 2 e 3.
 2. Progettare una funzione C che, presi in ingresso attraverso opportuni parametri
 la struttura di dati che memorizza, per ciascuno dei 12 viaggi, il numero di auto
 veicoli già assegnati e la disponibilità residua in metri, la lunghezza in metri di
 un autoveicolo (reale), e il codice di un viaggio per cui è richiesto l'imbarco
 (intero compreso tra 0 e 11),
 restituisca alla funzione chiamante il codice del primo viaggio, da quello
 richiesto in poi, su cui l'autoveicolo può effettivamente essere imbarcato,
 considerando le disponibilità residue e la lunghezza dell'autoveicolo. La
 funzione deve inoltre aggiornare in modo opportuno la struttura di dati passata
 come parametro. Se non vi è più disponibilità residua sufficiente su alcuno dei
 viaggi da quello richiesto in poi, la funzione deve restituire -1 e lasciare
 inalterata la struttura di dati.
 Ad esempio, se al viaggio 5 sono già assegnati 30 autoveicoli con disponibilità
 residua di 4.20 metri, al viaggio 6 sono già assegnati 28 autoveicoli con
 disponibilità residua di 3.40 metri, e al viaggio 7 sono già assegnati 32
 autoveicoli con disponibilità residua di 6.80 metri, allora, ad un autoveicolo di
 4.50 metri che richiede l'imbarco sul viaggio 5, può essere assegnato il viaggio
 7, e per tale viaggio 7 il numero di autoveicoli assegnati diventa 33 con
 disponibilità residua di 2.30 metri.
 3. Le richieste di imbarco sono memorizzate in ordine di arrivo su un file, una
 per riga. Per ogni richiesta sono specificati (separati da spazi bianchi):
 la targa dell'autoveicolo (stringa di 7 caratteri, non contenente spazi
 bianchi), la lunghezza in metri dell'autoveicolo (reale), il codice del viaggio per
 cui è richiesto l'imbarco.
 Progettare una funzione C che, presi in ingresso attraverso opportuni parametri
 il nome di un file di richieste di imbarco e la struttura di dati che memorizza,
 per ciascuno dei 12 viaggi, la disponibilità residua in metri e il numero di
 autoveicoli già assegnati, costruisca e restituisca alla funzione chiamante una
 lista, rappresentata attraverso strutture e puntatori, in cui ciascun elemento
 contiene la targa di un autoveicolo ed il codice del viaggio che gli viene
 assegnato. Gli autoveicoli devono comparire nella lista nello stesso ordine che
 avevano nel file. Gli autoveicoli a cui non può essere assegnato alcun viaggio
 non devono comparire nella lista. La funzione deve inoltre aggiornare la
 struttura di dati passata come parametro in base alle assegnazioni effettuate.
 Ovviamente, per determinare il codice del viaggio a cui un autoveicolo può
 essere assegnato, la funzione dovrà attivare in modo opportuno la funzione
 sviluppata al punto 2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    int n_veicoli;
    float lunghezza_max;
    int codice;
} Viaggio;

typedef struct lista {
    char targa[8];
    int codice;
    struct lista* next;
} *Nodo;

bool checkIntero(float n) {
    int tmp=floor(n);
    return (tmp==n) ? true : false;
}

int inserisciIntero(float* x) {
    while(scanf("%f",x)!=1 || !checkIntero(*x)) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}

float inserisciReale(float* x) {
    while(scanf("%f",x)!=1) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}

int richiede(Viaggio viaggi[],float lung,int codice) {
    
    /*float tmp,lung;
    int n_viaggio;
    printf("Inserisci il numero del viaggio sul quale vuoi richiedere l'imbarco(0-11): ");
    do {
        codice=inserisciIntero(&tmp);
    } while((n_viaggio<0 || n_viaggio>11) && printf("Riprova: "));
    printf("Inserisci la lunghezza del veicolo: ");
    lung = inserisciReale(&tmp);*/
    
    for(int i=codice;i<12;i++) {
        if(viaggi[i].lunghezza_max >= lung) {
            viaggi[i].n_veicoli++;
            viaggi[i].lunghezza_max -= lung;
            return i;
        }
    }
    return -1;
}

Nodo creaLista(Viaggio viaggi[], char nomeFile[]) {
    FILE* fp;
    fp = fopen(nomeFile,"r");
    
    if(fp == NULL) {
        printf("Impossibile aprire il file %s\n",nomeFile);
        return NULL;
    }
    
    char riga[MAX],targa[8];
    float lung;
    int codice;
    
    Nodo top = NULL, tmp = NULL, curr = tmp;
    
    while(fgets(riga,MAX,fp)) {
        if(sscanf(riga,"%7s %f %d",targa,&lung,&codice)==3 && codice>=0 && codice<=11) {
            int r = richiede(viaggi,lung,codice);
            if(r!=-1) {
                tmp = malloc(sizeof(struct lista));
                strcpy(tmp->targa,targa);
                tmp->codice = r;
                tmp->next = NULL;
                if(!top) {
                    curr = tmp;
                    top = tmp;
                }
                else {
                    curr->next = tmp;
                    curr = tmp;
                }
            }
        }
    }
    
    fclose(fp);
    return top;
}

void stampaLista(Nodo top) {
    if(top == NULL)
        printf("NULL\n");
    else {
        printf("(%s %d)->",top->targa,top->codice);
        stampaLista(top->next);
    }
}

int main(int argc, const char * argv[]) {
    Viaggio viaggi[12];
    
    viaggi[0].codice = 0; viaggi[1].codice = 1; viaggi[2].codice = 2; viaggi[3].codice = 3;     viaggi[4].codice = 4; viaggi[5].codice = 5; viaggi[6].codice = 6; viaggi[7].codice = 7; viaggi[8].codice = 8; viaggi[9].codice = 9; viaggi[10].codice = 10; viaggi[11].codice = 11;
    
    viaggi[5].n_veicoli = 30;       //30 autoveicoli
    viaggi[5].lunghezza_max = 4.20;     //4.20 metri rimasti
    viaggi[6].n_veicoli = 28;   viaggi[6].lunghezza_max = 3.40;
    viaggi[7].n_veicoli = 32;   viaggi[7].lunghezza_max = 6.80;
    
    Nodo top = creaLista(viaggi,"richieste.txt");
    stampaLista(top);
    
    printf("\nNel viaggio 5 e' rimasto %.2f spazio\n",viaggi[5].lunghezza_max);
    printf("Nel viaggio 6 e' rimasto %.2f spazio\n",viaggi[6].lunghezza_max);
    printf("Nel viaggio 7 e' rimasto %.2f spazio\n",viaggi[7].lunghezza_max);
    
    printf("\n");
    return 0;
}
