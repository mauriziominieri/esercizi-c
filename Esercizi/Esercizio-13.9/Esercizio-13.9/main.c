//
//  main.c
//  Esercizio-13.9
//
//  Created by Maurizio Minieri on 17/01/21.
//

/*
 Gioco dell’impiccato
 Si realizzi un programma in linguaggio C che permetta di giocare al gioco dell’impiccato. Il
 gioco si svolge tra due giocatori: il primo giocatore inserisce la parola segreta da indovinare,
 mentre il secondo la deve indovinare.
 Il secondo giocatore conosce la lunghezza della parola segreta, e ad ogni tentativo specifica una lettera (si considerino le lettere maiuscole equivalenti alle minuscole): se tale lettera compare nella parola, il programma indica in quali posizioni, altrimenti il tentativo è considerato un errore.
 Il gioco termina quando il secondo giocatore ha indovinato tutte le lettere della parola (ed in tal caso egli vince) oppure quando ha totalizzato 10 errori (nel qual caso perde).
 Esempio:
 Giocatore 1, immetti la parola segreta: Esame
 Giocatore 2, indovina!
 La parola e’: _ _ _ _ _
 Tentativo? e
 Indovinato! La parola e’: E _ _ _ E
 Tentativo? o
 Errore! La parola e’: E _ _ _ E
 Tentativo? a
 Indovinato! La parola e’: E _ A _ E
 . . . e così via.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define LUN 32

void stampaParola(char parola[]) {
    for(int i=0;i<strlen(parola);i++)
        printf("%c ",parola[i]);
}

bool checkPresenza(char lettere[],char c) {
    for(int i=0;i<strlen(lettere);i++)
        if(lettere[i] == c)
            return true;
    return false;
}

bool gioco(char parola[]) {
    int conta=0;
    for(int i=0;i<strlen(parola);i++)
        conta++;
    char parola2[conta+1];
    char lettere[26];
    for(int i=0;i<strlen(parola);i++)
        parola2[i] = '_';
    lettere[0] = '\0';
    printf("TENTATIVI: %d, lettere inserite: ",10);
    stampaParola(lettere);
    stampaParola(parola2);
    int n=10,lettere_indovinate=0,k=0;
    char c;
    bool ok = false;
    do {
        printf("\n\nInserisci una lettera: ");
        do {
            scanf(" %c",&c);
        } while(checkPresenza(lettere,c) && printf("Lettera già inserita, riprova: "));
        lettere[k++] = c;
        lettere[k] = '\0';
        for(int i=0;i<strlen(parola);i++) {
            if(parola[i] == c) {
                parola2[i] = c;
                ok = true;
                lettere_indovinate++;
            }
        }
        
        if(!ok)
           n--;

        system("clear");
        
        printf("TENTATIVI: %d, lettere inserite: ",n);
        stampaParola(lettere);
        printf("\n\n");
        stampaParola(parola2);
        
        
        if(n==0)
            return false;
        if(lettere_indovinate==strlen(parola2))
           return true;
        
        ok = false;
    }
    while(1);
}


int main(int argc, const char * argv[]) {
   
    char parola[LUN];
    printf("Giocatore 1, immetti la parola segreta: ");
    scanf("%s",parola);
    system("clear");
    printf("Giocatore 2, indovina!\n\n");
    
    if(gioco(parola))
        printf("\n\nHAI VINTO\n");
    else {
        printf("\n\nHAI PERSO\n");
        printf("La parola era: %s\n",parola);
    }
    
    printf("\n");
    return 0;
}
