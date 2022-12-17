//
//  main.c
//  2014-07-09
//
//  Created by Maurizio Minieri on 18/07/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//

/*
 Si supponga che in un file di testo siano memorizzate le informazioni relative ai prezzi e alla categoria degli alberghi di n città. In particolare, il file è così organizzato: sulla prima riga è presente il numero n di città e, per ogni albergo, il nome dell'albero, la categoria (1stella, 2stelle etc..) e il prezzo per camera singola. Si supponga che tutti i nomi siano senza spazi.

 3
 Napoli 2 Vesuvio 4 100 Vulcano 3 80
 Roma 3 Colosseo 2 80 Tevere 4 150 SanPietro 4 200
 Caserta 2 Reggia 3 50 SanLeucio 2 60

 Si Scriva una funzione di nome "lettura" la quale, dato il nome del file, ed eventualmente altri parametri, se opportuno) legga i dati dal file e li memorizzi in apposite strutture dati.Inoltre, si scriva una funzione di nome "scrittura" la quale, dato un nome di un file ed un valore k (ed eventualmente altri parametri se opportuno), scriva in tale file le città che abbiano almeno un albergo a k stelle, riportando anche il nome dell'albergo a k stelle con prezzo più basso. Considerando l'esempio precedente: con k=4 nel file di output sarà scritto:

 Napoli Vesuvio 100
 Roma Tevere 150
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 50
int num_citta;

struct citta{
    char nome[MAXLEN];
    int num_alberghi;
    struct albergo *array_alberghi;
};

struct albergo{
    char nome[MAXLEN];
    int stelle;
    int prezzo;
};

struct citta* lettura(char* nome){
    
    FILE* fp;
    fp=fopen(nome,"r");
    int i,j;
    struct citta *array_citta = NULL;
   
    if(fp != NULL){
        fscanf(fp,"%d",&num_citta);
        array_citta=(struct citta *)malloc(num_citta*sizeof(struct citta));
        for(i=0;i<num_citta;i++){
            fscanf(fp,"%s %d",array_citta[i].nome, &array_citta[i].num_alberghi);
            array_citta[i].array_alberghi=malloc(array_citta[i].num_alberghi*sizeof(struct albergo));
            for(j=0;j<array_citta[i].num_alberghi;j++)
                fscanf(fp,"%s %d %d",array_citta[i].array_alberghi[j].nome,&array_citta[i].array_alberghi[j].stelle, &array_citta[i].array_alberghi[j].prezzo);
        }
    }
    else
        printf("File non trovato");
    
    return array_citta;
}

void scrittura(char* nome,int k,struct citta *array_citta){
    
    FILE* output;
    int min_prezzo=0,flag=0;
    char* min_nome;
    
    output=fopen(nome,"w");
    for(int i=0;i<num_citta;i++){
        for(int j=0;j<array_citta[i].num_alberghi;j++){
            if(array_citta[i].array_alberghi[j].stelle >= k){
                flag=1;
                if(min_prezzo==0){
                    min_prezzo=array_citta[i].array_alberghi[j].prezzo;
                    min_nome=array_citta[i].array_alberghi[j].nome;
                }
                else if(array_citta[i].array_alberghi[j].prezzo<min_prezzo){
                    min_prezzo=array_citta[i].array_alberghi[j].prezzo;
                    min_nome=array_citta[i].array_alberghi[j].nome;
                }
            }
        }
        if(flag==1)
            fprintf(output,"%s %s %d\n",array_citta[i].nome,min_nome,min_prezzo);
        
        min_prezzo=0;
        flag=0;
    }
    
    fclose(output);
    printf("Scrittura eseguita con successo\n");
}



void dealloca(struct citta *array_citta, int num_citta){
    int i;
    for(i=0;i<num_citta;i++)
        free(array_citta[i].array_alberghi);
    free(array_citta);
    return;
}

int main(int argc, const char * argv[]) {
    
    int k=4;
    struct citta* array_citta=lettura("/Users/mauriziominieri/Progetti/Linguaggio-C/Esami-RobertoPrevete/2014-07-09/input.txt");
    scrittura("/Users/mauriziominieri/Progetti/Linguaggio-C/Esami-RobertoPrevete/2014-07-09/output.txt",k,array_citta);
    
    
    return 0;
}
