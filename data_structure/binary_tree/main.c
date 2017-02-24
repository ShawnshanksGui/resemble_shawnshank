#include<stdio.h>
#include<stdlib.h>

struct b_tnode{
int num;
int count;
struct b_tnode *left;
struct b_tnode *right;};    //define binary_tree

typedef struct b_tnode btnode;         
typedef struct b_tnode *binary_tree;       //type definition


binary_tree btree_crt(int num_f, binary_tree ptrbit)
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
		++ ptr_bit->count;
	}
	else if(ptr_bit->num > num_f)
	{
		ptr_bit->left = btree_crt(num_f, ptr_bit->left);
	}
	else if(ptr_bit->num < num_f)
	{
		ptr_bit->right = btree_crt(num_f, ptr_bit->right);
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

/*	if(ptr == NULL)
	{
		printf("%3d %d\n",ptr->num, ptr->count);
	}                                                  why!!!               */
}

int main()
{

	int array[20] = {2,4,54,23,65,43,32,7,
	4,98,33,23,55,33,43,21,77,99,2,11};   

	int i = 0;

	binary_tree root = (binary_tree)malloc(sizeof(btnode));
	root->left = root->right = NULL;

	while(i < 20)
	{
		printf("%d ", array[i]);
		i++;
	}

	printf("\n");

	i = 0;

	while(i < 20)
	{
		root = btree_crt(array[i], root);
		i++;
	}
	btree_print(root);

	return 0;
}
