#include<stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	char str[20] = {'\0'};
	int count = 0;
	scanf("%d", &count);
	while(getchar() != '\n'); //过滤掉第一个数字count//

	while(count--)
	{
		while((str[i] = getchar()) != '\n')
		{
			i++;
		}
		for(i = 0; i < 11; i++)
		{
			if(i > 2 && i < 7)
			{
				printf("*");
			}
			else
			{
				printf("%c", str[i]);
			}
		}
		printf("\n");
		i = 0;
	}
	return 0;
}
