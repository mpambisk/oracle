#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"



//tree functions

//creates an empty tree

void tree_create(Tree * dentro)	{
	dentro->root = NULL;
	dentro->depth = -1;
	printf("A tree has been created\n");
	}

//--------------------------------------------------------------

//insert nodes to the tree use kombos to find the parent of the new node
//returns the new node
//

Tree_node * tree_insert(Tree * dentro,const char * word, Tree_node * kombos,int max_depth)	{
	int length=strlen(word)+1;
	int i=0;
	if(kombos!=NULL)	{						//check the max depth
		if((kombos->level+1)>max_depth)	{
			return NULL;
		}
	}
	Tree_node * newnode;							//first allocate memory for the new node					
	newnode=malloc(sizeof(Tree_node));															
	newnode->data=malloc(length*sizeof(char));															
	strcpy(newnode->data,word);
	newnode->parent=kombos;	
	newnode->degree=0;
	newnode->children=NULL;

	if(dentro->root==NULL){							//empty
		dentro->root=newnode;
		dentro->depth=0;
		newnode->level=0;
		return newnode;
		}

	else	{																	//first child
		if(kombos->children==NULL)	{
			kombos->children=malloc(kombos->degree * sizeof(Tree_node *));								
			for(i=0;i<kombos->degree;i++)
				kombos->children[i]=NULL;
			kombos->children[0]=newnode;
			newnode->level=kombos->level+1;
			return newnode;
			}
		else	{
			i=0;
			while(kombos->children[i]!=NULL)
				i++;
			kombos->children[i]=newnode;
			newnode->level=kombos->level+1;
			return newnode;
			}
		}
	}

//--------------------------------------------------------------

//print all the words stored in the tree

void tree_print(Tree_node * node)	{
	int i,x;
	if(node!=NULL)	{
		x=node->degree;
		printf(" %s ",node->data);
		if(node->children!=NULL)	{
			for(i=0;i<x;i++){
				if(node->children[i]!=NULL)	{
					printf("  %s ",node->data);
					tree_print(node->children[i]);
				}
			}
		}
	}
}


//--------------------------------------------------------------

//free memory

void tree_delete(Tree_node * node)	{
	int i,x;
	x=node->degree;
	if(node->children!=NULL){
		for(i=0;i<x;i++){
			if(node->children[i]!=NULL)
				tree_delete(node->children[i]);
		}}
		if(node->children!=NULL)
			free(node->children);
		if(node->data!=NULL)
			free(node->data);
		if(node!=NULL)
			free(node);
	}

//--------------------------------------------------------------

//used to find depth

int max_dep(int lvl, int h)	{
	if(lvl>h)
		return lvl;
	return h;
}



	
		


