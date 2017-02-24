#include<stdio.h>

int main()
{
	int i = 0;
	int count = 0;
//	char *ptr = NULL;
	char str[11] = {'\0'};
	char *ptr = str;

	while(1)
	{
		scanf("%d", &count);
		while(count--)
		{
			i = 0;
			scanf("%s", ptr);
			for(i = 0; i < 11; ptr++, i++)
			{
				if(i > 3 && i < 8)
				{
					*ptr = '*';
				}
				printf("%c", *ptr);
			}
			printf("\n");
		}
	}
	return 0;
}
