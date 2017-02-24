#include<stdlib.h>

#define INFINITY 1000
#define TRUE 1
#define FALSE 0

typedef struct graph{
int vexnum;
int (*arcs)[6];
}MGraph, *graph_ptr;

typedef int ** pathMatrix;
typedef int * shortestPathTable;

static p[6][6] = {0};

void shortestPath_Dijkstra(graph_ptr G, int v_num, int *D)
{
	int final[6] = {0};
	int i = 0;
	int w = 0;
	int v = 0;
	int min = 0;

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
		}
	}

	
	D[v_num] = 0;
	final[v_num] = TRUE;
	
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
		printf("V0到V%d的距离 = %d\n", v, D[v]);


		for(w = 0; w < G->vexnum; w++)
		{
			if(!final[w] && (min + G->arcs[v][w]) < D[w])
			{
				D[w] = min + G->arcs[v][w];
//				p[w] = p[v];
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

//	int matrix_path[6][6] = {0};
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

	shortestPath_Dijkstra(G, 0, matrix_shortestpath)	;
	
	return 0;
}











