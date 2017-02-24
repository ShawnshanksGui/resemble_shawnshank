#include<stdio.h>
#include<stdlib.h>

int rand7()
{
	return  rand() % 7 + 1;
}

int rand10()
{
	int a71 = 0;
	int a72 = 0;
	int a10 = 0;

//	while(a10 >= 40)
	do
	{
		a71 = rand7() - 1;
		a72 = rand7() - 1;
		a10 = a71 * 7 + a72;
	}while(a10 >= 40);

	return (a71 * 7 + a72) / 4 + 1;
}


int main()
{
	char c = '\0';
	printf("%d\n", rand() % 7 + 1);
//	printf("%d\n", rand7());

	while(1)
	{
		while((c = getchar()) != EOF)
		{
			printf("%d\n",rand10());
		}
		break;
	}
	
	return 0;
}
