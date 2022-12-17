//
//  main.c
//  Esercizio-9.2
//
//  Created by Maurizio Minieri on 22/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
#define MAXA 20
#define LUN 30

int main(int argc, const char * argv[]) {
    
    char riga[MAX+1],mitt[LUN+1],dest[LUN+1],luogo[LUN+1];
    FILE *f;
    int r;
    bool trovato=false;
    
    if(argc!=4 && argc!=6) {
        printf("Errore, numero parametri errato\n");
        return 1;
    }
    
    f=fopen(argv[1], "r");
    
    if ( f==NULL ) {
        printf("ERRORE: impossibile aprire file %s\n", argv[1]) ;
        exit(1);
    }
    
    if(strcmp(argv[2],"new")==0 && argc==6) {
        while(fgets(riga,MAX,f) != NULL ) {
            r=sscanf(riga,"%s %s %s",mitt,dest,luogo);
            if(strcmp(argv[3],mitt)==0 &&
               strcmp(argv[4],dest)==0 &&
               strcmp(argv[5],luogo)==0
               )
                trovato=true;
        }
        
        if(trovato==false) {
            fclose(f);
            f=fopen(argv[1], "a");
            fprintf(f,"%s %s %s\n",argv[3],argv[4],argv[5]);
            printf("Cartolina aggiunta con successo\n");
            fclose(f);
        }
        else
            printf("Errore, cartolina già presente\n");
    }
    else if(strcmp(argv[2],"find")==0 && argc==4) {
        printf("Cartoline ricevute da %s\n",argv[3]);
        while(fgets(riga,MAX,f) != NULL ) {
            r=sscanf(riga,"%s %s %s",mitt,dest,luogo);
            if(r==3) {
                if(strcmp(argv[3],dest)==0)
                    printf("%s da %s\n",mitt,luogo);
            }
        }
    }
    else {
        printf("Errore, il 3° parametro può essere find o new\n");
        printf("con find necessito di 4 parametri, con new 6\n");
        return 1;
    }
    
    fclose(f);
    
    printf("\n");
    return 0;
}
