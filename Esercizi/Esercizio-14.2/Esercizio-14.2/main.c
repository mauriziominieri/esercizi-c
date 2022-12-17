//
//  main.c
//  Esercizio-14.2
//
//  Created by Maurizio Minieri on 24/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, const char * argv[]) {
    
    if(argc != 7) {
        printf("Errore: numero di parametri errato\n");
        return 1;
    }
    if(atoi(argv[2])<0 || atoi(argv[2])>10000) {
        printf("Errore: numero del cliente errato\n");
        return 1;
    }
    if(atoi(argv[3])<1 || atoi(argv[3])>5) {
        printf("Errore: numero dell'azienda errato\n");
        return 1;
    }
    if(strlen(argv[4]) != 1) {
        printf("Errore: l'operazione da svolgere deve essere un carattere\n");
        return 1;
    }
    if(argv[4][0] != 'A' && argv[4][0] != 'V' && argv[4][0] != 'G') {
        printf("Errore: operazione non riconosciuta\n");
        return 1;
    }
    if(atoi(argv[5])<0) {
        printf("Errore: numero di azioni coinvolte non valido\n");
        return 1;
    }
    
    FILE* fp = fopen(argv[1],"r");
    if(!fp) {
        printf("Errore: impossibile aprire il file %s\n",argv[1]);
        return 1;
    }
    FILE* fwp = fopen(argv[6],"w");
    
    char riga[MAX];
    int id_cliente,s1,s2,s3,s4,s5;
    while(fgets(riga,MAX,fp)) {
        if(sscanf(riga,"%d %d %d %d %d %d",&id_cliente,&s1,&s2,&s3,&s4,&s5)==6 && id_cliente>=1 && id_cliente<=10000 && s1>=0 && s2>=0 && s3>=0 && s4>=0 && s5>=0) {
            if(atoi(argv[2]) == id_cliente || atoi(argv[2]) == 0) {
                switch(atoi(argv[3])) {
                    case 1:
                        if(argv[4][0] == 'A')
                            s1 += atoi(argv[5]);
                        else if(argv[4][0] == 'G')
                            s1 += (s1 * atoi(argv[5])/100);
                        else
                            s1 -= atoi(argv[5]);
                        if(s1 < 0)
                            s1 = 0;
                        break;
                    case 2:
                        if(argv[4][0] == 'A')
                            s2 += atoi(argv[5]);
                        else if(argv[4][0] == 'G')
                            s2 += (s2 * atoi(argv[5])/100);
                        else
                            s2 -= atoi(argv[5]);
                        if(s2 < 0)
                            s2 = 0;
                        break;
                    case 3:
                        if(argv[4][0] == 'A')
                            s3 += atoi(argv[5]);
                        else if(argv[4][0] == 'G')
                            s3 += (s3 * atoi(argv[5])/100);
                        else
                            s3 -= atoi(argv[5]);
                        if(s3 < 0)
                            s3 = 0;
                        break;
                    case 4:
                        if(argv[4][0] == 'A')
                            s4 += atoi(argv[5]);
                        else if(argv[4][0] == 'G')
                            s4 += (s4 * atoi(argv[5])/100);
                        else
                            s4 -= atoi(argv[5]);
                        if(s4 < 0)
                            s4 = 0;
                        break;
                    case 5:
                        if(argv[4][0] == 'A')
                            s5 += atoi(argv[5]);
                        else if(argv[4][0] == 'G')
                            s5 += (s5 * atoi(argv[5])/100);
                        else
                            s5 -= atoi(argv[5]);
                        if(s5 < 0)
                            s5 = 0;
                        break;
                }
            }
            fprintf(fwp,"%d\t%d\t%d\t%d\t%d\t%d\n",id_cliente,s1,s2,s3,s4,s5);
        }
    }
    
    printf("%s creato con successo\n",argv[6]);
    
    fclose(fwp);
    fclose(fp);
    printf("\n");
    return 0;
}
