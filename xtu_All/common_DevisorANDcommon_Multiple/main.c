#include<stdio.h>

void number_Judge(int *, int *);

int main()
{
	int number_a = 0;
	int number_b = 0;
	int a = 0;
	int b = 0;
	int temp = 0;
	int greatest_CommonDivisor = 0;
	int least_CommonMultiple = 0;

	scanf("%d %d", &a, &b);
	number_a = a;
	number_b = b;
	number_Judge(&number_a, &number_b);
	//****//
	while((number_a % number_b) != 0)
	{
		temp = number_b;
		number_b = number_a % number_b;
		number_a = temp;
	}
	greatest_CommonDivisor = number_b;
	least_CommonMultiple = a * b / greatest_CommonDivisor;
	printf("The greatest common multiple is : %d\n", greatest_CommonDivisor);
	printf("The least common divisor is : %d\n", least_CommonMultiple);
	//****//

	return 0;
}

void number_Judge(int *a, int *b)
{
	int temp = 0;
	if(*a < *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

