//
//  main.c
//  Esercizio-32
//
//  Created by Maurizio Minieri on 20/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che acquisisca da standard input un testo composto da al più 1000
 righe, ciascuna di al più 100 caratteri.
 L’inserimento termina
 • o quando l’utente inserisce una riga che contiene FINE;
 • oppure quando sono state inserite 1000 righe.
 Al termine dell’acquisizione del testo, occorre fornire su standard output le seguenti informazioni:
 1. il numero di righe inserite (esclusa eventualmente la riga che contiene FINE);
 2. il numero di caratteri inseriti;
 3. il numero di caratteri alfanumerici inseriti; (a-z,A-Z,0-9)
 4. il numero di parole inserite.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXR 1000
#define MAXC 100

int main(int argc, const char * argv[]) {
   
    //ALLOCAZIONE DINAMICA DELLA MEMORIA
    char **str;
    str = malloc(MAXR * sizeof(char*));
    for(int i=0;i<MAXR;i++)
        str[i] = malloc(MAXC * sizeof(char));
    
    //ALLOCAZIONE STATICA
    //char str[MAXR][MAXC];
    int i=0, parole=0, caratteri=0, caratteriAlfanumerici=0;

    printf("Inserisci un testo\n");
    for(i=0;i<MAXR;i++) {
        printf("Scrivi la %d° riga: ",i+1);
        gets(str[i]);
        //fgets(str[i], MAXC, stdin);  //ti legge anche i "\n"
        //scanf("%s",str[i]); //non va bene perchè vede gli spazi come se fossero dei daccapo e quindi li mette in altre righe
        
        if(strstr(str[i],"FINE")!=NULL)
            break;
    }
    
    i=0;
    printf("\nScrivo il mio testo\n");
    while(strstr(str[i],"FINE")==NULL) {  //FINCHE' non incontro la parola FINE
        printf("RIGA %d: ",i+1);
        printf("%s\n",str[i]);
        i++;
    }
   
    i=0;
    int j=0;
    while(strstr(str[i],"FINE")==NULL) {  //FINCHE' non incontro la parola FINE
        while(str[i][j] != '\0') {
            //putchar(str[i][j]);
            caratteri++;
            if(str[i][j] == ' ') {
                parole++;
                //printf("\nIncremento parole: %d\n",parole);
            }
            if((str[i][j] >= 'a' && str[i][j] <= 'z') || (str[i][j] >= 'A' && str[i][j] <= 'Z') || (str[i][j] >= '0' && str[i][j] <= '9'))
                caratteriAlfanumerici++;
            j++;
        }
        
        i++;
        parole++;
        j=0;
        //printf("\ncambio riga, incremento le parole: %d\n",parole);
    }
    
    printf("\nIl numero totale di righe è: %d",i);
    printf("\nIl numero totale di caratteri è: %d",caratteri);
    printf("\nIl numero totale di caratteri alfanumerici è: %d",caratteriAlfanumerici);
    printf("\nIl numero totale di parole è: %d",parole);
    
    
    //L'ALLOCAZIONE ESPLICITA CON LA MALLOC NON PREVEDE UNA LIBERAZIONE AUTOMATICA DEI BYTE.
    /*for(int i=0;i<MAXR;i++)
        free(str[i]);
    free(str);*/
    
    printf("\n\n");
    return 0;
}
