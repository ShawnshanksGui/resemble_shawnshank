#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int k = 0;

	for(i = 0; i < 10; i++)
	{
		k = 1 + rand() % 10;
		printf("%d ", k);
	}

	return 0;
}

