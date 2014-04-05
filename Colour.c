#ifndef Colour_c
#define Colour_c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.c"
#include "List.h"
#include "Colour.h"

colour *newColour(char *name, int rojo, int verde, int azul){
	colour *puntero;
	puntero = (colour*)malloc(sizeof(colour));	
	puntero -> nombre = (char *)malloc(sizeof(name));
	strcpy(puntero -> nombre,name);
	puntero -> red = rojo;
	puntero -> green = verde;
	puntero -> blue = azul;
	return puntero;
	}

int main(int argc, char** argv){
	return(255);}

#endif
