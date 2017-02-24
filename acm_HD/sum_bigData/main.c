#include<stdio.h>
#include<string.h>

void sum_Bigdata(char *, char *);
void reverse(char *);

int main()
{
	char array_A[1000] = {'\0'};
	char array_B[1000] = {'\0'};
	char *ptr_a = array_A;
	char *ptr_b = array_B;
	
	scanf("%s %s", ptr_a, ptr_b);

	sum_Bigdata(ptr_a, ptr_b);
//	reverse(ptr_a);

	printf("%s\n", ptr_a);

	return 0;
}

void reverse(char array[])
{
	int i = 0;
	int k = strlen(array) - 1;
	char temp = '\0';

	for(i = 0; i < k; i++, k--)
	{
		temp = array[i];
		array[i] = array[k];
		array[k] = temp;
	}
}

void sum_Bigdata(char *str_a, char *str_b)
{
	int sum_TwoLetter = 0;
	int carry = 0;
	char *ptr_a = str_a;
	char *ptr_b = str_b;
	reverse(ptr_a);
	reverse(ptr_b);
	
	for( ; *ptr_a != '\0' && *ptr_b != '\0'; ptr_a++, ptr_b++)
	{
		sum_TwoLetter = (*ptr_a - '0') + (*ptr_b - '0') + carry;
		carry = sum_TwoLetter / 10;
		*ptr_a = (sum_TwoLetter % 10) + '0';
	}
	if(*ptr_a == '\0')
	{
		while(*ptr_b != '\0')
		{
			sum_TwoLetter = (*ptr_b - '0') + carry;
			carry = sum_TwoLetter / 10;
			*ptr_a++ = (sum_TwoLetter % 10) + '0';
			ptr_b++;
		}
	}
	else
	{
		while(*ptr_a != '\0')
		{
			sum_TwoLetter = (*ptr_a - '0') + carry;
			carry = sum_TwoLetter / 10;
			*ptr_a = (sum_TwoLetter % 10) + '0';
			ptr_a++;
		}
	}
	if(carry)
	{
		*ptr_a = carry + '0';
	}
	reverse(str_a);
}
