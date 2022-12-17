//
//  main.c
//  Esercizio-15
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, preso da standard input un voto numerico compreso fra 0 e
 10, converta il voto in giudizio secondo la seguente corrispondenza:
 voto ≤ 5 =⇒ insufficiente;
 5 < voto ≤ 6.5 =⇒ sufficiente;
 6.5 < voto ≤ 7.5 =⇒ buono;
 voto > 7.5 =⇒ ottimo.
 Al termine di ogni operazione di conversione, il programma deve richiedere all’utente se vuole continuare o meno e,
 in caso di risposta positiva (carattere ’s’), acquisisce il dato ed effettua la nuova conversione.
 */

#include <stdio.h>
#include <stdlib.h>

void inserisci(float* x) {
    while(scanf("%f",x)!=1 || *x<0 || *x>10) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

int main(int argc, const char * argv[]) {
    
    float n;
    char c;
    
    do {
        printf("Inserisci un numero compreso tra 0 e 10: ");
        //do {
        inserisci(&n);
        //} while((n<0 || n>10) && printf("Riprova: "));
        
        if(n<=5) printf("Insufficiente");
        else if(n<=6.5) printf("Sufficiente");
        else if(n<=7.5) printf("Buono");
        else printf("Ottimo");
        
        printf("\nVuoi continuare? [s/n]: ");
        scanf(" %c",&c);
        if(c=='s'||c=='S')
            system("@cls||clear");
    }
    while(c=='s' || c=='S');
    
    printf("\n");
    return 0;
}
