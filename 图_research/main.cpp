#include <stdio.h>
#include "Graph.h"
#include "Graph_List.h"
#include "Graph_Matrix.h"
#include "Output.h"
#include "Head.h"

int main_GaphList()
//int main()
/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 1.dot -o 1.png
*/
{
	const int edge_num = 3;
	ArcInfo edge[edge_num] = { {1, 2,0}, {3, 4,0}, {5,6,0} };

	const int vertex_num = 6;
	int vertex[vertex_num] = { 1,2,3,4,5,6 };
	
	for (int i = 0; i < edge_num; i++)
	{
		printf("%d %d; ", edge[i].v, edge[i].w);
		printf("\n");
	}
	printf("\n");

	Graph* G = (Graph*)malloc(sizeof(Graph));// = (G)malloc(sizeof(VerNode));
	CreateGraphList(G, vertex_num, edge_num, vertex, edge, UDG);

	char name[40] = "1.dot";
	fprint_Graph(*G, name);

	return 0;
}

int main_MG()
//int main()
/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 2.dot -o 2.png
*/
{
	const int edge_num = 3;
	ArcInfo edge[edge_num] = { {1, 2,0}, {3, 4,0}, {5,6,0} };

	const int vertex_num = 6;
	int vertex[vertex_num] = { 1,2,3,4,5,6 };

	for (int i = 0; i < edge_num; i++)
	{
		printf("%d %d; ", edge[i].v, edge[i].w);
		printf("\n");
	}
	printf("\n");

	MGraph G;
	//InitGraph(G, UDG, vertex, vertex_num);
	ArcInfo vertex0[edge_num];
	for (int i = 0; i < edge_num; i++)
	{
		vertex0[i].v = edge[i].v;
		vertex0[i].w = edge[i].w;
	}
	CreateGraph(G, UDG, vertex, vertex_num, vertex0, edge_num);
	

	char name[40] = "2.dot";
	fprint_MGraph(G, name);

	return 0;
}

//测试func03的alG2mG
int main_03()
//int main()
/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 3.dot -o 3.png
*/
{
	const int edge_num = 3;
	ArcInfo edge[edge_num] = { {1, 2,0}, {3, 4,0}, {5,6,0} };

	const int vertex_num = 6;
	int vertex[vertex_num] = { 1,2,3,4,5,6 };

	for (int i = 0; i < edge_num; i++)
	{
		printf("%d %d; ", edge[i].v, edge[i].w);
		printf("\n");
	}
	printf("\n");

	Graph* G = (Graph*)malloc(sizeof(Graph));
	CreateGraphList(G, vertex_num, edge_num, vertex, edge,UDG);

	MGraph re = *alG2mG(*G);
	printf_arcs(re);

	char name[40] = "3.dot";
	fprint_MGraph(re, name);

	return 0;
}

//测试func04的delete_edge
int main_04()
//int main()
/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 401.dot -o 401.png
dot -Tpng 402.dot -o 402.png
*/
{
	/*
	const int edge_num = 3;
	int edge[edge_num][2] = { {1, 2}, {3, 4}, {5,6} };
	*/

	const int edge_num = 9;
	ArcInfo edge[edge_num] = { {1, 2,0},{2,3,0}, {3, 4,0}, {4,5,0}, {5,6,0},{6,1,0},{1,3,0},{6,3,0},{6,4,0} };

	const int vertex_num = 6;
	int vertex[vertex_num] = { 1,2,3,4,5,6 };

	for (int i = 0; i < edge_num; i++)
	{
		printf("%d %d; ", edge[i].v,edge[i].w);
		printf("\n");
	}
	printf("\n");

	Graph* G = (Graph*)malloc(sizeof(Graph));
	CreateGraphList(G, vertex_num, edge_num, vertex, edge,UDG);

	VerNodeElemtype src, dst;
	puts("请输入要删除的边的起点：");
	scanf("%d", &src);
	puts("请输入要删除的边的终点：");
	scanf("%d", &dst);

	char name1[40] = "401.dot";
	fprint_Graph(*G, name1);
	
	if (delete_edge(G, src, dst))
		puts("删除成功！");
	else
		puts("删除失败！");
	
	char name2[40] = "402.dot";
	fprint_Graph(*G, name2);

	return 0;
}

//

//
int main()
/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng First.dot -o First.png
*/
{
	const int edge_num = 9;
	ArcInfo edge[edge_num] = { {1, 2,0},{2,3,0}, {3, 4,0}, {4,5,0}, {5,6,0},{6,1,0},{1,3,0},{6,3,0},{6,4,0} };

	const int vertex_num = 6;
	int vertex[vertex_num] = { 1,2,3,4,5,6 };

	for (int i = 0; i < edge_num; i++)
	{
		printf("%d %d; ", edge[i].v, edge[i].w);
		printf("\n");
	}
	printf("\n");

	Graph* G = (Graph*)malloc(sizeof(Graph));
	CreateGraphList(G, vertex_num, edge_num, vertex, edge, UDG);

	VerNodeElemtype src, dst;
	puts("请输入要查找的顶点：");
	scanf("%d", &src);
	
	//puts("请输入要删除的边的终点：");
	//scanf("%d", &dst);

	char name1[40] = "First.dot";
	fprint_Graph(*G, name1);

	int p = FirstAdject(G, src);
	printf("%d\n", G->vList[src].info);
	//for (int i=0; i<G->num_E; i++)
	for (;p>=0;p=NextAdject(G,src))
	{
		printf("First = %d\n", G->vList[p].vertex);
		printf("First info = %d\n", G->vList[p].info);
		//p = NextAdject(G, src);
	}
	return 0;
}