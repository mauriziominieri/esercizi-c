//
//  main.cpp
//  Matrici_ordinaBySomma
//
//  Created by Maurizio Minieri on 02/01/21.
//

/*Sia data una matrice quadrata di interi.
Si devono calcolare le somme degli elementi di riga in modo da stampare la matrice disponendo le
stesse righe secondo l'ordine crescente delle somme in precedenza calcolate.
Ad esempio dato il file:
51 2 13
11 23 10
11 5 6
si deve ottenere la stampa:
11 5 6
11 23 10
51 2 13*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

using namespace std;

void righe_colonne(int* n){
    do {
        cout<<"inserisci il numero di righe e colonne(>1): ";
        cin>>*n;
    }
    while(*n<2);
}

int** allocazione_mat(int** mat,int n){
    mat= new int*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[n];
    }
    return mat;
}

void inserimento_mat(int** mat,int n){
    for(int i=0; i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<"Inserisci elemento ["<<i<<"]""["<<j<<"]: ";
            cin>>mat[i][j];
        }
    }
}

void stampa_mat(int** mat,int n){
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selectionSort(int somme[],int indici[],int n) {
    int i, j, min_i;

    for (i=0;i<n-1;i++) {
        min_i = i;
        for (j=i+1;j<n;j++)
            if (somme[j] < somme[min_i])
                min_i = j;

        swap(&somme[min_i], &somme[i]);
        swap(&indici[min_i],&indici[i]);
    }
}

void stampaOrdinataByRowSomma(int** M,int n){
    int somme[n],indici[n];
    
    for(int i=0;i<n;i++)
        somme[i]=0;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            somme[i]+=M[i][j];
        indici[i]=i;
    }
    
    selectionSort(somme,indici,n);
    cout<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<M[indici[i]][j]<<" ";
        cout<<endl;
    }
}

int main(){
    
    int** M1 = NULL;
    int n;
    
    righe_colonne(&n);
    M1=allocazione_mat(M1,n);
    cout<<"\nCreazione M1"<<endl;
    inserimento_mat(M1,n);
    
    cout<<"\nStampa M1"<<endl;
    stampa_mat(M1,n);
    cout<<"\nStampa M1 ordinata in base alla somma delle righe"<<endl;
    stampaOrdinataByRowSomma(M1,n);
    
    cout<<"\n\n";
    return 0;
}
