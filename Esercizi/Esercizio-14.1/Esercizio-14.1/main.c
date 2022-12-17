//
//  main.c
//  Esercizio-14.1
//
//  Created by Maurizio Minieri on 24/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
#define L 50

int main(int argc, const char * argv[]) {
    
    if(argc != 2) {
        printf("Errore: numero parametri errato\n");
        return 1;
    }
    FILE* fp = fopen(argv[1],"r");
    if(!fp) {
        printf("Errore: impossibile aprire il file %s\n",argv[1]);
        return 1;
    }
    
    char riga[MAX];
    char tipo_gara[L],chosen[L],g[L];
    int giorno = 0,finale = 0,i,f = 0;
    bool trovato = false;
    
    FILE* fwp = fopen("output.txt","w");
    
    for(i=10;i<=26;i++) {
        while(fgets(riga,MAX,fp)) {
            if(sscanf(riga,"%d %50s %d",&giorno,tipo_gara,&finale)==3 && giorno >= 10 && giorno <= 26 && (finale == 0 || finale == 1)) {
                
                if(giorno == i) {
                    trovato = true;
                    f = finale;
                    strcpy(g,tipo_gara);
                    if(finale == 1)
                        strcpy(chosen,tipo_gara);
                }
            }
        }
        printf("i:%d, giorno:%d, tipogara: %s, finale: %d\n",i,giorno,tipo_gara,f);
        if(!trovato)
            fprintf(fwp,"giorno %d: niente di interessante\n",i);
        else if(f == 0)
            fprintf(fwp,"giorno %d: %s\n",i,g);
        else
            fprintf(fwp,"giorno %d: %s\n",i,chosen);
        trovato = false;
        rewind(fp);
    }
    
    printf("File scritto con successo\n");
   
    fclose(fwp);
    fclose(fp);
    printf("\n");
    return 0;
}
