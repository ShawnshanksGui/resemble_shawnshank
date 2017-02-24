#include<stdio.h>
#include<stdlib.h>

#define INFINITY 1000
#define TRUE 1
#define FALSE 0

typedef struct graph{
int vex_Num;
int (*arcs)[6];
}GRAPH, *graph_ptr;


void shortestPath_Dijkstra(graph_ptr G, int vex_Selected)
{
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
			path[i] = vex_Selected;
		}
		else
		{
			path[i] = -1;
		}
	}
	D[vex_Selected] = 0;

	for(i = 1; i < G->vex_Num; i++)
	{
		min = IFFINTY;
		for(v = 0; v < G->vex_Num; v++)
		{
			if(!final[v] && D[v] <= min)
			{
				min = D[v];
				point_Selected = v;
			}
		}

		final[point_Selected] = TRUE;
		
		///****///
		///****///

		for(w = 0; w < G->vex_Num; w++)
		{
			if(!final[w] && (min + G->arcs[point_Selected][w]) < D[w])
			{
				D[w] = min + G->arcs[point_Selected][w];
				path[w] = point_Selected;
			}

		}
	}

}


int main()
{
	int matrix[][] =
}
