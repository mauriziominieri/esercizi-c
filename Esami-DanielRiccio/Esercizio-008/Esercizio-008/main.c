//
//  main.c
//  Esercizio-008
//
//  Created by Maurizio Minieri on 03/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
Scrivere un programma C che:
1) Definisce un nuovo tipo di variabile Polinomio come record (grado n, n+1 coefficienti float).
2) Scrivere una funzione float polydev(Polinomio p, Polinomio *pdev) che inserisce in pdev la derivata prima di p.
Input e Output
Inserisci il grado del polinomio: 3
Inserisci il coefficiente per x^0: 2
Inserisci il coefficiente per x^1: 1.8
Inserisci il coefficiente per x^2: 2.6
Inserisci il coefficiente per x^3: 4.5
Il polinomio di grado 3 è: 4.5x^3 +2.6x^2 +1.8x^1 +2
Il polinomio derivato è di grado 2 ed è: 13.5x^2 +5.2x^1 +1.8
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

float polyval(Polinomio p,Polinomio *pdev) {
    pdev->grado=p.grado-1;
    pdev->c=malloc(pdev->grado*sizeof(float));
    for(int i=p.grado;i>=0;i--)
        pdev->c[i-1]=p.c[i]*i;
    
    printf("\nIl polinomio derivato e' di grado %d ed e': ",pdev->grado);
    for(int i=pdev->grado;i>0;i--) {
        if(i==pdev->grado)
            printf("%gx^%d ",pdev->c[i],i);    //stampa il valore più corto possibile
        else if(pdev->c[i]>=0)
            printf("+%gx^%d ",pdev->c[i],i);
        else
            printf("%gx^%d ",pdev->c[i],i);
    }
    if(pdev->c[0]>=0) printf("+");
    printf("%g",pdev->c[0]);
    return 0.0;
}

int main(int argc, const char * argv[]) {
    
    Polinomio p,pdev;
    float tmp;
    printf("Inserisci il grado del polinomio: ");
    p.grado=inserisciIntM0(&tmp);
    p.c = malloc(p.grado*sizeof(float));
    
    for(int i=0;i<=p.grado;i++) {
        printf("Inserisci il coefficiente per x^%d: ",i);
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
    
    polyval(p,&pdev);
   
    printf("\n\n");
    return 0;
}
