#include<stdio.h>

void sort_insertion(int *, int);

int main()
{
	int i = 0;
	int count = 0;
	int array[20] = {0};

	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &array[i++]);
	}
	sort_insertion(array, i);
	
	for(count = 0; count < i; count++)
	{
		printf("%d  ", array[count]);
	}
	printf("\n");

	return 0;
}


void sort_insertion(int array[], int len)
{
	int i = 0;
	int ii = 0;
	int k = 0;
	int temp = 0;

	for(i = 1; i < len; i++)
	{
		for(k = i - 1, ii = i; k >= 0; k--)
		{

			if(array[k] > array[ii])
			{
				temp = array[ii];
				array[ii] = array[k];
				array[k] = temp;
				ii = k;
			}
		}
	}
}
