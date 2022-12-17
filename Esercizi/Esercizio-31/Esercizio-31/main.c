//
//  main.c
//  Esercizio-31
//
//  Created by Maurizio Minieri on 13/12/20.
//
/*
 In un concorso, ciascuno degli N commissari esprime un voto (valore numerico tra 0 e 30) per ciascuno dei K
 candidati.
 Si progetti ed implementi in C/C++ un algoritmo che acquisisca da standard input i voti espressi dai commissari e
 fornisca su standard output il/i giudice/i i ∈ {1, . . . , N} più severo/i (in termini di voto espresso) e il/i candidato/i
 j ∈ {1, . . . , K} più intelligente/i (in termini di voto ricevuto)
 */

#include <stdio.h>
#include <stdlib.h>

void stampa(int** M,int n,int m) {
    printf("STAMPA\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("[%d]",M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** trasposta(int** M,int n,int m) {
    
    int** MT = malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
        MT[i] = malloc(n*sizeof(int));
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            MT[i][j] = M[j][i];
        }
    
    return MT;
}

int main(int argc, const char * argv[]) {
    
    int N=3,K=3;
    
    int **M = malloc(N*sizeof(int*));
    for(int i=0;i<N;i++)
        M[i] = malloc(K*sizeof(int));
    
    for(int i=0;i<N;i++) {
        printf("Giudice %d\n",i+1);
        for(int j=0;j<K;j++) {
            do {
                printf("Esprimi il voto per il %d° candidato: ",j+1);
                scanf("%d",&M[i][j]);
            }
            while((M[i][j]<0 || M[i][j]>30) && printf("Il voto deve essere compreso tra 0 e 30\n"));
        }
        printf("\n");
    }
    
    //stampa(M, N, K);
    
    int **MT = trasposta(M,N,K);
    
    //stampa(MT,K,N);
    
    int min=-1,max=-1,somma=0;
    int *giudicePiuSevero = NULL,*giudicePiuBuono = NULL;
    int *candidatoPiuIntelligente = NULL,*candidatoMenoIntelligente = NULL;
    int lunghezza1 = 0,lunghezza2 = 0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<K;j++) {
            somma += M[i][j];
        }
        
        if(min==-1 || somma<min)
            min = somma;
        if(max==-1 || somma>max)
            max = somma;
        
        somma = 0;
    }
    
    somma = 0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<K;j++) {
            somma += M[i][j];
        }
        
        if(somma == min) {
            lunghezza1++;
            giudicePiuSevero = realloc(giudicePiuSevero,lunghezza1 * sizeof(int));
            giudicePiuSevero[lunghezza1-1] = i+1;
        }
        if(somma == max) {
            lunghezza2++;
            giudicePiuBuono = realloc(giudicePiuBuono,lunghezza2 * sizeof(int));
            giudicePiuBuono[lunghezza2-1] = i+1;
        }
        somma = 0;
    }
    
    
    char c1,c2,c3,c4;
    
    c1 = lunghezza1 > 1 ? 'i' : 'e';
    c2 = lunghezza1 > 1 ? 'i' : 'o';
    c3 = lunghezza2 > 1 ? 'i' : 'e';
    c4 = lunghezza2 > 1 ? 'i' : 'o';
    
    printf("Giudic%c più sever%c: [",c1,c2);
    for(int i=0;i<lunghezza1;i++)
        if(i==lunghezza1-1)
            printf("%d",giudicePiuSevero[i]);
        else
            printf("%d,",giudicePiuSevero[i]);
    printf("]\n");
    
    printf("Giudic%c più buon%c: [",c3,c4);
    for(int i=0;i<lunghezza2;i++)
        if(i==lunghezza2-1)
            printf("%d",giudicePiuBuono[i]);
        else
            printf("%d,",giudicePiuBuono[i]);
    printf("]\n");
    
    somma = 0;
    min = -1;
    max = -1;
    
    for(int i=0;i<K;i++) {
        for(int j=0;j<N;j++) {
            somma += MT[i][j];
        }
        
        if(min==-1 || somma<min)
            min = somma;
        if(max==-1 || somma>max)
            max = somma;
        
        somma = 0;
    }
    
    somma = 0;
    lunghezza1 = 0;
    lunghezza2 = 0;
    
    for(int i=0;i<K;i++) {
        for(int j=0;j<N;j++) {
            somma += MT[i][j];
        }
        
        if(somma == min) {
            lunghezza1++;
            candidatoMenoIntelligente = realloc(candidatoMenoIntelligente,lunghezza1 * sizeof(int));
            candidatoMenoIntelligente[lunghezza1-1] = i+1;
        }
        if(somma == max) {
            lunghezza2++;
            candidatoPiuIntelligente = realloc(candidatoPiuIntelligente,lunghezza2 * sizeof(int));
            candidatoPiuIntelligente[lunghezza2-1] = i+1;
        }
        somma = 0;
    }
    
    c1 = lunghezza1 > 1 ? 'i' : 'o';
    c2 = lunghezza1 > 1 ? 'i' : 'e';
    c3 = lunghezza2 > 1 ? 'i' : 'o';
    c4 = lunghezza2 > 1 ? 'i' : 'e';
    
    printf("\nCandidat%c meno intelligent%c: [",c1,c2);
    for(int i=0;i<lunghezza1;i++)
        if(i==lunghezza1-1)
            printf("%d",candidatoMenoIntelligente[i]);
        else
            printf("%d,",candidatoMenoIntelligente[i]);
    printf("]\n");
    
    printf("Candidat%c più intelligent%c: [",c3,c4);
    for(int i=0;i<lunghezza2;i++)
        if(i==lunghezza2-1)
            printf("%d",candidatoPiuIntelligente[i]);
        else
            printf("%d,",candidatoPiuIntelligente[i]);
    printf("]\n");
    
    printf("\n\n");
    return 0;
}
