//
//  main.c
//  Esercizio-19
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presa da standard input una sequenza di al più 32 caratteri,
 conti il numero di vocali ’a’ fino al primo punto, fornendo in output detto numero.
 */

#include <stdio.h>
#include <string.h>
#define LENGTH 32

int main(int argc, const char * argv[]) {
    
    char sequenza[LENGTH];
    int vocali = 0;
    
    printf("Inserisci una sequenza di al più 32 caratteri: ");
    fgets(sequenza, LENGTH, stdin);
    
    for(int i=0;i<strlen(sequenza);i++) {
        if(sequenza[i]=='.') break;
        if(sequenza[i]=='a') vocali++;
    }
    
    printf("Numero vocali: %d",vocali);
    printf("\n\n");
    return 0;
}
