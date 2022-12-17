//
//  main.c
//  2020-09
//
//  Created by Maurizio Minieri on 06/01/21.
//

/*
 In un vettore, un valore `e maggioritario se occorre in pi`u di n/2
 posizioni (ad esempio, se n = 6 oppure n = 7 un valore `e maggioritario se
 occorre in almeno 4 posizioni).
 Scrivere due funzioni C entrambe di prototipo int maggioritario(int[] v, int n, int* mag) che ritornano 1 se esiste un valore maggioritario nel vettore v di lunghezza n e 0 altrimenti.
 Quando ritornano 1, caricano nella locazione puntata da mag il valore maggioritario.
 La prima funzione maggioritario non pu`o modificare il vettore v(complessit`a attesa quadratica), mentre la seconda pu`o modificare v (complessit`a attesa O(n log n)).
 Gli eventuali virtuosi (a loro rischio) possono tentare di scrivere un’unica versione della funzione maggioritario basata su un’idea divide et impera di complessit`a O(n log n) che non modifica il vettore.
 */

#include <stdio.h>
#include <stdlib.h>

//O(n^2)
int maggioritario1(int v[], int n, int* mag) {
    int conta;
    for(int i=0;i<n-1;i++) {
        conta = 1;
        for(int j=i+1; j<n; j++) {
            if(v[i]==v[j])
                conta++;
            if(conta>n/2) {
                *mag=v[i];
                return 1;
            }
        }
    }
    return 0;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//O(log n)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); //0 , n-1
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//O(n log n)
int maggioritario2(int v[], int n, int* mag) {
    quickSort(v, 0, n-1);
    int conta=1;
    for(int i=0;i<n-1;i++) {
        if(v[i]!=v[i+1])
            conta=1;
        else {
            conta++;
            if(conta>n/2) {
                *mag=v[i];
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int n=7,mag;
    int v[] = {4,7,1,4,4,1,4};
    
    if(maggioritario1(v, n, &mag))
        printf("Valore maggioritario: %d\n",mag);
    if(maggioritario2(v, n, &mag))
        printf("Valore maggioritario: %d\n",mag);
    
    printf("\n");
    return 0;
}
