#include<stdio.h>
#include<string.h>

void knapsack(int (*temp)[11], int weight[], int value[], int sum_wei, int sum_val);
void knapsack_reverse_sequenceOf_i(int (*temp)[11], int weight[], int value[], int sum_wei, int sum_amount);
void knapsack_a(int temp_a[], int weight[], int value[], int sum_wei, int sum_val);

void knapsack_complete(int temp[], int weight[], int value[], int sum_wei, int sum_amount);

int main()
{
	int value[6] = {0};
	int weight[11] = {0};
	int temp[11][11] = {0};
	int temp_a[11] = {0};

	int i = 0;

	for(i = 1; i <= 5; i++)
	{
		scanf("%d %d", &value[i], &weight[i]);
	}
	
//	knapsack(temp_a, weight, value, 10, 5);	

//	knapsack_a(temp_a, weight, value, 10, 5);
	
	knapsack_complete(temp_a, weight, value, 10, 5);

//	printf("%d\n", temp[5][10]);

	printf("%d\n", temp_a[10]);

/****************************************/
	memset(temp_a, '\0', 11);
	
	knapsack_reverse_sequenceOf_i(temp, weight, value, 10, 5);
	printf("%d\n", temp[5][10]);
/****************************************/

	return 0;
}


void knapsack(int (*temp)[11], int weight[], int value[], int sum_wei, int sum_amount)
{
	int i = 0;
	int k = 0;

	for(k = 1; k <= sum_amount; k ++)
	{
		for(i = 1; i <= sum_wei; i++)
//		for(i = sum_wei; i >= 1; i--)
		{
			if(weight[k] <=  i && (temp[k-1][i-weight[k]] + value[k]) > temp[k-1][i])
			{
				temp[k][i] = temp[k-1][i-weight[k]] + value[k];
			}
			else
				temp[k][i] = temp[k-1][i];
		}
	}
}


/********************************************/
void knapsack_reverse_sequenceOf_i(int (*temp)[11], int weight[], int value[], int sum_wei, int sum_amount)
{
    int i = 0;
	    int k = 0;

		    for(k = 1; k <= sum_amount; k ++)
			    {
				        for(i = sum_wei; i >= 1; i--)
						//      for(i = sum_wei; i >= 1; i--)
						        {
								            if(weight[k] <=  i && (temp[k-1][i-weight[k]] + value[k]) > temp[k-1][i])
											            {
														                temp[k][i] = temp[k-1][i-weight[k]] + value[k];
																		            }
																					            else
																								                temp[k][i] = temp[k-1][i];
																												        }
																														    }
																															}
/********************************************/

void knapsack_a(int temp[], int weight[], int value[], int sum_wei, int sum_amount)
{
	int k = 0;
	int i = 0;

	for(k = 1; k <= sum_amount; k++)
	//	for(i = 1; i <= sum_wei; i++)
		for(i = sum_wei; i >= 1; i--)
		{
			if((weight[k] <= i) && (temp[i-weight[k]] + value[k]) > temp[i]) //replace a two-demensional array
																			 //with a one-demensional array
			{
				temp[i] = temp[i-weight[k]] + value[k];
			}
		}
	//printf("%d\n", temp[10]);
}

//*************************//
// writen in: 2017.01.05
// author: shawnshanks fei
//beiBao wen ti knapsack complete //
//*************************//


void knapsack_complete(int temp[], int weight[], int value[], int sum_wei, int sum_amount)
{
	int i = 0;
	int k = 0;

	for(i = 1; i <= sum_wei; i++)
		for(k = 1; k <= sum_amount; k++)
		{
			if((weight[k] <= i) && (temp[i-weight[k]] + value[k]) > temp[i])
			{
				temp[i] = temp[i-weight[k]] + value[k];
			}
		}
}

