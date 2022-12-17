//
//  main.c
//  Esercizio-002b
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende da linea di comando 10 interi e li inserisce in un vettore
 2) Implementa la funzione ricorsiva int Conta_Occorrenze(int V[], int n, int val) che restituisce il numero di volte che il valore val compare nel vettore V.
 Input e Output
 Input: 5 8 6 12 9 5 2 5 1 8
 Output:
 Il valore 5 compare 3 volte
 */

#include <stdio.h>
#include <stdlib.h>

int Conta_Occorrenze(int V[], int n, int val) {
    int n_volte=0;
    if(n==0)
        return V[0]==val;
    else {
        n_volte=Conta_Occorrenze(V, n-1, val);
        return (V[n]==val) ? ++n_volte : n_volte;
    }
}

int main(int argc, const char * argv[]) {
    
    if(argc!=11) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int v[10];
    int val;
    for(int i=0;i<10;i++)
        v[i]=atoi(argv[i+1]);
    printf("Inserisci val: ");
    scanf("%d",&val);
    
    int n = Conta_Occorrenze(v, argc-2, val);
    char c = n==1 ? 'a' : 'e';
    printf("Il valore %d compare %d volt%c\n",val,n,c);
    
    printf("\n");
    return 0;
}
