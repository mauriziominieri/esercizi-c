//
//  main.c
//  Esercizio-9.3
//
//  Created by Maurizio Minieri on 22/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LUN 9   //mat = 999999 voto = 20
#define MAX 10

int main(int argc, const char * argv[]) {
   
    const char nomeFile[] = "registro.txt";
    int matricola,r,N,voto,n_promossi=0,somma=0,mat,v;
    bool trovato = false;
    FILE *fp1,*fp2;
    
    if(argc!=2 && argc!=4) {
        printf("ERRORE: numero di parametri errato\n");
        exit(1);
    }
    
    fp1=fopen(nomeFile, "r");
    
    if(fp1==NULL) {
        printf("ERRORE: impossibile aprire il file %s\n",nomeFile);
        exit(1);
    }
    
    r=fscanf(fp1,"%d",&N);   //lo sscanf legge una stringa, quindi dovrei fare la gets prima e poi analizzarla e poi fare un file... a me non serve, devo prendere N
    
    if(r!=1) {
        printf("ERRORE: formato errato nella prima riga\n");
        exit(1);
    }
    //printf("N=%d\nr=%d",N,r);
    if(argc==2 && strcmp(argv[1],"stat")==0) {
        for(int i=0;i<N;i++) {
            r=fscanf(fp1,"%d %d",&matricola,&voto);
            //printf("r=%d\nmatricola=%d\nvoto=%d\n",r,matricola,voto);
            if(r==2) {
                if(matricola>0 && matricola<=999999) {
                    if(voto>=18 && voto<=30) {
                        n_promossi++;
                        somma += voto;
                    }
                }
            }
        }
        float percentuale = (float)n_promossi/N*100;
        float media = (float)somma/n_promossi;
        printf("promossi = %d (%.1f %%)\n",n_promossi,percentuale);
        printf("voto medio = %.1f\n",media);
    }
    else if(argc==4 && strcmp(argv[1],"voto")==0) {
        int r1=sscanf(argv[2],"%d",&mat);
        int r2=sscanf(argv[3],"%d",&v);
        
        if(r1 != 1 || r2 != 1) {
            printf("ERRORE: %s e %s devono essere numeri\n",argv[2],argv[3]);
            exit(1);
        }
        
        fp2=fopen(nomeFile,"w");
        fprintf(fp2,"%d\n",N);
        for(int i=0;i<N;i++) {
            r=fscanf(fp1,"%d %d",&matricola,&voto);
            if(matricola==mat) {
                trovato=true;
                if(voto!=0) {
                    printf("ERRORE: voto già presente\n");
                    fprintf(fp2,"%d %d\n",matricola,voto);
                }
                else {
                    fprintf(fp2,"%d %d\n",matricola,v);
                    printf("Aggiornamento eseguito\n");
                }
            }
            else
                fprintf(fp2,"%d %d\n",matricola,voto);
        }
        if(trovato==false)
            printf("%d non presente\n",mat);
        fclose(fp2);
    }
    else {
        printf("ERRORE: parametri errati\n");
        exit(1);
    }
    
    fclose(fp1);
    
    printf("\n");
    return 0;
}
