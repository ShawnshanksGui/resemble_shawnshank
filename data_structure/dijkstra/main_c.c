#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define INFINITY 1000

typedef struct gragh{
	int (*arcs)[6];
	int vex_Num;
}GRAPH, *graph_ptr;


void shortestPath_Dijkstra(graph_ptr G, int vex_Selected)
{
	int i = 0;
	int v = 0;
	int w = 0;
	int min = 0;
	int pre = 0;
	int point_Selected;
	int D[6] = {0};
	int final[6] = {0};
	int path[6] = {0};

	for(i = 0; i < G->vex_Num; i++)
	{
		D[i] = G->arcs[vex_Selected][i];
		if(i == vex_Selected)
		{
			final[i] = TRUE;
		}
		else
		{
			final[i] = FALSE;
		}

		if(D[i] < INFINITY)
		{
			path[i] = G->vex_Num;
		}
		else
		{
			path[i] = -1;
		}

	}

	D[vex_Selected] = 0;

	for(i = 1; i < G->vex_Num; i++)
	{
		min = INFINITY;
		for(v = 0; v < G->vex_Num; v++)	
		{
			if(!final[v] && D[v] <= min)
			{
				min = D[v];
				point_Selected = v;
			}
		}

		final[point_Selected] = TRUE;

		//******//
		printf("V %d to V %d:%d\n",vex_Selected, point_Selected, D[point_Selected]);
		pre = point_Selected;
		printf("%d<-", point_Selected);
		while(pre)
		{
			printf("%d<-", path[pre]);
			pre = path[pre];
		}
		printf("\n");
		//******//

		for(w = 0; w < G->vex_Num; w++)
		{
			if(!final[w] && (min + G->arcs[point_Selected][w] < D[w]))
			{
				D[w] = min + G->arcs[point_Selected][w];
				path[w] = point_Selected;
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

	//  int matrix_path[7][6] = {0};
	//int matrix_shortestpath[6] = {0};

	graph_ptr G = (graph_ptr)malloc(sizeof(GRAPH));

	if(!G)
	{	
		exit(FALSE);
	}

	else
	{
		G->vex_Num = 6;
		G->arcs = matrix;
	}
	/*求V0到每一个顶点的最短距离，并打印最短距离及路径*/
	shortestPath_Dijkstra(G, 0)    ;

	return 0;

}
