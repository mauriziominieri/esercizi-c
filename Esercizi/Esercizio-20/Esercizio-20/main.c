//
//  main.c
//  Esercizio-20
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presa da standard input una sequenza qualunque di caratteri
 (inclusi ’spazio’, ’\n’ e ’\t’) terminata con un ’.’, conti e fornisca su standard output
 1. il numero di caratteri;
 2. il numero di parole;
 3. il numero di linee.
 */

#include <stdio.h>
#include <string.h>
#define LENGTH 2000

int main(int argc, const char * argv[]) {
    
    char sequenza[LENGTH];
    int parole=1,linee=1,i=0;
    printf("Inserisci una sequenza di caratteri terminata con un punto\n");
    while(sequenza[i++]!='.') {
        sequenza[i]=getchar();  //getchar per far in modo che ' ' oppure '\n' '\t'...
        if(i>=LENGTH || sequenza[i]=='.') break;
        if(sequenza[i]==' ' || sequenza[i]=='\n') parole++;
        if(sequenza[i]=='\n') linee++;
    }
    
    printf("\nNumero caratteri: %d\n",i);
    printf("Numero parole: %d\n",parole);
    printf("Numero linee: %d",linee);
    
    printf("\n");
    return 0;
}
