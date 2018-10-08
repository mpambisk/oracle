


typedef struct Tree_node	{
	char * data;
	int degree;
	int level;
	struct Tree_node * parent;
	struct Tree_node ** children;
	}Tree_node;

typedef struct Tree	{
	struct Tree_node * root;
	int depth;
	}Tree;


void tree_create(Tree *);										//creates an empty tree
Tree_node * tree_insert(Tree *,const char *, Tree_node *,int);		//insert a node
void tree_print(Tree_node *);										//print all the nodes of the tree
void tree_delete(Tree_node *);										//empty memory
int max(int,int);													//used to find depth
