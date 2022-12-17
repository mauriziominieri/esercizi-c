//
//  main.cpp
//  Matrici_stessiValori
//
//  Created by Maurizio Minieri on 02/01/21.
//

/*Siano date due matrici quadrate denominate M1 ed M2 rispettivamente.
Scrivere un programma che verifichi se le due matrici hanno righe e/o colonne contenenti
gli stessi valori.*/

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

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

void inserimentoTrasposta(int** mt,int** m,int n){
    for(int i=0; i<n;i++) {
        for(int j=0;j<n;j++) {
            mt[i][j] = m[j][i];
        }
    }
}

void stampa_mat(int** mat,int n){
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"["<<mat[i][j]<<"]";
        }
        cout<<endl;
    }
}

void verifica_valori(int** M1,int** M2,int n,bool riga){
    int a=0,b=0;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            while(a<n && b<n) {
                if(M1[i][a] == M2[j][b]) {
                    b=-1;
                    a++;
                }
                b++;
                if(a==n) {
                    if(riga==true)
                        cout<<"\nRiga "<<i<<" di M1 uguale alla riga "<<j<<" di M2";
                    else
                        cout<<"\nColonna "<<i<<" di M1 uguale alla colonna "<<j<<" di M2";
                }
            }
            b=0;
            a=0;
        }
        b=0;
        a=0;
    }
}

int main(){
    
    int** M1 = NULL;
    int** M1T = NULL;
    int** M2 = NULL;
    int** M2T = NULL;
    int n;
    
    righe_colonne(&n);
    M1=allocazione_mat(M1,n);
    cout<<"\nCreazione M1"<<endl;
    inserimento_mat(M1,n);
    M2=allocazione_mat(M2,n);
    cout<<"\nCreazione M2"<<endl;
    inserimento_mat(M2,n);
    
    M1T=allocazione_mat(M1T,n);
    M2T=allocazione_mat(M2T,n);
    inserimentoTrasposta(M1T,M1,n);
    inserimentoTrasposta(M2T,M2,n);
    
    cout<<"\nStampa M1"<<endl;
    stampa_mat(M1,n);
    cout<<"\nStampa M2"<<endl;
    stampa_mat(M2,n);
    
    verifica_valori(M1,M2,n,true);
    verifica_valori(M1T,M2T,n,false);
    
    cout<<"\n\n";
    return 0;
}
