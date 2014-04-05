#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "List.c"

int main(int argc, char **argv)
{
	printf("holiwiiu %d %s jorgito\n", argc, argv[1]);
	
	FILE *colourInput;
	colourInput = fopen("colours.txt", "r");
	char *nombre=(char *)malloc(sizeof(char)*30);
	int rojo;
	int verde;
	int azul;
	linkedList *wachalomo=newList();
	while (fscanf(colourInput,"%s\n", nombre) == 1){
		fscanf(colourInput,"%d\n%d\n%d\n\n", &rojo, &verde, &azul);}
		colour *cloro=newColour(nombre,rojo,verde,azul);
		append(wachalomo,cloro);
	fclose(colourInput);
	if(argc==6 && strcmp(argv[1],"-i")==0){
		colour *insertion=newColour(argv[2],atoi(argv[3]),atoi(argv[4]),atoi(argv[5]));
		append(wachalomo,insertion);
		moveToStart(wachalomo);
		FILE *colourOutput=fopen("coloursaux.txt","w");
		while(!finalLista(wachalomo)){
			cloro=datoActual(wachalomo);
			fprintf(colourOutput,"%s\n%d\n%d\n%d\n\n",cloro->nombre,cloro->red,cloro->green,cloro->blue);
			next(wachalomo);}
		fclose(colourOutput);
		rename("coloursaux.txt","colours.txt");
		}
	
	else if(argc==3 && strcmp(argv[1],"-d")==0){
		delete(wachalomo,argv[2]);
		moveToStart(wachalomo);
		FILE *colourOutput=fopen("coloursaux.txt","w");
		while(!finalLista(wachalomo)){
			cloro=datoActual(wachalomo);
			fprintf(colourOutput,"%s\n%d\n%d\n%d\n\n",cloro->nombre,cloro->red,cloro->green,cloro->blue);
			next(wachalomo);
			}
		fclose(colourOutput);
		rename("coloursaux.txt","colours.txt");
		}
	else if(argc==2 &&(strcmp(argv[1],"grid")==0 || strcmp(argv[1],"list")==0)){
		//grid
		}
	
		
		
		
		
		
		
	
	
	
		
	
	return 0;
}

