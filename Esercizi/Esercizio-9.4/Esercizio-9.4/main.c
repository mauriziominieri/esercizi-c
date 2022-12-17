//
//  main.c
//  Esercizio-9.4
//
//  Created by Maurizio Minieri on 22/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    
    FILE* fp1,*fp2;
    char ch;
    
    if(argc!=4) {
        printf("ERRORE: numero parametri errato\n");
        exit(1);
    }
    
    char c1=argv[3][0],c2=argv[3][1];
    
    if(strlen(argv[3])!=2 || !isalpha(c1) || !isalpha(c2) || c1==c2) {
        printf("ERRORE: parametro %s non valido\n", argv[3]) ;
        printf("Deve essere composto di 2 caratteri alfabetici diversi tra loro\n") ;
        exit(1) ;
    }
    
    fp1=fopen(argv[1],"r");
    
    if(fp1==NULL) {
        printf("ERRORE: impossibile aprire il file %s",argv[1]);
        exit(1);
    }
    
    char nomeFile[30];
    strcpy(nomeFile,argv[2]);

    if(strstr(nomeFile, ".")==NULL)    //se non contiene il punto (strstr ritorna la stringa dal carattere in poi, altrimenti se non lo trova restituisce NULL)
        strcat(nomeFile,".txt");
    
    fp2=fopen(nomeFile,"w");
    
    while((ch = fgetc(fp1)) != EOF) {
        if(tolower(ch)==tolower(c1)) {
            if(isupper(ch))
                ch=toupper(c2);
            else
                ch=c2;
        }
        else if(tolower(ch)==tolower(c2)) {
            if(isupper(ch))
                ch=toupper(c1);
            else
                ch=c1;
        }
        fputc(ch,fp2);
    }
    printf("%s creato con successo\n",nomeFile);
    fclose(fp1);
    fclose(fp2);
    
    printf("\n");
    return 0;
}
