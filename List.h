#ifndef List_h
#define List_h

#include <stdlib.h>
#include "Colour.c"
#include "Colour.h"

typedef struct lnode{
	struct lnode *prev;
	struct lnode *next;
	colour *data;
	struct lnode (*newNode)();
	} listNode;
	
typedef struct dlinklist{
	listNode *first;
	listNode *last;
	listNode *curr;
	int size;
	struct dlinklist (*newList)();
	void (*append)();
	} linkedList;

listNode *newNode(colour *datos);
	
linkedList *newList();

void append(linkedList *lista, colour *datos);
	
void delete(linkedList *lista, char *color);
				 
void next(linkedList *lista);

void moveToStart(linkedList *lista);

colour *datoActual(linkedList *lista);

int finalLista(linkedList *lista);

#endif
