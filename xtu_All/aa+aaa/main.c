#include<stdio.h>

int main()
{
	int a = 0; 
	int lenth_a = 0;
	int sum = 0;
	int temp = 0;

	scanf("%d %d", &a, &lenth_a);
	while(lenth_a--)
	{
		temp += a;
		sum += temp;
		a *= 10;
	}

	printf("%d\n", sum);

	return 0;

}
