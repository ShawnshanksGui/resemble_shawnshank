#include<stdio.h>
#include<math.h>
#include<string.h>

int E[10][31] = {0};
double M[10][31] = {0.0};

void find_match(double , int);

int main()
{
	int i = 0;
	int k = 0;
	int e = 0.0;
	double m = 0.0;
	double t = 0.0;
	double c = 0.0;
	
	char array[50] = {'\0'};
	char *ptr = NULL;

	freopen("datain.txt", "r", stdin);
	freopen("dataout.txt", "w", stdout);

	for(k = 0; k <= 9; k++) // reserved first bit//
		for(i = 1; i <= 30; i++)
		{
			e = (1 << i) - 1;    
			m = 1.0 - 1.0 / (1 << (k+1)); // 
			t = log10(m) + e * log10(2.0);
		    E[k][i]  = t / 1;      ///Round down///
			M[k][i] = pow(10, (t - E[k][i]));
		}
	while(1)
	{
		scanf("%s", array);
		if(strcmp(array, "0e0") == 0)
		{
			break;
		}

		ptr = strchr(array, 'e');
		*ptr = ' ';
		sscanf(array, "%lf%d", &m, &e);
		find_match(m, e);

		memset(array, '\0', sizeof(array));
	}

	return 0;	
}


void find_match(double m, int e)
{
	int k = 0;
	int i = 0;
	double tolerance = pow(10,-5);

	for(k = 0; k <= 9; k++)
		for(i = 1; i <= 30; i++)
		{
			if((E[k][i] == e) && ((fabs(m - M[k][i])) < tolerance))
			{
				printf("%d  %d\n", k, i);
			}
		}
}
