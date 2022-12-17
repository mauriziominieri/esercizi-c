//
//  main.c
//  Esercizio-7.3
//
//  Created by Maurizio Minieri on 20/12/20.
//
/*
 7.3 Rubrica telefonica
 Si realizzi un programma in linguaggio C in grado di gestire una rubrica di nomi e numeri
 telefonici. La rubrica deve contenere fino a 100 voci diverse. Ciascuna voce è composta da
 un nome (max 40 caratteri) e da un numero di telefono (max 20 caratteri).
 Il programma deve fornire all’utente un menù di scelta, con le seguenti voci:
 1) Aggiungi nuova voce in rubrica
 2) Ricerca esatta per nome
 3) Ricerca approssimata per nome
 4) Stampa completa rubrica
 0) Esci dal programma
 Una volta che l’utente ha scelto l’operazione desiderata (1-4), il programma acquisirà i
 dati necessari dall’utente ed eseguirà il comando. Nota: nella rubrica non possono esistere
 due voci con lo stesso nome.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAXV 100
#define MAXN 40
#define MAXT 20

char rubrica[MAXV][MAXN+MAXT+2]; //per i 2 \0

void inserisci(int* x) {
    while(scanf("%d",x)!=1) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

int menu() {
    int r;
    printf("*---------------------------------*\n");
    printf("|1) Aggiungi nuova voce in rubrica|\n");
    printf("|2) Ricerca esatta per nome\t\t  |\n");
    printf("|3) Ricerca approssimata per nome |\n");
    printf("|4) Stampa completa rubrica\t\t  |\n");
    printf("|0) Esci dal programma\t\t\t  |\n");
    printf("*---------------------------------*\n");
    printf("Inserisci scelta: ");
    inserisci(&r);
    return r;
}

void Pulisci() {
    printf("\n\nPremi Enter per continuare... ");
    char prev=0;

    while(1) {
        char c = getchar();

        if(c == '\n' && prev == c) {
            system("@cls||clear");
            break;
        }
        prev = c;
    }
}

bool findNome(char* nome,int n) {
    char stringa[MAXN+MAXT];
   
    for(int i=0;i<n;i++) {
        strcpy(stringa,rubrica[i]);
        if(strcmp(strtok(stringa,"-"),nome)==0)  //modifica rubrica[i], e quindi perderei il numero se non facessi una copia
            return true;
    }
    return false;
}

bool findNomeA(char* nome,int n) {
    char stringa[MAXN+MAXT];
   
    for(int i=0;i<n;i++) {
        strcpy(stringa,rubrica[i]);
        if(strstr(strtok(stringa,"-"),nome)!=NULL)  //modifica rubrica[i], e quindi perderei il numero se non facessi una copia
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    int r,n=0;
    char nome[MAXN],numero[MAXT];
    
    do {
        r=menu();
        switch(r) {
            case 0:
                printf("\nArrivederci\n");
            break;
            case 1:
                do {
                    printf("Inserisci nome completo: ");
                    scanf("%s",nome);
                }
                while(findNome(nome,n) && printf("Nome già esistente\n"));
                strcat(nome,"-");
                printf("Inserisci telefono: ");
                scanf("%s",numero);
                strcpy(rubrica[n],strcat(nome,numero));
                n++;
                Pulisci();
            break;
            case 2:
                printf("Inserisci nome da cercare: ");
                scanf("%s",nome);
                if(findNome(nome,n))
                    printf("NOME PRESENTE IN RUBRICA\n");
                else
                    printf("NOME NON PRESENTE IN RUBRICA\n");
                Pulisci();
            break;
            case 3:
                printf("Inserisci nome da cercare: ");
                scanf("%s",nome);
                if(findNomeA(nome,n))
                    printf("NOME PRESENTE IN RUBRICA\n");
                else
                    printf("NOME NON PRESENTE IN RUBRICA\n");
                Pulisci();
            break;
            case 4:
                for(int i=0;i<n;i++)
                    printf("VOCE %d: %s\n",i+1,rubrica[i]);
                Pulisci();
            break;
            default:
                printf("Errore\n");
        }
    }
    while(r!=0);
    
    printf("\n\n");
    return 0;
}
