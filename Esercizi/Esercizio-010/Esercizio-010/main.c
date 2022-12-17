//
//  main.c
//  Esercizio-010
//
//  Created by Maurizio Minieri on 19/12/20.
//
/*
 Scrivere un programma che acquisisca i dati relativi agli studenti
 di una classe:
 •nome
 •cognome
 •data di nascita (struct con giorno mese anno)
 •indirizzo (struct con via, numero civ, cap, citta, provincia)
 •voti – rappresenta i voti dello studente in 3 materie
 (italiano, matematica, inglese);
 Il programma deve successivamente calcolare e stampare, per
 ogni studente, la media dei voti ottenuti nelle 3 materie
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const int n_materie = 3;
#define MAXS 30
#define MAXC 6
#define MAXP 3

typedef struct {
    int giorno,mese,anno;
} data;

typedef struct {
    char via[MAXS],citta[MAXS],cap[MAXC],prov[MAXP];
    int num_civ;
} indirizzo;

typedef struct {
    char nome[MAXS];
    int voto;
} materia;

typedef struct {
    char nome[MAXS],cognome[MAXS];
    char sesso;
    data data;
    indirizzo indirizzo;
    materia materia[n_materie];
} studente;

bool checkIntero(float x) {
    int tmp = floor(x);
    if(tmp==x) return true;
    else return false;
}

void inserisciInteroM0(float* x) {
    while(scanf("%f",x)!=1 || checkIntero(*x)==false || *x<1) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
}

bool checkGM(int giorno, int mese) {
    
    if(giorno<1 || giorno>31 || mese<1 || mese>12)
        return false;
    
    switch(mese) {
        case 2:
                if(giorno>28)
                    return false;
            break;
        case 4:
                if(giorno>30)
                    return false;
            break;
        case 6:
                if(giorno>30)
                    return false;
            break;
        case 9:
            if(giorno>30)
                return false;
            break;
        case 11:
            if(giorno>30)
                return false;
            break;
    }
    
    return true;
}

bool checkAnno(int anno) {
    if(anno<1900 || anno>2010) //massimo 120 e minimo 10 anni
        return false;
    return true;
}

int main(int argc, const char * argv[]) {
    
    float nTmp,giornoTmp,meseTmp,annoTmp,votoTmp;
    int n=0,somma=0;
    
    
    printf("Inserisci il numero di studenti: ");
    inserisciInteroM0(&nTmp);
    n=nTmp;
    
    /*int *p; //dichiaro un puntatore ad un intero, occupo 4 quadratini occupati con l'indirizzo del puntatore, non si può dare un valore direttamente in questa locazione, il puntatore infatti PUNTERA' ad un qualcosa
    p=&n;    //p punta all'indirizzo di memoria dove vive la variabile n
    p=&array  //non si può fare dato che array non è di tipo int, quindi &array non è di tipo *int
    p=&array[0] //oppure p=array //punto all'indirizzo del primo elemento dell'array e poi per stampare i vari elementi faccio *(p++)
    printf("n=%d\n",n);
    printf("*p=%d\n",*p); //valore dell'oggetto puntato
    printf("p=%p\n",p); //valore del puntatore (locazione di memoria)
    *p=99;  //sto modificando il valore nella locazione dove punta p, in pratica sto cambiando il valore di n
     */
   
    studente studenti[n];
    //studente *studenti[n]  è un array di n puntatori di tipo studente
    //studente (*studenti)[n] è un puntatore ad un array di n elementi di tipo studente
    materia materie[n_materie] = {{"italiano",0},{"matematica",0},{"inglese",0}};
    
    for(int i=0;i<n;i++) {
        printf("Studente %d\n",i+1);
        printf("\tnome: ");
        scanf("%s",studenti[i].nome);
        printf("\tcognome: ");
        scanf("%s",studenti[i].cognome);
        do{
            printf("\tsesso: ");
            scanf(" %c",&studenti[i].sesso);
            while(getchar()!='\n');
        }
        while(studenti[i].sesso!='m' && studenti[i].sesso!='f');
        do{
            printf("\tdata di nascita, giorno: ");
            inserisciInteroM0(&giornoTmp);
            printf("\tmese: ");
            inserisciInteroM0(&meseTmp);
            studenti[i].data.giorno = giornoTmp;
            studenti[i].data.mese = meseTmp;
        }
        while(!checkGM(studenti[i].data.giorno,studenti[i].data.mese) && printf("Data impossibile"));
        do{
            printf("\tanno: ");
            inserisciInteroM0(&annoTmp);
            studenti[i].data.anno = annoTmp;
        }
        while(!checkAnno(studenti[i].data.anno) && printf("Anno impossibile"));
       
        for(int j=0;j<n_materie;j++) {
            do{
                printf("\tInserisci il voto per %s: ",materie[j].nome);
                inserisciInteroM0(&votoTmp);
                studenti[i].materia[j].voto = votoTmp;
            }
            while((studenti[i].materia[j].voto<18 || studenti[i].materia[j].voto>30)&&printf("Errore (>=18 <=30)\n"));
        }
    }
    
    printf("\nSTUDENTI\n");
    for(int i=0;i<n;i++) {
        printf("Studente %d: ",i+1);
        printf("%s",studenti[i].nome);
        printf(",%s",studenti[i].cognome);
        if(studenti[i].sesso == 'f')
            printf(",femmina. Nata il: ");
        else
            printf(",maschio. Nato il: ");
        printf("%d/",studenti[i].data.giorno);
        printf("%d/",studenti[i].data.mese);
        printf("%d. ",studenti[i].data.anno);
        
        for(int j=0;j<n_materie;j++) {
            printf("[%s: ",materie[j].nome);
            printf("%d]",studenti[i].materia[j].voto);
            somma+=studenti[i].materia[j].voto;
        }
        printf(" MEDIA:%f",(float)somma/n_materie);
        printf("\n");
        somma=0;
    }
    
    printf("\n\n");
    return 0;
}
