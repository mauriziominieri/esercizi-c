//
//  main.c
//  2019-01
//
//  Created by Maurizio Minieri on 18/07/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//

/*
 Implementare le seguenti 4 funzioni:
 1. int read_file(FILE *in, char *s): legge una stringa composta da massimo 100 caratteri presente in un file già aperto, non vuoto, il cui puntattore è in.La stringa è memorizzata nel vettore il cui indirizzo base è gestito mediante il puntatore s. (PUNTI 3)
 2. char * store_vect (char *s):la stringa del punto 1, a cui punta s, viene memorizzata in un vettore, allocato dinamicamente, la cui dimensione coincide esattamente con la dimensione della stringa (la stringa è memorizzata in un vettore di 100 caratteri ma potrà essere composta da un numero minore di caratteri). La funzione restituisce l’indirizzo del vettore allocato dinamicamente. (PUNTI 5)
 3. int pal(char *s1): usando la notazione puntatore verifica se la stringa, a cui punta s1, è palindroma, restituendo 1 in caso lo sia o 0 in caso contrario. (PUNTI 11)
 4. char * reverse (char *s1): usando la notazione puntatore inverte la stringa, a cui punta s1, copiandola in un nuovo vettore allocato dinamicamente di cui restituisce l’indirizzo. (PUNTI 11)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR 100

int read_file(FILE *in, char *s);
char * store_vect (char *s);
int pal(char *s1);
char * reverse (char *s1);

int read_file(FILE* in,char* s){
    
    if (in == NULL){
        printf("File non trovato\n");
        return 0;
    }
    
    while (fgets(s, MAXCHAR, in) != NULL)  //verranno letti al massimo 99 caratteri dato che c'è il carattere terminatore
        printf("parola nel file: %s\n", s);
    
    fclose(in);
    
    return 1;
}

char* store_vect(char *s){
    
    char* str=(char*)malloc(strlen(s)+1);  //creo tante celle di memoria quante le lettere in s, più il '/0'
    strcpy(str,s);
    
    printf("parola creata dinamicamente e copiata: %s\n", str);
    return str;
}


int pal (char* s1){

    int l = 0;
    int h = strlen(s1) - 1;
    
    //h=5,l=0  |  h=4,l=1  | h=3,l=2  | h=2,l=3
    while (h > l)
    {
        //primo step: str[0] != str[5]?
        //secondo step: str[1] != str[4]?
        //terzo step: str[2] |= str[3]?
        if (s1[l++] != s1[h--])
        {
            //printf("%s non palindroma\n", str);
            return 0;
        }
    }
    
  //  printf("%s palindroma\n", str);
    return 1;
}

char* reverse(char* s1){
    
    char* s1_reverse=malloc(strlen(s1)+1);
    int i,j=0;
    
    for(i=strlen(s1)-1;i>=0;i--){
        s1_reverse[j] = s1[i];
        j++;
    }
    
    printf("reverse: %s\n", s1_reverse);
    return s1_reverse;
}

int main(int argc, const char * argv[]) {
    
    FILE* in;
    char s[MAXCHAR];
    
    in=fopen("/Users/mauriziominieri/Progetti/Linguaggio-C/Gionata Esposito/2019-01/input.txt","r");
    read_file(in, s);
    char* s1=store_vect(s);
    if(pal(s1)==1)
        printf("palindroma\n");
    else
        printf("NON palindroma\n");
    reverse(s1);
    
    return 0;
}
