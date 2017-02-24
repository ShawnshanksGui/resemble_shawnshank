/**************************************
attention ， please!!!!!!!!!!!!!!!
创建链表时，准确来说是往链表末尾插入元素时（包括空链表），需返回已经在其位置修改过的地址
***************************************/

#include<stdio.h>
#include<stdlib.h>

#define ERROR 0
#define OK 1

typedef struct lnode
{
	int data;
    struct lnode *next;
}lknode, *linklist;

struct linkst{
	linklist top;
};

typedef struct linkst link_H;
typedef struct linkst *node;
/*
linklist link_insert(int val, linklist ptr_h)
{
	linklist ptr = ptr_h;
	linklist ptr_temp = NULL;
	linklist ptr_temp_a = ptr_h;

	while(ptr)
	{
		ptr_temp_a = ptr;
		ptr = ptr->next;
	}

	if(ptr_temp_a)
	{
		if(ptr_temp = (linklist)malloc(sizeof(lknode)))
		{
			ptr_temp->data = val;
			ptr_temp->next = NULL;
			ptr_temp_a->next = ptr_temp;
			return ptr_h;          
		}
		else
		{
			exit(ERROR);
		}
	}
	else
	{
		if(ptr = (linklist)malloc(sizeof(lknode)))
		{
			ptr->data = val;
			ptr->next = NULL;
			return ptr;                          // 如何你想返回普通话ptr_h，这样不会起作用，因为开头的语句ptr = ptr_h,只起拷贝作用，当ptr改变时													无法改变ptr_h的值
		}		else
		{
			exit(ERROR);
		}
	}
}
*/

linklist link_insert(int val, linklist ptr_h)
{
	linklist ptr_pre = NULL;
	linklist ptr_temp = NULL;
	linklist ptr = ptr_h;

	if(ptr != NULL)
	{
		while(ptr)
		{
			ptr_pre = ptr;
			ptr = ptr->next;
		}
		if(ptr_temp = (linklist)malloc(sizeof(lknode)))
		{
			ptr_temp->data = val;
			ptr_temp->next = NULL;
			ptr_pre->next = ptr_temp;
			return ptr_h;
		}
		else
		{
			exit(ERROR);
		}
	}
	else
	{
		if(ptr = (linklist)malloc(sizeof(lknode)))
		{
			ptr->data = val;
			ptr->next = NULL;
			return ptr;
		}
		else
		{
			exit(ERROR);
		}
	}
}
/*
void link_insert(int ay[], linklist ptr)

	linklist ptr_cp = ptr;
	linklist ptr_temp_a = ptr;
	linklist ptr_temp = NULL;

//	ptr_cp->next = NULL;        //  
	int i = 0;
	int *array_a = array;

	for(; i <= 9; i++)
	{
		if(ptr_temp = (linklist)malloc(sizeof(lknode)))
			;

		else
			exit(ERROR);

		if(i != 0)
		{
			ptr_temp->data = array_a[i];
//			ptr_temp->next = (*ptr_cp)->next;
			ptr_temp->next = NULL;
			(*ptr_cp)->next = ptr_temp;
			*ptr_cp = (*ptr_cp)->next;
		}
		else
		{
			ptr_cp = ptr_temp;
			(*ptr_cp)->data = array_a[i]; 
			(*ptr_cp)->next = NULL;

		}
	}
		if(ptr_temp = (linklist)malloc(sizeof (lknode)))
		{
			ptr_temp->data = array_a[i];

			/////////为了避免段错误
			if(ptr_cp)
			{
				ptr_temp->next = ptr_cp->next;
			}
			else
			{
				ptr_temp->next = NULL;
			}
			/////////避免段错误

			ptr_cp->next = ptr_temp;
		}
		else{ 
			printf("what an error !!");
			return 0;
			}				*/           
/*
linklist find_prev(linklist ptr_h)
{
	linklist ptr = ptr_h;
	linklist ptr_ret = NULL;
	while(ptr)
	{
		if(ptr->data == num)
		{	
			
			if(ptr_ret)
				return ptr_ret;
			else
		
		}

		ptr_ret = ptr;
		ptr = ptr->next;
	}
}
*/
/*
void link_Delete(linklist ptr_h, int num)
{
	linklist ptr = ptr_h;
	linklist ptr_temp = NULL;
	while(ptr)
	{
		ptr_temp = ptr;
		if(ptr->data == num)
		{
			
		}

		ptr = ptr->next;
	}
}
*/
void linklist_Print(linklist ptr_h)
{
	linklist ptr = ptr_h;
	while(ptr)
	{
		printf("%3d  ", ptr->data);
		ptr = ptr->next;
	}
}

linklist linklist_reverse(linklist ptr_a)
{
	linklist ptr_cp = ptr_a;
	linklist ptr_temp = NULL;
	linklist ptr_temp_a = NULL;
/*	ptr_temp = ptr_cp->next;
	ptr_cp->next = NULL;
	ptr_temp->next = ptr_cp;
	ptr_cp = ptr_temp;   ** * think complicately */

/*	while(ptr_cp->next != NULL)
	{
		ptr_temp_a = ptr_cp->next;
		ptr_temp = ptr_cp->next;
		ptr_temp->next = ptr_cp;
	//	ptr_cp = ptr_cp->next   mistake ,make a circle!!
	}   */

	while(ptr_cp != NULL)
	{
		ptr_temp_a = ptr_cp->next;
		ptr_cp->next = ptr_temp;
		ptr_temp = ptr_cp;
		ptr_cp = ptr_temp_a;
	}
	return ptr_temp;  //return updated pointer

//	while(ptr_cp != NULL)
//	{
//		ptr_temp = 
//	}
}

int main()
{
	int array[10] = {1, 4, 3, 6 , 213, 10, 23, 12, 12, 23};
	node stack = (node)malloc(sizeof(link_H)); //why must I use function malloc

	stack->top = NULL;
	
	int i = 0;

	for(; i <= 9; i++)
	{
		stack->top = link_insert(array[i], stack->top);
	//	link_insert(array[i], stack->top);
	}
	linklist_Print(stack->top);
	printf("\n");

	stack->top = linklist_reverse(stack->top);
//	while(ptr_h != NULL)
//	{
//		printf("%d\n", ptr_h->data);
//		ptr_h = ptr_h->next;
//	}

	linklist_Print(stack->top);
	return 0;

}



