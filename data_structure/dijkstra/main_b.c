#include<>






void shortestPath_Dijkstra(graph_ptr G, int v_num, int *D)
{
	int final[6] = {0};
	int i = 0;
	int w = 0;
	int v = 0;
	int min = 0;
	int path[6] = {0};
	int pre = 0;

	for(v = 0; v < G->vexnum; v++)
	{
	//	final[v] = FALSE;
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
		else
		{
			path[v] = 0;
		}
	}
	D[v_num] = 0;
	final[v_num] = TRUE;

	for(i = 1; i < G->vexnum; ++i)
	{
		min = INFINTY;

		for(w = 0; w < G->vexnum; ++i)
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
		/********/
		printf();

		/********/
		
		for(w = 0; w < G->vexnum; w++)
		{
			if(!final[w] && (min + G->arcs[v][w]) < D[w])
			{
				D[w] = min + G->arcs[v][w];
				path[w] = v;
				p[w][w] = TRUE;
			}
		}

		for(w = 0; w < G->vexnum; w++)
		{
			if(!final[w] && (min + G->arcs[v][w]) < D[w])
			{
				D[w] = min + G->arcs[v][w];
				path[w] = v;
				p[w][w] = TRUE;
			}
		}

		for(w = 0; w < G->vexnum; w++)
		{
			if( !final[w] && (min + G->arcs[v][w]) < D[w])
			{
				D[w] = min + arcs[v][w];
				path[w] = v;
				p[w][w] = TRUE;
			}
		}
	}
}






