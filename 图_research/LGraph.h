#pragma once
#include <stdio.h>
#include <malloc.h>
#include "Graph.h"

#define MaxVertexNum 10
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

bool Visited[MaxVertexNum] = { false };

//边的定义
typedef struct ENode
{
	Vertex V1, V2;    //有向边<V1,V2>
	WeightType Weight;    //权重
}*Edge;

//邻接点的定义
typedef struct AdjVNode
{
	Vertex AdjV;    //邻接点下标
	WeightType Weight;    //边权重
	struct AdjVNode* Next;    //指向下一个邻接点的指针
}*PtrToAdjVNode;

//顶点表头结点的定义
typedef struct VNode
{
	/* DataType Data;    //存顶点的数据，很多情况下，顶点无数据，此时Data可以不用出现 */
	struct AdjVNode* FirstEdge;    //边表头指针
}AdjList[MaxVertexNum];

//图结点的定义
typedef struct GNode
{
	int num_V;        //顶点数
	int num_E;        //边数
	AdjList G;  //邻接表表示的图
}*LGraph;

LGraph BuildGraph(int vertex_num, int edge_num,Edge *edge)
{
	LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->num_V = vertex_num;
	Graph->num_E = edge_num;
	for (int i = 0; i < Graph->num_V; ++i)
		Graph->G[i].FirstEdge = NULL;    //初始化所有表头指针为NULL


	
	return Graph;
}