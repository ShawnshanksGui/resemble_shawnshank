#include<stdio.h>

struct lnode{int num;
struct lnode *next;
};
typedef struct lnode *linklist;

extern linklist stack_ptr;

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

