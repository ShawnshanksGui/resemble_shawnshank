#include<stdio.h>
#include<stdlib.h>

#define LEN_Btree sizeof(btnode)
#define LEN_linknode sizeof(linknode)
#define ERROR 0
#define OK 1

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

typedef struct node list_node;
typedef struct node *link;


//linklist ptr_stack = NULL;		


//extern binary_tree btree_crt(binary_tree, int);
//extern void btree_print(binary_tree);

//extern int stack_init(linklist);
//extern int getop(linklist, void *);
//extern binary_tree getop(linklist);
//extern int push(linklist, binary_tree);
//extern void *pop(linklist);




void stack_Init(linklist *ptrstack)
{
    if(*ptrstack = (linklist)malloc(LEN_linknode))
	{
		(*ptrstack)->next = NULL;
//		return ptrstack;
	}

	else
	{
	     exit(ERROR);
	}
}

void btree_Init(binary_tree *ptr)
{
	if(*ptr = (binary_tree)malloc(LEN_Btree))
	{
		(*ptr)->left = NULL;
		(*ptr)->right = NULL;
	}

	else
	{
		exit(ERROR);
	}



}

binary_tree getop(linklist ptr_lnode)       // ptr !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	binary_tree ptr =NULL;
	if(ptr_lnode != NULL)
	{
		ptr = ptr_lnode->num;   /// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		return ptr;
	}

	else
	return NULL;
}


linklist push(linklist ptr_lnode, binary_tree val)
{
    linklist ptr = ptr_lnode;
	linklist ptr_temp = NULL;

	if(ptr_temp = (linklist)malloc(LEN_linknode))
	{ 
		ptr_temp->next = ptr;
		ptr_temp->num = val;
	//	ptr_stack = ptr_temp;

		return ptr_temp;
	}

	else
	{
		return NULL;
		printf("the stack is overflow\n");
	}

}

/*int push(linklist ptr_lnode, binary_tree val, link stack)
{
	linklist ptr = ptr_lnode;
	linklist ptr_temp = NULL;

	if(ptr_temp = (linklist)malloc(LEN_linknode))
	{
		ptr_temp->next = ptr;
		ptr_temp->num = val;
		stack->top = ptr
	}


}*/

//binary_tree pop(linklist ptr_node)
linklist pop(linklist ptr_node, binary_tree *val)
{
    linklist ptr = ptr_node;
	linklist ptr_stack = NULL;
	if(ptr != NULL)
	{
		*val = ptr->num;
		ptr_stack = ptr->next; /*有待修正*/
		free(ptr);
		return ptr_stack;
	//	return val;
	}
	else
	{
		//return ERROR;
		return NULL;
		printf("the stack is empty");
	}
}

////////////以上是栈定义/////////////


binary_tree btree_crt(binary_tree ptrbit, int num_f)
{
    binary_tree ptr_bit = ptrbit;

	if(ptr_bit == NULL)
	{
		if(ptr_bit = (binary_tree)malloc(sizeof(btnode)))
		{
			ptr_bit->count = 1;
			ptr_bit->num = num_f;
			ptr_bit->left = NULL;
			ptr_bit->right = NULL;
		}
	}
	else if(ptr_bit->num == num_f)
	{
		++ptr_bit->count;
	}
	else if(ptr_bit->num > num_f)
	{
		ptr_bit->left = btree_crt(ptr_bit->left, num_f);
	}
		else if(ptr_bit->num < num_f)
	{																		
			ptr_bit->right = btree_crt(ptr_bit->right, num_f);
																																				   	}
																																					return ptr_bit;
}



void btree_print(binary_tree ptr_btree)
{
    binary_tree ptr = ptr_btree;

	if(ptr != NULL)
	{
		btree_print(ptr->left);
		printf("%3d %d\n", ptr->num, ptr->count);
		btree_print(ptr->right);
	}
}


///////////以上是二叉树定义///////////









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
   // stack_init(ptr_stack);
	linklist ptr_sh = ptr_stack;
	binary_tree ptr_th = ptr_btree;
	binary_tree ptr_temp = NULL;
	//push(ptr_sh,ptr_th);
	ptr_sh = push(ptr_sh, ptr_th);

//	while(ptr_sh != NULL)
	while(ptr_sh != ptr_stack)
	{
		while(ptr_temp = getop(ptr_sh))
		{
		//	push(ptr_sh, ptr_temp);
			ptr_sh = push(ptr_sh, ptr_temp->left);
			ptr_temp = ptr_temp->left;
		}

//		for(; ptr_temp = getop(ptr_sh); )

	//	ptr_temp = pop(ptr_sh);
		ptr_sh = pop(ptr_sh, &ptr_temp);
	//	if(ptr_sh != NULL)
		if(ptr_sh != ptr_stack)
		{
		//	ptr_temp = pop(ptr_sh);
			ptr_sh = pop(ptr_sh, &ptr_temp);

			if(ptr_temp)
			{
				printf("%d\n", ptr_temp->num);	
			
		//	push(ptr_sh,ptr_temp->right);
				ptr_sh = push(ptr_sh, ptr_temp->right);
		//		ptr_temp = ptr_temp->right;
		//	ptr_th = ptr_temp;
			}
		}
		
	}
}


int main()
{
	int array[5] = {5, 4, 7, 8, 2};
	binary_tree ptr_header = NULL;
	linklist ptr_stack; 
	stack_Init(&ptr_stack);

	if(ptr_header = (binary_tree)malloc(LEN_Btree))
	{
		ptr_header->left = NULL;
		ptr_header->right = NULL;
	}

//	stack_init(ptr_stack);         //栈chushi始化
//	push(ptr_stack, ptr_header);
	btree_Init(&ptr_header);

	int i = 0;
	for(; i < 5; i++)
	{
		ptr_header = btree_crt(ptr_header,array[i]); 
	}

	btree_print(ptr_header);
//	push(ptr_stack, ptr_header);
//	push(ptr_stack, ptr_header);
//	if(ptr_stack = (linklist)malloc(LEN_linknode))
//	{
//		ptr_stack->next = NULL;
//	}
//
	Inorder_Traverse(ptr_stack,ptr_header);

	return 0;

}
