//
//  main.c
//  Esercizio-9.6
//
//  Created by Maurizio Minieri on 23/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int main(int argc, const char * argv[]) {
    
    int nRighe=0,nCaratteriTot=0,nCaratteri=0,nCarMassimo=0;
    char rigaMax[MAX],riga[MAX];
    FILE* fp;
    
    if(argc != 2) {
        printf("ERRORE: numero di parametri errato\n");
        return 1;
    }
    
    fp=fopen(argv[1],"r");
    if(fp==NULL) {
        printf("ERRORE: impossibile aprire il file %s\n",argv[1]);
        exit(1);
    }
    
    while(fgets(riga,MAX,fp)!=NULL) {
        for(int i=0;riga[i]!='\n';i++) {
            if(riga[i]!=' ')
                nCaratteri++;
        }
        nCaratteriTot += nCaratteri;
        if(nCaratteri>nCarMassimo) {
            nCarMassimo=nCaratteri;
            strcpy(rigaMax,riga);
        }
        
        nCaratteri = 0;
        nRighe++;
    }
    
    printf("numero di righe: %d\n",nRighe);
    printf("numero di caratteri: %d\n",nCaratteriTot);
    printf("numero di caratteri per riga:\n- medio %.1f\nmassimo %d\n",(float)(nCaratteriTot/nRighe),nCarMassimo);
    printf("riga più lunga: %s",rigaMax);
    
    fclose(fp);
    
    printf("\n");
    return 0;
}
