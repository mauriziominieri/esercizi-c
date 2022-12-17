//
//  main.c
//  Liste
//
//  Created by Maurizio Minieri on 07/01/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct lista {
    int key;
    struct lista *next;    //campo dell'indirizzo del nodo successivo
} *Nodo;

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
    printf("\n\nx-------------------------------x");
    printf("\n| 0) Esci\t\t\t|");
    printf("\n| 1) Inserisci intero in testa\t|\n| 2) Inserisci intero in coda\t|\n| 3) Inserisci intero in mezzo\t|");
    printf("\n| 4) Stampa\t\t\t|\n| 5) Cercare un numero\t\t|\n| 6) Inserisci numeri in ordine |");
    printf("\n| 7) Ordina\t\t\t|\n| 8) Cancella un numero\t\t|\n| 9) Cancella l'intera lista\t|\n");
    printf("x-------------------------------x");
    printf("\nSCELTA = ");
    int scelta=inserisciIntero(&tmp);
    return scelta;
}

struct lista* Creanodo(int k) {
    struct lista* temp=(struct lista*)malloc(sizeof(struct lista));
    temp->key=k;
    temp->next=NULL;
    return temp;
}

void Dealloca(struct lista* top) {
    if(top==NULL)
        return; //free(top);
    else {
        top->next=NULL;
        free(top);
        Dealloca(top->next);
    }
    //poi nel main devi mettere top=NULL;    !!!
}

Nodo Testa(Nodo top,char n) {   //'z'
    Nodo tmp=malloc(sizeof(struct lista));
    tmp->key=n;
    tmp->next=top;
    return tmp;
}

struct lista* Coda(struct lista* top,int n) {
    struct lista *tmp;
    if (top==NULL) {
        tmp=malloc(sizeof(struct lista));
        tmp->key=n;
        tmp->next=top;
        return tmp;
    }
    else {
        top->next=Coda(top->next,n);
        return top;
    }
}

int isEmpty(struct lista* top) {
    return (!top) ? 1 : 0;
}

void Stampa(struct lista* top) {
    if(top==NULL)
        printf("NIL");
    else {
        printf("%d -> ",top->key);
        Stampa(top->next);
    }
}

int Cerca(struct lista* top,int n) {
    struct lista* curr;
    for(curr=top;curr!=NULL;curr=curr->next)
        if(curr->key==n)
            return 1;
    return 0;
}

struct lista* Ordinan(struct lista* top,int n) {
    struct lista *tmp;
    
    if(top==NULL||top->key>n) {
        tmp=malloc(sizeof(struct lista));
        tmp->key=n;
        tmp->next=top;
        return tmp;
    }
    else {
        top->next=Ordinan(top->next,n);
        return top;
    }
}

void Ordina(struct lista* head,int scelta) {
    struct lista* temp;
    int swap,r=1;
    
    if(scelta==0) {
        while(r==1) {
            r=0;
            for(temp=head;temp->next!=NULL;temp=temp->next) {
                if(temp->key >  (temp->next)->key) {
                    swap=temp->key;
                    temp->key=(temp->next)->key;
                    (temp->next)->key=swap;
                    r=1;
                }
            }
        }
        printf("\nLista Ordinata\n");
    }
    else if(scelta==1) {
        while(r==1) {
            r=0;
            for(temp=head;temp->next!=NULL;temp=temp->next) {
                if(temp->key < (temp->next)->key) {
                    swap=temp->key;
                    temp->key= (temp->next)->key;
                    (temp->next)->key=swap;
                    r=1;
                }
            }
            
        }
        printf("Lista Ordinata");
    }
    else
        printf("Errore");
    
    temp=NULL;      //libero temp
}

struct lista* Mezzo(struct lista* top,int n,int num) {
    
    /* struct lista* tmp = Creanodo(n);
     struct lista* point;
     tmp->key=n;                                                              //Iterativo
     for (point=top; point->next!=NULL&&num>1; point=point->next)
     num--;
     tmp->next=point->next;
     point->next=tmp;
     return top;*/
    
    
    struct lista *tmp;
    
    if (top==NULL||num==0) {
        tmp=malloc(sizeof(struct lista));
        tmp->key=n;
        tmp->next=top;
        return tmp;
    }
    else {
        top->next=Mezzo(top->next,n,num-1);    //e scalo di un nodo e scalo di un nodo
        return top;
    }
}

