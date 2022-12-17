//
//  main.c
//  Esercizio-003
//
//  Created by Maurizio Minieri on 03/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Definisce un numero complesso con un record;
 2) Chiede in input due numeri complessi.
 3) Calcola il prodotto dei due numeri complessi e lo stampa a video.
 Input e Output
 Inserisci il primo numero Complesso:
 8
 3
 Inserisci il secondo numero Complesso:
 9
 5
 I due numeri complessi sono:
 n1: 8.000+i3.000
 n2: 9.000+i5.000
 Il loro prodotto è:
 n2: 57.000+i67.000
 */

#include <stdio.h>

typedef struct {
    float a;
    float b;
} Complesso;

int main(int argc, const char * argv[]) {
    
    Complesso n1,n2;    //n1:(a,b) n2:(c,d) //somma: (a+b,b+d)  //prodotto: (ac-bd,bc+ad)
    
    printf("Inserisci il primo numero Complesso:\n");
    scanf("%f",&n1.a);
    scanf("%f",&n1.b);
    printf("Inserisci il secondo numero Complesso:\n");
    scanf("%f",&n2.a);
    scanf("%f",&n2.b);
    
    printf("I due numeri complessi sono:\n");
    printf("n1: %.3f+i%.3f\n",n1.a,n1.b);
    printf("n2: %.3f+i%.3f\n",n2.a,n2.b);
    printf("Il loro prodotto e':\n");
    printf("n2: %.3f+i%.3f\n",n1.a*n2.a-n1.b*n2.b,n1.b*n2.a+n1.a*n2.b);
    
    printf("\n");
    return 0;
}
