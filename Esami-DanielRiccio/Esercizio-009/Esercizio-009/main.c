//
//  main.c
//  Esercizio-009
//
//  Created by Maurizio Minieri on 03/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando una stringa in input e controlla che abbia esattamente 10 caratteri.
 2) Alloca dinamicamente un vettore di caratteri e ci copia dentro la stringa.
 3) Chiede in input un carattere c;
 4) Implementa la funzione int CercaOccorrenze(char *str, char c) che cerca tutte le
 occorrenze del carattere c nella stringa str e restituisce il numero di occorrenze.
 Input e Output
 Inserisci un carattere: f
 Il carattere f compare 1 volte nella stringa abtrafpotn
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CercaOccorrenze(char *str, char c) {
    int volte=0;
    for(int i=0;i<10;i++)
        if(str[i]==c)
            volte++;
    return volte;
}

int main(int argc, const char * argv[]) {
    
    if(argc!=2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    if(strlen(argv[1])!=10) {
        printf("Lunghezza stringa errata\n");
        return 1;
    }
    
    char* str=malloc(11*sizeof(char));
    strcpy(str,argv[1]);
    
    char c;
    printf("Inserisci un carattere: ");
    scanf(" %c",&c);
    
    int volte=CercaOccorrenze(str,c);
    char x = (volte==1) ? 'a' : 'e';
    printf("Il carattere %c compare %d volt%c nella stringa %s\n",c,volte,x,str);
    
    printf("\n");
    return 0;
}
