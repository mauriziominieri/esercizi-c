//
//  main.c
//  ABR
//
//  Created by Maurizio Minieri on 12/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define limit_rand 10

typedef struct nodo {
     int key;
     struct nodo* sx;
     struct nodo* dx;
} *Tree;

Tree initNode(int k) {
    Tree T = malloc(sizeof(struct nodo));
    T->key = k;
    T->sx = NULL;
    T->dx = NULL;
    return T;
}

int empty(Tree T) {
    return T ? 0 : 1;
}
     
//Per avere il puntatore al figlio sinistro (destro) di un nodo:
Tree sinistro(Tree rad) {
    return !empty(rad) ? rad->sx : NULL;
}

void preOrder(Tree T) {
    if(T) {
        printf("%d ", T->key);
        preOrder(T->sx);
        preOrder(T->dx);
    }
}

int ricercaIterativa(Tree T, int k) {
    if(empty(T))
        return 0; // Non Trovato poiché l’albero è vuoto
    while(T) {
        if(T->key == k)
            return 1; // Trovato
        else if(T->key > k)
            T = T->sx;
        else
            T = T->dx;
    }
    return 0;
}

int ricercaRicorsiva(Tree T, int k) {
    int r = 0;
    if(empty(T))
        return 0;
    if(T->key == k)
        return 1;
    else if(T->key > k)
        r = ricercaRicorsiva(T->sx,k);
    else
        r = ricercaRicorsiva(T->dx,k);
    return r;
}

Tree inserisci(Tree T, int e) {
    Tree aux;
    if(T==NULL) {
        aux=malloc(sizeof(struct nodo));
        if(aux) {
            aux->key=e;
            aux->sx=aux->dx=NULL;
            return aux;
        }
        else
            printf("Memoria non allocata");
    }
    else if(e<T->key)
        T->sx = inserisci(T->sx,e);
    else if(e>T->key)
        T->dx = inserisci(T->dx,e);
    // altrimenti il valore è già nell’albero e non si fa niente
    return T;
}

Tree freeTree(Tree T) {
    if(T) {
        T->sx = freeTree(T->sx);
        T->dx = freeTree(T->dx);
        free(T);
        T = NULL;
    }
    return T;
}

Tree minValueNode(Tree node) {
    Tree curr = node;
    // loop down to find the leftmost leaf
    while (curr && curr->sx != NULL)
        curr = curr->sx;
 
    return curr;
}

Tree insertNode_SenzaDoppioni(Tree T,int key) {

    if (T == NULL)
        T = initNode(key);
    else {
         if (T->key > key)
            T->sx = insertNode_SenzaDoppioni(T->sx,key);
         else if (T->key < key)
              T->dx = insertNode_SenzaDoppioni(T->dx,key);
         else   //doppione
             insertNode_SenzaDoppioni(T,rand()%(limit_rand+1));
    }
    return T;
}

Tree RandomTree(int num_nodi) {
    int i = 0;
    Tree T = NULL;
    for (i=0;i<num_nodi;i++)
        T = insertNode_SenzaDoppioni(T,rand()%(limit_rand+1));
    return T;
}

int max(int a, int b) {
    return (a>b) ? a : b;
}

int height(Tree T) {
     if(T == NULL)
        return -1;
     return 1+max(height(T->sx),height(T->dx));
}

void StampaGrafica(Tree T) {
    if (T == NULL)
        return;

    printf("%d ",T->key);

    if(T->sx != NULL)
        printf("(L:%d)",T->sx->key);
    if(T->dx != NULL)
        printf("(R:%d)",T->dx->key);
    printf("\n");

    StampaGrafica(T->sx);
    StampaGrafica(T->dx);
}

Tree Cancella(Tree T) {
    if(T) {
        if (T->sx == NULL) {
            Tree tmp = T->dx;
            free(T);
            return tmp;
        }
        else if (T->dx == NULL) {
            Tree tmp = T->sx;
            free(T);
            return tmp;
        }
        Tree tmp = minValueNode(T->dx);
        T->key = tmp->key;
        T->dx = Cancella(T->dx);
    }
    return T;
}

Tree deleteNode(Tree T, int k) {
    if (T == NULL)
        return T;
    if (k < T->key)
        T->sx = deleteNode(T->sx, k);
    else if (k > T->key)
        T->dx = deleteNode(T->dx, k);
    else
        T = Cancella(T);
    return T;
}

//Cancello tutti i nodi minori di k (versione efficiente)
Tree deleteNodeMin(Tree T, int k) {
    if(T) {
        if(T->key >= k)
            T->sx = deleteNodeMin(T->sx, k);
        else {
            //printf("Cancello: %d\n",T->key);
            T->sx = deleteNodeMin(T->sx, k);
            T->dx = deleteNodeMin(T->dx, k);
            T = Cancella(T);
        }
    }
    return T;
}


//Cancello tutti i nodi tra altezza h1 e h2
Tree deleteNodeH(Tree T, int h1, int h2) {
    if(T) {
        T->sx = deleteNodeH(T->sx, h1-1, h2-1);
        T->dx = deleteNodeH(T->dx, h1-1, h2-1);
        if(h1 <= 0 && h2 >= 0)
            T = Cancella(T);
    }
    return T;
}


