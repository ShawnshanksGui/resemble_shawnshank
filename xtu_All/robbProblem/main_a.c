#include<stdio.h>
#include<math.h>

int factorial(int val)
{
	int num_ret = val;

	if(val == 0)
		return 1;
	else if(val == 1)
		return 1;
	else
		for(val--; val >=1; val--)
		{
			num_ret *= val;
		}

	return num_ret;
}

int main()
{
	int num_size = 0;
	int num_a = 0;
	int count = 0;
	int temp = 0;
//	int i = 0;

	scanf("%d", &count);

	while(count--)
	{
		temp = 0;
		scanf("%d%d", &num_size, &num_a);
		temp = factorial(num_size);

		if(temp > 10)
		{
			temp = (temp - temp / pow(10, num_a) * pow(
			10, num_a)) / pow(10, num_a - 1);
			printf("%d\n", temp);

		/*	for(; num_a > 1; num_a--)
			{
				temp /= 10; 
			}
			temp %= 10;
			printf("%f\n", temp);
		*/
		}
		else
		{
			if(num_a == 1)
				printf("%d\n", temp);
		}
	}

	return 0;
}
