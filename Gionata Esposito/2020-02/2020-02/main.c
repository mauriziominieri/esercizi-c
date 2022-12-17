//
//  main.c
//  AppelloFebbraio2020
//
//  Created by Maurizio Minieri on 05/07/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//

/*
 Il codice di seguito riportato effettua l'ordinamento delle stringhe presenti nel vettore lista in base alla lunghezza utilizzando bubblesort (vedi le funzioni ordina, scorri e swap). Successivamente stampa la sequenza ordinata (vedi funzione stampaLista), memorizza la stringa più lunga con la relativa dimensione in un record di tipo MaxString (vedi funzione memStr) e lo stampa in un File il cui nome viene inserito da linea di comando (vedi funzione stampaFile).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define MAX 5
typedef struct{
	char* data;        //Stringa
	int dim;        //intero
}MaxString;

/* prototipi di funzioni */
void ordina(char **lista);
int scorri(char **lista);
void swap(char **lista, int i);
void stampaLista(char **lista);
void memStr(MaxString *info, char *ptr);
void stampaFile(MaxString info, FILE *output);



int scorri(char **lista){
	
	return MAX;  //restituisce la dimensione della lista(?)
}

void swap(char **lista, int i){
	
 //puntatore, immaginatelo come un quadrato che conterrà un indirizzio e esso stessa ha un indirizzo (via Verdi)
	char* temp;
	
	temp = *lista;             //ora temp contiene l'indirizzo di lista[i], cioè via Bianchi
	*lista = lista[i];         //via Bianchi ora punta all'indirizzo di lista[j] via Rosa
	lista[i] = temp;          //via Rosa ora contiene via Bianchi
}

void ordina(char** lista){
	
	int dim=scorri(lista);
	
	for(int i=0;i<dim-1;i++){
		for(int j=i+1;j<dim;j++){
			
			//printf("%s con %s\n",lista[i],lista[j]);
			if(strlen(lista[i]) > strlen(lista[j])){
				swap(&lista[i],j);   //passo l'indirizzo della cella lista[i] (Via Bianchi) e j, un intero
			}
		}
	}
}

void stampaLista(char** lista){
	
	for(int i=0; i<MAX; i++){
		printf("%s -> ",lista[i]);
	}
	
	printf("NULL\n");
}

//riempire l'elemento info
void memStr(MaxString *info, char *ptr){
	
	info->dim = strlen(ptr);
	info->data = ptr;
	
	//printf("info->data: %s\n",info->data);
	//printf("info->dim: %d\n",info->dim);
}


void stampaFile(MaxString info, FILE *output){
	//printf("info->data: %s\n",info.data);
	//printf("info->dim: %d\n",info.dim);
	
	/*
	char* nome;
	printf("Inserisci nome del file: ");
	scanf("%s",nome);
	char path[100] = "/Users/mauriziominieri/Projects/AppelloFebbraio2020/";
	strcat(path,nome);  //UNIONE DI SUE STRINGHE
	output = fopen(path,"w");
	 */
	
	fprintf(output,"info: %s %d",info.data,info.dim);
	printf("info inserito nel file con successo!\n\n");
	fclose(output);
}

int main(int argc, const char * argv[]) {
	
	char* lista[MAX]={"xxx","yy","ab","melabella","n"};  //array di stringhe
	char* max;                  //stringa
	FILE *output;               //puntatore a file
	MaxString info;             //info.data che è una stringa, info.dim che è un intero
	
	output = fopen("/Users/mauriziominieri/Progetti/Linguaggio-C/Studente-Gionata/2020-02/output.txt", "w"); //per semplicità uso un nome senza terminale

	printf("stampa prima\n");
	stampaLista(lista);
	ordina(lista);               //Punti18: Scorri+Swap
	printf("stampa dopo\n");
	stampaLista(lista);          //Punti1*/
	
	
	max=lista[4];                    //max="bxyz"  la stringa più lunga
	memStr(&info, max);            //Punti9
	stampaFile(info, output);     //Punti2
	
	
	
	return 0;
}
