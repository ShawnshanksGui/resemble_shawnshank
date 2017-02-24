#include<stdio.h>

int main()
{
	int count, a, b, i, j, sum = 0;

	while(scanf("%d\n", &count) != -1)
	{
		for(i = 0; i < count; i++)
		{
			scanf("%d", &b);
			for(j = 0; j < b; j++)
			{
				scanf("%d", &a);
				sum += a;
			}
			printf("%d\n", sum);
			sum = 0;
		}
	}

	return 0;

}
