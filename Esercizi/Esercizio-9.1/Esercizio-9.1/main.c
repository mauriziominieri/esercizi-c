//
//  main.c
//  Esercizio-9.1
//
//  Created by Maurizio Minieri on 21/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000
#define MAXM 10
#define MAXR 16 //ore più matricola

bool findDipendente(char matricole[][MAXM+1],char matricola[],int n) {
    for(int i=0;i<n;i++)
        if(strcmp(matricole[i],matricola)==0)
            return true;
    return false;
}

//argc è il numero di parametri passati da terminale
//argv invece è un array di stringhe, conterrà i parametri (argv[0] = ./main, argv[1]=...)
int main(int argc, const char * argv[]) {
    
    FILE *f ;
    char matricole[MAX][MAXM+1];    //array lungo MAX elementi, ognuno di lunghezza MAXM+1
    char riga[MAXR+1],matricola[MAXM+1];
    int r,n=0,ore,minuti,tempoMin=0,tempoMax=0;
    
    if(argc!=2 && argc!=3) {
        printf("Errore, numero di parametri errato\n");
        return 1;
    }
    
    f = fopen(argv[1], "r") ;
    
    if(f==NULL) {
        printf("Impossibile aprire il file %s\n",argv[1]);
        return 2;
    }
    
    if(argc==2) {
        while (fgets(riga,MAXR,f) != NULL) { //ogni riga del file la salvo nella stringa riga
            r = sscanf(riga, "%*d %*d %s", matricola) ;
            /* NOTA: gli asterischi nella stringa di formato della sscanf
            (come %*d) servono per far leggere il dato corrispondente
            ma non memorizzarlo in alcuna variabile.
            In effetti qui i primi due campi numerici non ci servono */
            if(r==1) {  //considero solo le righe nel giusto formato, solo se tutti i valori vengono mappati bene allora r sarà 1.
                if(!findDipendente(matricole,matricola,n)) {
                    strcpy(matricole[n],matricola);
                    n++;
                }
            }
        }
        printf("Ci sono %d dipendenti diversi.",n);
    }
    else {
        while (fgets(riga,MAXR,f) != NULL) {
            r = sscanf(riga,"%d %d %s",&ore,&minuti,matricola);
            if(r==3) {  //in questo caso r deve essere 3 dato che devono essere mappate tre variabili
                if(strcmp(matricola,argv[2])==0) {
                    if(tempoMin==0)
                        tempoMin = ore*60 + minuti; //converto tutto in minuti
                    else
                        tempoMax = ore*60 + minuti;
                }
            }
        }
        if(tempoMax>0)
           printf("Il dipendente %s ha lavorato per %d minuti.",argv[2],tempoMax-tempoMin);
        else if(tempoMin==0)
            printf("Il dipendente %s non è presente",argv[2]);
        else
            printf("Il dipendente %s non è ancora uscito",argv[2]);
    }
    
    fclose(f);
    printf("\n\n");
    return 0;
}
