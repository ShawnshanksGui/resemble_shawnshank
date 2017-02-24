#include<stdio.h>

void ackerman(int *val)
{
	*val = 100;
}

int main()
{	
	int num_a = 0;

	num_a = getchar();
	ackerman(&num_a);
	printf("%d\n", num_a);

	return 0;
}