void DeallocaIterativa(struct lista * top) {
    struct lista *curr;
    for(curr=top;top!=NULL; top=top->next) {
        curr=top->next;
        top->next=NULL;
        free(top);
    }
}

struct lista* CancellaelemIterativa(struct lista* top, int k,bool* trovato) {
    struct lista* tmp = top;
    struct lista* curr = top;
    while(curr) {
        if(curr->key == k) {
            tmp->next = curr->next;
            if(top == curr)
                top = top->next;
            free(curr);
            curr = NULL;
        }
        if(curr)
            tmp = curr;
        curr = curr->next;
    }
    return top;
}

struct lista* Cancellaelem(struct lista* top, int k,bool* trovato) {    //Cancello un nodo Funzione importantee!!
    struct lista* tmp;
    if(top==NULL)
        return top;
    if(top->key==k) {
        tmp=top;
        top=Cancellaelem(top->next,k,trovato);
        free(tmp);
        *trovato=true;
    }
    else
        top->next=Cancellaelem(top->next,k,trovato);
    return top;
}


int main(int argc, const char * argv[]) {
    
    
    Logo();
    int n,scelta_ordine,k,num,scelta;
    float tmp;
    char c;
    bool trovato=false;
    Nodo top=NULL;
    
    do {
        scelta=Menu();
        switch(scelta) {
            case 0:
                printf("\nArrivederci\n");
            break;
            case 1:
                printf("\nInserisci n: ");
                n=inserisciIntero(&tmp);
                top = Testa(top,n);
                system("@cls||clear");
            break;
            case 2:
                printf("\nInserisci n: ");
                n=inserisciIntero(&tmp);
                top = Coda(top,n);
                system("@cls||clear");
            break;
            case 3:
                printf("\nTOP-> ");
                Stampa(top);
                printf("\nInserisci n: ");
                n=inserisciIntero(&tmp);
                printf("Dopo quanti elementi vuoi inserirlo?: ");
                num=inserisciInteroM0(&tmp);
                top=Mezzo(top,n,num);
                system("@cls||clear");
            break;
            case 4:
                printf("\nTOP-> ");
                Stampa(top);
                Pulisci();
            break;
            case 5:
                if(top==NULL)
                    printf("\nLista vuota.\n");
                else {
                    printf("\nTOP-> ");
                    Stampa(top);
                    printf("\nScrivi il numero che vuoi cercare : ");
                    n=inserisciIntero(&tmp);
            
                    if(Cerca(top,n))
                        printf("\n%d e' presente nella lista\n",n);
                    else
                        printf("\n%d non e' presente nella lista\n",n);
                }
                Pulisci();
            break;
            case 6:
                printf("\nTOP-> ");
                Stampa(top);
                printf("\nScrivi il numero che mettero' gia' in ordine: ");
                n=inserisciIntero(&tmp);
                top=Ordinan(top,n);
                printf("Numero inserito");
                printf("\nTOP-> ");
                Stampa(top);
                Pulisci();
            break;
            case 7:
                if(top==NULL)
                    printf("\nLista vuota.\n");
                else {
                    printf("\nTOP-> ");
                    Stampa(top);
                    printf("\nCrescente o decrescente? (0/1): ");
                    do {
                        scelta_ordine=inserisciIntero(&tmp);
                    } while((scelta_ordine<0 || scelta_ordine>1) && printf("Riprova: "));
                    Ordina(top,scelta_ordine);
                    printf("\nTOP-> ");
                    Stampa(top);
                }
                Pulisci();
            break;
            case 8:
                if(top==NULL)
                    printf("\nLista vuota.\n");
                else {
                    printf("\nTOP-> ");
                    Stampa(top);
                    printf("\nScrivi l'elemento che vuoi eliminare: ");
                    k=inserisciIntero(&tmp);
                    top=Cancellaelem(top,k,&trovato);
                    if(trovato)
                        printf("Numero eliminato");
                    else
                        printf("Numero non trovato");
                    printf("\nTOP-> ");
                    Stampa(top);
                    trovato=false;
                }
                Pulisci();
            break;
            case 9:
                if(top==NULL) {
                    printf("\nLista vuota.\n");
                    Pulisci();
                }
                else {
                    printf("\nSei sicuro di voler eliminare l'intera lista? (y/n): ");
                    do {
                        scanf(" %c",&c);
                    } while((c!='y' && c!='n') && printf("Riprova: "));
                    if(c=='y') {
                        Dealloca(top);
                        top=NULL;
                        printf("Lista deallocata");
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
    
    return 0;
}
