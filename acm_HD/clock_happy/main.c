#include<stdio.h>

int main()
{
	double degree = 0;
	double percent = 0;

	while(1)
	{
		scanf("%lf", &degree);
		if(degree < 0)
		{
			break;
		}
		if(degree >= 120)
		{
			percent = 0.0;
		}
		else
		{
			if(degree < 90)
			{
				percent = ((360.0 - degree * 3) / 360 +
				(360.0 - degree * 4) / 360) * (degree
				/ 360) + (1 - 4 * degree / 360) * (1 - 4 * 
				degree / 360);
			}
			else
			{
				percent = ((360.0 - degree * 3) / 360.0
				 * (degree / 360.0));
			}
		}
		percent *= 100.0;
		printf("%.4lf\n", percent);
	}
	
	return 0;
}
