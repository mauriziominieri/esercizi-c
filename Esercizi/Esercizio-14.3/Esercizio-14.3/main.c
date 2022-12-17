//
//  main.c
//  Esercizio-14.3
//
//  Created by Maurizio Minieri on 07/02/21.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define L_S 15

int main(int argc, const char * argv[]) {
    
    if(argc != 2) {
        printf("Numero parametri errato\n");
        return 1;
    }
    
    FILE* fp = fopen(argv[1],"r");
    if(!fp) {
        printf("Impossibile aprire il file %s",argv[1]);
        return 1;
    }
    
    FILE* fSquadre= fopen("squadre.txt","r");
    if(!fSquadre) {
        printf("Impossibile aprire il file squadre.txt");
        return 1;
    }
    
    char riga1[MAX],riga2[MAX],nomeSquadra[L_S+1];
    int r,r1,r2,numeroSquadra,sq1,sq2,nPartite = 0,punti = 0;
    while(fgets(riga1,MAX,fSquadre)) {
        r = sscanf(riga1,"%d %15s",&numeroSquadra,nomeSquadra);
        if(r == 2) {
            while(fgets(riga2,MAX,fp)) {
                r = sscanf(riga2,"%d %d %d %d",&sq1,&sq2,&r1,&r2);
                if(r == 4 && sq1 != sq2) {
                    if(numeroSquadra == sq1 || numeroSquadra == sq2) {
                        nPartite++;
                        if(r1 == r2)
                            punti += 1;
                        else if((r1 > r2 && sq1 == numeroSquadra) ||
                                (r1 < r2 && sq2 == numeroSquadra))
                            punti += 3;
                    }
                }
            }
            printf("%s\tpartite=%d punti=%d\n",nomeSquadra,nPartite,punti);
            nPartite = punti = 0;
            rewind(fp);
        }
    }
    
    fclose(fp);
    fclose(fSquadre);
    
    printf("\n");
    return 0;
}
