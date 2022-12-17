//
//  main.c
//  Esercizio-015
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando 2 parole di lunghezza pari
 2) Implementa la funzione void CombinaParole(char parol1[], char parola2[]) che
 concatena la seconda metà della seconda parola alla prima metà della prima parola e
 la seconda metà della prima parola alla prima metà della seconda parola (vedi
 esempio).
 Input e Output
 Input: sottotetto costantinopoli
 La parola 1 è: sottotetto
 La parola 2 è: costantinopoli
 La parola 1 è: sottoinopoli
 La parola 2 è: costanttetto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CombinaParole(char parola1[], char parola2[]) {
    int l1=strlen(parola1);
    int l2=strlen(parola2);
    int l3=l1/2+l2/2;
    char parola3[l3+1];
    
    int k = l2/2;
    for(int i=0;i<l3;i++) {
        parola3[i] = (i<l1/2) ? parola1[i] : parola2[k++];
    }
    printf("%s\n",parola3);
}

int main(int argc, const char * argv[]) {
   
    if(argc!=3) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    if(strlen(argv[1])%2!=0 || strlen(argv[2])%2!=0) {
        printf("Lunghezze parole errate\n");
        return 1;
    }
    
    char parola1[strlen(argv[1])+1];
    char parola2[strlen(argv[2])+1];
    
    strcpy(parola1,argv[1]);
    strcpy(parola2,argv[2]);
    
    printf("La parola 1 è: %s\n",argv[1]);
    printf("La parola 2 è: %s\n",argv[2]);
    printf("La parola 1 è: ");
    CombinaParole(parola1,parola2);
    printf("La parola 2 è: ");
    CombinaParole(parola2,parola1);
    
    printf("\n");
    return 0;
}
