//
//  main.cpp
//  ProvaMatrici
//
//  Created by Maurizio Minieri on 22/01/21.
//

/*
 Date due matrici A e B 3x3 calcoli una terza matrice C pari alla somma delle due precedenti.
 Successivamente si conti il numero di occorrenze di valori negativi in C.
 Si utilizzi una procedura per il calcolo della somma e delle occorrenze.
 La stampa del numero di occorrenze deve avvenire nel main
 */

#include <iostream>

using namespace std;

void procedura(int A[][3], int B[][3], int* occorrenze) {
    int C[3][3];
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            C[i][j] = A[i][j] + B[i][j];
    
    cout << "C: " << endl;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(C[i][j] < 0)
                (*occorrenze)++;
    
}

int main(int argc, const char * argv[]) {
    
    int A[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[][3] = {{1,2,3},{-5,5,6},{7,-8,9}};
    int occorrenze = 0;
    procedura(A,B,&occorrenze);
    cout << "\nOccorrenze numeri negativi in C: " << occorrenze << endl;
    
    cout << "\n";
    return 0;
}
