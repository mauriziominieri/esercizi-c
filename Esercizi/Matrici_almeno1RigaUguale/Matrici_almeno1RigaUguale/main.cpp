//
//  main.cpp
//  Matrici_almeno1RigaUguale
//
//  Created by Maurizio Minieri on 02/01/21.
//

/*Siano date due matrici quadrate di numeri interi, denominate rispettivamente M1 ed M2.
Si scriva un programma che verifichi se la matrice M1 e la matrice M2 presentano almeno una riga
uguale e stampi a video un messaggio.
Il programma deve stampare a video, in caso di presenza di una o più righe uguali tra le matrici, gli
indici di tali righe.
Esempio:
1 3 4 5   3 4 5 6
3 4 5 6   1 1 1 1
2 2 3 4   2 2 3 2
3 4 5 7   1 3 4 5
Output: M1 ed M2 hanno almeno una riga uguale;
 La riga 0 di M1 Ë uguale alla riga 3 di M2
 La riga 1 di M1 Ë uguale alla riga 0 di M2 */

#include <iostream>

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
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Esercizio(int** M1,int** M2,int n) {
    int a=0,volta=0;
    bool uguale=true;
    
    while(a<n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M1[a][j]!=M2[i][j]) {
                    uguale=false;
                    break;
                }
            }
            if(uguale) {
                if(volta==0) {
                    cout<<"\nM1 ed M2 hanno almeno una riga uguale;"<<endl;
                    volta=1;
                }
                cout<<"La riga "<<a<<" di M1 è uguale alla riga "<<i<<" di M2"<<endl;
            }
            uguale=true;
        }
        a++;
    }
}

int main(int argc, const char * argv[]) {
    int** M1 = NULL;
    int** M2 = NULL;
    int n;
    
    righe_colonne(&n);
    M1=allocazione_mat(M1,n);
    cout<<"\nCreazione M1"<<endl;
    inserimento_mat(M1,n);
    M2=allocazione_mat(M2,n);
    cout<<"\nCreazione M2"<<endl;
    inserimento_mat(M2,n);
    
    cout<<"\nStampa M1"<<endl;
    stampa_mat(M1,n);
    cout<<"\nStampa M2"<<endl;
    stampa_mat(M2,n);
   
    Esercizio(M1,M2,n);
    
    int a=6;
    int* x = &a;
    cout<<"x="<<*x;     //6
    
    return 0;
}
