//
//  main.c
//  Esercizio-3
//
//  Created by Maurizio Minieri on 09/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presi da standard input due numeri interi a ≥ 0 e b ≥ 0, ne
 determini il prodotto p, fornendo il risultato su standard output.
 */

#include <stdio.h>
#include <stdlib.h>

//controlla che la variabile sia effettivamente int
void inserisci(int *x) {    //passo l'indirizzo di memoria di a, quindi x deve essere un puntatore, (immagina il VALORE di x collegato all' INDIRIZZO di a)
    while (scanf("%d",x)!=1 || *x<0) {
        printf("Riprova: ");
        while (getchar() != '\n');
    }
    
   /*printf("x = %p\n",x);  // x quindi è l'INDIRIZZO di memoria di a
    printf("*x = %d\n",*x); // *x è il VALORE associato all'INDIRIZZO di memoria di a
    printf("&x = %p\n",&x); // &x è l'INDIRIZZO di memoria della variabile x*/
}

int main(int argc, const char * argv[]) {
    
    int a,b;
    
    printf("Inserisci il primo numero(>=0): ");
    inserisci(&a);
    /*
     while (scanf("%d",&a)!=1 || a<0) {
         printf("Riprova: ");
         while (getchar() != '\n');
     }
     */
    printf("Inserisci il secondo numero(>=0): ");
    inserisci(&b);
    
    int p = 0;
    
    if(a>=0 && b>=0) {
        p = a * b;
        printf("\nIl prodotto tra %d e %d e': %d",a,b,p);
    }
    
    printf("\n\n");
    return 0;
}
