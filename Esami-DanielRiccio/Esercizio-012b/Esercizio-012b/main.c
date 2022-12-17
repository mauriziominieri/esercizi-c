//
//  main.c
//  Esercizio-012b
//
//  Created by Maurizio Minieri on 07/01/21.
//

/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando una serie di numeri
 2) Implementa la funzione ricorsiva void separa_valori(int V[], int n), che stampa prima tutti i valori pari e poi tutti quelli dispari
 Input e Output
 Input: 1 2 3 4 5 6 7
 La partizione è: 6 4 2 1 3 5 7
 */

#include <stdio.h>
#include <stdlib.h>

void separa_valori(int V[], int n) {
    if(n==0)
        printf("%d ",V[n]);
    else {
        if(V[n]%2==0)
            printf("%d ",V[n]);
        separa_valori(V,n-1);
        if(V[n]%2!=0)
            printf("%d ",V[n]);
    }
}

int main(int argc, const char * argv[]) {
    
    if(argc<2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int n=argc-1;
    int V[n];
    for(int i=0;i<n;i++)
        V[i]=atoi(argv[i+1]);
    
    separa_valori(V,n-1);
    
    printf("\n");
    return 0;
}
