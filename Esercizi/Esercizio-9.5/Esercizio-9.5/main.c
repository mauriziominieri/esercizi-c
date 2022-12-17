//
//  main.c
//  Esercizio-9.5
//
//  Created by Maurizio Minieri on 23/12/20.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(int argc, const char * argv[]) {
    
    int nPiani,r,nStanze,altezzaPiano;
    float superficie=0.0,volume=0.0,x,y,metriQ=10000.0,metriC=1000000.0;
    FILE *fp;
    
    if(argc!=3) {
        printf("ERRORE: numero parametri errato\n");
        exit(1);
    }
    
    r = sscanf( argv[2], "%d", &nPiani );
    if(r!=1 || nPiani<1) {
        printf("ERRORE: parametro %s errato\n",argv[2]);
        printf("Ci deve essere almeno un piano\n");
        exit(1);
    }
    
    fp = fopen(argv[1],"r");
    if(fp==NULL) {
        printf("ERRORE: impossibile aprire il file %s\n",argv[1]);
        exit(1);
    }
    
    for(int i=0;i<nPiani;i++) {
        r=fscanf(fp,"%d %d",&nStanze,&altezzaPiano);
        if(r==2) {
            for(int j=0;j<nStanze;j++) {
                r=fscanf(fp,"%f %f",&x,&y);
                if(r==2) {
                    superficie += (x * y);
                    volume += (x * y * altezzaPiano);
                }
            }
        }
    }
    
    printf("Superficie totale dell’edificio: %.2f metri quadri\n",superficie/metriQ);
    printf("Volume totale dell’edificio: %.2f metri cubi",volume/metriC);
    
    fclose(fp);
    
    printf("\n");
    return 0;
}
