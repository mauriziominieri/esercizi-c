//
//  main.c
//  Queue
//
//  Created by Maurizio Minieri on 12/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>


#define QUEUE_MAX 128

struct TQueue {
    int A[QUEUE_MAX+2];
};

typedef struct TQueue* Queue;

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
    printf("| 1) Coda popolata da valori random\t\t|\n");
    printf("| 2) Coda popolata da valori forniti in input   |\n");
    printf("| 3) Stampa\t\t\t\t\t|\n");
    printf("| 4) Cercare un numero\t\t\t\t|\n");
    printf("| 5) Inserisci numero in ordine \t\t|\n");
    printf("| 6) Ordina\t\t\t\t\t|\n");
    printf("| 7) Cancella un numero\t\t\t\t|\n");
    printf("| 8) Cancella l'intera coda\t\t\t|\n");
    printf("x-----------------------------------------------x");
    printf("\nSCELTA = ");
    int scelta=inserisciIntero(&tmp);
    return scelta;
}


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
}

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


// Inizializza la coda
Queue initQueue() {
    Queue Q = (Queue)malloc(sizeof(struct TQueue));
    Q->A[0] = 0;
    Q->A[QUEUE_MAX+1] = 1;
    return Q;
}

// Ritorna 1 se la coda e' piena, 0 altrimenti
int fullQueue(Queue Q){
    return Q->A[0] == Q->A[QUEUE_MAX+1];
}

// Ritorna 1 se la coda e' vuota, 0 altrimenti
int emptyQueue(Queue Q){
    return Q->A[0] == 0;
}

// Accoda un elemento 'value' dato in ingresso
void enqueue(Queue Q, int value){
    if (!fullQueue(Q)) {
        Q->A[Q->A[QUEUE_MAX+1]] = value; // Inserisci valore in coda
        if (emptyQueue(Q)) {
            Q->A[0] = 1; // Se e' vuota, sposto la testa in prima posizione
        }
        Q->A[QUEUE_MAX+1] = (Q->A[QUEUE_MAX+1] % (QUEUE_MAX)) + 1;
    }
}

// Inserisce valori random nella coda
void randomQueue(Queue Q, int dim){
    int i = 0;

    for (i = 0; i < dim; i++)
        enqueue(Q, rand() % 100);
}

int dimQueue(Queue Q) { //Restituisce il numero di nodi attualmente nella coda
    return ((Q->A[QUEUE_MAX+1]-Q->A[0])%QUEUE_MAX);
}

int headQueue(Queue Q) { //Restituisce l'elemento in testa alla coda senza rimuoverlo
    if (!emptyQueue(Q))
        return Q->A[Q->A[0]];
    else
        return INT_MIN;
}

// Toglie un elemento dalla coda
int dequeue(Queue Q){
    int value = 0;
    if (!emptyQueue(Q)) {
        value = Q->A[Q->A[0]]; // Prendo il valore in 'head' della coda
        Q->A[0] = (Q->A[0] % (QUEUE_MAX)) + 1;
        if (fullQueue(Q)) {
            Q->A[0] = 0;
            Q->A[QUEUE_MAX+1] = 1;
        }
    }
    return value;
}

// Salva la coda in reverse
//O(n)  n=dimensione della lista
void reverseQueue(Queue Q){
    int value;
    if (!emptyQueue(Q)) {
        value = dequeue(Q);
        reverseQueue(Q);
        enqueue(Q, value);
    }
}

// Stampa la coda
void printQueueInc(Queue Q){
    int value;
    if (!emptyQueue(Q)) {
        value = dequeue(Q);
        printf("%d ", value);
        printQueueInc(Q);
        enqueue(Q, value);
    }
}

// Stampa la coda
void printQueue(Queue Q){
    printQueueInc(Q); // Stampa la coda
    reverseQueue(Q); // Riordina la coda prima di uscire
    printf("\n\n");
}

bool Cerca(Queue Q, int k) {
    int n;
    bool b;
    if(emptyQueue(Q))
        return false;
    else {
        n = dequeue(Q);
        b = Cerca(Q,k);
        enqueue(Q,n);
        if(k==n)
            return true;
        return b;
    }
}

