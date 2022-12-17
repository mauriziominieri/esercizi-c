//
//  main.c
//  Esercizio-012
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando un numero generico di interi (es.: 2 3 7 10)
 2) Inserisce i valori in un vettore di interi allocato dinamicamente
 3) Implementa la funzione ricorsiva int SommaPari(int *v, int n) che somma solo i valori pari all’interno dell’array
 Input e Output
 Input: 2 3 7 10
 La somma degli elementi nel vettore è: 12
 */

#include <stdio.h>
#include <stdlib.h>

int SommaPari(int *v, int n) {
    int somma=0;
    if(n==0)
        return (v[0]%2==0) ? v[0] : 0;
    else {
        somma=SommaPari(v, n-1);
        if(v[n]%2==0)
            somma+=v[n];
        return somma;
    }
}

int main(int argc, const char * argv[]) {
    
    if(argc<=1) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int n=argc-1;
    int* v=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        v[i]=atoi(argv[i+1]);
    
    printf("La somma degli elementi nel vettore e': %d\n",SommaPari(v,n-1));
    
    free(v);
    printf("\n");
    return 0;
}
