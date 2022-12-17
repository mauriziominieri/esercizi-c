//
//  main.c
//  Esercizio-001
//
//  Created by Maurizio Minieri on 02/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende in input da linea di comando 8 caratteri e li inserisce in un vettore.
 2) Trova il carattere con il massimo valore ASCII.
 3) Sostituisce nel vettore tutte le occorrenze del carattere con uno spazio vuoto.
 Input: a t e r z o i w
 Output:
 il carattere con valore massimo è: z
 il vettore senza il carattere con valore ASCII massimo è: ater oiw
 */

#include <stdio.h>

#define n 8

//argc = 2
//argv[0] = ./main
//argv[1] = aterzoiw
//v[8] = [a][t][e][r][z][o][i][w]

int main(int argc, const char * argv[]) {
   
    char v[n+1];
    int max_c=0;
    
    if(argc!=2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    for(int i=0;i<n;i++)
        v[i]=argv[1][i];
    
    for(int i=0;i<n;i++)
        if(v[i]>max_c)
            max_c=v[i];
    
    printf("il carattere con valore massimo e': %c\n",max_c);
    
    for(int i=0;i<n;i++)
        if(v[i]==max_c)
            v[i]=' ';
    
    printf("il vettore senza il carattere con valore ASCII massimo è: %s\n",v);
        
    printf("\n");
    return 0;
}
