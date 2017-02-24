#include<stdio.h>

void print_Min(char a, char b, char c);

int main()
{
	char c = '\0';
	char count_x = 0;
	char count_t = 0;
	char count_u = 0;

	while(1)
	{
		count_x = 0;
		count_t = 0;
		count_u = 0;
		while((c = getchar()) != '\n')
		{
			if(c == 'X')
			{
				count_x++;
			}
			else if(c == 'T')
			{
				count_t++;
			}
			else if(c == 'U')
			{
				count_u++;
			}
		}
		print_Min(count_x, count_t, count_u);
	}
	
	
	return 0;

}


void print_Min(char a, char b, char c)
{
	if(a <= b)
	{
		if(a <= c)
			printf("%d\n", a);
		else
		{
			printf("%d\n", c);
		}
	}
	else
	{
		if(b <= c)
			printf("%d\n", b);
		else
		{
			printf("%d\n", c);
		}
	}
}
