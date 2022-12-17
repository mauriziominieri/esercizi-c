//
//  main.c
//  Esercizio-9.8
//
//  Created by Maurizio Minieri on 26/12/20.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200
#define MAXC 10
#define LUN 32

int main(int argc, const char * argv[]) {
   
    char codice[MAXC+1],riga[MAX],nomeFile[LUN+1]="lezioni.txt";
    int data,numStudenti,r,dataMin=-1,dataMax=-1,min=-1,max=-1,nLezioni=0,totStudenti=0;
    float mediaStudenti=0.0;
    FILE* fp;
    
    if(argc != 3) {
        printf("ERRORE: numero di parametri errato\n");
        return 1;
    }
    
    if(strlen(argv[2])!=1 || !isalpha(argv[2][0])) {
        printf("ERRORE: parametri errati\n");
        printf("il terzo parametro deve essere un singolo carattere\n");
        return 1;
    }
    
    if(argv[2][0]!='i' && argv[2][0]!='s' && argv[2][0]!='I' && argv[2][0]!='S') {
        printf("ERRORE: parametri errati\n");
        printf("il terzo parametro deve essere la lettera i oppure la lettera s\n");
        return 1;
    }
    
    if(argv[2][0]=='i'||argv[2][0]=='I') {
        fp = fopen(nomeFile,"a");
        
        if(fp == NULL) {
            printf("ERRORE: impossibile aprire il file %s\n",nomeFile);
            return 1;
        }
        
        do {
            printf("Data: ");
            scanf("%d",&data);
        }
        while(data<0 || data>365);
        do {
            printf("Studenti: ");
            scanf("%d",&numStudenti);
        }
        while(numStudenti < 1);
        fprintf(fp,"%s %d %d\n",argv[1],data,numStudenti);
        printf("Riga inserita con successo in %s\n",nomeFile);
    }
    else {
        fp = fopen(nomeFile,"r");
        
        if(fp == NULL) {
            printf("ERRORE: impossibile aprire il file %s\n",nomeFile);
            return 1;
        }
        
        while(fgets(riga,MAX,fp)!=NULL) {
            r=sscanf(riga,"%s %d %d",codice,&data,&numStudenti);
            if(r==3) {
                if(strcmp(codice,argv[1])==0) {
                    totStudenti += numStudenti;
                    nLezioni++;
                    if(min==-1) {
                        min=numStudenti;
                        dataMin=data;
                        max=numStudenti;
                        dataMax=data;
                    }
                    else {
                        if(numStudenti>max) {
                            max=numStudenti;
                            dataMax=data;
                        }
                        if(numStudenti<min) {
                            min=numStudenti;
                            dataMin=data;
                        }
                    }
                }
            }
        }
        if(nLezioni == 0)
            printf("Non ci sono lezioni del corso %s\n",argv[1]);
        else {
            mediaStudenti = (float)totStudenti/nLezioni;
            printf("Il minimo di studenti si è raggiunto in data %d\n",dataMin);
            printf("Il massimo di studenti si è raggiunto in data %d\n",dataMax);
            printf("La media di studenti vale %.1f\n",mediaStudenti);
        }
    }
    
    fclose(fp);
    
    printf("\n");
    return 0;
}
