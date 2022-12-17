//
//  main.c
//  Esercizio-010-Puntatori
//
//  Created by Maurizio Minieri on 30/12/20.
//
/*
 Scrivere un programma che acquisisca i dati relativi agli studenti
 di una classe:
 •nome
 •cognome
 •data di nascita (struct con giorno mese anno)
 •indirizzo (struct con via, numero civ, cap, citta, provincia)
 •voti – rappresenta i voti dello studente in 3 materie
 (italiano, matematica, inglese);
 Il programma deve successivamente calcolare e stampare, per
 ogni studente, la media dei voti ottenuti nelle 3 materie
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAXS 32
#define MAXC 5
#define MAXP 2

const int nMaterie = 3;
const char materie[][MAXS] = {"italiano","matematica","inglese"};

typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct {
    char via[MAXS],citta[MAXS],cap[MAXC+1],prov[MAXP+1];
    int numCiv;
} Indirizzo;

typedef struct {
    char nome[MAXS];
    char cognome[MAXS];
    Data* data;
    Indirizzo* indirizzo;
    int* voti;
} Studente;

bool checkIntero(float x) {
    int tmp = floor(x);
    if(tmp==x) return true;
    else return false;
}

int inserisciInteroM0(float* x) {
    while(scanf("%f",x)!=1 || *x<=0 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}

bool checkGM(int giorno, int mese) {
    if(giorno<1 || giorno>31 || mese<1 || mese>12)
        return false;
    
    switch(mese) {
        case 2:
                if(giorno>28)
                    return false;
            break;
        case 4:
                if(giorno>30)
                    return false;
            break;
        case 6:
                if(giorno>30)
                    return false;
            break;
        case 9:
            if(giorno>30)
                return false;
            break;
        case 11:
            if(giorno>30)
                return false;
            break;
    }
    
    return true;
}

bool checkAnno(int anno) {
    if(anno<1900 || anno>2010) //massimo 120 e minimo 10 anni
        return false;
    return true;
}

Studente** creaStudenti(int n) {
    Studente** studenti;
    studenti = malloc(n*sizeof(Studente*));
    for(int i=0;i<n;i++) {
        studenti[i] = malloc(sizeof(Studente));
        studenti[i]->data = malloc(sizeof(Data));
        studenti[i]->indirizzo = malloc(sizeof(Indirizzo));
        studenti[i]->voti = malloc(nMaterie*sizeof(int));
    }
    return studenti;
}

void stampaStudenti(Studente** studenti,int n) {
    int somma=0;
    printf("\nELENCO STUDENTI\n");
    for(int i=0;i<n;i++) {
        printf("%d° studente: ",i+1);
        printf("%s %s - ",studenti[i]->nome,studenti[i]->cognome);
        printf("%d/%d/%d - ",studenti[i]->data->giorno,studenti[i]->data->mese,studenti[i]->data->anno);
        printf("via %s %d, %s, %s (",studenti[i]->indirizzo->via,studenti[i]->indirizzo->numCiv,studenti[i]->indirizzo->cap,studenti[i]->indirizzo->citta);
        for(int j=0;j<strlen(studenti[i]->indirizzo->prov);j++)
            printf("%c",toupper(studenti[i]->indirizzo->prov[j]));
        printf(")\n[");
        for(int j=0;j<nMaterie;j++) {
            if(j<nMaterie-1)
                printf("%s: %d, ",materie[j],studenti[i]->voti[j]);
            else
                printf("%s: %d",materie[j],studenti[i]->voti[j]);
            somma += studenti[i]->voti[j];
        }
        printf("] media: %f\n",(float)somma/nMaterie);
        somma=0;
    }
}

int main(int argc, const char * argv[]) {
    
    float tmp;
    int n;
    
    printf("Inserisci il numero di studenti: ");
    n=inserisciInteroM0(&tmp);
    while(getchar()!='\n');
    
    Studente** studenti = creaStudenti(n);
    
    for(int i=0;i<n;i++) {
        printf("%d° studente\n",i+1);
        printf("Inserisci nome: ");
        gets(studenti[i]->nome);
        printf("Inserisci cognome: ");
        gets(studenti[i]->cognome);
        do {
            printf("Nascita - Inserisci giorno: ");
            studenti[i]->data->giorno=inserisciInteroM0(&tmp);
            printf("Inserisci mese: ");
            studenti[i]->data->mese=inserisciInteroM0(&tmp);
        }
        while(checkGM(studenti[i]->data->giorno,studenti[i]->data->mese)==false && printf("Riprova "));
        printf("Inserisci anno: ");
        do {
            studenti[i]->data->anno=inserisciInteroM0(&tmp);
        }
        while(checkAnno(studenti[i]->data->anno)==false && printf("Riprova: "));
        while(getchar()!='\n');
        printf("Inserisci via: ");
        gets(studenti[i]->indirizzo->via);
        printf("Inserisci numero civico: ");
        studenti[i]->indirizzo->numCiv=inserisciInteroM0(&tmp);
        while(getchar()!='\n');
        printf("Inserisci CAP: ");
        gets(studenti[i]->indirizzo->cap);
        printf("Inserisci citta': ");
        gets(studenti[i]->indirizzo->citta);
        printf("Inserisci provincia: ");
        gets(studenti[i]->indirizzo->prov);
        for(int j=0;j<nMaterie;j++) {
            printf("Inserisci il voto in %s: ",materie[j]);
            do {
                studenti[i]->voti[j]=inserisciInteroM0(&tmp);
            }
            while(studenti[i]->voti[j]>30 && printf("Riprova: "));
        }
        while(getchar()!='\n');
    }
    
    stampaStudenti(studenti,n);
    
    printf("\n");
    return 0;
}
