#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
int weight;
int parent;
int lchild;
int rchild;
}HTnode, *HuffmanTree;

typedef char ** HuffmanCode;

void select_a(HuffmanTree HT, int *flag, int i, int *s1, int *s2)
{
	int smallest = 100;
	int secondary= 100;
	int j = i;

	for(; i >= 1; i--)
	{
		if(flag[i] == 0 && HT[i].weight < smallest)
		{
			smallest = HT[i].weight;
			*s1 = i;
		}
	}
	/*先选择最小的*/

	for(; j >= 1; j--)
	{
		if(j != *s1)
		{
			if(flag[j] == 0 && secondary > HT[i].weight)
			{
				secondary = HT[i].weight;
				*s2 = j;
			}
		}
	}		/*再选次小的*/
	flag[*s1] = 1;
	flag[*s2] = 1;
}

HuffmanCode HuffmanCoding(HuffmanCode HC, int *w, int n)
{
	int m = 0;
	int start = 0;
	int c = 0;
	int i = 0;
	int f = 0;
	int s1 = 0;
	int s2 = 0;
	int temp = 0;
	HuffmanTree p = NULL;
	int flag[8] = {0};
	HuffmanTree HT[8] = {NULL};
/*	HTnode HT[8] = {0,0,0,0,7,0,0,0,5,0,0,0,2,0,0,0,4,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0};  //初始化//
*/
	if(n <= 1)
	{
		return;
	}

	m = 2 * n - 1;

	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTnode));

	for(p = HT, i = 1; i <= n; ++i, p++, w++)
	{
	//	*p = {*w, 0, 0, 0};
		p[i] = {*w, 0, 0, 0};
	//	p[i].weight = *w;
	//	p[i].lchild = p[i].rchild = p[i].parent = 0;
	}


	for(; i <= m; i++, p++)
	{
		*p = {0, 0, 0, 0};
	//	p[i].weight = p[i].lchild = p[i].rchild = p[i].parent = 0;
	}

	
	for(i = n + 1; i <= m; i++)
	{
		temp = i - 1;
		select_a(HT, flag, temp, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	/****/
//	HC = (HuffmanCode)malloc((n+1) * sizeof(char *));

	char *cd = (char *)malloc(n * sizeof(char));
	//分配n个字符串编码的头指正向量//
	cd[n - 1] = '\0'; //编码结束符
	/**/

	for(i = 1; i <= n; i++)
	{
		start = n - 1;
		for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if(HT[f].lchild == c)
			{
				cd[--start] = '0';//编码结束符//
			}
			else
			{
				cd[--start] = '1';
			}
		}

		HC[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);//释放内存空间//

	return HC;
}

int main()
{
	int i = 1;
	char a = 'A';
//	HuffmanTree HT = NULL;
	HuffmanCode HC = (char **)malloc(5 * sizeof(char *));
	int array[4] = {7, 5, 2, 4};

	HC = HuffmanCoding(HC, array, 4);

	printf("huffman编码如下：\n");
	for(; i <= 4; i++)
	{
		printf("%c:   %s\n", a++, HC[i]);
	}
//	print_code(HC);
	return 0;

}








