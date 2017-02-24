#include<stdio.h>
int main()
{
    int a=0,n=0;
	    int sn=0,tn=0;
		    printf("a,n=:");
			    scanf("%d,%d",&a,&n);
				    while(n--)
					    {
						        tn=tn+a;
								        sn=sn+tn;
										        a=a*10;
												    }
													    printf("a+aa+aaa+...=%d\n",sn);
														    return 0;
															}




