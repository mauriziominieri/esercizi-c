//
//  main.c
//  Esercizio-009
//
//  Created by Maurizio Minieri on 18/12/20.
//
/*
 Misura il perimetro di un poligono irregolare sapendo le cordinate cartesiane dei vertici.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool checkIntero(float n) {
    int tmp=floor(n);
    if(tmp==n) return true;
    else return false;
}

void inserisciReale(float* x) {
    while (scanf("%f",x)!=1) {
        printf("Riprova: ");
        while (getchar()!='\n');
    }
}

void stampaVertici(float X[],float Y[],int n) {
    printf("\nSTAMPA VERTICI\n");
    for(int i=0;i<n;i++) {
        printf("%d°: (%.2f,%.2f)\n",i+1,X[i],Y[i]);
    }
}

int main(int argc, const char * argv[]) {
    
    float n;
    int i;
    
    printf("Scrivi quanti vertici ha il poligono(>1): ");
    while (scanf("%f",&n)!=1||checkIntero(n)==false||n<=1) {
        printf("Riprova: ");
        while (getchar()!='\n');
    }
    
    //int *A = calloc(n,sizeof(int)); //inizializza ogni byte del blocco di memoria a 0
    
    /*int B[]={2,5,-4,9,88};
    printf("%d\n",sizeof(B));   //risultato in byte, quindi se contiene 5 elementi la lunghezza dell'array sarà 20
    printf("%d\n\n",(sizeof(B)/sizeof(int))); //in questo modo quindi saprò quanti elementi contiene*/
    
    float* X = malloc(n*sizeof(float));
    float* Y = malloc(n*sizeof(float));
    
    for(i=0;i<n;i++) {
        printf("Inserisci la x del %d° vertice: ",(i+1));
        inserisciReale(&X[i]);
        printf("Inserisci la y del %d° vertice: ",(i+1));
        inserisciReale(&Y[i]);
    }
    
    stampaVertici(X,Y,n);
    
    float perimetro=0;
    for(i=0;i<n-1;i++)  //AB = radical(Ax-Bx)^2 + radical(Ay-By)^2
        perimetro += sqrt(pow((X[i]-X[i+1]),2)+pow((Y[i]-Y[i+1]),2));
    
    if(n!=2)
        perimetro += sqrt(pow((X[i]-X[0]),2)+pow((Y[i]-Y[0]),2));
    printf("\nperimetro: %f\n",perimetro);
   
    printf("\n\n");
    return 0;
}
