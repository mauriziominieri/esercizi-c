//
//  main.c
//  Stringhe_maxOccorrenze
//
//  Created by Maurizio Minieri on 03/01/21.
//

/*
 Data una stringa di 10 caratteri stampare il numero massimo di occorrenze di un carattere con il relativo carattere
 */

#include <stdio.h>

#define n 10

void inserimento(char seq[]) {
    printf("Inserisci una sequenza di 10 caratteri\n");
    for(int i=0;i<n;i++) {
        scanf("%c",&seq[i]);
    }
}

void stampa(char seq[]) {
    for(int i=0;i<n;i++)
        printf("%c ",seq[i]);
}

void occorrenze(char seq[]) {
    int conta=1,max=0;
    char maxc='z';
    
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(seq[i]!=seq[j])
                break;
            conta++;
        }
        if(conta>max) {
            maxc=seq[i];
            max=conta;
        }
        conta=1;
    }
    
    printf("\n\nOccorrenze max: %d del carattere %c\n",max,maxc);
}

int main(int argc, const char * argv[]) {
    
    char seq[n+1];
    
    inserimento(seq);
    printf("\nSEQUENZA: ");
    stampa(seq);
    occorrenze(seq);
    
    printf("\n");
    return 0;
}
