//
//  main.c
//  Esercizio-013b
//
//  Created by Maurizio Minieri on 07/01/21.
//

//https://drive.google.com/drive/folders/1aeR-YWph2wzwu7xI_4oVeRo8xMloZUyA
/*
 Scrivere un programma C che:
 1) Prende dalla linea di comando due parole
 2) Implementa la funzione char *interfoglia(char parola1[], char parola2[]), che alloca e restituisce una nuova stringa, in cui inserisce in modo alternato (interfogliato) i caratteri della prima e della seconda parola.
 3) Stampa a video la stringa prodotta
 Input e Output
 Input: dodici elemento
 Le parole in input sono: dodici e elemento
 La stringa interfogliata è: deoldeimceinto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *interfoglia(const char parola1[], const char parola2[]) {
    int n1=(int)strlen(parola1),n2=(int)strlen(parola2);
    int k1=0,k2=0,n3=n1+n2;
    char* parola3=malloc((n3+1)*sizeof(char));
    
    for(int i=0;i<n3;i++) {
        if(k1<n1 && k2<n2 && i%2==0)
            parola3[i]=parola1[k1++];
        else if(k1<n1 && k2<n2 && i%2!=0)
            parola3[i]=parola2[k2++];
        else if(k1<n1)
            parola3[i]=parola1[k1++];
        else
            parola3[i]=parola2[k2++];
    }
    
    return parola3;
}

int main(int argc, const char * argv[]) {
    
    if(argc!=3) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    printf("Le parole in input sono: %s e %s\n",argv[1], argv[2]);
    char* parola = interfoglia(argv[1], argv[2]);
    printf("La stringa interfogliata è: %s\n",parola);
    
    printf("\n");
    return 0;
}
