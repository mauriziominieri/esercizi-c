//
//  main.c
//  Esercizio-005
//
//  Created by Maurizio Minieri on 03/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende in input 8 valori interi da linea di comando e li inserisce in un vettore
 di interi.
 2) Implementa la funzione ricorsiva int recursive_max(int v[], int n)
 3) Stampa il valore massimo
 Input e Output
 Input: 5 2 8 34 3 45 3 12
 Il massimo è: 45
 */

#include <stdio.h>
#include <stdlib.h>

int recursive_max(int v[], int n) {
    int max=0;
    if(n==0)
        return v[n];
    else {
        max=recursive_max(v,n-1);
        /*printf("v[n]=%d\n",v[n]);
        printf("max=%d\n",max);
        if(v[n]>max)
            return v[n];
        else
            return max;*/
        return (v[n] > max) ? v[n] : max;
    }
}

int main(int argc, const char * argv[]) {
    
    if(argc!=9) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int v[8];
    for(int i=0;i<8;i++)
        v[i]=atoi(argv[i+1]);
    
    printf("Il massimo è: %d\n",recursive_max(v,7));
    
    printf("\n");
    return 0;
}
