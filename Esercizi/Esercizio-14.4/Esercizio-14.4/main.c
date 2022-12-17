//
//  main.c
//  Esercizio-14.4
//
//  Created by Maurizio Minieri on 07/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define L_NAZ 3
#define LUN 30

int main(int argc, const char * argv[]) {
  
    if(argc != 2) {
        printf("Numero di parametri errato\n");
        return 1;
    }
    
    FILE* fp = fopen(argv[1],"r");
    if(!fp) {
        printf("Impossibile aprire il file %s\n",argv[1]);
        return 1;
    }
    
    FILE* fAtleti = fopen("atleti.txt","r");
    if(!fAtleti) {
        printf("Impossibile aprire il file atleti.txt\n");
        return 1;
    }
    
    char riga[MAX],nazione[L_NAZ+1],cognome[LUN+1],nome[LUN+1];
    char cognomeOro[LUN+1],nomeOro[LUN+1],nazioneOro[L_NAZ+1];
    char cognomeArgento[LUN+1],nomeArgento[LUN+1],nazioneArgento[L_NAZ+1];
    char cognomeBronzo[LUN+1],nomeBronzo[LUN+1],nazioneBronzo[L_NAZ+1];
    int r,nPettorale,nPett,n,lunghezza;
    int lOro = 0,lArgento = 0,lBronzo = 0,nPOro = 0,nPArgento = 0,nPBronzo = 0;
    while(fgets(riga,MAX,fp)) {
        r = sscanf(riga,"%d %*c %d",&nPett,&lunghezza);
        if(r == 2) {
            if(lOro == 0) {
                lOro = lArgento = lBronzo = lunghezza;
                nPOro = nPArgento = nPBronzo = nPett;
            }
            else if(lunghezza > lOro) {
                lArgento = lOro;
                nPArgento = nPOro;
                lOro = lunghezza;
                nPOro = nPett;
            }
            else if(lunghezza > lArgento) {
                lBronzo = lArgento;
                nPBronzo = nPArgento;
                lArgento = lunghezza;
                nPArgento = nPett;
            }
        }
    }
    
    fgets(riga,MAX,fAtleti);
    r = sscanf(riga,"%d",&n);
    if(r!=1 || n<3) {
        printf("Errore nel file atleti.txt\n");
        return 1;
    }
    for(int i=0;i<n;i++) {
        r = fscanf(fAtleti,"%d %3s %s %s",&nPettorale,nazione,cognome,nome);
        if(r == 4) {
            if(nPettorale == nPOro) {
                strcpy(cognomeOro,cognome);
                strcpy(nomeOro,nome);
                strcpy(nazioneOro,nazione);
            }
            else if(nPettorale == nPArgento) {
                strcpy(cognomeArgento,cognome);
                strcpy(nomeArgento,nome);
                strcpy(nazioneArgento,nazione);
            }
            else if(nPettorale == nPBronzo) {
                strcpy(cognomeBronzo,cognome);
                strcpy(nomeBronzo,nome);
                strcpy(nazioneBronzo,nazione);
            }
        }
    }
    
    printf("Medaglia d'oro: %s %s (%s)\n",cognomeOro,nomeOro,nazioneOro);
    printf("Medaglia d'argento: %s %s (%s)\n",cognomeArgento,nomeArgento,nazioneArgento);
    printf("Medaglia di bronzo: %s %s (%s)\n",cognomeBronzo,nomeBronzo,nazioneBronzo);
    
    fclose(fp);
    fclose(fAtleti);
    
    printf("\n");
    return 0;
}
