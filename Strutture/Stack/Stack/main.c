//
//  main.c
//  Stack
//
//  Created by Maurizio Minieri on 09/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define STACK_MAX 128

struct TStack{
    int A[STACK_MAX+1];
};

typedef struct TStack* Stack;

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

void Logo() {
    printf("    _____        ___          ___      ___                 ___\n");
    printf("   /  /::\\      /  /\\        /  /\\    /  /\\    ___        /  /\\ \n");
    printf("  /  /:/\\:\\    /  /::\\      /  /::\\  /  /::\\  /  /\\      /  /::\\\n");
    printf(" /  /:/  \\:\\  /  /:/\\:\\    /  /:/\\:\\/  /:/\\:\\/  /:/     /  /:/\\:\\ \n");
    printf("/__/:/ \\__\\:|/  /:/  \\:\\  /  /:/~/:/  /:/~/:/__/::\\    /  /:/~/::\\\n");
    printf("\\  \\:\\ /  /:/__/:/ \\__\\:\\/__/:/ /:/__/:/ /:/\\__\\/\\:\\__/__/:/ /:/\\:\\\n");
    printf(" \\  \\:\\  /:/\\  \\:\\ /  /:/\\  \\:\\/:/\\  \\:\\/:/    \\  \\:\\/\\  \\:\\/:/__\\/\n");
    printf("  \\  \\:\\/:/  \\  \\:\\  /:/  \\  \\::/  \\  \\::/      \\__\\::/\\  \\::/  \n");
    printf("   \\  \\::/    \\  \\:\\/:/    \\  \\:\\   \\  \\:\\      /__/:/  \\  \\:\\  \n");
    printf("    \\__\\/      \\  \\::/      \\  \\:\\   \\  \\:\\     \\__\\/    \\  \\:\\  \n");
    printf("                \\__\\/        \\__\\/    \\__\\/___          __\\__\\/  \n");
    
    printf("                /  /\\        /__/\\        /__/\\        /  /\\ \n");
    printf("               /  /:/_      |  |::\\      |  |::\\      /  /:/_ \n");
    printf("              /  /:/ /\\     |  |:|:\\     |  |:|:\\    /  /:/ /\\  \n");
    printf("             /  /:/ /:/_  __|__|:|\\:\\  __|__|:|\\:\\  /  /:/ /:/_  \n");
    printf("            /__/:/ /:/ /\\/__/::::| \\:\\/__/::::| \\:\\/__/:/ /:/ /\\ \n");
    printf("            \\  \\:\\/:/ /:/\\  \\:\\~~\\__\\/\\  \\:\\~~\\__\\/\\  \\:\\/:/ /:/ \n");
    printf("             \\  \\::/ /:/  \\  \\:\\       \\  \\:\\       \\  \\::/ /:/ \n");
    printf("              \\  \\:\\/:/    \\  \\:\\       \\  \\:\\       \\  \\:\\/:/  \n");
    printf("               \\  \\::/      \\  \\:\\       \\  \\:\\       \\  \\::/   \n");
    printf("                \\__\\/        \\__\\/        \\__\\/        \\__\\/   \n\n");
}

void clearBuffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { };
}

/*
int getInt(int *data){
    int ok, // ritorno della funzione
        i, // indice per scorrere la stringa letta
        negative; // indica se il numero è negativo
    char buffer[51];
    scanf("%50s",buffer);
    clearBuffer();
    i = negative = (buffer[0]=='-') ? 1 : 0 ;
    while( buffer[i]>47 && buffer[i]<58 ) i++;
    ok = (buffer[i]=='\0' && i>negative );
    if(ok) *data = atoi(buffer);
    return ok;
}*/

bool checkIntero(float x) {
    int tmp=floor(x);
    if(tmp==x) return true;
    else return false;
}

int inserisciIntero(float* x) {
    while(scanf("%f",x)!=1 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n'); //prende tutti i caratteri prima del \n
    }
    return *x;
}

int inserisciInteroM0(float* x) {
    while(scanf("%f",x)!=1 || *x<0 || checkIntero(*x)==false) {
        printf("Riprova: ");
        while(getchar()!='\n');
    }
    return *x;
}


