#include<stdio.h>

int main()
{
	int count = 0;
	int i = 0;
	char c = '\0';
	scanf("%d", &count);
	while((c = getchar()) != '\n');   

	while(count--)
	{
		for(i = 0; (c = getchar()) != '\n'; i++)
		{
			if(i > 2 && i < 7)
			{
				printf("*");
				continue;
			}
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}

