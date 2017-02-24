#include<stdio.h>

#define IS_VALID 1
#define IS_INVALID 0

int judge_matrix(char (*a)[10000], int , int , char );
void print_HexVal_storaged(char (*a)[10000], int , int , int );

int main()
{
	int d = 0;
	int s = 0;
	int b = 0;
    char matrix[10][10000];

	int i = 0;
	int thisNumber_disk = 0;
	int column = 0;
	char is_evenOrOdd = '\0';

	freopen("datain.txt", "r", stdin);
	freopen("dataout.txt", "w", stdout);
	
//	char Is_evenOrOdd = '\0';
	while(1)
	{
		scanf("%d", &d);
		if(d == 0)
		{
			break;
		}
		scanf("%d %d", &s, &b);
		getchar();
		scanf("%c", &is_evenOrOdd);
		for(i = 0; i < d; i++)
		{
			scanf("%s", matrix[i]);
		}
		//above is argument of Output!!!!!
		thisNumber_disk++;
		column = s * b;
		if(judge_matrix(matrix, d, column, is_evenOrOdd) == IS_VALID)  /// !!!!!///agument fault//////
		{
			printf("Disk set %d is valid, contents are", thisNumber_disk);
			print_HexVal_storaged(matrix, d, s, b);
		}
		else
		{
			printf("Disk set %d is invalid.\n", thisNumber_disk);
		}
	}

	return 0;
}

int judge_matrix(char (*a)[10000], int d, int column, char is_evenOrOdd)
{
	int position_x = 0;
	int count_x = 0;
//	int column = 0;
	int line = 0;
	int i = 0;
	int key_value = 0;
//	column = s * b;

	for(i = 0; i < column; i++)
	{
		count_x = 0;
		position_x = -1;

		while(a[line][i] == 'x')
		{
			count_x++;
			if(count_x > 1)
			{
				return IS_INVALID;
			}
			position_x = line;
			line++;
		}
		if(line < d)
		{
			key_value = a[line][i] - '0'; ///???
		}
		line++;
	//**Core code: using parity check to judge**//
		for(; line < d; line++)
		{
			if(a[line][i] == 'x')
			{
				count_x++;
				position_x = line;
			}
			else
			{	
				key_value ^= (a[line][i] - '0');
			}
		}
	/////////////////****////////////////////
		if(count_x > 1)
		{	
			return IS_INVALID; ////IS NOT VALID!!!!!
		}
		else
		{
			if(count_x == 0)
			{
				if(is_evenOrOdd == 'E' && key_value != 0)
				{	
					return IS_INVALID;
				}
				else if(is_evenOrOdd == 'O' && key_value != 1)
				{	
					return IS_INVALID;
				}
			}

			///////*****data recover****///////
			else if(count_x == 1 && position_x != -1)
			{
				if(is_evenOrOdd == 'E')
				{
					a[position_x][i] = key_value + '0';
				}
				else
				{
					a[position_x][i] = (key_value ^ 1)+ '0';
				}
			}
		}
	}
	
	return IS_VALID;
}

void print_HexVal_storaged(char (*a)[10000], int d, int s, int b)
{
	int hex_value = 0;
	int weight = 8;
	int t = 0;
	int i = 0;
	int j = 0;
	int pla = 0;

	for(t = 0; t < b; t++)
	{
		for(i = 0; i < d; i++)
		{
			if(i == (t %d))
			{
				continue;
			}
			pla = t * s;
			for(j = pla; j < pla+s; j++)
			{
				if(weight == 0)
				{
					weight = 8;
					printf("%X", hex_value);
					hex_value = 0;
				}
				hex_value += (a[i][j] - '0') * weight;
				weight /= 2;
			}
		}
	}
	printf("%X\n", hex_value);
}