void enqueueOrdinato(Queue Q, int k){
    if(emptyQueue(Q))
        enqueue(Q,k);
    else {
        int n=dequeue(Q);
        if(n<k) {
            enqueueOrdinato(Q, k);
            reverseQueue(Q);
            enqueue(Q, n);
            reverseQueue(Q);
        }
        else {
            reverseQueue(Q);
            enqueue(Q, n);
            enqueue(Q, k);
            reverseQueue(Q);
        }
    }
}

void ordina(Queue Q){
    /*if (emptyCoda(S))
        return;
    int n = pop(S);
    ordina(S);
    pushOrdinato(S, n);*/
}

bool cancella(Queue Q,int n) {
    if (emptyQueue(Q))
        return false;
    int k=dequeue(Q);
    bool b=cancella(Q,n);
    if(k==n)
        return true;
    else
        enqueue(Q,k);
    return b;
}



int main(int argc, const char * argv[]) {
    
    srand((unsigned int)time(NULL));
    system("@cls||clear");
    Logo();
    int n,scelta,dim,i=0;
    float tmp;
    char c;
    Queue Q=initQueue();
    
    do {
        scelta=Menu();
        switch(scelta) {
            case 0:
                printf("\nArrivederci\n");
            break;
            case 1:
                if(!emptyQueue(Q)) {
                    free(Q); Q=initQueue();
                }
                printf("\nInserisci il numero di elementi: ");
                n=inserisciIntero(&tmp);
                randomQueue(Q,n);
                printf("Coda random creata\n");
                Pulisci();
            break;
            case 2:
                if(!emptyQueue(Q)) {
                    free(Q); Q=initQueue();
                }
                printf("\nInserisci il numero di elementi: ");
                dim=inserisciIntero(&tmp);
                while(dim>0) {
                    if(fullQueue(Q)){
                        printf("Coda piena, non č possibile pių di %d elementi\n",QUEUE_MAX);
                        break;
                    }
                    else {
                        printf("%d° elemento: ",++i);
                        n=inserisciIntero(&tmp);
                        enqueue(Q,n);
                        dim--;
                    }
                }
                i=0;
                system("@cls||clear");
            break;
            case 3:
                if(!emptyQueue(Q)) {
                    printf("\nQ: ");
                    printQueue(Q);
                }
                else
                    printf("\nCoda vuota\n");
                Pulisci();
            break;
            case 4:
                if(emptyQueue(Q))
                    printf("\nCoda vuota.\n");
                else {
                    printf("\nQ: ");
                    printQueue(Q);
                    printf("\nScrivi il numero che vuoi cercare : ");
                    n=inserisciIntero(&tmp);
            
                    if(Cerca(Q,n))
                        printf("\n%d e' presente nello coda\n",n);
                    else
                        printf("\n%d non e' presente nello coda\n",n);
                    reverseQueue(Q);
                }
                Pulisci();
            break;
            case 5:
                printf("\nQ: ");
                printQueue(Q);
                printf("Inserisci il numero che vuoi inserire in ordine: ");
                n=inserisciIntero(&tmp);
                enqueueOrdinato(Q,n);
                printf("%d inserito con successo.\n\nQ: ",n);
                printQueue(Q);
                Pulisci();
            break;
            /*case 6:
                if(emptyQueue(Q))
                    printf("\nCoda vuota.\n");
                else {
                    printf("\nQ: ");
                    printQueue(Q);
                    ordina(Q);
                    printf("\nCoda ordinata.\n\nS: ");
                    printQueue(Q);
                }
                Pulisci();
            break;*/
            case 7:
                if(emptyQueue(Q))
                    printf("\nCoda vuota.\n");
                else {
                    printf("\nQ: ");
                    printQueue(Q);
                    printf("\nInserisci il numero che vuoi cancellare: ");
                    n=inserisciIntero(&tmp);
                    if(cancella(Q,n)) {
                        printf("\n%d cancellato.\n\nS: ",n);
                        printQueue(Q);
                    }
                    else
                        printf("\n%d non trovato\n",n);
                }
                Pulisci();
            break;
            case 8:
                if(emptyQueue(Q)) {
                    printf("\nCoda vuota.\n");
                    Pulisci();
                }
                else {
                    printf("\nSei sicuro di voler eliminare l'intera coda? (y/n): ");
                    do {
                        scanf(" %c",&c);
                    } while((c!='y' && c!='n') && printf("Riprova: "));
                    if(c=='y') {
                        free(Q);
                        printf("Coda deallocata");
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
