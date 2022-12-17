//
//  main.c
//  Esercizio-13
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presa da standard input una sequenza di caratteri terminata
 da un punto, determini e fornisca su standard output il numero di “doppie” presenti nella sequenza (diversi da
 ’spazio’ e ’\n’).
 Esempio:
 Input: Arriverò appena possibile.
 Output: Nella sequenza di input sono presenti 3 doppie.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char c,curr = '\0',prev;
    int doppie=0;
    
    printf("Inserisci una sequenza di caratteri terminata da punto\n");
    do {
        prev = curr;
        scanf(" %c",&c);
        curr = c;
        
        if(curr==prev && curr != '\n' && curr != ' ')
            doppie++;
        
    } while(c!='.');
    
    printf("Nella sequenza di input sono presenti %d doppie",doppie);
    
    printf("\n\n");
    return 0;
}
