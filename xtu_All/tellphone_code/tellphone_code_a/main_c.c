#include<stdio.h>

int main()
{
	char str[12]  = {'\0'};
	int i = 0;
	int count = 0;

	scanf("%d", &count);

	while(count--)
	{
		scanf("%s", str);
		for(i = 0; i <= 11; i++)
		{
			if(i > 2 && i < 7)
			{
				str[i] = '*';
			}
		}
		printf("%s\n", str);
	}
	return 0;
}

