//
//  main.c
//  Esercizio-9.7
//
//  Created by Maurizio Minieri on 26/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LUN 31
#define MAX 200

int main(int argc, const char * argv[]) {
    
    FILE* fp;
    int r,n = 0,n2 = 0;
    float temperatura,temperaturaI = 0.0,somma = 0.0;
    char luogo[LUN+1],luogoI[LUN+1],riga[MAX];
    
    if(argc != 3 && argc != 4) {
        printf("ERRORE: numero di parametri errato\n");
        return 1;
    }

    if(argc == 4) {
        r=sscanf(argv[3],"%f",&temperaturaI);
        if(r != 1) {
            printf("ERRORE: parametri errati\n");
            printf("%s deve essere un numero\n",argv[3]);
            return 1;
        }
    }
    
    fp=fopen(argv[1],"r");
    
    if(fp==NULL) {
        printf("ERRORE: impossibile aprire il file %s\n",argv[1]);
        return 1;
    }
    
    //while(fgets (riga, MAX, fp) != NULL) {
    for(int i=1;fgets (riga, MAX, fp) != NULL;i++) {
        r=sscanf(riga,"%f %s",&temperatura,luogo);
        if(r!=2)
            printf("riga n.%d errata - ignorata\n",i);
        else {
            for(int j=0;j<strlen(luogo);j++)
                luogo[j]=tolower(luogo[j]);
            for(int j=0;j<strlen(argv[2]);j++)
                luogoI[j]=tolower(argv[2][j]);
            if(strcmp(luogo,luogoI)==0) {
                somma += temperatura;
                n++;
                if(argc==4 && temperatura>temperaturaI)
                    n2++;
            }
        }
    }
    
    if(somma==0.0)
        printf("%s non trovato tra i luoghi\n",argv[2]);
    else {
        printf("%s:\n- temperatura media %.1f\n",argv[2],somma/n);
        if(argc==4)
            printf("- %d giorni con T > %.1f\n",n2,temperaturaI);
    }
    
    fclose(fp);
    
    printf("\n");
    return 0;
}
