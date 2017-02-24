#include<stdio.h>

int main()
{
	int count = 0;
	int sub_num = 0;
	float val_a = 0;
	float val_b = 0;
	
	int sub_num_dup = 0;
	float val_stu = 0.0;
	float val = 0.0;
	char flag = 0;
	while(1)
	{
		scanf("%d", &count);

		while(count--)
		{
			scanf("%d%f%f", &sub_num, &val_a, &val_b);
			
			sub_num_dup = sub_num;

			while(sub_num--)
			{
				scanf("%f", &val_stu);
				if(val_stu < val_b)
				{
					flag = 1;
					continue;
				}
				val += val_stu;
			}
			if((val/sub_num_dup) < val_a || flag == 1)
			{
				printf("No\n");
				flag = 0;
			}
			else if(flag == 0)
			{
				printf("Yes\n");
			}
		}
	}

	return 0;

}
