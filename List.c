#ifndef List_c
#define List_c

#include "List.h"
#include <stdlib.h>
#include <string.h>

listNode *newNode(colour *datos){
	listNode *puntero;
	puntero = (listNode*)malloc(sizeof(listNode));
	puntero -> prev = NULL;
	puntero -> next = NULL;
	puntero -> data = datos;
	return puntero;
	}
	
linkedList *newList(){
	linkedList *puntero;
	puntero = (linkedList*)malloc(sizeof(linkedList));
	puntero -> last = NULL;
	puntero -> size = 0;
	puntero -> first = NULL;
	puntero -> curr = puntero -> first;
	return puntero;
	}

void append(linkedList *lista, colour *datos){
	listNode *puntero;
	if(lista->size==0){
		puntero = newNode(datos);
		lista -> last = puntero;
		lista -> first = puntero;
		lista -> curr = puntero;
		lista -> size++;
		return;
		}
	puntero = newNode(datos);
	lista -> last -> next = puntero;
	puntero -> prev = lista -> last;
	lista -> last = puntero;
	lista -> size++;
	return;
	}
	
void delete(linkedList *lista, char *color){
	int i;
	if(lista->size==0){return;}
	if(lista->size==1){
		free(lista->first);
		lista->first=lista->last=lista->curr=NULL;
		return;
		}
	lista -> curr = lista -> first;
	for (i = 0; i < (lista -> size); i++){
		if (strcmp(lista -> curr -> data -> nombre, color) == 0){ 
			if (lista -> curr == lista -> first){ 
				lista -> first = lista -> first -> next;
				lista -> first -> prev = NULL;
				free(lista -> curr);
				lista -> curr = lista -> first;
				lista -> size--;
				break;
				}
			else if (lista -> curr == lista -> last){
				lista -> last = lista -> last -> prev;
				lista -> last -> next = NULL;
				free(lista -> curr);
				lista -> curr = lista -> last;
				lista -> size--;
				break;
				}
			else{
				listNode *aux = lista -> curr -> next;
				lista -> curr -> prev -> next = lista -> curr -> next;
				lista -> curr -> next -> prev = lista -> curr -> prev;
				free(lista -> curr);
				lista -> curr = aux;
				lista -> size--;
				break;}}}return;} //this line is art
				 
void next(linkedList *lista){
	if(lista->curr==lista->last){return;}
	lista->curr=lista->curr->next;
	}
void moveToStart(linkedList *lista){
	lista->curr=lista->first;
	}

colour *datoActual(linkedList *lista){
	return lista->curr->data;
	}
int finalLista(linkedList *lista){
	if(lista->curr==lista->last){return 1;}
	else{return 0;}}	
	
#endif
