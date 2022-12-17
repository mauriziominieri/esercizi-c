//
//  main.c
//  AppelloGennaio2020
//
//  Created by Maurizio Minieri on 05/07/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//


/*
 #include <stdio.h>
 #include <string.h>
 #define MAX 5
 
char * cerca_pal(char *[], FILE *);
int pal(char *);
int scrivi_file(FILE *, char *);
int main(int argc, char *argv[])
{
	FILE *output, *input;
	input=fopen(argv[1],"r");
	output=fopen(argv[2],"w");
	char *data[MAX]={"nvcfvfdv", "vfvfhvvs","xxppxx","uutryvsdg","nvjfiep"}, *ptr_pal;
	ptr_pal=cerca_pal(data, input);
	if (ptr_pal)
		scrivi_file(output,ptr_pal);
}
A partire dal codice di cui sopra implementare le seguenti funzioni (i nomi dei file sono passati da linea di comando):
1. char *cerca_pal (char *data[]), FILE *): determina se la stringa (unica) presente nel File input è
contenuta nell’array di puntatori a carattere e ne restituisce l’indirizzo solo se è palindroma (eventualmente
																																 NULL se la stringa non esiste o non è palindroma). Utilizzare la notazione puntatore (Punti 18)
2. int pal (char *): ricevuto l’indirizzo della stringa, verifica se è palindroma: restituisce 1 (la stringa esiste)
o 0 (la stringa non esiste). Utilizzare la notazione puntatore e vettore (Punti 7)
3. void scrivi_file(FILE *, char *): la funzione scrive nel file, il cui nome è immesso sulla linea di comando
 (vedi void main(int argc, char *argv[])), la stringa palindroma ed il suo indirizzo. (Punti 5)
 */

#include <stdio.h>
#include <string.h>
#define MAX 5

char *cerca_pal (char *data[], FILE* fp){
	
	char* buff=NULL;
	long fsize;
	
	
	printf("Leggo dal file.txt scritto come primo argomento da terminale\n");
	
	if(fp != NULL){
		
		//prendo la dimensione del file
		fseek(fp,0,SEEK_END);
		fsize = ftell(fp);
		rewind(fp); //torno all'inizio
		
		
		char* file_content = (char*)malloc(fsize);
		fgets(file_content,fsize+1,fp);
		//puts(file_content);   //uguale a printf("%s\n",file_content);
		
		
		//vedo se la parola nel file è contenuta nell'array data
		for(int i=0;i<MAX;i++){
			if(strcmp(data[i], file_content)==0)
			{
				   //printf("%s trovata\n", data[i]);
				   //se la trovo verifico sia palindroma
					if(pal(data[i])==1)
					   buff=file_content;
			}
		}
			
			
	}
	else{
		printf("File not found\n");
	}
	
	fclose(fp);
	
	return buff;
}

int pal (char* str){

	int l = 0;
	int h = strlen(str) - 1;
	
	while (h > l)
	{
		if (str[l++] != str[h--])
		{
			//printf("%s non palindroma\n", str);
			return 0;
		}
	}
	
	//printf("%s palindroma\n", str);
	return 1;
}

void scrivi_file(FILE* fp, char* x){
	
	printf("Scrivo nel file.txt scritto come secondo argomento da terminale\n");
	
	fprintf (fp, "stringa: %s\nindirizzo: %p",x,&x);
	
	fclose (fp);
}

//per avviarlo con gli argv devi usare il terminale, entra con cd nella cartella del progetto fino ad arrivare al main.c, a questo punto inserisci il comando gcc -o main.exe main.c, per compilare, e ./main.exe per runnare. In questo caso abbiamo argomenti quindi: ./main.exe arg1 arg2
int main(int argc, const char * argv[]) {
	
	FILE *output, *input;
	input=fopen(argv[1],"r");
	output=fopen(argv[2],"w");
	
	char *data[MAX]={"nvcfvfdv", "vfvfhvvs","xxppxx","uutryvsdg","nvjfiep"}, *ptr_pal;
	
	ptr_pal=cerca_pal(data, input);
	
	if (ptr_pal)
		scrivi_file(output,ptr_pal);
	
	return 0;
}
