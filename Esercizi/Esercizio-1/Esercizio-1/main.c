//
//  main.c
//  Esercizio-1
//
//  Created by Maurizio Minieri on 09/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presi da standard input due numeri reali a e b, effettui le 4
 operazioni
 1. a + b;
 2. a − b;
 3. a × b;
 4. a / b
 .
 Assicurandosi che i risultati siano definiti, l’algoritmo deve fornire su standard output questi ultimi.
 */

//a = [13.0]
//b = [0.0]

#include <stdio.h>

//controlla che la variabile sia effettivamente double
void inserisci(double *x) {
    while (scanf("%lf",x)!=1)   //C++ --> cin >> a;  //vammi a riempiere l'indirizzo di memoria della variabile x
    {
        printf("Riprova: ");
        while (getchar() != '\n');
    }
}

int main(int argc, const char * argv[]) {

    double a,b;

    printf("Inserisci il primo numero: ");  //C++ --> cout << "Inserisci il primo numero:"
    /*while (scanf("%lf",&a)!=1)
    {
        printf("Riprova: ");
        while (getchar() != '\n');
    }*/
    inserisci(&a);
    
    printf("Inserisci il secondo numero: ");
    inserisci(&b);  //C++ --> cin >> b;
    
    printf("\n1. La somma di %.2f e %.2f e': %.2f",a,b,(a+b));
    printf("\n2. La differenza di %.2f e %.2f e': %.2f",a,b,(a-b));
    printf("\n3. La moltiplicazione di %.2f e %f e': %.2f",a,b,(a*b));
    if(b==0)
        printf("\n4. La divisione di %.2f e %.2f e' impossibile",a,b);
    else
        printf("\n4. La divisione di %.2f e %.2f e': %.2f",a,b,(a/b));
    
    printf("\n\n");
    return 0;
}
