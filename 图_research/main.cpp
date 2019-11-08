#include <stdio.h>
#include "Graph_List.h"
#include "Graph_Matrix.h"
#include "Output.h"
#include "Head.h"

int main_GaphList()
//int main()
{
	const int edge_num = 3;
	int edge[edge_num][2] = { {1, 2}, {3, 4}, {5,6} };

	const int vertex_num = 6;
	int vertex[vertex_num] = { 1,2,3,4,5,6 };
	
	for (int i = 0; i < edge_num; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d; ", edge[i][j]);
		}
		printf("\n");
	}

	Graph* G = (Graph*)malloc(sizeof(Graph));// = (G)malloc(sizeof(VerNode));
	CreateGraphList(G, vertex_num, edge_num, vertex, edge);

	char name[40] = "1.dot";
	fprint_Graph(*G, name);

	return 0;
}

int MG()
//int main()
{
	const int edge_num = 3;
	int edge[edge_num][2] = { {1, 2}, {3, 4}, {5,6} };

	const int vertex_num = 6;
	int vertex[vertex_num] = { 1,2,3,4,5,6 };

	for (int i = 0; i < edge_num; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d; ", edge[i][j]);
		}
		printf("\n");
	}

	MGraph G;
	//InitGraph(G, UDG, vertex, vertex_num);
	ArcInfo vertex0[edge_num];
	for (int i = 0; i < edge_num; i++)
	{
		vertex0[i].v = edge[i][0];
		vertex0[i].w = edge[i][1];
	}
	CreateGraph(G, UDG, vertex, vertex_num, vertex0, edge_num);
	

	char name[40] = "1.dot";
	fprint_MGraph(G, name);

	return 0;
}

int main()
{
	const int edge_num = 3;
	int edge[edge_num][2] = { {1, 2}, {3, 4}, {5,6} };

	const int vertex_num = 6;
	int vertex[vertex_num] = { 1,2,3,4,5,6 };

	for (int i = 0; i < edge_num; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d; ", edge[i][j]);
		}
		printf("\n");
	}

	Graph* G = (Graph*)malloc(sizeof(Graph));
	CreateGraphList(G, vertex_num, edge_num, vertex, edge);

	MGraph re = *alG2mG(*G);
	printf_arcs(re);

	char name[40] = "3.dot";
	fprint_MGraph(re, name);

	return 0;
}