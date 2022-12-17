//
//  main.c
//  Esercizio-7.4
//
//  Created by Maurizio Minieri on 21/12/20.
//

#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAXL 30

void inserisciInt(int* x) {
    while(scanf("%d",x)!=1) {
        printf("Quantita' non valida,riprova: ");
        while(getchar()!='\n');
    }
}

void inserisciChar(char* x) {
    while(scanf(" %c",x)!=1 || (*x!='e' && *x!='u')) {
        printf("Lettera non valida,riprova: ");
        while(getchar()!='\n');
    }
}

int findProduct(char magazzino[][MAXL],char prodotto[],int n) {
    for(int i=0;i<n;i++) {
        if(strcmp(magazzino[i],prodotto)==0)
            return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    char magazzino[MAX][MAXL];
    char prodotto[MAXL];
    char tipo;
    int quantità[MAX],n=0,trovato,qta;
    
    printf("Inserisci comandi nel formato: prodotto E/U quantità. FINE per terminare\n");
    do {
        scanf("%s",prodotto);
        if(strcmp(prodotto,"FINE")==0)
            break;
        scanf(" %c",&tipo);
        inserisciInt(&qta);
        trovato=findProduct(magazzino,prodotto,n);
        if(qta>0 && (tipo=='E' || tipo=='e')) {
            if(trovato>-1)  //trovato
                quantità[trovato] += qta;
            else {
                strcpy(magazzino[n],prodotto);
                quantità[n]=qta;
                n++;
            }
        }
        else if(qta>0 && (tipo=='U' || tipo=='u')) {
            if(trovato>-1)  //trovato
                if(quantità[trovato]>=qta)
                    quantità[trovato] -= qta;
                else
                    printf("Errore, quantità massima raggiunta\n");
            else
                printf("Errore, prodotto non presente\n");
        }
        else if(qta<=0)
            printf("Errore, quantità non valida\n");
        else
            printf("Errore, lettera non valida, comando ignorato.\n");
    }
    while(strcmp(prodotto,"FINE")!=0);
    
    if(n<=0)
        printf("\nNon ci sono prodotti nel magazzino");
    else {
        printf("\nI prodotti presenti nel magazzino\n");
        for(int i=0;i<n;i++)
            printf("%s: %d\n",magazzino[i],quantità[i]);
    }
    
    printf("\n\n");
    return 0;
}
