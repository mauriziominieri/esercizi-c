//
//  main.c
//  Esercizio-018
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende in input una parola dalla linea di comando
 2) Implementa la funzione void SeparaCaratteri(char parola[]) che risistema i caratteri nella parola ponendo prima le vocali e poi le consonanti e restituisce il numero di vocali presenti nella parola.
 Input e Output
 Input: precipitevolissimevolmente
 La parola è: precipitevolissimevolmente
 La parola risultante è: eiieoiieoeeprcptvlssmvlmnt e contiene 11 vocali
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SeparaCaratteri(char parola[]) {
    int n_vocali=0,k=0,j=0;
    printf("La parola risultante è: ");
    for(int i=0;i<strlen(parola);i++) {
        if(parola[i]=='a' || parola[i]=='e' || parola[i]=='i' || parola[i]=='o' || parola[i]=='u')
            n_vocali++;
    }
    
    char vocali[n_vocali+1];
    char consonanti[strlen(parola)-n_vocali+1];
    
    for(int i=0;i<strlen(parola);i++) {
        if(parola[i]=='a' || parola[i]=='e' || parola[i]=='i' || parola[i]=='o' || parola[i]=='u')
            vocali[k++] = parola[i];
        else
            consonanti[j++] = parola[i];
    }
    printf("%s e contiene %d vocali\n",strcat(vocali,consonanti),n_vocali);
}

int main(int argc, const char * argv[]) {
    
    if(argc!=2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    char parola[strlen(argv[1])+1];
    strcpy(parola,argv[1]);
    printf("La parola è: %s\n",parola);
    SeparaCaratteri(parola);
   
    printf("\n");
    return 0;
}
