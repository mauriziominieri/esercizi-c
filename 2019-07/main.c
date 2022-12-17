//
//  main.c
//  AppelloLuglio2019
//
//  Created by Maurizio Minieri on 06/07/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//

/*
 char * concatena(char *, char *);
 void conta_conta_consonanti(char [ ], int *);
 Dati i 2 prototipi di funzione, sopra riportati, implementare le rispettive funzioni:
 1. char * concatena(char *input1, char *input2): la funzione, date 2 stringhe (che esistono già e sono composte solo da caratteri alfabetici minuscoli), puntate rispettivamente da *input1 e *input2, crea una nuova stringa in cui inserisce solo le consonanti delle 2 stringhe precedenti. La nuova stringa dovrà essere allocata dinamicamente ed avrà dimensione uguale al numero di consonanti presenti nelle 2 stringhe. Il numero di consonanti in ogni stringa sarà calcolato mediante la funzione conta_consonanti. La funzione, che dovrà utilizzare solo la notazione puntatore, restituisce il puntatore alla stringa di consonanti. ESEMPIO: input1= sdaeteruiop, input2= eiearteoiana, output=sdtrprtn
 2. void conta_consonanti(char vect [ ], int *num_cons): la funzione data una stringa determina il numero di consonanti e lo memorizza utilizzando la variabile puntatore num_cons.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Al posto di usare il classico PASSAGGIO PER VALORE la traccia ci impone di usare un PASSAGGIO PER INDIRIZZO della variabile num_cons, tale passaggio può essere molto utile dato che i cambiamenti fatti all'interno della funzione su tale variabile influiscono anche all'esterno. In realtà si può usare anche il PASSAGGIO PER RIFERIMENTO, la differenza è solamente sintattica, infatti al posto del simbolo * nel parametro si usa il simbolo &, e all'interno della funzione NON SERVE mettere ogni volta il simbolo * prima della variabile.


/* PASSAGGIO PER INDIRIZZO                         PASSAGGIO PER RIFERIMENTO
 int moltiplica(int* x, int* y);                   int moltiplica(int &x, int &y);
 main(){                                           main(){
    risultato = moltiplica(&a, &b);                   risultato = moltiplica(a, b);
 }                                                 }
 int moltiplica(int* x, int* y){                   int moltiplica(int &x, int &y){
     ris = *x * *y;                                   ris = x * y;
     return ris;                                      return ris;
 }                                                 }
 */

void conta_consonanti(char vect[], int *num_cons) {
	
	for(int i=0;i<strlen(vect);i++){
		//printf("%c\n",input1[i]);
		if(vect[i]!='a' && vect[i]!='e' && vect[i]!='i' && vect[i]!='o' && vect[i]!='u')
			(*num_cons)++;
	}
}

char* concatena(char *input1, char *input2){
	
	int num_cons=0,k=0;
	
	conta_consonanti(input1,&num_cons);  //se voglio che i cambiamenti fatti su un altra funzione valgano anche qui devo passare l'indirizzo di num_cons (&), se passassi semplicemente la variabile num_cons ogni cambiamento fuori questa funzione sarebbe ininfluente, passerei semplicemente 0, poi ripasserei 0, e nel printf avrei 0
	conta_consonanti(input2,&num_cons);
	//printf("consonanti totali = %d\n",num_cons);
	
	char *output = malloc(sizeof(char)*(num_cons));    //creo 8 celle contigue di memoria adatte a contenere 8 caratteri
	
	
	for(int i=0;i<strlen(input1);i++){
		if(input1[i]!='a' && input1[i]!='e' && input1[i]!='i' && input1[i]!='o' && input1[i]!='u'){
			output[k]=input1[i];
			
			k++;
		}
	}
	
	for(int j=0;j<strlen(input2);j++){
		if(input2[j]!='a' && input2[j]!='e' && input2[j]!='i' && input2[j]!='o' && input2[j]!='u'){
			output[k]=input2[j];
		
			k++;
	    }
	}
		
	output[k]='\0';   //aggiungiamo alla fine il carattere di terminazione stringa
	
	return output;
}



int main(int argc, const char * argv[]) {
	
	printf("output: %s\n\n",concatena("sdaeteruiop","eiearteoiana"));
	
	return 0;
}
