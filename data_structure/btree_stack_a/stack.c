#include<stdio.h>
#include<stdlib.h>

#define LEN_linknode sizeof(linknode)
#define OK 1
#define ERROR 0


struct b_tnode{
int num;
int count;
struct b_tnode *left;
struct b_tnode *right;};    //define binary_tree

typedef struct b_tnode btnode;
typedef struct b_tnode *binary_tree;     

struct lnode{
binary_tree num;
struct lnode *next;};

typedef struct lnode linknode;
typedef struct lnode *linklist;

linklist ptr_stack = NULL;

int stack_init(linklist ptr_stack)
{
	if(ptr_stack = (linklist)malloc(LEN_linknode))
	{
		ptr_stack->next = NULL;
	}

	else
	{
		return ERROR;
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



int push(linklist ptr_lnode, binary_tree val)
{
	linklist ptr = ptr_lnode;
	linklist ptr_temp = NULL;

	if(ptr_temp = (linklist)malloc(LEN_linknode))
	{
		ptr_temp->next = ptr;
		ptr_temp->num = val;
		ptr_stack = ptr_temp;
	}

	else
	{
		return ERROR;
		printf("the stack is overflow\n");
	}

}


binary_tree pop(linklist ptr_node)
{
	linklist ptr = ptr_node;
	binary_tree val;

	if(ptr != NULL)
	{
		val = ptr->num;
		ptr_stack = ptr->next; /*有待修正*/
		free(ptr);
		return val;
	}
	else
	{
		return ERROR;
		printf("the stack is empty");
	}
}

/*
int main()
{
	int num_a = 0;
	stack_init(stack_ptr);
	push(stack_ptr, 7);
	push(stack_ptr, 5);

	printf("%d\n",stack_ptr->num);

	pop(stack_ptr);
	num_a = pop(stack_ptr);
	printf("%d\n",num_a);
	return 0;          
}


*/










