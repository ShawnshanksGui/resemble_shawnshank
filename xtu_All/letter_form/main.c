#include<stdio.h>

#define LEN_MAX 200

typedef unsigned char uchar;

char *getline_ex(char *ptr, int len)
{
	char *ptr_str = ptr;
	uchar i = 0;
	char c = '\0';
	while((c = getchar()) != '\n' && i < len)
	{
		*ptr_str ++ = c;
		i++;
	}
	*ptr_str = '\0';              /*字符串末尾终止符*/
	return ptr;
}

void letterForm_Transform(char *ptr)
{
	char *ptr_retrurn = ptr;

	while(*ptr != '\0')
	{
		if(*ptr >= 'A' && *ptr <= 'Z')
		{
			*ptr = *ptr + 32;
		}
		else if(*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr = *ptr - 32;
		}

		ptr++;
	}
}



int main()
{
	int count = 0 ;
	char *ptr[10] = {NULL, NULL};
	char array_s[10][200] = {'\0'};
	char i = 0;
	char k = 0;
	char c = '\0';
	while((c = getchar()) != '\n')
	{
		count = 10 * count + (c - '0');
	}
	
	for(; count > 0; i++, count--)
	{
		ptr[i] = getline_ex(array_s[i], LEN_MAX);
		
		letterForm_Transform(ptr[i]);
	}

	for(; k < i; k++)
	{
		printf("%s\n", ptr[k]);
	}

	return 0;
}