int Menu() {
    float tmp;
    printf("\n\nx-----------------------------------------------x\n");
    printf("| 0) Esci\t\t\t\t\t|\n");
    printf("| 1) Stack popolato da valori random\t\t|\n");
    printf("| 2) Stack popolato da valori forniti in input  |\n");
    printf("| 3) Stampa\t\t\t\t\t|\n");
    printf("| 4) Cercare un numero\t\t\t\t|\n");
    printf("| 5) Inserisci numero in ordine \t\t|\n");
    printf("| 6) Ordina\t\t\t\t\t|\n");
    printf("| 7) Cancella un numero\t\t\t\t|\n");
    printf("| 8) Cancella l'intero stack\t\t\t|\n");
    printf("x-----------------------------------------------x");
    printf("\nSCELTA = ");
    int scelta=inserisciIntero(&tmp);
    return scelta;
}


/*
int getPositive(int *data){
    int ok, // ritorno della funzione
        i; // indice per scorrere la stringa letta
    char buffer[51];
    scanf("%50s",buffer);
    clearBuffer();
    i = 0;
    while( buffer[i]>47 && buffer[i]<58 ) i++;
    ok = (buffer[i]=='\0' && i>0 );
    if(ok) *data = atoi(buffer);
    return ok;
}

int getFloat(float *f){
    char buffer[51];
    int cont, //indice per lo scorrimento dell'input utente
        off, //lunghezza minima della stringa (in base alla presenza del punto e/o del segno negativo)
        ret;
    scanf("%50s",buffer);
    clearBuffer();
    cont = off = (buffer[0]=='-') ? 1 : 0;
    while(buffer[cont]>47 && buffer[cont]<58) cont++;
    if(buffer[cont]=='.'){
        cont++;
        off++;
        while(buffer[cont]>47 && buffer[cont]<58) cont++;
    }
    ret = (buffer[cont]=='\0' && cont>off);
    if(ret)
        *f = atof(buffer);
    return ret;
}
*/



// Inizializza lo Stack
Stack initStack() {
    Stack S = (Stack)malloc(sizeof(struct TStack));
    S->A[0] = 0;
    return S;
}

// Ritorna 1 se lo Stack e' pieno, 0 altrimenti
int fullStack(Stack S){
    return S->A[0] == STACK_MAX;
}

void push(Stack S, int value){
    if(!fullStack(S)){
        S->A[0]++;
        S->A[S->A[0]] = value;
    }
}

void randomStack(Stack S, int n) {
    int i = 0;
    for (i = 0; i < n; i++)
        push(S, rand() % 100);
}

// Ritorna 1 se lo Stack e' vuoto, 0 altrimenti
int emptyStack(Stack S){
    return S->A[0] == 0;
}

int dimStack(Stack S){ // Ritorna il numero di elementi attualmente nello stack
    return S->A[0];
}

int headStack(Stack S) { //Restituisce l'elemento in testa allo stack senza rimuoverlo
    if (!emptyStack(S)) {
        return S->A[S->A[0]+1];
    }
    else {
        return INT_MIN;
    }
}

// Estrae dallo Stack un elemento e lo ritorna
int pop(Stack S){
    //int errh=0, *err=&errh;
    if(!emptyStack(S)){
        S->A[0]--;
        //*err = 0;
    //    checkStackError(err);
        return S->A[S->A[0]+1];
    } else {
    //    *err = 2;
    //    checkStackError(err);
        return 0;
    }
}

// Dato uno Stack S, attraversera' tutto lo Stack inserendo
// in un altro Stack dato in ingresso 'tmp' tutti gli
// elementi nell'ordine inverso
void reverseStack(Stack S, Stack tmp){
    int value;
    if(!emptyStack(S)){
        value = pop(S);
        push(tmp, value);
        reverseStack(S, tmp);
        push(S, value);
    }
}

void printStack(Stack S){
    int value;
    if(!emptyStack(S)){
        value = pop(S);
        printf("%d ", value);
        printStack(S);
        push(S, value);
    }
    else
        printf("\n");
}

bool Cerca(Stack S, int k) {
    int n;
    bool b;
    if(emptyStack(S))
        return false;
    else {
        n = pop(S);
        if(n==k) {
            push(S,n);
            return true;
        }
        b=Cerca(S,k);
        push(S,n);
        return b;
    }
}

