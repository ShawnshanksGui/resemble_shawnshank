#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERROR 0
#define MAXLEN 15

typedef struct balloon{
	char *color_label;
	int count;
	struct balloon *next;
}info_balloon, *ptr_balloon;

struct node_head{
	ptr_balloon next;
};

int getline_gf(char *, int );
void deal_linkCreate(char *, struct node_head *);
void amount_judge(struct node_head *);
void free_gf(ptr_balloon);

int main()
{
	int count = 0;
	char str[16] = {'\0'};
	char *color = NULL;
	int len = 0;
	char c = '\0';
	ptr_balloon ptr_free = NULL;

	struct node_head *header = (struct node_head *)malloc(sizeof(struct node_head));
	header->next = NULL;
	
	while(1)
	{
		scanf("%d", &count);
		while((c = getchar()) != '\n');

		if(!count)
		{
			break;
		}
		else
		{
			while(count--)
			{
				//scanf("%s", str);
				len = getline_gf(str, MAXLEN);
				if((color = (char *)malloc(len + 1)) != NULL)
				{
					strcpy(color, str);
					deal_linkCreate(color, header);
				}
				else
				{
					exit(ERROR);
				}
			}
		}
		amount_judge(header);
		ptr_free = header->next;
		header->next = NULL;
		free_gf(ptr_free);
	}

	return 0;
}

void deal_linkCreate(char *this_color, struct node_head *ptr_a)
{
	ptr_balloon ptr_temp = ptr_a->next;
	ptr_balloon ptr = ptr_a->next;

	if(!ptr)
	{
	/*	if(ptr->next = (ptr_balloon)malloc(sizeof(info_balloon)))
		{
			ptr->next->count = 1;
			ptr->next->color_label = this_color;
			ptr->next->next = NULL;
		}
	*/
		if(ptr = (ptr_balloon)malloc(sizeof(info_balloon)))
		{
			ptr->count = 1;
			ptr->color_label = this_color;
			ptr->next = NULL;
			ptr_a->next = ptr;   //!!!!!! attention important//////
		}
		else
		{
			exit(ERROR);
		}
	}
	else
	{
		for(; ptr != NULL; ptr = ptr->next)
		{
			ptr_temp = ptr;
			if(strcmp(ptr->color_label, this_color) == 0)
			{
				ptr->count++;
				break;
			}
		}
		if(ptr == NULL)  // don't find the color//
		{
			if(ptr = (ptr_balloon)malloc(sizeof(info_balloon)))
			{
				ptr->next = NULL;
				ptr->count = 1;
				ptr->color_label = this_color;
				ptr_temp->next = ptr;
			}
		}
	}
//	return ptr_a;
}
/*
int find(char *this_color, ptr_balloon ptr)
{
	for(;ptr != NULL; ptr = )
}
*/

int getline_gf(char *str, int maxlen)
{
	int c = '\0';
	int len = 0;

	while((c = getchar()) != '\n' && (maxlen > 0))
	{
		*str = c;
		str++;
		len++;
		maxlen--;
	}
	*str = '\0';

	return len;
}

void amount_judge(struct node_head *ptr_a)
{
	int largest = 0;
	char *color_max = NULL;

	ptr_balloon ptr = ptr_a->next;

	if(!ptr)
	{
		printf("No Input!!!");
	}
	else
	{
		for(; ptr != NULL; ptr = ptr->next)
		{
			if(ptr->count > largest)
			{
				largest = ptr->count;
				color_max = ptr->color_label;
			}
		}
	}
	printf("%s\n", color_max);
}

void free_gf(ptr_balloon ptr)
{
	ptr_balloon ptr_posterior = NULL;

	while(ptr != NULL)
	{
		ptr_posterior = ptr->next;
		free(ptr);
		ptr = ptr_posterior;
	}
}
