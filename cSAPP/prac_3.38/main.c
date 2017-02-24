/********************************
author : shawnshanks fei
data : 09.02.2016
aim:take a test of a diffrent way to use typedef to make argument of 
multi-dimensional array, and compare the normal way of pass arguments to function
with the current way
********************************/
#include<stdio.h>
#include<stdlib.h>

#define N 6

typedef int fix_matrix[N][N];
/*
int main()
{
	fix_matrix array = {0};
	
	return 0;
}*/

//void fix_set_diag(fix_matrix array, int val);
void fix_set_diag(int (*ptr)[N], int val);

int main()
{
	fix_matrix array = {{0}};//definition of array is not eaqual to pointer of two demensional pointer
	int (*ptr)[N] = array;

	int val = 1000;

/*	while(!array = (fix_matrix)malloc(sizeof(array)))
	{
		exit(1);
	}
*/
	//array = 0;
//	fix_set_diag(array, val);
	fix_set_diag(array, val);

	return 0;
}

//void fix_set_diag(fix_matrix array, int val)
void fix_set_diag(int (*ptr)[N], int val)
{
	int i = 0;

	for(i = 0; i < N; i++)
	{
		ptr[i][i] = val;
	}
}
