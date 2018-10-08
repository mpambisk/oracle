#include "tree.h"

typedef struct Node	{
	char * data;
	Tree_node * parent;
	struct Node * prev;
	struct Node * next;
}Node;

typedef struct List	{
	Node * head;
}List;


//functions

void list_create(List *);						//creates an empty list
int list_empty(List *);							//check if the list is empty(if empty return 1)
void list_push(const char*, List *,Tree_node *);	//add a node at the end of the list
void list_print(List *);							//prints the list
Node * list_pop(List *);							//return the head node
Tree_node * list_getparent(List *);					//return parent of a node
void list_delete();									//empty memory

