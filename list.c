#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//list functions

//create an empty list

void list_create(List * lista){
	lista->head=NULL;
	printf("a list has been created \n");
	}

//--------------------------------------------------------------

//check if a list is empty

int list_empty(List * lista){
	if(lista->head==NULL)
		return 1;
	return 0;
	}

//--------------------------------------------------------------

//push a new node with node->data=word at the end of the list

void list_push(const char* word, List * lista,Tree_node * pateras)	{
	int length = strlen(word)+1;
	Node * kombos;
	kombos = malloc (sizeof(Node));
	kombos->data=malloc((length)*sizeof(char));
	strcpy(kombos->data,word);
	kombos->parent=pateras;
	if(lista->head==NULL)	{
		kombos->next=NULL;
		kombos->prev=NULL;
		lista->head=kombos;
	}
	else	{
		Node * temp = lista->head;
		while(temp!=NULL){
			if(temp->next==NULL)
				break;
			temp = temp->next;
		}
		kombos->next = NULL;
		kombos->prev = temp;
		temp->next=kombos;
		
	}
	
}


//--------------------------------------------------------------

//print list

void list_print(List * lista )	{
	Node * temp=lista->head;
	while(temp!=NULL){
		printf("  %s",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

//--------------------------------------------------------------

//return the head of the list

Node * list_pop(List * lista)	{
	if(list_empty(lista))
		printf("pop: error: list is empty \n");
	else	{
	Node * temp = lista->head;
	lista->head=temp->next;
	return temp;
	}
}

Tree_node * list_getparent(List * lista)	{
	Node * temp;
	temp=lista->head;
	return temp->parent;
}


//--------------------------------------------------------------

//empty memory
	
void list_delete(List * lista)	{
	Node * temp;
	while(!(list_empty(lista))){
		temp=list_pop(lista);
		free(temp->data);
		free(temp);
	}
	printf("list has been deleted \n");
}







	

	

