#ifndef Colour_h
#define Colour_h

#include <stdlib.h>
#include <string.h>

typedef struct strColour{
	char* nombre;
	int red;
	int green;
	int blue;
	struct strColour (*newColour)();
	} colour;

colour *newColour(char *name, int rojo, int verde, int azul);

#endif
