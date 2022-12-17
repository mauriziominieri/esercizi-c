//
//  main.c
//  Esercizio-006
//
//  Created by Maurizio Minieri on 03/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende in input 8 valori interi da linea di comando.
 2) Alloca dinamicamente un vettore v di 8 interi.
 3) Inserisce in v prima i valori dispari e poi i valori pari.
 Input e Output
 Input: 5 2 8 34 3 45 3 12
 Il contenuto del vettore v è: 5 3 45 3 2 8 34 12
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    if(argc!=9) {
        printf("Numero parametri errato\n");
        return 1;
    }
   
    int* v=malloc(8*sizeof(int));
    int n=0;
    
    for(int i=0;i<8;i++) {
        if(atoi(argv[i+1])%2!=0)
            v[n++]=atoi(argv[i+1]);
    }
    
    for(int i=0;i<8;i++)
        if(atoi(argv[i+1])%2==0)
            v[n++]=atoi(argv[i+1]);
    
    printf("Il contenuto del vettore v è: ");
    for(int i=0;i<8;i++)
        printf("%d ",v[i]);
    
    free(v);
    
    printf("\n\n");
    return 0;
}
