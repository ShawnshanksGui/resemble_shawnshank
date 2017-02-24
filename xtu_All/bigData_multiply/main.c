#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char str_Len(char *ptr)
{
	char count = 0;
	for(; *ptr != '\0'; ptr++)
	{
		count ++;
	}

	count++;
	
	return count;
} 
/*
char *str_Reverse(char *ptr)
{
	char *ptr_temp = ptr;
	char count = 0;

	for(; *ptr != '\0'; count++, ptr ++);  //没刹住车到了'\0'//
	ptr--;						  //往回退一个地址//			
	
	for(; count >= 0; ptr--, ptr_temp++, count--)
	{
		*ptr_temp = *ptr;
	}

	return ptr_temp;
}
*/

void str_Reverse(char *ptr)
{
//	char *array = ptr;
	char i = 0;
	char j = 0;
	char mid = 0;
	char temp = 0;
//	for(; ptr[i] != '\0'; i++);
//	i--;
	i = str_Len(ptr) - 1;   //抵消'\0'的影响//
	mid = i / 2;
	i--;                 

	for(; i >= mid; i--, j++)
	{
		temp = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = temp;
	}
//	return ptr;
}

void strNumChar_Transfer(char *ptr)
{
	for(; *ptr != '\0'; ptr++)
	{
		*ptr += 48;
	}
}

char strLen_Cmp(char *ptr_a, char *ptr_b)
{
	if(str_Len(ptr_a) >= str_Len(ptr_b))
	{
		return (str_Len(ptr_a) + 1);
	}
	else
	{
		return (str_Len(ptr_b + 1));
	}
}

void str_Addzero(char *ptr)
{
	for(;*ptr != '\0'; ptr++);
	
	*ptr++ = '0';
	*ptr = '\0';
}

char *bigdata_Mul(char *ptr_a, char *ptr_b)
{
	char count = 0;
	char count_a = 0;
	char *ptrB_dup = NULL;
	char carry_a = 0;
	char carry_b = 0;
	char *ptr_ret = (char *)malloc(str_Len(ptr_a) + str_Len(ptr_b));
	char *ptr_temp = (char *)malloc(strLen_Cmp(ptr_a, ptr_b));
	char *ptr_ret_a = ptr_ret;
	char *ptr_temp_a = ptr_temp;
	char add_result = 0;

//	char len = 0;
	assert(ptr_temp);     //假设ptr_temp分配成功//

	str_Reverse(ptr_a);
	str_Reverse(ptr_b);
	ptrB_dup = ptr_b;

	for(; *ptr_a != '\0'; ptr_a++)
	{
		for(carry_a = 0, ptr_b = ptrB_dup, ptr_temp = ptr_temp_a;
		*ptr_b != '\0'; ptr_b++, ptr_temp++)
		{
			*ptr_temp = ((*ptr_a - '0') * (*ptr_b - '0')
			+ carry_a) % 10 + 48;
			carry_a = ((*ptr_a - '0') * (*ptr_b - '0'
			) + carry_a) / 10;
		}
		if(carry_a)
		{
			*ptr_temp++ = carry_a + 48;
		}
		
		*ptr_temp = '\0';
	
		/*以上是计算乘数与当前被乘数的一位（从低到高一次遍历），
		所得结果不过结果为逆序*/
	
		ptr_temp = ptr_temp_a;       //这就是用指针不好的地方，操作偶尔比较麻烦，难看懂//
//		strNumChar_transfer(ptr_temp);
		if(count++ >= 1)
		{
			count_a = count - 1;

			str_Reverse(ptr_temp);
			while(count_a--)
			{
				str_Addzero(ptr_temp);
			}								//这几行为加零操作，相当于实际数字乘以10//
			str_Reverse(ptr_temp);
		}
				/*以上是加零（实则为乘以10的count_a次方）*/

						/*以上为一部分 以下为一部分*/

		for(carry_b = 0, ptr_ret = ptr_ret_a; *ptr_temp != '\0'; ptr_temp++, ptr_ret++)  //字符的顺序不对//
		{
			if(*ptr_ret)
			{
				add_result = (*ptr_ret - '0') + (*ptr_temp - '0') + carry_b;
			//	*ptr_ret = ((*ptr_ret - '0') + (*ptr_temp - '0') + carry_b) % 10 + 48;
			//	carry_b = ((*ptr_ret - '0') + (*ptr_temp - '0') + carry_b) / 10;

				*ptr_ret = add_result % 10 + 48;
				carry_b = add_result / 10;
			}
			else
			{
				add_result = *ptr_temp - '0' + carry_b;
				*ptr_ret = add_result + 48;
				carry_b = add_result / 10;
			}
		}/*以上是计算乘数与当前被乘数的一位（从低到高一次遍历），所得结果
		                不过结果为逆序*/

		if(carry_b)	
		{
			*ptr_ret++ = '1';
		}
		*ptr_ret = '\0';
	}	
	
//	strNumChar_change(ptr_ret_a);
	str_Reverse(ptr_ret_a);

	return ptr_ret_a;
}

/*
char *multiply(char *data_a, char *data_b)
{
	char *ptr_a = data_a;
	char *ptr_b = data_b;
	
	char  
	for()

}
*/

int main()
{	
	char array_a[100] ={'\0'};
	char array_val[100] = {'\0'};
	char *ptr_a = array_a;
	char *ptr_b = array_val;

	scanf("%s%s", ptr_a, ptr_b);
	printf("%s\n",bigdata_Mul(ptr_a, ptr_b));

//	printf("%s\n", ptr_b);
//	for(; ptr_b != '\0'; ptr_b++)
//	{
//		printf("%d", *ptr_b);
//	}
/*
	for(; ptr_b != '\0'; ptr_b ++)
	{	
		
		for(carry = 0; ptr_a != '\0'; i++, ptr_a++)
		{
			array_a[i] = ((*ptr_a - '0') * (*ptr_b - '0') % 10) + carry;     //当前结果加上进位制//

			carry = (*ptr_a - '0') * (*ptr_b - '0') / 10;         //刷新进位值//
			
		}


	}

*/
	return 0;


}



