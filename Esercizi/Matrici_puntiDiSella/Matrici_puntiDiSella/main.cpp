//
//  main.cpp
//  Matrici_puntiDiSella
//
//  Created by Maurizio Minieri on 02/01/21.
//

/* assegnata una matrice di interi di riempimento N ed M ; si determino gli eventuali punti di sella
    (elementi che sono sia massimi della colonna che della riga di appartenenza) */

#include <iostream>

using namespace std;


 struct triple {
    int a,b,c;
};

void righe_colonne(int* n){
    do {
        cout<<"inserisci il numero di righe e colonne(>1): ";
        cin>>*n;
    }
    while(*n<2);
}

int** allocazione_mat(int n){
    int** mat= new int*[n];
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

int punti_di_sella_max(int** mat,int n,int sella){
    int max_temporaneo=0;
    int col_max;
   
    for(int i =0;i<n;i++){
        for(int j=0; j<n;j++){
            if(mat[i][j]>max_temporaneo){
                max_temporaneo=mat[i][j];
                col_max=j;
            }
        }
    }
    for(int j=0; j<n;j++){
        if(max_temporaneo>mat[0][j]){
            sella=max_temporaneo;
            return sella;
        }
    }
    
    return -1;
}

void altri_punti_di_sella(int**mat,int n,int altri_punti,int*nrpp){
    
    triple ts[n];
    ts[0].a=1;
    
    for(int i =0;i<n;i++){
        int max_temporaneo=0;
        int col_max=0;
        int k=0;
        for(int j=0; j<n;j++){
            if(mat[i][j]>max_temporaneo){
                max_temporaneo=mat[i][j]; //3
                col_max=j; //2
            }
        }
     
        bool trovato=true;
        while( k<n && trovato==true){
            if(mat[k][col_max] > max_temporaneo)
                trovato= false;
            k++;
        }
     
        if (trovato==true) {
            //cout<<"\npunto di sella : ""("<<max_temporaneo<<")"" nella posizione ("<<i<<","<<col_max<<")";
            *nrpp=*nrpp+1;
        }
        
        k=0;
        max_temporaneo=0;
        col_max=0;
    }
}

int main(int argc, const char * argv[]) {
    int n,sella=0;
    int altri_punti=0,nrpp=0;
    
    righe_colonne(&n);
    int** mat = allocazione_mat(n);
    inserimento_mat (mat,n);
    cout<<"Stampa matrice\n";
    stampa_mat(mat,n);
    cout<<"\nPunto di sella con valore massimo= "<<punti_di_sella_max(mat,n,sella);
    altri_punti_di_sella(mat,n,altri_punti,&nrpp);
    
    cout<<"\n\n";
    return 0;
}
