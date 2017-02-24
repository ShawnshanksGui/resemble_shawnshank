#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct substr{
	char symbol;
	struct substr *next;
}*ptr_substr;
int findAnd_add(char , ptr_substr);

int longestLenth_substr(char *);

int main()
{
	char array[50] = {'\0'};
//	char *ptr = array;
	while(1)
	{
		scanf("%s", array);
		if(array[0] == '*')
		{
			break;
		}
		printf("%d\n", longestLenth_substr(array));
		memset(array, '\0', 50);
	}

	return 0;
}

int longestLenth_substr(char *str)
{
	int count = 0;
	ptr_substr List = NULL;

	if(*str != '\0')
	{
		List = (ptr_substr)malloc(sizeof(struct substr));
		List->symbol = *str;
		List->next = NULL;

		count++; //lenth plus 1;
	}

	str++;
	for( ; *str != '\0'; str++)
	{
		if(!findAnd_add(*str, List))
		{
			count++;
		}
	}
//	len_linklist();
	return count;
}

int findAnd_add(char letter, ptr_substr List)
{
	int Is_find = 0;
	ptr_substr pre_list = List;

	for(; List != NULL; List = List->next)
	{
		if(List->symbol == letter)	
		{
			Is_find = 1;
		}
		pre_list = List;
	}

	if(!Is_find)
	{
		if(List = (ptr_substr)malloc(sizeof(struct substr)))
		{
			List->symbol = letter;
			List->next = NULL;
			pre_list->next = List;		
		}
	}
	return Is_find;
}	
