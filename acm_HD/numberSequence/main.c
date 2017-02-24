#include<stdio.h>

int main()
{
	int A = 0;
	int B = 0;
	int n = 0;
	int i = 0;
	int pre_value = 0;
	int rear_value = 0;
	int this_value = 0;

	while(1)
	{
		scanf("%d %d %d", &A, &B, &n);
		if(!A && !B && !n)
		{
			return 0;
		}
		pre_value = 1;
		rear_value = 1;
		
		if(n == 1 || n == 2)
		{
			this_value = 1;
		}
		for(i = 3; i <= n; i++)
		{
			this_value = (A * rear_value + B * pre_value) % 7;
			pre_value = rear_value;
			rear_value = this_value;
		}
		printf("%d\n", this_value);
	}


	return 0;
}
