#include<stdio.h>

int main()
{
	int count = 0;
	int n = 0;
	int sum = 0;

	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		if(n & 0x01) // if odd number//
		{
			sum = (1 + n) * (n / 2) + (1 + n) / 2;
		}
		else
		{
			sum = (1 + n) * (n / 2);
		}
		printf("%d\n", sum);
	}
	return 0;
}
