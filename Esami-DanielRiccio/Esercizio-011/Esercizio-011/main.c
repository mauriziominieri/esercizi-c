//
//  main.c
//  Esercizio-011
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Definisce una retta con un record con due campi: coefficiente angolare (m) e intercetta (q)
 2) Prende dalla linea di comando le coordinate di quattro punti A e B (es.: 23 34 56 45)
 Implementa la funzione Retta *CalcolaRetta(int Ax, int Ay, int Bx, int By) che prende
 in input le coordinate di due punti e restituisce la retta passante per tali punti.
 Input e Output
 Input: 23 34 56 45
 La retta r per i due punti è: y=0.333333x+26.333332
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float m;  //coefficiente angolare
    float q;  //intercetta;
} Retta;

Retta* CalcolaRetta(int Ax,int Ay,int Bx,int By);

Retta* CalcolaRetta(int Ax,int Ay,int Bx,int By) {
    Retta* r=malloc(sizeof(Retta));
    r->m=(float)(By-Ay)/(Bx-Ax);
    r->q=(float)(Bx*Ay-Ax*By)/(Bx-Ax);
    return r;
}

int main(int argc, const char * argv[]) {
    
    if(argc!=5) {
        printf("Numero parametri errato\n");
        return 1;
    }

    int Ax=atoi(argv[1]),Ay=atoi(argv[2]);
    int Bx=atoi(argv[3]),By=atoi(argv[4]);
    
    Retta* r=CalcolaRetta(Ax, Ay, Bx, By);
    printf("La retta r per i due punti e': y=%fx+%f",r->m,r->q);
    
    free(r);
    printf("\n");
    return 0;
}
