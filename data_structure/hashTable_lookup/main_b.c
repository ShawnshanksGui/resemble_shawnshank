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

static linklist hashtab[HASHSIZE];

char *str_Dup(char *s)
{
	char *p = (char *)malloc(sizeof(strlen(s) + 1));
	
	if(p != NULL)
	{
		strcpy(p, s);
	}
	return p;
}


uint hash(char *s)
{
	uint hashval = 0;

	for(; *s != '\0'; s++)
	{
		hashval = 31 * hashval + *s;
	}

	return hashval % HASHSIZE;
}

uint hash(char *s)
{
	uint hashval = 0;
	
	for(; *s != '\0'; s++)
	{
		hashval = 31 * hashval + *s;
	}
	return hashval % HASHSIZE;
}

linklist lookup(char *s)
{
	lnklist p = NULL;

	for(p = hashtab[hash(s)]; p != NULL; p = p->next)
	{
		if(strcmp(p->name, s) == 0)
		{
			return p;
		}
	}

	return p;
}

linklist install(char *name, char *defn)
{
	linklist ptr_a = NULL;
	uint hashval = 0;

	if((ptr_a = lookup(name)) == NULL)
	{
		ptr_a = (linklist)malloc(sizeof(lknode));

		if(ptr_a == NULL || (ptr_a->name = str_Dup(name)) == NULL)
		{
			return NULL;
		}
		hashval = hsah(name);
		ptr_a->next = hashtab[hashval];
		hsahtab[hashval] = ptr_a;
	}

	else
	{
		printf("%s\n", ptr_a->name);
		printf("%s\n", ptr_a->defn);

		free(ptr_a->defn);
	}

	if((ptr_a->defn = str_Dup(defn)) == NULL)
	{
		return NULL;
	}

	printf("%s\n", ptr_a->name);
	printf("%s\n", ptr_a->defn);

	return ptr_a;
}























