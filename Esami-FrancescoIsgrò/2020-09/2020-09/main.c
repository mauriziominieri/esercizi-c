//
//  main.c
//  2020-09
//
//  Created by Maurizio Minieri on 16/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define L 32

struct PesiSpecifici {
    char ingrediente[32];
    float peso;
};

float pesoTotale(struct PesiSpecifici v[], FILE* fp) {
    
    char riga[MAX];
    char ingrediente[L];
    float qnt;
    float somma=0;
    int n = 4,i;
    
    while(fgets(riga,MAX,fp)!=NULL) {
        if(sscanf(riga,"%s %*c %f",ingrediente,&qnt)==2) {
            for(i=0;i<n;i++) {
                if(strcmp(ingrediente,v[i].ingrediente)==0) {
                    somma+=qnt*v[i].peso;
                    break;
                }
            }
            if(i==n)
                somma+=qnt;
        }
    }
    
    return somma;
}

int main(int argc, const char * argv[]) {
    
    struct PesiSpecifici V[4] = {{"latte", 1000}, {"olio", 950}, {"acqua", 1000}, {"uova", 75.0}};
    FILE* fp;
    fp=fopen("ingredienti.tic","r");
    if(!fp) {
        printf("Errore: impossibile aprire il file ingredienti.tic\n");
        return 1;
    }
    
    FILE* fwp = fopen("ingredienti.toc","w");
    
    char riga[MAX];
    char ingrediente[L];
    char misura;
    float qnt;
    while(fgets(riga,MAX,fp)!=NULL) {
        if(sscanf(riga,"%s %c %f",ingrediente,&misura,&qnt)==3) {
            fprintf(fwp,"%s\t%c\t\t%g\n",ingrediente,misura,qnt);   //rappresento il float come il più breve tra float (%f) e notazione scientifica (%o)
        }
    }
    fclose(fwp);
    fclose(fp);
    
    fp = fopen("ingredienti.toc","r");
    printf("%g",pesoTotale(V,fp));
    
    fclose(fp);
    printf("\n");
    return 0;
}
