//
//  main.c
//  Esercizio-011b
//
//  Created by Maurizio Minieri on 07/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando una parola
 2) Implementa la funzione ricorsiva void stampa_inversa(char stringa[], int n), che stampa la parola al contrario
 Input e Output
 Input: acetone
 La stringa è: acetone
 La stringa inversa è: enoteca
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stampa_inversa(const char stringa[], int n) {
    
    if(n==0)
        printf("%c",stringa[0]);
    else {
        printf("%c",stringa[n]);
        stampa_inversa(stringa, n-1);
    }
}

int main(int argc, const char * argv[]) {
  
    if(argc!=2) {
        printf("Numero parametri errato\n");
        return 1;
    }

    printf("La stringa e': %s\n",argv[1]);
    printf("La stringa inversa e': ");
    stampa_inversa(argv[1],(int)strlen(argv[1])-1);
    
    printf("\n");
    return 0;
}
