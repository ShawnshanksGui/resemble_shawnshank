#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x   = *y;
	*y   = temp;
}

void max_Heapify(int array[], int i, int len)
{
	int heap_size = len;
	int largest = i;
//	int largest = 0;	
	int _right = i * 2 + 1;
	int _left  = i * 2;

	if(_left <= heap_size && array[largest] < array[_left])
	{
		largest = _left;
	}
/*	else
	{
		largest = i;
	}
*/
	if(_right <= heap_size && array[largest] < array[_right]) 
	{
		largest = _right;
	}
	if(largest != i)
	{
		swap(&array[largest], &array[i]);
		max_Heapify(array, largest, heap_size);
	}
}

void build_Maxheap(int array[], int len)
{
	int i = 0;
	int heap_size = len;

	for(i = len / 2; i >= 1; i--)
	{
		max_Heapify(array, i, heap_size);
	}
}


void heap_Sort(int array[], int len)
{
	int i = 0;
	int heap_size = len;
	build_Maxheap(array, len);

	for(i = len; i >= 2; i--)
	{
		swap(&array[1], &array[i]);
		heap_size--;
		max_Heapify(array, 1, heap_size);
	}
}



int main()
{
	int array[]={0,14,10,8,7,9,3,2,4,1};
	int len = 9;
	heap_Sort(array, len);

	return 0;
}
