//
//  main.c
//  Esercizio-9.10
//
//  Created by Maurizio Minieri on 26/12/20.
//

#include <stdio.h>
#include <string.h>

#define MAXN 5
#define MAX 200

int main(int argc, const char * argv[]) {
   
    int r,nCartucce=1,min=-1,max=-1,somma=0,n=0;
    char dipartimento[MAXN+1],comando[4],riga[MAX];
    FILE *fp;
    
    if(argc != 4) {
        printf("ERRORE: numero di parametri non valido\n");
        return 1;
    }
    
    r=sscanf(argv[3],"-%s",comando);
    if(r!=1 || (strcmp(comando,"min")!=0 && strcmp(comando,"max")!=0 && strcmp(comando,"med")!=0) ) {
        printf("ERRORE: parametri errati\n");
        printf("il quarto parametro %s può essere min,max o med\n",argv[3]);
        return 1;
    }
    
    fp=fopen(argv[1],"r");
    if(fp==NULL) {
        printf("ERRORE: impossibile aprire il file %s\n",argv[1]);
        return 1;
    }
    
    while(fgets(riga,MAX,fp)!=NULL) {
        r=sscanf(riga,"%s %d",dipartimento,&nCartucce);
        if(r==2 && strcmp(argv[2],dipartimento)==0 && nCartucce>0 && nCartucce<100) {
            if(strcmp(comando,"min")==0) {
                if(min==-1 || nCartucce<min)
                    min=nCartucce;
            }
            else if(strcmp(comando,"max")==0) {
                if(nCartucce>max)
                    max=nCartucce;
            }
            else {
                somma += nCartucce;
                n++;
            }
        }
    }
    
    if(strcmp(comando,"min")==0 && min!=-1)
            printf("%d\n",min);
    else if(strcmp(comando,"max")==0 && max!=-1)
            printf("%d\n",max);
    else if(strcmp(comando,"med")==0 && n>0)
            printf("%.1f\n",(float)somma/n);
    else
        printf("Dipartimento %s non trovato\n",argv[2]);
    
    fclose(fp);
    
    printf("\n");
    return 0;
}
