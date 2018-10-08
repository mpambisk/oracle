



typedef struct Bloom_filter	{
	unsigned char * bloom;
	long int size;
}Bloom;


void bloom_init(Bloom *,int );			//initialize with 0
void bloom_size(Bloom * ,long int) ;	//set size allocate memory
void bloom_update(uint64_t,Bloom *);	//mark with 1s
int bloom_check(uint64_t,Bloom *);		//check if a bit is 0/1(if 0 return 0)
void bloom_delete(Bloom *);				//free memory
