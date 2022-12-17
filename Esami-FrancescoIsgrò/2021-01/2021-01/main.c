//
//  main.c
//  2021-01
//
//  Created by Maurizio Minieri on 13/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUN 200
#define MAX 1000

typedef struct listaLibro {
    char autore[LUN+1];
    char titolo[LUN+1];
    char genere[LUN+1];
    float prezzo;
    int copie;
    struct listaLibro* next;
} *Libro;

typedef struct lista {
    char key[LUN+1];
    struct lista* next;
    struct listaLibro* listaLibro;
} *Nodo;

Libro coda(Libro top,char autore[],char titolo[],char genere[],float prezzo,int copie) {
    if(top==NULL) {
        top=malloc(sizeof(struct listaLibro));
        strcpy(top->autore,autore);
        strcpy(top->titolo,titolo);
        strcpy(top->genere,genere);
        top->prezzo=prezzo;
        top->copie=copie;
        top->next = NULL;
        return top;
    }
    else {
        top->next = coda(top->next,autore,titolo,genere,prezzo,copie);
        return top;
    }
}

Nodo codaSenzaDoppioni(Nodo top,char genere[]) {
    if(top==NULL) {
        top=malloc(sizeof(struct lista));
        strcpy(top->key,genere);
        top->next = NULL;
        return top;
    }
    else if(strcmp(top->key,genere)==0)
        return top;
    else {
        top->next = codaSenzaDoppioni(top->next,genere);
        return top;
    }
}

void stampaLibri(Libro top) {
    if(top==NULL)
        return;
    else {
        printf("%s, \"%s\", %.2f, %d\n",top->autore,top->titolo,top->prezzo,top->copie);
        stampaLibri(top->next);
    }
}

void stampa(Nodo top) {
    if(top==NULL)
        return;
    else {
        printf("\n%s\n",top->key);
        stampaLibri(top->listaLibro);
        stampa(top->next);
    }
}

Libro cancella_m10(Libro top) {
    Libro tmp;
    if(top==NULL)
        return NULL;
    else if(top->copie<10) {
        tmp=top;
        top=cancella_m10(top->next);
        free(tmp);
    }
    else
        top->next=cancella_m10(top->next);
    return top;
}

int main(int argc, const char * argv[]) {
    
    FILE* fp;
    fp=fopen("input.txt","r");
    if(fp==NULL) {
        printf("Errore: impossibile aprire il file input.txt.\n");
        return 1;
    }
    
    int copie;
    char riga[MAX];
    char autore[LUN+1],titolo[LUN+1],genere[LUN+1];
    float prezzo;
    
    Nodo top=NULL;
    while(fgets(riga,MAX,fp)!=NULL) {
        if(sscanf(riga,"%[^,] %*[^\"]%*c%[^\"]%*c %*c %[^,]",autore,titolo,genere) == 3)
            top=codaSenzaDoppioni(top,genere);
    }
    
    //stampa(top);
    
    Nodo curr=top;
    while(curr) {
        rewind(fp); //torno all'inizio del file
        while(fgets(riga,MAX,fp)!=NULL) {
            if(sscanf(riga,"%[^,] %*[^\"]%*c%[^\"]%*c %*c %[^,] %*c %f, %d",autore,titolo,genere,&prezzo,&copie) == 5) {
                if(strcmp(curr->key,genere)==0)
                    curr->listaLibro = coda(curr->listaLibro,autore,titolo,genere,prezzo,copie);
            }
        }
        curr=curr->next;
    }
    
    //stampa(top);
    
    
    //PUNTO 2
    curr=top;
    Nodo prev=top,tmp;
    while(curr) {
        curr->listaLibro=cancella_m10(curr->listaLibro);
        if(curr->listaLibro==NULL) {
            if(curr==prev) {    //primo nodo (top) da cancellare
                curr=curr->next;
                top=curr;
                free(prev);
                prev=curr;
            }
            else {
                prev->next=curr->next;
                tmp=curr;
                curr=curr->next;
                free(tmp);
            }
        }
        else {
            prev=curr;
            curr=curr->next;
        }
    }
    
    stampa(top);
    
    fclose(fp);
    printf("\n");
    return 0;
}
