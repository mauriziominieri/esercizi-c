//
//  main.c
//  Esercizio-9.9
//
//  Created by Maurizio Minieri on 26/12/20.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200
#define LUND 8

int main(int argc, const char * argv[]) {
    
    int r,valore,matricola,codice,voto,totVoti=0,nVoti=0,i=0;
    char comando;
    char riga[MAX],data[LUND+1];
    FILE* fp;
    
    if(argc!=3) {
        printf("ERRORE: numero di parametri errato\n");
        return 1;
    }
    
    r = sscanf(argv[2],"-%c%d",&comando,&valore);
    if( r!=2 || ( comando!='a' && comando!='s' && comando!='e' ) ) {
        printf("ERRORE: comando %s non riconosciuto\n", argv[2]);
        return 1;
    }
    
    fp=fopen(argv[1],"r");
    if(fp==NULL) {
        printf("ERRORE: impossibile aprire il file %s\n", argv[1]);
        return 1;
    }
    
    while(fgets(riga,MAX,fp)!=NULL) {
        sscanf(riga,"%d %d %s %d",&matricola,&codice,data,&voto);
        if(voto>=18 && codice>=1000 && codice<6000 && matricola<1000000 && strlen(data)==8) {
            if((comando=='s' && matricola==valore) ||
               (comando=='a' && codice/1000==valore) ||
               (comando=='e' && codice==valore)) {
                    totVoti += voto;
                    nVoti++;
            }
        }
        else
            printf("riga %d ignorata\n",++i);
    }
    
    if(nVoti!=0)
        printf("%.1f\n",(float)totVoti/nVoti);
    else if(comando=='e')
        printf("Nessun esame di codice %d trovato\n",valore);
    else if(comando=='a')
        printf("Nessun esame del %d° anno trovato\n",valore);
    else
        printf("Nessuno studente con matricola %d trovato\n",valore);
    
    fclose(fp);
    
    printf("\n");
    return 0;
}
