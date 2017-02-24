#include<stdio.h>
char a[10][10000];
int main()
{
	freopen("datain.txt","r",stdin);
	freopen("dataout.txt","w",stdout);
	int d,s,b,pla,flag,tj=0;
	char ero;
	while(scanf("%d%d%d",&d,&s,&b)==3&&d)
	{
		getchar();
		tj++;
		flag=0;
		scanf("%c",&ero);
		for(int i=0;i<d;i++) scanf("%s",a[i]);
/*		for(int i=0;i<b&&!flag;i++)//此循环意在查看校验数据块中是否有错误区域 
		{
			pla=s*i;//pla为校验块的起始位置 
			for(int j=0;j<s;j++) if(a[i%d][pla+j]=='x') flag=1;
		}说好的校验块检测呢！！！！原来是我想多了*/
		for(int i=0;i<b*s&&!flag;i++)
		{
			int count=0;
			int wei=-1;
			int zhi,j=0;
			while(a[j][i]=='x') {count++;wei=j;j++;}
			if(j<d) zhi=a[j][i]=='0'?0:1;
			j++;
			for(j;j<d;j++)//统计同一列数据出错的个数和各数据之间的异或值 
			{
				if(a[j][i]=='x')
				{
					count++;
					wei=j;
				}
				else zhi^=(a[j][i]-'0');
			}
			if(count>1) {flag=1;break;}//如果同列上出错区域的个数大于1个则无法恢复 
			if(count==0)//若一列中没有出错区域就看他们的异或值是否合适 
			{
				if(ero=='E'&&zhi!=0) {flag=1;break;}
				if(ero=='O'&&zhi!=1) {flag=1;break;}
			}
			if(count==1&&wei!=-1)//如果有一个数据块损坏就修复好 
			{
				if(ero=='E') a[wei][i]=zhi+'0';
				else a[wei][i]=zhi^1+'0';
			}
		}
		if(flag==1)
		{
			printf("Disk set %d is invalid.\n",tj);
			continue;
		}
		else
		{
			printf("Disk set %d is valid, contents are: ",tj);
			int count=0;
			int wt=8;
			for(int t=0;t<b;t++)
			{
				for(int i=0;i<d;i++)
				{
					if(i==t%d) continue;
					pla=t*s;
					for(int j=pla;j<pla+s;j++)
					{
						if(wt==0)
						{
							wt=8;
							printf("%X",count);
							count=0;
						}
						count+=(a[i][j]-'0')*wt;
						wt/=2;
					}
				}
			}
			printf("%X\n",count);
		}
	}
	return 0;
}

