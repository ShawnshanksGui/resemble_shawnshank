#include<stdio.h>
#include<math.h>

typedef unsigned int uint;

void prime_judge(uint val)
{
	uint i = 1;
	uint num_a = 1;
	uint ss = 1;

	if(val == 2)
	{
		printf("yes\n");
	}
	else if(val == 1 || (val & 0x01) == 0)
	{
		printf("No\n");
	}

	else
	{
		ss = sqrt(val);

		for(i = 2; i <= ss ; i++)
		{
			if((val % i) == 0)
			{
				printf("no\n");
				break;
			}
		}
	/*
		while(ss--)
		{
			if((val % ss) == 0 && ss != 1)
			{
				printf("no\n");
				break;
			}
		}
	*/
		if(i > ss)
		{
			printf("Yes\n");
		}
	}
	
}

/*int main()
{
	uint num_a[100] = {0, 0, 0};
	char i = 0;
	char count = 0;

	scanf("%d", &num_a[i]);

	for(; num_a[i] != 0; )
	{	
		i++;
		scanf("%d", &num_a[i]);
	}
	count = i; 
	i = 0;
	
	for(; i <= count; count--)
	{
		prime_judge(num_a[i]);
	}
	return 0;
}
*/
int main()
{
	    uint num_a = 0;
	    char i = 0;

	    scanf("%u", &num_a);

		for(; num_a != 0; )
		{
			i++;
			prime_judge(num_a);
			scanf("%u", &num_a);
		}
		
		return 0;
	
}
