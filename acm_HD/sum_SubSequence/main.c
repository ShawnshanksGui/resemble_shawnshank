#include<stdio.h>

int main()
{
	int count_testCase = 0;
	int count_number = 0;
	int sum_finalSubsequence = 0;
	int temp_sum = 0;
	int currentValue = 0;
//	int startPosition = 0;
//	int endPosition = 0;

	scanf("%d", &count_testCase);
	while(count_testCase--)
	{
		sum_finalSubsequence = 0;
		temp_sum = 0;
	//	this_positon = 1;

		scanf("%d", &count_number);
		while(count_number--)
		{
		//	start = this_positon;

			scanf("%d", &currentValue);
			temp_sum += currentValue;
			if(temp_sum > sum_finalSubsequence)
			{
				sum_finalSubsequence = temp_sum;
			}
			else if(temp_sum < 0)
			{
				temp_sum = 0;
			}
		}
		printf("%d\n", sum_finalSubsequence);
	}

	return 0;
}
