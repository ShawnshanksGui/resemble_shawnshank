#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 101

typedef unsigned int uint;

typedef struct node{
	struct node *next;
	char *name;
	char *defn;
}lknode, *linklist;

static linklist hashtab[HASHSIZE]; //定义一个静态hash指针数组//

char *str_Dup(char *s)
{
	char *p = (char *)malloc(sizeof(strlen(s) + 1));   
	//为了在字符串末尾加上'\0'//

	if(p != NULL)
	{
		strcpy(p, s);      //include在头文件string.h//
	}
	return p;
}

uint hash(char *s)
{
	uint hashval = 0;

	for(; *s != '\0'; s++)
	{
		hashval =  31 * hashval + *s;
	}
	
	return hashval % HASHSIZE;

	/*将上一次循环得到的hashval经过变换（乘以31）后得到的
	新值同字符串当前字符值相加（即(hashval * 31) + *s）*/
}


linklist lookup(char *s)
{
	linklist p = NULL;

	for(p = hashtab[hash(s)]; p != NULL; p = p->next)
	{
		if(strcmp(p->name, s) == 0)  //inlcude<sring.h>
			return p;
	}
	
	return p;

	/*该函数通过hash函数得到hash表指针数组的下表地址
	，即为链表的头指针，然后再遍历链表查找*/
}

linklist install(char *name, char *defn)
{
	linklist ptr_a = NULL;
	uint hashval = 0;
//	linklist ptr_b = NULL;

/*	if((ptr_a = lookup(name)) == NULL)   //没找到//
	{
		ptr_b = (linklist)malloc(sizeof(lknode));

		if((ptr_b->name = str_Dup(name)) == NULL)
		{
			return NULL;
		}
		ptr_b->defn = str_Dup(defn);
		ptr_b->next = NULL;
		ptr_a->next = ptr_b;
	}
*/
	if((ptr_a = lookup(name)) == NULL)
	{
		ptr_a = (linklist)malloc(sizeof(lknode));		
		
		if(ptr_a == NULL || (ptr_a->name = str_Dup(name)) == NULL)
		{
			return NULL;
		}
		hashval = hash(name);
		ptr_a->next = hashtab[hashval];
		hashtab[hashval] = ptr_a;
	/*链表插入选择的是从表头插入，省去遍历链表或者定义尾指针的任务*/
	}
	else
	{
		printf("%s\n", ptr_a->name);
		printf("%s\n", ptr_a->defn);

		free(ptr_a->defn);  //释放上一个defn//
	}
		/*因为结构体里的成员命名与函数中的变量所用namespace
		不一样所以ptr_a->defn与strdup(defn)并不冲突*/
	if((ptr_a->defn = str_Dup(defn)) == NULL)  
	{
		return NULL;
	}
	printf("%s\n", ptr_a->name);
	printf("%s\n", ptr_a->defn);
	return ptr_a;
}

int main()
{
	char array_a[10] = {'\0'};
	char array_b[10] = {'\0'};
	char *ptr_a = array_a;
	char *ptr_b = array_b;

	while(1)
	{
		scanf("%s%s", ptr_a, ptr_b);
		install(ptr_a, ptr_b);
	}
	return 0;
}






