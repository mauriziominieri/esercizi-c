//
//  main.c
//  Esercizio-10.1
//
//  Created by Maurizio Minieri on 16/01/21.
//

/*
 Re e Regina
 Su una scacchiera 8x8 sono posizionati due pezzi: il Re bianco e la Regina nera.
 Si scriva un programma in linguaggio C che, acquisite le posizioni del Re e della Regina,
 determini se la Regina è in posizione tale da poter mangiare il Re. Le posizioni dei due pezzi
 sono identificate da mediante la riga e la colonna su cui si trovano, espresse come numeri
 interi tra 1 e 8.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool checkIntero(float x) {
    int tmp = floor(x);
    if(tmp==x) return true;
    else return false;
}

int inserisciIntero(float* x) {
    while(scanf("%f",x)!=1 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}

//La Regina o Donna si muove di quante caselle vuole in orizzontale, verticale o diagonale
bool canEat(int M[][8],int i1,int j1,int i2,int j2) {
    if(i2==i1 || j2==j1)
        return true;
    if((i1%2==0 && i2%2==0 && j1%2==0 && j2%2==0) ||
       (i1%2!=0 && i2%2!=0 && j1%2!=0 && j2%2!=0) ||
       (i1%2==0 && i2%2==0 && j1%2!=0 && j2%2!=0) ||
       (i1%2!=0 && i2%2!=0 && j1%2==0 && j2%2==0))
        return true;
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    int i_re,j_re,i_regina,j_regina;
    int M[8][8];
    float tmp;
    
    printf("SCACCHIERA: Inserisci la posizione del re\ni: ");
    do {
        i_re = inserisciIntero(&tmp);
    } while((i_re < 1 || i_re > 8) && printf("Riprova: "));
    printf("j: ");
    do {
        j_re = inserisciIntero(&tmp);
    } while((j_re < 1 || j_re > 8) && printf("Riprova: "));
    
    printf("Inserisci la posizione della regina\ni: ");
    do {
        i_regina = inserisciIntero(&tmp);
    } while((i_regina < 1 || i_regina > 8) && printf("Riprova: "));
    printf("j: ");
    do {
        j_regina = inserisciIntero(&tmp);
    } while((j_regina < 1 || j_regina > 8) && printf("Riprova: "));
    
    if(canEat(M,i_re,j_re,i_regina,j_regina))
        printf("\nLa regina può mangiare il re\n");
    else
        printf("\nLa regina non può mangiare il re\n");
    
    printf("\n");
    return 0;
}
