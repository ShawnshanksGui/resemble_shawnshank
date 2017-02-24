#include<stdio.h>
#include<math.h>

double f(double x); 

int main()
{	
	double n = 0;
	scanf("%lf",&n);
	double t;	
	t=f(n);
	printf("%.5lf",t);

	return 0;

} 

double f(double x)
{
	int i;
	double y=1;
	double z=0;
	
	//double temp = 1.0/x;
 	
	for(i=1;y > 1e-6;i++)  //循环一次z加上第一项 
	{
		z=z+y;
		y=pow(1/x,i);  
	 //  y = 1/pow(x, i);
    }
	return z;   
} 

