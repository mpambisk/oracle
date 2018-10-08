#include "oracle.h"
#include "hash.h"
#include "bloom.h"
#include <stdio.h>
#include <stdlib.h>

//			bloom filter functions :



//initialize with 0

void bloom_init(Bloom * bl, int byte)	{
	int i=0;
	for(i=0;i<byte;i++)
		bl->bloom[i]=0;
}

//--------------------------------------------------------------


//set size allocate memory


void bloom_size( Bloom * bl,long int size)	{
	int byte;	
	if(size%8==0)
		byte=size/8;
	else
		byte=size/8+1;
	bl->bloom=malloc(byte*sizeof(unsigned char));
	bl->size=size;
	bloom_init(bl,byte);
	printf("A bloom filter has been created \n");
}

//--------------------------------------------------------------

//update the bloom filter
//0->1 at the proper position

void bloom_update(uint64_t hresult,Bloom * bl )	{
	int byte_pos,bit_pos;
	long int x;
	unsigned char temp;
	x=hresult%bl->size;
	byte_pos=x/8;
	bit_pos=x%8;
	bit_pos=7-bit_pos;
	temp=1;
	temp=temp<<bit_pos;
	bl->bloom[byte_pos]=bl->bloom[byte_pos]|temp;
	//printf("bloom update to bl->bloom einai : %u\n",bl->bloom[byte_pos]);

	}

//--------------------------------------------------------------

//check if a bit is 0 or 1

int bloom_check(uint64_t hresult ,Bloom * bl){
	int byte_pos,bit_pos;
	long int x;
	unsigned char temp,temp2;
	x=hresult%bl->size;
	byte_pos=x/8;
	bit_pos=x%8;
	bit_pos=7-bit_pos;
	temp=1;
	temp=temp<<bit_pos;
	temp2=temp&bl->bloom[byte_pos];
	if(temp2!=0)
		return 1;
	return 0;

}


//--------------------------------------------------------------

//empty memory

void bloom_delete(Bloom * bl){
	free(bl->bloom);
	free(bl);
	bl=NULL;
	printf("Bloom filter deleted \n");
	}























	
