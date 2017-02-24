#include<stdio.h>
#include<stdlib.h>

#define INFINITY 1000
#define TRUE 1
#define FALSE 0

typedef struct graph{
int vexnum;
int (*arcs)[6];
}MGraph, *graph_ptr;
/*数据结构为带权邻接矩阵*/

typedef int ** pathMatrix;

typedef int * shortestPathTable;

static int p[6][6] = {0};

void shortestPath_Dijkstra(graph_ptr G, int v_num, int *D)
{
	/**final[v] == TRUE时，V属于S，即已求V0到V的最短距离**/
	int final[6] = {0};
	int i = 0;
	int w = 0;
	int v = 0;
	int min = 0;
	int path[6] = {0};
	int pre = 0;

	/*******初始化及设置空路径*******/
	for(v = 0; v < G->vexnum; v++)
	{
		final[v] = FALSE;
		D[v] = G->arcs[v_num][v];

		for(w = 0; w < G->vexnum; w++)
		{
			p[v][w] = FALSE;
		}

		if(D[v] < INFINITY)
		{
			p[v][v_num] = TRUE;
			p[v][v] = TRUE;

			path[v] = v_num;
		}
		else
		{
			path[v] = 0;
		}
	}

	D[v_num] = 0;
	final[v_num] = TRUE;
	
	/*开始主循环，每次求V0到某个顶点的最短路并加入V到S*/
	for(i = 1; i < G->vexnum; ++i)
	{
		min = INFINITY;

		for(w = 0; w < G->vexnum; ++w)
		{
			if(!final[w])
			{
				if(D[w] <= min)
				{
					v = w;
					min = D[w];
				}
			}
		}
		final[v] = TRUE;

		/*打印时依静态链表的存储方式打印*/
		printf("V %d 到V %d 的距离 = %d\n", v_num,  v, D[v]);
		pre = v;
		printf("路径是");
		printf("%d<-", v);
		while(pre)
		{
			printf("%d<-", path[pre]);
			pre = path[pre];
		}
		printf("\n\n");
		/*********************************/

		/*更新当前最短路径及距离*/
		for(w = 0; w < G->vexnum; w++)
		{
			/*修改D[w]和Path[w], w∈ V-S*/
			if(!final[w] && (min + G->arcs[v][w]) < D[w])
			{
				D[w] = min + G->arcs[v][w];
				path[w] = v;
				p[w][w] = TRUE;
			}
		}
	}
}

int main()
{
	int matrix[6][6] = {1000, 1000, 10, 1000, 30, 100,
	1000, 1000, 5, 1000, 1000, 1000,
	1000, 1000, 1000, 50, 1000, 1000,
	1000, 1000, 1000, 1000, 1000, 10,
	1000, 1000, 1000, 20, 1000, 60,
	1000, 1000, 1000, 1000, 1000, 1000};

//	int matrix_path[7][6] = {0};
	int matrix_shortestpath[6] = {0};

	graph_ptr G = (graph_ptr)malloc(sizeof(MGraph));

	if(!G)
	{
		exit(FALSE);
	}
	
	else
	{
		G->vexnum = 6;
		G->arcs = matrix;
	}
		/*求V0到每一个顶点的最短距离，并打印最短距离及路径*/
	shortestPath_Dijkstra(G, 0, matrix_shortestpath)	;
	
	return 0;
}