void pushOrdinato(Stack S, int k){
    if(emptyStack(S))
        push(S,k);
    else {
        int n=pop(S);
        if(n<k) {
            pushOrdinato(S,k);
            push(S,n);
        }
        else {
            push(S,n);
            push(S,k);
        }
    }
}

void ordina(Stack S){
    if (emptyStack(S))
        return;
    int n = pop(S);
    ordina(S);
    pushOrdinato(S, n);
}

bool cancella(Stack S,int n) {
    if (emptyStack(S))
        return false;
    int k=pop(S);
    bool b=cancella(S,n);
    if(k==n)
        return true;
    else
        push(S,k);
    return b;
}

int main(int argc, const char * argv[]) {
    
    srand((unsigned int)time(NULL));
    system("@cls||clear");
    Logo();
    int n,scelta,dim,i=0;
    float tmp;
    char c;
    Stack S=initStack();
    
    do {
        scelta=Menu();
        switch(scelta) {
            case 0:
                printf("\nArrivederci\n");
            break;
            case 1:
                if(!emptyStack(S)) {
                    free(S); S=initStack();
                }
                printf("\nInserisci il numero di elementi: ");
                n=inserisciIntero(&tmp);
                randomStack(S,n);
                printf("Stack random creato\n");
                Pulisci();
            break;
            case 2:
                if(!emptyStack(S)) {
                    free(S); S=initStack();
                }
                printf("\nInserisci il numero di elementi: ");
                dim=inserisciIntero(&tmp);
                while(dim>0) {
                    if(fullStack(S)){
                        printf("Stack pieno, non č possibile pių di %d elementi\n",STACK_MAX);
                        break;
                    }
                    else {
                        printf("%d° elemento: ",++i);
                        n=inserisciIntero(&tmp);
                        push(S,n);
                        dim--;
                    }
                }
                i=0;
                system("@cls||clear");
            break;
            case 3:
                if(!emptyStack(S)) {
                    printf("\nS: ");
                    printStack(S);
                }
                else
                    printf("\nstack vuoto\n");
                Pulisci();
            break;
            case 4:
                if(emptyStack(S))
                    printf("\nstack vuoto.\n");
                else {
                    printf("\nS: ");
                    printStack(S);
                    printf("\nScrivi il numero che vuoi cercare : ");
                    n=inserisciIntero(&tmp);
            
                    if(Cerca(S,n))
                        printf("\n%d e' presente nello stack\n",n);
                    else
                        printf("\n%d non e' presente nello stack\n",n);
                }
                Pulisci();
            break;
            case 5:
                printf("\nS: ");
                printStack(S);
                printf("\nInserisci il numero che vuoi inserire in ordine: ");
                n=inserisciIntero(&tmp);
                pushOrdinato(S,n);
                printf("%d inserito con successo.\n\nS: ",n);
                printStack(S);
                Pulisci();
            break;
            case 6:
                if(emptyStack(S))
                    printf("\nstack vuoto.\n");
                else {
                    printf("\nS: ");
                    printStack(S);
                    ordina(S);
                    printf("\nStack ordinato.\n\nS: ");
                    printStack(S);
                }
                Pulisci();
            break;
            case 7:
                if(emptyStack(S))
                    printf("\nStack vuoto.\n");
                else {
                    printf("\nS: ");
                    printStack(S);
                    printf("\nInserisci il numero che vuoi cancellare: ");
                    n=inserisciIntero(&tmp);
                    if(cancella(S,n)) {
                        printf("\n%d cancellato.\n\nS: ",n);
                        printStack(S);
                    }
                    else
                        printf("\n%d non trovato\n",n);
                }
                Pulisci();
            break;
            case 8:
                if(emptyStack(S)) {
                    printf("\nStack vuoto.\n");
                    Pulisci();
                }
                else {
                    printf("\nSei sicuro di voler eliminare l'intero stack? (y/n): ");
                    do {
                        scanf(" %c",&c);
                    } while((c!='y' && c!='n') && printf("Riprova: "));
                    if(c=='y') {
                        free(S);
                        printf("Stack deallocato");
                        Pulisci();
                    }
                    else
                        system("@cls||clear");
                }
            break;
            default:
                printf("\nTasto non valido");
                Pulisci();
        }
    }
    while(scelta!=0);

    printf("\n");
    return 0;
}
