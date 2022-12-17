//
//  main.c
//  Esame_21-01-20
//
//  Created by Maurizio Minieri on 09/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* consonanti_lower(const char parola[]) {
    char* v = malloc((strlen(parola) + 1) * sizeof(char));
    for(int i=0;i<strlen(parola);i++)
        if(parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u' ||
           parola[i] == 'A' || parola[i] == 'E' || parola[i] == 'I' || parola[i] == 'O' || parola[i] == 'U')
            v[i] = toupper(parola[i]);
        else
            v[i] = tolower(parola[i]);
    return v;
}

int main(int argc, const char * argv[]) {
    
    if(argc != 2) {
        printf("Numero di parametri errato\n");
        return 1;
    }
    
    printf("La nuova parola è: ");
    char* v = consonanti_lower(argv[1]);
    printf("%s",v);
    free(v);
    
    printf("\n");
    return 0;
}