//Cancella la radice dei sottoalberi che hanno un numero di nodi compreso tra n1 e n2
int deleteSubtree(Tree P,Tree T,int n1,int n2) {
    int n_nodi = 0;
    if(T) {
        n_nodi = deleteSubtree(T, T->sx, n1, n2);
        n_nodi += deleteSubtree(T, T->dx, n1, n2);
        //StampaGrafica(T);
        printf("T->key: %d, ",T->key);
        printf("n_nodi: %d\n",n_nodi);
        if(n_nodi>=n1 && n_nodi<=n2) {
            if(P->sx == T) {
                printf("Cancello %d e riempio P->sx\n",T->key);
                P->sx = Cancella(T);
            }
            else {
                printf("Cancello %d e riempio P->dx\n",T->key);
                P->dx = Cancella(T);
            }
        }
        return n_nodi+1;
    }
    return 0;
}

/*
 Scrivere un algoritmo ri-corsivo efficiente che restituisca una listaLordinata in ordine crescente, contenente tutti i nodi di T le cui chiavi siano pari e contenute nell’intervallo di interi[k1, k2], doveT,k1,k2 sono tutti e soli i parametri di input dell’algoritmo.Non`e ammesso l’uso di passaggio di parametri per riferimento n ́e l’impiego di varia
*/
Tree Es1(Tree T, int k1, int k2) {
    if(T) {
        if(T->key >= k2)
            T->sx = Es1(T->sx, k1,k2);
        else {
            T->sx = Es1(T->sx, k1,k2);
            T->dx = Es1(T->dx, k1,k2);
            if(!(T->key % 2) && T->key >= k1)
                printf("Inserisco in ordine: %d\n",T->key);
                //L = inOrdine(L,T->key);
        }
    }
    return T;
}

/*
 ricorsivo, dati 5 valori h1,h2 >= 1, n1,n2 >= 0 e k cancelli dall'albero T tutti i nodi che rispettano la proprietà:
 1) chiave pari < k
 2) la sua distanza dalla radice è compresa tra h1 e h2
 3) radice di un sottoalbero i cui nodi con chiave < k sono in numero compreso tra n1 e n2
 */
int Es2(Tree P, Tree T, int k, int h1, int h2, int n1, int n2) {
    int n_nodi = 0;
    if(T) {
        if(T->key >= k)
            n_nodi = Es2(T, T->sx, k, h1-1, h2-1, n1, n2);
        else {
            n_nodi = Es2(T, T->sx, k, h1-1, h2-1, n1, n2);
            n_nodi += Es2(T, T->dx, k, h1-1, h2-1, n1, n2);
            //avrò il sottoalbero
            //printf("T: %d, n_nodi: %d\n",T->key,n_nodi);
            if(T->key % 2 == 0 && h1 <= 0 && h2 >= 0 && n_nodi >= n1 && n_nodi <= n2) {
                if(P->sx == T) {
                    printf("Cancello %d e riempio P->sx\n",T->key);
                    P->sx = Cancella(T);
                }
                else {
                    printf("Cancello %d e riempio P->dx\n",T->key);
                    P->dx = Cancella(T);
                }
            }
        }
        return n_nodi + 1;
    }
    return 0;
}

/*
 Tre interi: h>=0, k1 e k2 (k1 <= k2). Cancella i nodi che soddisfano le seguenti condizioni:
 1) chiave compresa tra k1 e k2
 2) il sottoalbero in essi radicato contiene almeno un nodo con chiave compresa nell'intervallo k1 e k2 che sta a profondità >= h
 */
int Es3(Tree P, Tree T, int k1, int k2, int h) {
    int s = 0;
    if(T) {
        if(T->key > k2)
            s = Es3(T,T->sx,k1,k2,h-1);
        else if(T->key < k1)            //con questi due if visito SOLO i nodi compresi tra k1 e k2
            s += Es3(T,T->dx,k1,k2,h-1);
        else {
            s = Es3(T,T->sx,k1,k2,h-1);
            s += Es3(T,T->dx,k1,k2,h-1);
            printf("Visito: %d.\n",T->key);
            //printf("Profondità: %d\n",h);
            printf("n_nodi: %d\n",s);
            if(T->key >= k1 && h<=0) {
                if(P->sx == T) {
                    printf("Cancello %d e ricollego a P->sx\n",T->key);
                    P->sx = Cancella(T);
                }
                else {
                    printf("Cancello %d e ricollego a P->dx\n",T->key);
                    P->dx = Cancella(T);
                }
            }
        }
        return s + 1;
    }
    return 0;
}


int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    Tree T = NULL;
    //T = RandomTree(7);
    //printf("Stampa Preorder \n");
    //preOrder(T);
    T = inserisci(T, 5);
    T = inserisci(T, 2);
    T = inserisci(T, 1);
    T = inserisci(T, 0);
    T = inserisci(T, 3);
    T = inserisci(T, 7);
    T = inserisci(T, 6);
    T = inserisci(T, 8);
    
    
    StampaGrafica(T);
    //T = deleteNodeMin(T,6);
    //T = deleteNodeH(T,1,2); //voglio cancellre tutti i nodi di altezza compresa (1 , 2)
    //deleteSubtree(T, T, 1, 2);
    //Es1(T,0,5);
    //Es2(T,T,99,0,3,0,3);
    Es3(T,T,0,99,2);
    printf("\n\n");
    StampaGrafica(T);
    
    printf("\n\n");
    return 0;
}
