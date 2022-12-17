//
//  main.c
//  Esercizio-24
//
//  Created by Maurizio Minieri on 11/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, letta da standard input una sequenza di caratteri (di lunghezza
 massima n) e terminata da un ’.’, controlli se la sequenza è palindroma.
 Esempi:
 radar e abba sono palindrome.
 abcabc non è palindroma.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool checkIntero(float x) {
    int tmp=floor(x);
    if(tmp==x) return true;
    else return false;
}

int inserisciInteroM0(float* x) {
    while(scanf("%f",x)!=1 || *x<=0 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}

int pal (char s1[]){
    
    if(s1[strlen(s1)-1]=='.')  //se l'ultimo carattere è un punto
        s1[strlen(s1)-1] = '\0';  //ci metto null, quindi tolgo il punto
    
    int i = 0;  //inizio
    long f = strlen(s1) - 1;  //in realtà  mela è mela\0 , dove \0 è il carattere null, e strlen conta fino a quel carattere
    //con mela h è 4
    
    while (f > i) {
        if (s1[i++] != s1[f--]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    
    float tmp;
    int n = 2;
    
    printf("Inserisci lunghezza massima(>0): ");
    n=inserisciInteroM0(&tmp);
    
    char parola[n];
    
    printf("Inserisci sequenza terminata da un punto\n");
    /*for(int i=0;i<n;i++) {
        scanf(" %c",&parola[i]);
        if(parola[i]=='.')
            break;
    }*/
    scanf("%s",parola);
    
    if(pal(parola)==1)
        printf("\n%s è palindroma\n", parola);
    else
        printf("\n%s NON è palindroma\n", parola);
    
    printf("\n\n");
    return 0;
}
