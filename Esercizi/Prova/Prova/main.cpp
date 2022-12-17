//
//  main.cpp
//  Prova
//
//  Created by Maurizio Minieri on 21/01/21.
//

/*
 1) Data la struttura esame(nome,voto), si crei una funzione che preso il nome di un esame ne stampi il relativo voto
 2) Data la struttura esame(nome,voto), si crei una funzione che preso il voto stampi tutti gli esami con quel voto
 3) Data la struttura persona(nome,cognome,anni), si crei una procedura che stampi tutti i maggiorenni
 4) Data la struttura persona(nome,cognome,anni), si crei una procedura che restituisca la persona (l'oggetto persona, non solo il nome) più giovane
 5) Data la struttura libro(titolo,autore) e la struttura autore (cognome,sesso(m o f),anni), si crei una procedura che stampi tutti i libri di autrici (sesso f)
 6) Data la struttura libro(titolo,autore,prezzo) e la struttura autore (cognome,sesso(m o f),anni), si crei una funzione che restituisca il titolo del libro più costoso di un autore (sesso m)
 7) Data la struttura libro, in cui ogni libro ha un codice numerico (numero intero) che lo caratterizza, un numero di pagine e un costo. Si memorizzino i dati di tre libri e si calcoli il costo medio per pagina dei libri e si stampino i dati dei tre libri in ordine crescente di costo per pagina.
 */

#include <iostream>
#include <string.h>

using namespace std;

/*
typedef struct {
    char nome[32];
    int voto;
} Esame;

//1)
int f1(Esame esami[],char nome[]) {
    for(int i=0;i<3;i++)
        if(strcmp(esami[i].nome,nome)==0)
           return esami[i].voto;
    return -1;
}

//2)
void f2(Esame esami[],int voto) {
    for(int i=0;i<3;i++)
        if(esami[i].voto == voto)
           cout << esami[i].nome << endl;
}
*/
/*
typedef struct {
    char nome[32];
    char cognome[32];
    int anni;
} Persona;


void f3(Persona persone[],int n) {
    for(int i=0;i<n;i++)
        if(persone[i].anni > 17)
            cout << persone[i].nome << " " <<  persone[i].cognome << endl;
}

Persona f4(Persona persone[],int n) {
    Persona minPersona;
    minPersona.anni = INT_MAX;
    for(int i=0;i<n;i++)
        if(persone[i].anni < minPersona.anni)
            minPersona = persone[i];
    return minPersona;
}*/
/*
typedef struct {
    char cognome[32];
    char sesso;
    int anni;
} Autore;

typedef struct {
    char titolo[32];
    Autore autore;
    float prezzo;
} Libro;*/

typedef struct {
    int codice;
    int pagine;
    float costo;
} Libro;

/*
void f5(Libro libri[],int n) {
    for(int i=0;i<n;i++)
        if(libri[i].autore.sesso == 'f')
            cout << libri[i].titolo << endl;
}

string f6(Libro libri[],int n) {
    string libroCostoso;
    int max = 0;
    for(int i=0;i<n;i++)
        if(libri[i].autore.sesso == 'm' && libri[i].prezzo > max) {
            max = libri[i].prezzo;
            libroCostoso = libri[i].titolo;
        }
    return libroCostoso;
}*/

void f7(Libro libri[],int n) {  //medie = 1 0.6 0.4 ,indiceMax = 0 indicieMin = 1 medio = 0
    
    float max = 0.0,min = INT_MAX;
    float medie[3];
    int indiceMax = -1,indiceMin = -1, indiceMedio = -1;
    medie[0] = libri[0].costo / libri[0].pagine;
    medie[1] = libri[1].costo / libri[1].pagine;
    medie[2] = libri[2].costo / libri[2].pagine;
    
    for(int i=0;i<3;i++) {
        if(medie[i] > max) {
            max = medie[i];
            indiceMax = i;
        }
        if(medie[i]<min) {
            min = medie[i];
            indiceMin = i;
        }
    }
    
    if((indiceMin == 0 && indiceMax == 1) || (indiceMin == 1 && indiceMax == 0))
        indiceMedio = 2;
    else if((indiceMin == 0 && indiceMax == 2) || (indiceMin == 2 && indiceMax == 0))
        indiceMedio = 1;
    else if((indiceMin == 1 && indiceMax == 2) || (indiceMin == 2 && indiceMax == 1))
        indiceMedio = 0;
    
    cout << "Libro meno costoso per pagina: " << libri[indiceMin].codice << endl;
    cout << "Libro medio: " << libri[indiceMedio].codice << endl;
    cout << "Libro più costoso per pagina: " << libri[indiceMax].codice;
}

int main(int argc, const char * argv[]) {
   
    /*Esame esami[3] = {{"Storia",20},{"Informatica",20},{"Matematica",22}};
    //1)
    char nome[32];
    cout << "Inserisci il nome di un esame: ";
    cin >> nome;
    cout << f(esami,nome);

    int voto;
    cout << "Inserisci il voto di un esame: ";
    do {
        cin >> voto;
    } while((voto<0 || voto>30) && cout << "Riprova: ");
    f2(esami,voto);*/
    
    /*Persona persone[3] = {{"Maurizio","Minieri",24},{"Luigi","Minieri",70},{"Domenico","Simoni",35}};
    //f3(persone,3);
    Persona p = f4(persone,3);
    cout << "La persona più giovane è: " << p.nome << " " << p.cognome;
    */
    //Autore autori[3] = {{"Minieri",'m',25},{"Silvia",'f',50},{"Cinzia",'f',35}};
    //Libro libri[3] = {{"Magico",autori[0],34},{"Bello",autori[1],66},{"Brutto",autori[2],23}};
    //f5(libri,3);
    //cout << f6(libri,3);
    
    Libro libri[3] = {{1,50,50},{2,100,50},{3,20,40}};   //1 euro per pagina, 0.50 euro per pagina, 2 euro per pagina
    f7(libri,3);
    
    cout << "\n\n";
    return 0;
}
