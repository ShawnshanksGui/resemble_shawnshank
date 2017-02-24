#include<stdio.h>

int main()
{
	int count = 0;
	int i = 0;
	int k = 0;
	float num_a = 0.0;
	float num_b = 0.0;
	float array[100] = {0, 0, 0};

	scanf("%d", &count);

	for(i = 0; count > 0; i++)
	{
		scanf("%f%f", &num_a, &num_b);
		array[i] = (num_a * num_b) / 2;		
		count --;
	}
	

	for(; k < i; k++)
	{
		printf("%.1f\n", array[k]);
	}
	return  0;
}
