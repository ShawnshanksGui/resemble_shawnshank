#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define OVERFLOW 2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10


//typedef BiTree SElemType;
typedef int Status;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct BiTNode *SElemType;
/*
typedef struct{
    BiTree base;
	BiTree top;
    int stacksize;
}SqStack;
*/
typedef struct{
	BiTree *base;
	BiTree *top;
	int stacksize;
}SqStack;
/*
typedef struct Header{
	BiTree header;
}*node_Header;
*/

//global variable//
BiTree array[101] = {NULL,NULL};

//global variable//

Status InitStack(SqStack *S)
{
    //S->base=(SElemType *)malloc(STACK_INIT_SIZE*(sizeof(SElemType)));
//	BiTree array[30] = {NULL};

//    if(!S->base)
  //      exit(OVERFLOW);
    S->base = array;
	S->top  = array;

    S->stacksize=STACK_INIT_SIZE;
}

Status IsEmpty(SqStack *S)
{
    if(S->base == S->top)
	{
		return TRUE;
	}
	else
		return FALSE;
}
/***
IsEmpty needs to be modified
****/

void Push(SqStack *S,BiTree x)
{

   	if((S->top-S->base) >= S->stacksize)
   	{
      	S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*(sizeof(SElemType)));
	//	if(!S->base)
		exit(OVERFLOW);
 	//	S->top=S->base+S->stacksize;
    //	S->stacksize+=STACKINCREMENT;
  	}
	else
	{
   	 	*S->top = x;//key point
		(S->top)++;
	}
//    return TRUE;
}
/*
Status Pop(SqStack *S,SElemType *x)
{
    if(S->top!=S->base)
       printf("%d\n",*--S->top);

	return 0;
}
*/

void Pop(SqStack *S, BiTree *x)
{
	if((S->top - S->base) <= 0)
	{
		printf("The stack is empty");
	//	--(S->top);
	//	*x = *s->top;
	}
	else
	{
		--(S->top);
		*x = *(S->top);
	}
}
/*
void CreateBiTree(BiTree T)
{
    char c = '\0';

    scanf("%c",&c);

    if(c==' ')
        T = NULL;
    else
    {
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=c;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
*/

void CreateBiTree(BiTree *ptr)
{
    char c = '\0';

	scanf("%c", &c);

	if(c==' ')
		*ptr = NULL;
	else
	{
		(*ptr) = (BiTree)malloc(sizeof(BiTNode));
		(*ptr)->data=c;
		CreateBiTree(&((*ptr)->lchild));
		CreateBiTree(&((*ptr)->rchild));
	}
	//return 
}


void Visit(BiTree T)
{
    if(T->data != ' ')
        printf("%c",T->data);
}

//先序遍历（非递归）
void PreOrderTraversal(BiTree T)
{
    BiTree p=T;
    SqStack S;
    InitStack(&S);
    while(p||!IsEmpty(&S))
    {
        /*while(p)
        {
            Push(&S,&p->data);//???????????
            Visit(p);
            p=p->lchild;
        }*/
		while(p != NULL)
		{
			Push(&S, p);
			Visit(p);
			p = p->lchild;
		}
		if(!IsEmpty(&S))
		{
			Pop(&S,&p);
			p = p->rchild;
		}
        /*if(!IsEmpty(&S))
        {
            Pop(&S,&p->data);
            p=p->rchild;
        }*/
    }
}

int main()
{
	BiTree T = NULL;
//	node_Header tNode;

//	tNode = (node_Header)malloc(sizeof(struct Header));
//	tNode->header = NULL;

	CreateBiTree(&T);

    printf("先序遍历：\n");
    PreOrderTraversal(T);
    printf("\n");

   /* printf("先序遍历（非递归）：\n");
    PreOrderTraversal(T);
    printf("\n");
    printf("中序遍历：\n");
    InOrder(T);
    printf("\n");
    printf("中序遍历（非递归）：\n");
    InOrderTraversal(T);
    printf("\n");
    printf("后序遍历：\n");
    PostOrder(T);
    printf("\n");
    printf("后序遍历（非递归）：\n");
    PostOrderTraversal(T);
    printf("\n");
	*/
    return 0;
}
