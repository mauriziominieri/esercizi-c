//
//  main.c
//  Esercizio-6.8
//
//  Created by Maurizio Minieri on 20/12/20.
//
//abchdfffchdtlchd
//chd

#include <stdio.h>
#include <string.h>

#define MAX 30

int main(int argc, const char * argv[]) {
    
    char parola1[MAX],parola2[MAX];
    int k=0;
    
    printf("Inserisci prima parola: ");
    gets(parola1);  //scanf("%s",parola1); da problemi con lo spazio e altri caratteri
    printf("Inserisci seconda parola: ");
    gets(parola2);
    
    for(int i=0;i<strlen(parola1);i++) {
        if(parola1[i]==parola2[k]) {
            k++;
        }
        if(k==strlen(parola2)) {
            for(int j=1;j<=strlen(parola2);j++)
                parola1[i-strlen(parola2)+j] = '*';
            k=0;
        }
    }
    
    printf("\nparola1: %s",parola1);
    
    printf("\n\n");
    return 0;
}
