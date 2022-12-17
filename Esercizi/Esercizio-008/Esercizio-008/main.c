//
//  main.c
//  Esercizio-008
//
//  Created by Maurizio Minieri on 18/12/20.
//
/*
 Stampa il bit in posizione i-esima di un numero intero N
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int Menu(void);
void Pulisci(void);
bool checkIntero(float numero);
int inserisciInteroM0(float* x);
int inserisciIntero(float* x);
int inserisciBinario(float* x);
int* convertiDecimaleBinario(int numero);
bool checkBinario(int numero);
int convertiBinarioDecimale(int numero);
void sommaBinaria(int numero1,int numero2);

int Menu() {
    float tmp;
    int scelta;
    printf("\t\t\t\t  Maurizio Minieri");
    printf("\n\nx------------------------------------------------x");
    printf("\n| 0) EXIT\t\t\t\t\t |\n| 1) Per fare la conversione decimale - binario\t |\n| 2) Per fare la conversione binario - decimale  |\n| 3) Per effettuare la somma di due binari\t |\n| 4) Per effettuare la differenza di due binari  |\n");
    //printf("\t\t |\n| 5) Per cancellare un segmento stradale\t |\n| 6) Per calcolare il percorso\t\t\t |\n");
    printf("x------------------------------------------------x");
    printf("\nSCELTA = ");
    scelta=inserisciIntero(&tmp);
    return scelta;
}

void Pulisci() {
    printf("\n\nPremi Enter per continuare... ");
    char prev=0;
    while(1) {
        char c = getchar();
        if(c == '\n' && prev == c) {
            system("@cls||clear");
            break;
        }
        prev = c;
    }
}

//non permette proprio di inserire 4.5, normalmente me lo fa inserire e lo tronca in 4
bool checkIntero(float numero) {
    int tmp = floor(numero);    //tmp = (int)numero;
    if(numero == tmp) return true;
    else return false;
}
//non permette di inserire niente che non sia un numero > 0
int inserisciInteroM0(float* x) {
    while(scanf("%f",x)!=1 || *x<=0 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}
//non permette di inserire niente che non sia un numero > 0
int inserisciIntero(float* x) {
    while(scanf("%f",x)!=1 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}
//non permette di inserire niente che non sia un numero binario, se togliessi checkIntero() potrei inserire 1.5
int inserisciBinario(float* x) {
    while(scanf("%f",x)!=1 || checkIntero(*x)==false || checkBinario(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}

int* convertiDecimaleBinario(int numero) {
    
    int binario[32];  //il massimo numero intero rappresentabile è 2 alla 32 = 4294967296.
    //2 alla 31 = 2147483648, alla 30 = 1073741824
    int num,i;
    num = numero;
    
    for(i=0;i<32;i++)
        binario[i] = 0;
    
    i = 31;
    while(num != 0) {
        binario[i] = num % 2;
        num /= 2;  //num = num / 2;
        i--;
    }
    
    printf("\n%d in binario: ",numero);
    for(i=0;i<32;i++)
        printf("%1d",binario[i]);  //0 spazi, %2d mette uno spazio tra i numeri
    
    return binario;
}

bool checkBinario(int numero) {
    int n;
    
    while(numero) {  //>0 implicito
        n = numero % 10;

        if(n * n != n)
            return false;
        numero/=10;
    }
    
    return true;
}

int convertiBinarioDecimale(int numero) {
    
    int decimale=0,i=0,n=numero;
    //dato che è un binario a me interessa sapere solo se passo dopo passo ho 0 oppure 1
    //i=0 -> n = 101, diviso 10 non fa resto 0 quindi-> decimale = 0 + 1, n = 10
    //i=1 -> n = 10, diviso 10 fa resto 0, decimale = 1, n = 1
    //i=2 -> n = 1, diviso 10 non fa resto 0 -> decimale = 1 + 4, n = 0
    //i=3 -> n = 0
    
    while(n>0) {
        if(n%2!=0)
            decimale += pow(2,i);
        n/=10;
        i++;
    }
    
    printf("%d in decimale: %d",numero,decimale);
    return decimale;
}

void sommaBinaria(int numero1,int numero2) {
   
    int somma=0;
    somma = convertiBinarioDecimale(numero1) + convertiBinarioDecimale(numero2);
    printf("La somma di %d e %d e': %d",numero1,numero2,numero1+numero2);
}

int main(int argc, const char * argv[]) {
    
    float tmp;   //ci servono per assicurarci che vengano inseriti degli interi
    int scelta,numero,numero2,i,bit,bit_pos;
    
    system("@cls||clear");
    do {
        scelta=Menu();
        switch(scelta) {
            case 0 :
                printf("\nArrivederci\n");
            break;
            case 1:
                printf("Inserisci un numero intero(>0): ");    //se numero = 7 allora (00000111)
                numero=inserisciInteroM0(&tmp);
                
                printf("Inserisci la posizione(>0): ");
                i=inserisciInteroM0(&tmp);                         //es: 3
                
                if(i>(8*sizeof(int)))   //un intero è composto da 32 bit, il sizeof mi darà il risultato in byte.
                    printf("\nLa posizione indicata eccede il numero di bit di un intero");
                else {
                    convertiDecimaleBinario(numero);
                    bit_pos = 1 << (i-1);   //faccio un left shift del numero binario 1 di (i-1) posizioni. Sposterò 00000001 di 2 posizioni a sinistra -> bit_pos = 00000100
                    bit = numero & bit_pos; //faccio un AND tra bit. Es: 00000111 AND 00000100 = 00000100
                    bit = bit >> (i-1); //right shift di 00000100 di 2 posizioni -> 00000001
                    printf("\nIl %d° bit di %d è: %d",i,numero,bit);
                }
                Pulisci();
            break;
            case 2:
                //do {
                printf("Inserisci un numero binario: ");
                numero=inserisciBinario(&tmp);
                //}
                //while(checkBinario(numero) == false && printf("Errore, non è un numero binario. Riprova\n"));
                convertiBinarioDecimale(numero);
                Pulisci();
            break;
            case 3:
                printf("Inserisci il primo numero binario: ");
                numero=inserisciBinario(&tmp);
                printf("Inserisci il secondo numero binario: ");
                numero2=inserisciBinario(&tmp);
                sommaBinaria(numero,numero2);
                Pulisci();
            break;
            case 4:
                Pulisci();
            break;
            default:
                printf("\nErrore, numero non valido");
                Pulisci();
        }
    }
    while(scelta!=0);
    
    printf("\n");
    return 0;
}
