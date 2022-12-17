//
//  main.c
//  2020-07
//
//  Created by Maurizio Minieri on 07/01/21.
//

/*
 Esercizio 2 Data una sequenza di n valori w0, . . . , wn−1, le medie mobili di
 periodo k sono i valori m0, . . . , mn−k definiti da mi =
 1/k sommatoria da j=i a i+k-1 di wj.
 Scrivere una funzione C di prototipo: float* medieMobili(float w[], int n, int k, int* min, int* max) che prendendo in input un vettore w di numeri reali di lunghezza n restituisce come risultato il vettore di lunghezza n−k+1 delle medie mobili di periodo k e carica nelle variabili min e max passate per indirizzo gli indici in cui le medie mobili raggiungono rispettivamente il loro minimo e massimo valore.
 Osservazione: Una buona funzione dovrebbe avere complessit`a O(n) e
 non, ad esempio, O(nk).
 */

#include <stdio.h>
#include <stdlib.h>

float* medieMobili(float w[], int n, int k, int* min, int* max) {
    
    float* v = calloc((n-k+1),sizeof(float));
    int el_max = 0,el_min = 0;
    
    for(int i=0;i<=n-k;i++) {
        for(int j=i;j<i+k-1;j++) {
            v[i]+=(float)1/k*w[j];          //O(n-k * i+k-1)
        }
        if(i==0) {
            *max=*min=0;
            el_max=el_min=v[i];
        }
        else {
            if(v[i]>el_max) {
                el_max=v[i];
                *max=i;
            }
            if(v[i]<el_min) {
                el_min=v[i];
                *min=i;
            }
        }
    }
    
    return v;
}

int main(int argc, const char * argv[]) {
    
    int n=6,k=3;
    float w[] = {9,2,3,4,5,6};
    int min,max;
    
    float* v=medieMobili(w,n,k,&min,&max);
    
    for(int i=0;i<n-k+1;i++)
        printf("[%.5f]",v[i]);
    printf("\nMIN: %d, MAX: %d\n",min,max);
    
    free(v);
    printf("\n");
    return 0;
}
