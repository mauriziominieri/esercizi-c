//
//  main.c
//  Esercizio-003b
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende da linea di comando 10 interi e li inserisce in un vettore
 2) Implementa la funzione ricorsiva int Cerca_Valore(int V[], int n, int val) che
 restituisce 1 se val è nel vettore e 0 altrimenti.
 Input e Output
 Input: 1 8 6 12 9 5 2 5 1 8
 Output:
 Il valore 8 compare nel vettore
 */

#include <stdio.h>
#include <stdlib.h>

int Cerca_Valore(int V[], int n, int val) {
    if(n==0)
        return V[0]==val;
    else {
        Cerca_Valore(V,n-1,val);
        return (V[n]==val) ? 1 : Cerca_Valore(V,n-1,val);
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
    
    if(Cerca_Valore(v, argc-2, val))
        printf("Il valore %d compare nel vettore\n",val);
    else
        printf("Il valore %d non compare nel vettore\n",val);
    
    printf("\n");
    return 0;
}
