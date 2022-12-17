//
//  main.c
//  Esercizio-010
//
//  Created by Maurizio Minieri on 03/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Definisce un triangolo con un record contenente le coordinate dei tre vertici A, B e C.
 2) Prende dalla linea di comando le coordinate dei tre vertici (es.: 23 34 56 12 65 5)
 3) Implementa la funzione CalcolaPerimetro che prende in input un triangolo e restituisce come output il perimetro del triangolo, inoltre fornisce il tipo di triangolo (equilatero, isoscele, scaleno)
 Input e Output
 Input: 23 34 56 12 65 5
 Il perimetro del triangolo è: 101
 Il triangolo è scaleno
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int Ax,Ay;
    int Bx,By;
    int Cx,Cy;
} Triangolo;

int CalcolaPerimetro(Triangolo t,char* tipo) {
    int AB,AC,BC;
    
    AB=sqrt(pow((t.Ax - t.Bx), 2) + pow((t.Ay - t.By), 2));
    AC=sqrt(pow((t.Ax - t.Cx), 2) + pow((t.Ay - t.Cy), 2));
    BC=sqrt(pow((t.Bx - t.Cx), 2) + pow((t.By - t.Cy), 2));
   
    if(AB==AC && AB==BC)
        *tipo='e';
    else if(AB==AC || AB==BC || AC==BC)
        *tipo='i';
    else
        *tipo='s';
    
    return AB+AC+BC;
}

int main(int argc, const char * argv[]) {
   
    if(argc!=7) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    char tipo;
    Triangolo t;
    t.Ax=atoi(argv[1]);
    t.Ay=atoi(argv[2]);
    t.Bx=atoi(argv[3]);
    t.By=atoi(argv[4]);
    t.Cx=atoi(argv[5]);
    t.Cy=atoi(argv[6]);
    
    printf("Il perimetro del triangolo è: %d\n",CalcolaPerimetro(t,&tipo));
    printf("Il triangolo è ");
    if(tipo=='e')
        printf("equilatero\n");
    else if(tipo=='i')
        printf("isoscele\n");
    else
        printf("scaleno\n");
    
    printf("\n");
    return 0;
}
