//
//  main.c
//  Esercizio-017
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Definisce un tipo Cerchio con un record con tre campi (coordinate x e y del centro e il raggio)
 2) Prende in input da linea di comando tre valori float che rappresentano le coordinate del centro e il raggio di un cerchio.
 3) Implementa la funzione int VerificaPunto (Cerchio cr , float x, float y)) che prende in input una variabile di tipo cerchio e le coordinate di un punto e verifica se il punto è interno o esterno al cerchio.
 Input e Output
 Input: 4.5 8.7 12.3
 Inserisci la coordinata x del punto: 10
 Inserisci la coordinata y del punto: 5
 Il punto è interno al cerchio
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x,y;
    float raggio;
} Cerchio;

//𝑑=√(𝑥𝑝−𝑥𝑐)^2+(𝑦𝑝−𝑦𝑐)^2.
/*
 se d<raggio: p è interno al cerchio
 se d==raggio: p è sul cerchio
 altrimenti p fuori
 */
int VerificaPunto(Cerchio cr, float x, float y) {
    float d = sqrt(pow((x - cr.x),2)+pow((y - cr.y),2));
    return d<cr.raggio;
}

int main(int argc, const char * argv[]) {
    
    if(argc!=4) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    Cerchio c;
    c.x = atoi(argv[1]);
    c.y = atoi(argv[2]);
    c.raggio = atoi(argv[3]);
    float x,y;
    
    printf("Inserisci la coordinata x del punto: ");
    scanf("%f",&x);
    printf("Inserisci la coordinata y del punto: ");
    scanf("%f",&y);
    
    if(VerificaPunto(c,x,y)==1)
        printf("Il punto è interno al cerchio\n");
    else
        printf("Il punto non è interno al cerchio\n");
    
    printf("\n");
    return 0;
}
