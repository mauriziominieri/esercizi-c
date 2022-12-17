//
//  main.c
//  Esercizio-11
//
//  Created by Maurizio Minieri on 10/12/20.
//
/*
 Si progetti ed implementi in C/C++ un algoritmo che, presa da standard input una sequenza di caratteri terminata da
 un punto, determini il numero di vocali minuscole presenti nella sequenza e fornisca su standard output il numero
 calcolato.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    
    /*char c;  //immagino la ram divisa in quadratini, ogni quadratino è un byte.
    int conta = 0;
    
    //quindi dichiarando queste due variabili ho occupato un quadratino per il char (8 bit, spazio di memoria che indico con c), e 4 quadratini per l'intero (dato che sono 32 bit, che indico con conta e ci metto anche il valore 0)
    
    printf("Inserisci una sequenza di caratteri terminata da un punto\n");
    do {
        c=getchar();    //scanf(" %c",&c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            conta++;
    } while(c != '.');
    
    printf("\nIl numero di vocali minuscole presenti nella sequenza è: %d",conta);
    
    
    
    
    int i;
    char ch;
    printf("\n\nImmetti codice ASCII (32-126): ");
    scanf("%d", &i);
    ch = i;
    printf("Il carattere di codice %d è %c\n", i, ch);
    printf("Immetti un carattere: ");
    scanf(" %c",&ch);  //con %c senza spazio considera anche il daccapo e quindi me lo legge codificato 10 in ASCII, cioè '\n'
    //ch = getchar();        //da problemi, gli stessi che ho con scanf(%c senza spazi)
     //per le stringhe si usa gets(stringa)
    //while(getchar() != '\n');
    i = ch;
    printf("Il carattere %c ha codice %d\n", ch, i);*/
    
    
    int i=0,j,z,N=26;
    char c='A';
    
    if(isdigit(c))
        printf("E' una cifra numerica\n");
    if(isalpha(c))
        printf("E' una lettera maiuscola o minuscola\n");
    if(isupper(c))  //toupper(c) o tolower(c) per trasformare
        printf("E' una lettera maiuscola\n");
    if(islower(c))
        printf("E' una lettera minuscola\n");
    if(ispunct(c))
        printf("E' una simbolo speciale\n");
    if(isgraph(c))
        printf("E' una simbolo visibile\n");
    if(isspace(c))
        printf("E' un carattere non visibile\n");

    for(i=0;i<N;i++) {
        c = 'A' + i;
        for(j=0;j<i+1;j++) {
            for(z=0;z<i+1;z++) {
                putchar(c);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    
    /*char s[5],s2[5]; //posso inserire massimo 4 caratteri (a causa del '\0')
    
    gets(s);
    printf("s=%s",s);a
    strcpy(s2,s);//s2=s; non si può usare =
    printf("\ns2=%s",s2);*/
    //strcat(s1,s2) accoda s2 a s1
    //if(strcmp(s1,s2)==0) uguali
    //atoi(str) estrae l'eventuale intero contenuto all'interno di str
    //atof(str) estrea il reale
    
    
    printf("\n\n");
    return 0;
}
