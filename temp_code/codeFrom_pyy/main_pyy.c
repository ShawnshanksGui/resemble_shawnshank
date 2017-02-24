#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define OVERFLOW 2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef int Status;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{
    SElemType *base,*top;
    int stacksize;
}SqStack;

Status InitStack(SqStack *S)
{
    S->base=(SElemType *)malloc(STACK_INIT_SIZE*(sizeof(SElemType)));
    if(!S->base)
        exit(OVERFLOW);
    S->base=S->top;
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

void Push(SqStack *S,SElemType *x)
{
    if(S->top-S->base>=S->stacksize)
    {
        S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*(sizeof(SElemType)));
        if(!S->base)
            exit(OVERFLOW);
        S->top=S->base+S->stacksize;
        S->stacksize+=STACKINCREMENT;
    }
    *S->top++ =x;
    return TRUE;
}
/*
Status Pop(SqStack *S,SElemType *x)
{
    if(S->top!=S->base)
       printf("%d\n",*--S->top);

	return 0;
}
*/

void pop(SqStack *S, SElemneType *x)
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
		*x = *S->top;
	}
}
int CreateBiTree(BiTree T)
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
    return 0;
}

void Visit(BiTree T)
{
    if(T->data!=' ')
        printf("%c",T->data);
}

//�������
void PreOrder(BiTree T)
{
    if(T!=NULL)
    {
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//�������
void InOrder(BiTree T)
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
}

//�������
void PostOrder(BiTree T)
{
    if(T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);
    }
}

//����������ǵݹ飩
void PreOrderTraversal(BiTree T)
{
    BiTree p=T;
    SqStack S;
    InitStack(&S);
    while(p||!IsEmpty(&S))
    {
        while(p)
        {
            Push(&S,p);
            Visit(p);
            p=p->lchild;
        }
        if(!IsEmpty(&S))
        {
            Pop(&S,p);
            p=p->rchild;
        }
    }
}

//����������ǵݹ飩
void InOrderTraversal(BiTree T)
{
    BiTree p=T;
    SqStack S;
    InitStack(&S);
    while(p||!IsEmpty(&S))
    {
        while(p)
        {
            Push(&S,p);
            p=p->lchild;
        }
        if(!IsEmpty(&S))
        {
            p=Pop(&S,p);
            Visit(p);
            p=p->rchild;
        }
    }
}

//����������ǵݹ飩
void PostOrderTraversal(BiTree T)
{
    BiTree p=T;
    SqStack S;
    InitStack(&S);
    while(p)
    {
        if(p->rchild!=T)
        {
            if(p->lchild!=T)
                while(p->lchild)
            {
                Push(&S,p);
                p=p->lchild;
            }
            if(p->rchild)
            {
                Push(&S,p);
                p=p->rchild;
                continue;
            }
        }
        Visit(p);
        T=p;
        p=Pop(&S,p);
    }
}

int main()
{
    BiTree T;
    CreateBiTree(T);
    printf("���������\n");
    PreOrder(T);
    printf("\n");
   /* printf("����������ǵݹ飩��\n");
    PreOrderTraversal(T);
    printf("\n");
    printf("���������\n");
    InOrder(T);
    printf("\n");
    printf("����������ǵݹ飩��\n");
    InOrderTraversal(T);
    printf("\n");
    printf("���������\n");
    PostOrder(T);
    printf("\n");
    printf("����������ǵݹ飩��\n");
    PostOrderTraversal(T);
    printf("\n");
	*/
    return 0;
}
