#include<stdio.h>
#include<math.h>

typedef unsigned int uint;

int main()
{
	uint num_a = 1;
	uint ss = 1;
	uint i = 1;

	while(1)
	{	
		scanf("%u",&num_a);

		if(num_a == 0)
		{
			break;
		}
		else if(num_a == 2)
		{
			printf("Yes\n");
		}
		else if(num_a == 1 || (num_a & 0x01) == 0)
		{
			printf("No\n");
		}
		else
		{
			ss = sqrt(num_a);

			for(i = 2; i <= ss; i++)
			{
				if((num_a % i) == 0)
				{
					printf("No\n");
					break;
				}
			}
			if(i > ss)
			{
				printf("Yes\n");
			}
		}
	}

	return 0;
}

