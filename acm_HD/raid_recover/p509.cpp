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
/*		for(int i=0;i<b&&!flag;i++)//��ѭ�����ڲ鿴У�����ݿ����Ƿ��д������� 
		{
			pla=s*i;//plaΪУ������ʼλ�� 
			for(int j=0;j<s;j++) if(a[i%d][pla+j]=='x') flag=1;
		}˵�õ�У������أ�������ԭ�����������*/
		for(int i=0;i<b*s&&!flag;i++)
		{
			int count=0;
			int wei=-1;
			int zhi,j=0;
			while(a[j][i]=='x') {count++;wei=j;j++;}
			if(j<d) zhi=a[j][i]=='0'?0:1;
			j++;
			for(j;j<d;j++)//ͳ��ͬһ�����ݳ���ĸ����͸�����֮������ֵ 
			{
				if(a[j][i]=='x')
				{
					count++;
					wei=j;
				}
				else zhi^=(a[j][i]-'0');
			}
			if(count>1) {flag=1;break;}//���ͬ���ϳ�������ĸ�������1�����޷��ָ� 
			if(count==0)//��һ����û�г�������Ϳ����ǵ����ֵ�Ƿ���� 
			{
				if(ero=='E'&&zhi!=0) {flag=1;break;}
				if(ero=='O'&&zhi!=1) {flag=1;break;}
			}
			if(count==1&&wei!=-1)//�����һ�����ݿ��𻵾��޸��� 
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

