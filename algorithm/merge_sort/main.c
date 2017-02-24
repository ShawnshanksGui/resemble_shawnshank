#include<stdio.h>

void merge_array(int a[], int first, int mid, int last, int temp[]);

void merge_sort(int a[], int first, int last, int temp[]);


int main()
{
	int array[4] ={0};
	int temp[4] = {0};

	scanf("%d%d%d%d",&array[0], &array[1], &array[2], &array[3]);
	
//	merge_array(array, 0, 1, 3, temp);
	merge_sort(array, 0, 3, temp);
	return 0;
}

void merge_array(int a[], int first, int mid, int last, int temp[])
{
	int i = first;
	int j = mid + 1;

	int k = 0;

//	int m = mid;
//	int n = last;

	while(i <= mid && j <= last)
	{
		if(a[i] > a[j])
		{
			temp[k++] = a[j++];
		}
		else
		{
			temp[k++] = a[i++];
		}
	}

	while(i <= mid)
	{
		temp[k++] = a[i++];
	}

	while(j <= last)
	{
		temp[k++] = a[j++];
	}

	for(i = 0; i < k; i++)
	{
		a[first + i] = temp[i];
	}

}

void merge_sort(int a[], int first, int last, int temp[])
{
	int mid = 0;

	if(first < last)
	{
		mid = (first + last) / 2;
	
		merge_sort(a, first, mid, temp);
		merge_sort(a, mid+1, last, temp);

		merge_array(a, first, mid, last, temp);
	}
}
