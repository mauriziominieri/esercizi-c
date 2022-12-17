//
//  main.c
//  Esercizio-6
//
//  Created by Maurizio Minieri on 09/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, preso da standard input tre numeri reali a, b e c, determini se
 il triangolo di lati a, b e c è
 1. equilatero;
 2. isoscele;
 3. scaleno;
 4. rettangolo.
 L’algoritmo deve fornire su standard output le informazioni elaborate.
 */

#include <stdio.h>
#include <math.h>

void inserisci(double* x) {
    while(scanf("%lf",x)!=1 || *x<=0) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

int main(int argc, const char * argv[]) {
   
    double a,b,c;
    
    printf("Inserisci il primo numero: ");
    inserisci(&a);
    printf("Inserisci il secondo numero: ");
    inserisci(&b);
    printf("Inserisci il terzo numero: ");
    inserisci(&c);
    
    double max,c1,c2;
    
    if(a>b && a>c) { max = a; c1=b; c2=c; }
    else if(b>a && b>c) { max = b; c1=a; c2=c; }
    else { max = c; c1=a; c2=b; }
    
    printf("\n");
    if(a==b && b==c) printf("Il triangolo è equilatero");
    else if(a==b || b==c || a==c) printf("Il triangolo è isoscele");
    else if(pow(max,2)==pow(c1,2)+pow(c2,2)) printf("Il triangolo è rettangolo"); //oppure pow(a,2)==pow(b,2)+pow(c,2)) || ...
    else printf("Il triangolo è scaleno");
    
    printf("\n\n");
    return 0;
}
