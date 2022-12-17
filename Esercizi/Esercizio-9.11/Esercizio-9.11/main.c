//
//  main.c
//  Esercizio-9.11
//
//  Created by Maurizio Minieri on 26/12/20.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define LEN 32
#define MAXR 20
#define MAX 200

int main(int argc, const char * argv[]) {
  
    FILE *fpG,*fpF;
    int r,N=0;
    float quantita,totQ[MAX];
    char riga[MAX],ricetta[MAXR+1],ingrediente[MAXR+1],nomeFile[LEN+1]="Germana.txt";
    char ingredienti[MAX][MAXR+1];
    bool impossibile=false,ricettaTrovata=false;
    
    if(argc!=3) {
        printf("ERRORE: numero di parametri errato\n");
        return 1;
    }
    
    fpG = fopen(nomeFile,"r");
    fpF = fopen(argv[1],"r");
    
    if(fpG==NULL) {
        printf("Impossibile aprire il file %s\n",nomeFile);
        return 1;
    }
    
    if(fpF==NULL) {
        printf("Impossibile aprire il file %s\n",argv[1]);
        return 1;
    }
    
    for(int i=0;fgets(riga,MAX,fpF)!=NULL;i++) {
        r=sscanf(riga,"%s %f",ingrediente,&quantita);
        strcpy(ingredienti[i],ingrediente);
        totQ[i] = quantita;
        N++;
    }
    
    fclose(fpF);
  
    printf("Ingredienti:\n");
    while(fgets(riga,MAX,fpG)!=NULL) {
        r=sscanf(riga,"%s %s %f",ricetta,ingrediente,&quantita);
        if(r==3 && strcmp(ricetta,argv[2])==0) {
            ricettaTrovata=true;
            for(int i=0;i<N;i++) {
                if(strcmp(ingrediente,ingredienti[i])==0) {
                    if(quantita<=totQ[i]) {
                        printf("- %s: OK\n",ingrediente);
                        break;
                    }
                    else {
                        printf("- %s: richiesto %.1f, disponibile %.1f\n",ingrediente,quantita,totQ[i]);
                        impossibile=true;
                        break;
                    }
                }
            }
        }
        if(impossibile==true)
            break;
    }
    
    if(ricettaTrovata==false)
        printf("Ricetta per %s non trovata\n",argv[2]);
    else if(impossibile==true)
        printf("Ricetta '%s' impossibile\n",argv[2]);
    else
        printf("Ricetta '%s' possibile\n",argv[2]);
    
    fclose(fpG);
    
    printf("\n");
    return 0;
}
