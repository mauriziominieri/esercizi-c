//
//  main.c
//  Esame_21-01-25
//
//  Created by Maurizio Minieri on 09/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* estrai_doppie(const char parola[]) {
    int n = 0,k = 0;
    for(int i=0;i<strlen(parola)-1;i++)
        if(parola[i] == parola[i+1])
            n++;
    
    char* v = malloc((n + 1) * sizeof(char));
    for(int i=0;i<strlen(parola)-1;i++)
        if(parola[i] == parola[i+1])
            v[k++] = parola[i];
    return v;
}

int main(int argc, const char * argv[]) {
    
    if(argc != 2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    printf("Le doppie nella parola %s sono: ",argv[1]);
    char* v = estrai_doppie(argv[1]);
    printf("%s",v);
    free(v);
    
    printf("\n");
    return 0;
}
