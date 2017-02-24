#include<stdio.h>
#include<stdlib.h>

void matrix_Change_A(int size , int a, int b)
{
	int column = 1;
	int row = 1;
	int num = 1;

	for(row = 1; row <= size; row++)
	{
		for(column = 1; column <= size; column++)
		{
			if(row == (a - b))
			{
				printf("%d ", num + b * size);
				num++;
			}
			else if(row == a)
			{
				printf("%d ", num - b * size);
				num ++;
			}
			else
			{
				printf("%d ", num++);
			}
		}
	}
	printf("\n");
}

void matrix_Change_B(int size, int a, int b)
{
	int column = 1;
	int row = 1;
	int num = 1;

	for(row = 1; row <= size; row++)
	{
		for(column = 1; column <= size; column++)
		{
			if(row == (a + b))
			{
				printf("%d ", num - b * size);
				num++;
			}
			else if(row == a)
			{
				printf("%d ", num + b * size);
				num ++;	
			}
			else
			{
				printf("%d ", num++);
			}
		}
	}
	printf("\n");
}

void matrix_Change_C(int size, int a, int b)
{
	int num	= 1;
	int column  = 1;
	int row = 1;

	for(row = 1; row <= size; row++)
	{
		for(column = 1; column <= size; column++)
		{
			if(column == a)
			{
				printf("%d ", num - b);
				num ++;
			}
			else if(column == (a - b))
			{
				printf("%d ", num + b);
				num++;
			}
			else
			{
				printf("%d ", num++);
			}
		}
	}
	printf("\n");
}

void matrix_Change_D(int size, int a, int b)
{
	int num = 1;
	int column = 1;
	int row = 1;
	for(row = 1; row <= size; row++)
	{
		for(column = 1; column <= size; column++)
		{	
			if(column == a)
			{
				printf("%d ", num + b);
				num++;
			}
			else if(column == (a + b))
			{
				printf("%d ", num - b);
				num++;
			}
			else
			{
				printf("%d ", num++);
			}
		}
	}
	printf("\n");
}

int main()
{
	int size_matrix = 0;
	char imp_dir = '\0';
	int num_a = 0;
	int num_b = 0;

	scanf("%d", &size_matrix);

	while(1)
	{
		scanf("%c", &imp_dir);
		scanf("%d%d", &num_a, &num_b);

		if(imp_dir == 'U')
		{
			matrix_Change_A(size_matrix, num_a, num_b);
		}
		else if(imp_dir == 'D')
		{
			matrix_Change_B(size_matrix, num_a, num_b);
		}
		else if(imp_dir == 'L')
		{
			matrix_Change_C(size_matrix, num_a, num_b);
		}
		else if(imp_dir == 'R')
		{
			matrix_Change_D(size_matrix, num_a, num_b);
		}
	}
	return 0;
}
