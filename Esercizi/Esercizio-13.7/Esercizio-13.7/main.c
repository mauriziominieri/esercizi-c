//
//  main.c
//  Esercizio-13.7
//
//  Created by Maurizio Minieri on 27/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 4
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int x,y;
int mosse=0;

void intro() {
    printf("\t\t\t\t\t*-----------------*\n");
    printf("\t\t\t\t\t| " ANSI_COLOR_RED "IL GIOCO DEL 15" ANSI_COLOR_RESET " |\n");
    printf("\t\t\t\t\t*-----------------*\n");
    printf("In tale gioco, una scacchiera 4x4 contiene 15 pezzi (numerati da 1 a 15) ed una casella vuota.\nIl giocatore ad ogni mossa può spostare uno dei pezzi adiacenti alla casella vuota nella casella vuota stessa.\nVinci quando i numeri compaiono nell’ordine numerico corretto.\nSpecifica le tue mosse indicando la direzione in cui vuoi \"spostare\" la casella vuota.\n\n");
}

int** allocaMatrice(int **M) {
    M = (int**)malloc(N*sizeof(int *));
    for(int i=0;i<N;i++)
        M[i] = malloc(N*sizeof(int));
    return M;
}

void riempiMatrice(int **M) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("Inserisci elemento [%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
}

bool presente(int a[],int r) {
    for(int i=1;i<=N*N-1;i++) {
        if(a[i]==r) {
            a[i] = 0;
            return true;
        }
    }
    return false;
}

void riempiMatriceRandom(int **M) {
    int array[N*N-1];
    int r,conta=0;
    srand(time(NULL));
    
    for(int i=1;i<=N*N-1;i++)
        array[i]=i;
    
    x=rand() % N;
    y=rand() % N;
    M[x][y] = 0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i!=x || j!=y) {
                do {
                    r=rand() % (N*N-1) + 1;
                }
                while(presente(array,r)==false);
                M[i][j] = r;
                conta++;
                if(conta>=(N*N-1))
                    break;
            }
        }
    }
}

int** creaMatrice(int **M) {
    M=allocaMatrice(M);
    //riempiMatrice(M);
    riempiMatriceRandom(M);
    return M;
}

void stampaMatrice(int **M) {
    system("clear");
    intro();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(M[i][j]==0)
                printf(ANSI_COLOR_GREEN "[    ]" ANSI_COLOR_RESET);
            else if(M[i][j]>9)
                printf("[ %d ]",M[i][j]);
            else
                printf("[ %d  ]",M[i][j]);
        }
        printf("\n");
    }
}

void scambiaY(int **M,int s) {
    int tmp=M[x][y];
    M[x][y]=M[x][s];
    M[x][s]=tmp;
    y=s;
    mosse++;
}

void scambiaX(int **M,int s) {
    int tmp=M[x][y];
    M[x][y]=M[s][y];
    M[s][y]=tmp;
    x=s;
    mosse++;
}

bool vittoria(int **M) {
    int i,j,conta=1;
    for(i=0;i<N;i++) {
        for(j=0;j<N-1;j++) {
           if(conta==N*N-1)
               return true;
                
            if(M[i][j]!=M[i][j+1]-1)
                return false;
            conta++;
        }
        //controllo l'ultima colonna col la prima della riga successiva
        if(i!=N-1 && M[i][j]!=M[i+1][0]-1)
            return false;
        conta++;
    }
    return true;
}

void gioca(int **M) {
    char mossa;
    while(!vittoria(M)) {
        printf("\nLe mosse possibili sono: ");
        if(y==0)
            printf("%d, ",M[x][y+1]);
        else if(y==N-1)
            printf("%d, ",M[x][y-1]);
        else
            printf("%d, %d, ",M[x][y-1],M[x][y+1]);
        
        if(x==0)
            printf("%d.",M[x+1][y]);
        else if(x==N-1)
            printf("%d.",M[x-1][y]);
        else
            printf("%d, %d.",M[x-1][y],M[x+1][y]);

        printf("\nScegli mossa (a,w,s,d): ");
        scanf(" %c",&mossa);
        
        switch(mossa) {
            case 'w':
                if(x!=0)
                    scambiaX(M,x-1);
            break;
            case 'a':
                if(y!=0)
                    scambiaY(M,y-1);
            break;
            case 'd':
                if(y!=N-1)
                    scambiaY(M,y+1);
            break;
            case 's':
                if(x!=N-1)
                    scambiaX(M,x+1);
            break;
        }
        stampaMatrice(M);
    }
}

int main(int argc, const char * argv[]) {
   
    int **M = NULL;

    M=creaMatrice(M);
    stampaMatrice(M);
    gioca(M);
    
    if(mosse==1)
        printf("\nHAI VINTO IN %d MOSSA.\n",mosse);
    else
        printf("\nHAI VINTO IN %d MOSSE.\n",mosse);
    
    if(mosse<26)
        printf(ANSI_COLOR_GREEN "OTTIMO LAVORO\n" ANSI_COLOR_RESET);
    else if(mosse<51)
        printf(ANSI_COLOR_YELLOW "BUON LAVORO\n" ANSI_COLOR_RESET);
    else
        printf(ANSI_COLOR_RED "ALLENATI DI PIU'\n" ANSI_COLOR_RESET);
    
    printf("\n");
    return 0;
}
