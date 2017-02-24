#include<stdio.h>

int main()
{
	int count = 0;
	char array[12] = {'\0'};
	char *ptr = array;
	int i = 0;
	
	scanf("%d", &count);
	while(count--)
	{	
		ptr = array;
		scanf("%s", ptr);
		for(i = 0; *ptr != '\0'; i++, ptr++)
		{
			if(i >= 3 && i <= 6)
			{
				*ptr = '*';
			}
			
		}
		printf("%s\n", array);
	}
	return 0;
}
