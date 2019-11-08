#pragma once
#include <iostream>

//图的实现——邻接表

//边表结点的定义

typedef struct ArcNode
{
	int adjvex;	//边表结点在顶点表中的索引
	struct ArcNode* next;	//编标节点的后继
}ArcNode,*ArcList;

//顶点表结点

typedef struct VerNode
{
	int vertex;	//顶点的值
	ArcNode* first_edge;
}VerNode, * VerList;

typedef struct Graph
{
	VerList vList;	//顶点数组
	int num_V;	//顶点个数
	int num_E;	//边的个数
}Graph;

//初始化图的邻接表
void InitGraphList(Graph G)
{
	//初始化图的邻接表
	////初始化邻接表的顶点表
	G.vList = (VerList)malloc(sizeof(VerNode));
	G.num_V = 0;

	//初始化邻接表的边表
	G.vList[0].first_edge = NULL;
	G.vList[0].vertex = 0;
	G.num_E = 0;
}


//构造一个图的邻接表
void CreateGraphList(Graph *G, int num_V, int num_E, int* vertex, int (*edge)[2])
/*
* G: 指向一个图的指针
* num_V: 顶点的个数
* num_E: 边的个数
* vertex: 存有顶点值的数组
* edge：存有边的二维数组
*/
{
	//初始化图的邻接表
	G->vList = (VerList)malloc(num_V * sizeof(VerNode));
	//初始化邻接表的顶点表
	G->num_V = num_V;
	for (int i = 0; i < G->num_V; i++)
	{
		G->vList[i].vertex = vertex[i];
		G->vList[i].first_edge = NULL;
	}

	//初始化顶点表的边表并插入
	G->num_E = num_E;
	for (int i = 0; i < G->num_E; i++)
	{
		for (int j = 0; j < num_V; j++)
		{
			if (edge[i][0] == vertex[j])
			{
				ArcNode* r = G->vList[j].first_edge;
				ArcNode* p = (ArcList)malloc(sizeof(ArcNode));
				p->adjvex = edge[i][1];
				
				G->vList[j].first_edge = p;
				p = r;
				G->vList[j].first_edge->next = p;
			}
		}
		
	}
}