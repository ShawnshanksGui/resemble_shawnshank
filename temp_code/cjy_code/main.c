#include<stdio.h>


int main()
{
	signed long int a,b;
	int m = 0;
	signed long int sum;

	printf("please scanf:");
	scanf("%d", &m);

    while(m--)
	{
		printf("please scanf data:");
		scanf("%lx %lx", &a, &b);
		//sum = 
	//	if((a+b) >= 0)
	//	{
			printf("%lx\n", a+b);	
	//	}
	/*	else
		{
			if(a < 0 && b >=0)
			{
				sum = (-a) - b;
				printf("%lx\n", sum);
			}
		}*/
	}
}
