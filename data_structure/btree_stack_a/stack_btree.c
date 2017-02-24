#include<stdio.h>
#include<stdlib.h>

struct b_tnode{
int num;
int count;
struct b_tnode *left;
struct b_tnode *right;};    //define binary_tree

typedef struct b_tnode btnode;         
typedef struct b_tnode *binary_tree;       //type definition


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
		++ ptr_bit->count;
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

