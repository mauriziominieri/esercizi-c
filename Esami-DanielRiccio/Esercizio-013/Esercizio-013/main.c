//
//  main.c
//  Esercizio-013
//
//  Created by Maurizio Minieri on 04/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando n parole.
 2) Calcola la lunghezza massima L delle stringhe date in input e alloca dinamicamente un array A di stringhe di dimensioni n per L
 3) Copia nell’array A le parole date in input in ordine inverso rispetto a quello con cui sono state inserite
 4) Calcola la lunghezza media su tutte le parole in A
 Input e Output
 Input: casa dodici castagno dodecaedro esagono
 La parola più lunga contiene 10 caratteri
 0) esagono
 1) dodecaedro
 2) castagno
 3) dodici
 4) casa
 La lunghezza media delle parole è: 7.000000
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
  
    if(argc<=1) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    int n=argc-1;
    int L=0,k=0,somma=0;
    
    for(int i=1;i<=n;i++)
        if(strlen(argv[i])>L)
            L=strlen(argv[i]);
    
    printf("La parola più lunga contiene %d caratteri\n",L);
    
    char** A;
    A=malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
        A[i]=malloc((L+1)*sizeof(char));
    
    for(int i=n;i>=1;i--)
        strcpy(A[k++],argv[i]);
    for(int i=0;i<n;i++) {
        printf("%d) %s\n",i,A[i]);
        somma+=strlen(A[i]);
    }
    
    printf("La lunghezza media delle parole e': %f\n",(float)somma/n);
    
    for(int i=0;i<n;i++)
        free(A[i]);
    free(A);
    
    printf("\n");
    return 0;
}
