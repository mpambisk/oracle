#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include"oracle.h"
#include"hash.h"
#include "bloom.h"
#include <limits.h>



int main(int argc,char * argv[])	{

	if(argc!=5 && argc!=3)	{								//check if the number of arguments is correct
		printf("ERROR : wrong number of arguments \n");
		return 1;
		}
	long int size;
	int max_depth,number_h=3;

	if(argc==3)	{											//by default use hash_by 3 times
		size=atoi(argv[1]);
		max_depth=atoi(argv[2]);
		}

	if(argc==5)	{											//if true use set hash_by number_h times
		number_h=atoi(argv[2]);
		size=atoi(argv[3]);
		max_depth=atoi(argv[4]);
		}
	size=size*CHAR_BIT;										//convert number of bytes to bits

	printf("ba8os : %d\n",max_depth);		
	printf("size : %ld\n",size);
	const char **words;
	char * next_word;
	next_word=NULL;
	int flag=0,i=0,j=0;
	unsigned char ch;
	

	Tree * dentro;
	dentro=malloc(sizeof(Tree));
	tree_create(dentro);
	Tree_node * parent;
	Tree_node * temp;
	parent=NULL;
	temp=NULL;

	Bloom *filter;
	filter=malloc(sizeof(Bloom));
	bloom_size(filter,size);

	List *lista;
	lista = malloc(sizeof(List));
	list_create(lista);
	Node * temp2;

	initSeed(13);											//initialize oracle here

	uint64_t number;

	parent=tree_insert(dentro," ",parent,max_depth);		//insert the first word (tree root)
	temp=parent;											
	words=oracle(" ");										//ask oracle for the first time

	while(words!=NULL){										//while you have not found the word
		if(next_word!=NULL)	{								//free to allocate and use it again
			free(next_word);							
			next_word=NULL;
			}
		i=0;
		while((words[i])!=NULL){							//words that oracle returned
			ch=1;
			for(j=1;j<=number_h;j++)	{					
				number=hash_by(j,words[i]);					
				if(bloom_check(number,filter)==0){			//check the bloom filter 
					bloom_update(number,filter);			//if bloom_check==0 for at least one number
					ch=0;									//then add the word to the list
				}}											//and update the bloom_filter (mark with 1)
				if(ch==0){
					list_push(words[i],lista,parent);
				}
			
			i++;
		}
		parent->degree=i;									//parent has i children
		if(list_empty(lista)){
			printf("there is no hidden word \n");
			flag=1;
			break;
		}
			parent=list_getparent(lista);					//get the parent from the head of the list
			temp2=list_pop(lista);										//pop head of the list
			next_word=malloc((strlen(temp2->data)+1)*sizeof(char));		//temporary store the next word
			strcpy(next_word,temp2->data);								
			temp=tree_insert(dentro,next_word,parent,max_depth);		//next word sto dentro
			if(temp!=NULL)												
				parent=temp;
			dentro->depth=max_dep(parent->level,dentro->depth);			//tree depth
			words=oracle(next_word);									//ask the next word
			free(temp2->data);											//free the temporary variable
			free(temp2);
		
	}
	if(flag==0)													
		printf("the hidden word is :  %s \n",next_word);
	if(next_word!=NULL)
		free(next_word);
//	list_print(lista);												

	printf("ba8os : %d\n",dentro->depth);
	//tree_print(dentro->root);
	tree_delete(dentro->root);
	//tree_print(dentro->root);
																		//empty memory

	list_delete(lista);															
	free(dentro);
	free(lista);
	bloom_delete(filter);
	return 0;
}
	

