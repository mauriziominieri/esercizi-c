//
//  main.c
//  Esercizio-004
//
//  Created by Maurizio Minieri on 03/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Definisce un rettangolo con un record e prende in input un rettangolo.
 2) Calcola il perimetro e l’area del rettangolo.
 3) Stampa a video un rettangolo di asterischi di dimensioni pari a quelle date in
 input.
 Input e Output
 Inserisci le coordinate dell'angolo superiore sinistro:
 5
 8
 Inserisci le coordinate dell'angolo inferiore destro:
 12
 16
 L'area del rettangolo è: 56.000000
 Il perimetro del rettangolo è 30
 *******
 *******
 *******
 *******
 *******
 *******
 *******
 *******
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x1,x2,y1,y2;
} Rettangolo;

int main(int argc, const char * argv[]) {
    
    Rettangolo r;
    int base=0,altezza=0,perimetro=0;
    float area=0.0;
    
    printf("Inserisci le coordinate dell'angolo superiore sinistro:\n");
    scanf("%d %d",&r.x1,&r.y1);
    
    printf("Inserisci le coordinate dell'angolo inferiore destro:\n");
    scanf("%d %d",&r.x2,&r.y2);
    
    base=abs(r.x2-r.x1);
    altezza=abs(r.y2-r.y1);
    area=base*altezza;
    perimetro=base*2+altezza*2;
    printf("L'area del rettangolo è: %f\n",area);
    printf("Il perimetro del rettangolo è %d\n",perimetro);
    
    for(int i=0;i<altezza;i++){
        for(int j=0;j<base;j++) {
            printf("*");
        }
        printf("\n");
    }
   
    printf("\n");
    return 0;
}
