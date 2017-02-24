#include<stdio.h>
#include<stdlib.h>

#define Len_Btree sizeof(btnode)
#define ERROR 0

struct b_tnode{
int num;
int count;
struct b_tnode *left;
struct b_tnode *right;
};

typedef struct b_tnode btnode;
typedef struct b_tnode *binary_tree;     //二叉树类型定义


struct lnode{
binary_tree num;
struct lnode *next;
};

typedef struct lnode linknode;
typedef struct lnode *linklist;

struct node{
linklist top;
};

typedef struct node *link;


extern linklist ptr_stack;		


extern binary_tree btree_crt(binary_tree, int);
extern int stack_int(linklist);
//extern int getop(linklist, void *);
extern binary_tree getop(linklist);
extern int push(linklist, binary_tree);
extern void *pop(linklist);

/*int BinaryTree_Init(binary_tree ptr)
{
	if(ptr = (binary_tree)malloc(Len_Btree))
	{
		ptr->left = NULL;
		ptr->right = NULL;
	}
	else
	{
		return ERROR;            /////////////////?????????????
	}

	
}         */

void Inorder_Traverse(linklist ptr_stack, binary_tree ptr_btree)
{
	linklist ptr_sh = ptr_stack;
	binary_tree ptr_th = ptr_btree;
	binary_tree ptr_temp = NULL;

	while(ptr_th != NULL)
	{
		while(ptr_temp = getop(ptr_sh))
		{
			push(ptr_sh, ptr_th);
		}

		ptr_temp = pop(ptr_sh);

		if(ptr_sh != NULL)
		{
			ptr_temp = pop(ptr_sh);
			printf("%d\n", ptr_temp->num);	
			push(ptr_sh,ptr_temp->right);
		}
		
	}
}


int main()
{
	int array[5] = {5, 4, 7, 8, 2};
	binary_tree ptr_header = NULL;

	if(ptr_header = (binary_tree)malloc(Len_Btree))
	{
		ptr_header->left = NULL;
		ptr_header->right = NULL;
	}

	stack_init(ptr_stack);         //栈chushi始化
	push(ptr_stack, ptr_header);
//	BinaryTree_Init(ptr_header);

	int i = 0;
	for(; i < 5; i++)
	{
		ptr_header = btree_crt(ptr_header,array[i]); 
	}

	Inorder_Traverse(ptr_stack,ptr_header);

	return 0;

}
