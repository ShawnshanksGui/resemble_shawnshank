#include<stdio.h>

int main()
{
//	int array[5] = {0};
//	int k = 0;	
//	int *ptr = NULL;

//	ptr = &array[1];
	
//	printf("%d\n", sizeof(array));
//	printf("%d\n", sizeof(array[5]));

//	char ch = 10;
	char *ptr = (char *)0x7fffffffdc37; 
	*ptr = NULL;

	ptr = NULL;
	return 0;
}
