#include<stdio.h>

#define MAXN 1000
#define MAXC 10000

int weight[MAXN] = {0};
int val[MAXN] = {0};
int d[MAXN][MAXC] = {0};

int main()
{
	int n = 0;
	int c = 0;
	int i = 0;
	int j = 0;
	int path[100] = {0};

	while(1)
	{
		scanf("%d%d", &n, &c);

		for(i = 0; i < n; ++i)
		{
			for(j = 0; j <=c; j++)
			{
				if(i == 0)
				{
					d[i][j] = 0;
				}
				else
				{
					d[i][j] = d[i-1][j];
					if(j >= weight[i-1])
					{
						if((d[i-1][j-weight[i-1]] + val[i-1])
						   > d[i-1][j])
						{
							d[i][j] = d[i-1][j-weight[i-1]] + val[i-1];
						}
					}
				}
			}
		}
		j = c;
	}
}
