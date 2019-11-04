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


//初始化图的邻接表
void InitGraphList(VerNode *G)
{
	;
}


//构造一个图的邻接表
void CreateGraphList(VerNode* G, int num_V, int num_E, int* vertex, int** edge)
{
	G = (VerList)malloc(num_V * sizeof(VerNode));
	for (int i = 0; i < num_V; i++)
	{
		G[i].vertex = vertex[i];
		G[i].first_edge = NULL;
	}
}