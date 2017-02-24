#include<stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int array[], int p, int r)
{
	int x = array[r];
	int i = p-1;
	int j = 0;

	for(j = p; j <= r-1; j++)
	{
		if(array[j] <= x)	
		{	
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i+1], &array[r]);
	return i+1;
}

void quick_Sort(int array[], int _left, int _right)
{
	int _mid = 0;

	if(_left >= _right)
	{
		return;
	}
	else
	{
		_mid = partition(array, _left, _right);

		quick_Sort(array, _left, _mid-1);
		quick_Sort(array, _mid+1, _right);
	}
}



int main()
{
	int array[] = {2, 8, 7, 1, 3, 5, 6, 4, 11, 32, 33, 3};

	quick_Sort(array, 0, 11);
	return 0;
}
