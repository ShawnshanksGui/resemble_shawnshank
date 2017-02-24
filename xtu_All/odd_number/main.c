#include<stdio.h>
/*
int main()
{
	int count = 0;
	int odd_num[10] = {0,0};
	int num_a[10][10] = {0, 0};
	char i = 0;
	char k = 0;
	int num_print = 0;

	for(scanf("%d", &count);count != 0; i++  )
	{
		k = 0;
		for(; count > 0; count--,k++)
		{
			scanf("%d", &num_a[i][k]);
			if((num_a[i][k]&0x00000001) != 0)
			{
				odd_num[i]++;
			}
		}
		scanf("%d", &count);
	}
	for(;num_print < i ; num_print++)
	{
		printf("%d\n", odd_num[num_print]);
	}	
	return 0;
}


*/

int main()
{
	int num = 0;
	int count = 0;
	int num_a = 0;

	while(1)
	{
		scanf("%d", &num);

		if(num == 0)
			break;

		for(; num > 0; num-- )
		{
			scanf("%d",&num_a);
			if((num_a & 0x00000001) == 1)
			{
				count ++;
			}
		}
		printf("%d\n", count);
		count = 0;
	}
	return 0;

}
