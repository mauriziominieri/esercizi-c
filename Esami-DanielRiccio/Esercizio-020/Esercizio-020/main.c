//
//  main.c
//  Esercizio-020
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando una parola
 2) Implementa la funzione ricorsiva int Palindroma(char parola[]) che prende in input
 una stringa e restituisce n se è palindroma, dove n è il numero di caratteri nella
 parola e 0 se non è palindroma
 Input e Output
 Input: Onorarono
 La parola contiene 9 caratteri ed è palindroma
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPal(char s[], int i, int f) {
    if (i >= f)
        return true;
    if (s[i] != s[f])
        return false;
    else
        return isPal(s, i + 1, f - 1);
}

int Palindroma(char parola[]) {
    int n = (int)strlen(parola);
    return isPal(parola, 0, n - 1) ? n : 0;
}

int main(int argc, const char * argv[]) {
    
    if(argc!=2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    char parola[strlen(argv[1])+1];
    strcpy(parola,argv[1]);
    int n = Palindroma(parola);
    char c = n==1 ? 'e' : 'i';
    
    if(n==0)
        printf("La parola non è palindroma\n");
    else
        printf("La parola contiene %d caratter%c ed è palindroma\n",n,c);
   
    printf("\n");
    return 0;
}
