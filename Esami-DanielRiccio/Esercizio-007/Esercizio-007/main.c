//
//  main.c
//  Esercizio-007
//
//  Created by Maurizio Minieri on 03/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Definisce un nuovo tipo di variabile Polinomio come record (grado n, n+1
 coefficienti float).
 2) Scrivere una funzione float polyval(Polinomio p, float x) che valuta il polinomio in x.
 Input e Output
 Inserisci il grado del polinomio: 3
 Inserisci il coefficiente per x^0:2.0
 Inserisci il coefficiente per x^1:1.8
 Inserisci il coefficiente per x^2:2.6
 Inserisci il coefficiente per x^3:4.5
 Il polinomio di grado 3 è: 4.5x^3 +2.6x^2 +1.8x^1 +2
 Inserire il valore in cui valutare il polinomio: 1.0
 Il valore del polinomio in 1.000000 è: 10.900000
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int grado;
    float* c;
} Polinomio;

bool checkIntero(float x) {
    int tmp=floor(x);
    if(tmp==x) return true;
    else return false;
}

int inserisciIntM0(float* x) {
    while(scanf("%f",x)!=1 || *x<=0 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}

void inserisciFloat(float* x) {
    while(scanf("%f",x)!=1) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

float polyval(Polinomio p,float x) {
    float valore=0.0;
    for(int i=p.grado;i>=1;i--)
        valore+=p.c[i]*pow(x,i);
    valore+=p.c[0];
    return valore;
}

int main(int argc, const char * argv[]) {
    
    Polinomio p;
    float tmp;
    
    printf("Inserisci il grado del polinomio: ");
    p.grado=inserisciIntM0(&tmp);
    p.c = malloc(p.grado*sizeof(float));
    
    for(int i=0;i<=p.grado;i++) {
        printf("Inserisci il coefficiente per x^%d: ",i);
        //scanf("%f",&(p.c[i]));
        inserisciFloat(&(p.c[i]));
    }
    
    printf("Il polinomio di grado %d e': ",p.grado);
    for(int i=p.grado;i>=1;i--) {
        if(i==p.grado)
            printf("%gx^%d ",p.c[i],i);    //stampa il valore più corto possibile
        else if(p.c[i]>=0)
            printf("+%gx^%d ",p.c[i],i);
        else
            printf("%gx^%d ",p.c[i],i);
    }
    if(p.c[0]>=0)
        printf("+");
    printf("%g",p.c[0]);
    
    float valore;
    printf("\nInserire il valore in cui valutare il polinomio: ");
    inserisciFloat(&valore);
    
    printf("Il valore del polinomio in %f è: %f",valore,polyval(p,valore));
    
    free(p.c);
    
    printf("\n\n");
    return 0;
}
