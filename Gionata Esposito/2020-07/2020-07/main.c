//
//  main.c
//  2020-07
//
//  Created by Maurizio Minieri on 19/07/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//
/*
A partire dal codice di seguito riportato, scrivere il Codice C delle seguenti funzioni:
void concatena(char * [], infoStr *): a partire da 4 stringhe contenute in un array di puntatori char *stringhe[4],
concatena la prima con la seconda e la terza con la quarta e memorizza le 2 nuove stringhe in un record, infoStr rec,
utilizzando l’allocazione dinamica. Nel caso specifico il primo campo di rec punterà alla stringa aaaaabbbbb mentre il
secondo campo punterà a cccccddddd.
infoStr * prefix (char *, char * []): a partire dalla stringa inserita dall’utente mediante tastiera e acquisita mediante la
funzione char *leggi _stringa (da non implementare), crea 2 nuove stringhe: la prima combinando la stringa letta da
input e la prima stringa dell’array di puntatori char *stringhe[4], la seconda combinando la stringa letta da input e la
seconda stringa dell’array di puntatori char *stringhe[4]. Se l’utente inserisse la stringa zzz, le 2 nuove stringhe
sarebbero zzzaaaaa e zzzbbbbb. Utilizzando l’allocazione dinamica le 2 stringhe andranno memorizzate in un record
(attenzione al valore restituito dalla funzione!!!) il cui riferimento sarà restituito al main.
---------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
char * str1;
char * str2;
}infoStr;
char * leggi_stringa(void);
void concatena(char * [], infoStr *);
infoStr * prefix (char *, char * []);
void printRec(infoStr,infoStr *);
int main(void)
{
infoStr rec, *rec1;
char *stringhe[4]={"aaaaaa", "bbbbb", "ccccc", "ddddd"};
char *stringa1;
stringa1=leggi_stringa();
concatena(stringhe,&rec);
rec1=prefix(stringa1,stringhe);
printRec(rec, rec1);
free(stringa1);
free(rec.str1);
free(rec.str2);
free(rec1->str1);
free(rec1->str2);
return 0;
}
}
------------------------------------------------------SVOLGIMENTO-------------------------------------------
void concatena(char *vect2[], infoStr *rec)
{
}
infoStr * prefix(char *stringa1, char *vect2[])
{
}

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *str1;
    char *str2;
}infoStr;

void concatena(char * data[], infoStr *rec){
    
    //dato che devo usare il punto NON devo usare la malloc
    infoStr prova;
    
    prova.str1 = malloc((strlen(data[0])+strlen(data[1])+1)*sizeof(char));
    prova.str2 = malloc((strlen(data[2])+strlen(data[3])+1)*sizeof(char));
    
    strcpy(prova.str1,data[0]);
    strcat(prova.str1,data[1]);
    strcpy(prova.str2,data[2]);
    strcat(prova.str2,data[3]);
    
    //printf("prova->str1: %s\n",prova.str1);
    //printf("prova->str2: %s\n",prova.str2);
    
     *rec=prova;
    
    
    
    
    //se invece non avessi dovuto usare per forza il .
    //rec = (infoStr*) malloc(sizeof(infoStr));
    /*malloc(numero_bytes)
    sizeof(int) = 4. Nelle nuove macchine a 64bit darà 4, cioè un intero è grande 4 bytes, però dipende dal sistema, prima era 2
    sizeof(float) = 4
    sizeof(double) = 8
    sizeof(char) = 1. Quindi è come scrivere sizeof(1), un carattere infatti ha bisogno di 1 byte, quindi per esempio per creare spazio che possa contenere una parola di 50 caratteri puoi scrivere direttamente sizeof(51)) al posto di malloc(51*sizeof(char));
     */
   // rec->str1 = malloc((strlen(data[0])+strlen(data[1])+1)*sizeof(char));   //6 + 5 + 1
   // rec->str2 = malloc((strlen(data[2])+strlen(data[3])+1)*sizeof(char));
   
    //strcpy(rec->str1,data[0]);
   // strcat(rec->str1,data[1]);
    //strcpy(rec->str2,data[2]);
    //strcat(rec->str2,data[3]);
    
    //printf("rec->str1: %s\n",rec->str1);
    //printf("rec->str2: %s\n",rec->str2);
}


char * leggi_stringa(){
    
    char *ret = malloc(100);
    
    printf("Scrivi stringa: ");
    scanf("%s",ret);
    
    return ret;
}

infoStr * prefix (char *s, char * data[]){
    
    infoStr *rec = (infoStr*) malloc(sizeof(infoStr));
    rec->str1 = malloc((strlen(s)+strlen(data[0])+1)*sizeof(char));
    rec->str2 = malloc((strlen(s)+strlen(data[1])+1)*sizeof(char));
    
    strcpy(rec->str1,s);
    strcat(rec->str1,data[0]);
    
    strcpy(rec->str2,s);
    strcat(rec->str2,data[1]);
    
    //printf("rec->str1: %s\n",rec->str1);
    //printf("rec->str2: %s\n",rec->str2);
    
    return rec;
}

void printRec(infoStr rec,infoStr *rec1){
    
    printf("\nrec.str1: %s\n",rec.str1);
    printf("rec.str2: %s\n\n",rec.str2);
    
    printf("rec1->str1: %s\n",rec1->str1);
    printf("rec1->str2: %s\n\n",rec1->str2);
}

int main(int argc, const char * argv[]) {
   
    infoStr rec, *rec1;
    char *stringhe[4]={"aaaaaa", "bbbbb", "ccccc", "ddddd"};
    char *stringa1;
    stringa1=leggi_stringa();  //zzz
    concatena(stringhe,&rec);
    rec1=prefix(stringa1,stringhe);
    printRec(rec, rec1);
    free(stringa1);
    free(rec.str1);
    free(rec.str2);
    free(rec1->str1);
    free(rec1->str2);
    return 0;
}
