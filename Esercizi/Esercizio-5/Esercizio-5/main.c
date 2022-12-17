//
//  main.c
//  Esercizio-5
//
//  Created by Maurizio Minieri on 09/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, preso da standard input un numero reale d, calcoli e fornisca
 su standard output
 1. l’area del quadrato di lato d;
 2. l’area del cerchio di diametro d;
 3. l’area del triangolo equilatero di lato d.
 */

#include <stdio.h>
#include <math.h>

//controlla che la variabile sia effettivamente double (reale a 64 bit) e > 0
void inserisci(double* x) {
    while(scanf("%lf",x)!=1 || *x<=0) {
        printf("Riprova: ");
        while(getchar() != '\n');
    }
}

int main(int argc, const char * argv[]) {
    
    double d;
    
    printf("Inserisci il numero reale d: ");
    inserisci(&d);
    
    double areaQuadrato = 0.0,areaCerchio = 0.0,areaTriangolo = 0.0;
    
    areaQuadrato = d * d;
    areaCerchio = M_PI * pow((d/2),2); //pigreco * raggio al quadrato
    areaTriangolo = (d * (sqrt(3)/2)*d)/2; //(base * altezza) / 2
    
    printf("\nL'area del quadrato di lato %lf e': %lf\n",d,areaQuadrato);
    printf("L'area del cerchio di lato %lf e': %lf\n",d,areaCerchio);
    printf("L'area del triangolo di lato %lf e': %lf\n\n",d,areaTriangolo);
   
    return 0;
}
