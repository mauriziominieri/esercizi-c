//
//  main.c
//  Esercizio-016
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende in input una frase dalla linea di comando
 2) Implementa la funzione void SostituisciVocali(char frase[]) che sostituisce tutte le vocali nella frase con il carattere che rappresenta il numero corrispondente (a-1,e-2, i-3, o-4, u-5)
 Input e Output
 Input: Il gatto salta nella aiuola
 La frase è: Il gatto salta nella aiuola
 La nuova frase è: Il g1tt4 s1lt1 n2ll1 1354l1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SostituisciVocali(char frase[]) {
    printf("La nuova frase è: ");
    for(int i=0;i<strlen(frase)-1;i++) {
        switch(frase[i]) {
            case 'a':
                frase[i]='1';
                break;
            case 'e':
                frase[i]='2';
                break;
            case 'i':
                frase[i]='3';
                break;
            case 'o':
                frase[i]='4';
                break;
            case 'u':
                frase[i]='5';
                break;
        }
    }
    printf("%s\n",frase);
}

int main(int argc, const char * argv[]) {
    
    if(argc<=1) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int l=0,k=0;
    for(int i=1;i<argc;i++)
        l+=strlen(argv[i]);
    l+=argc-2;
    
    char frase[l+1];
    for(int i=1;i<argc;i++) {
        for(int j=0;j<strlen(argv[i]);j++) {
            frase[k++] = argv[i][j];
        }
        frase[k++] = ' ';
    }
    
    printf("La frase è: %s\n",frase);
    SostituisciVocali(frase);
    
    printf("\n");
    return 0;
}
