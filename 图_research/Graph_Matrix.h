#pragma once
#include <stdio.h>
#include <limits.h>
#include "Graph.h"

//图的表示——邻接矩阵的实现

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;

#define UNVISITED 0
#define VISITED 1
#define INFINTY INT_MAX

//图的邻接矩阵定义
typedef struct MGraph
{
	VerNodeElemtype* vexs;	//顶点数组
	int **arcs;		//邻接矩阵
	int n;		//顶点的个数
	int e;		//边的个数
	GraphKind kind;		//图的种类
	int *tag;
}MGraph,MGraphPointer;

int LocateVex(MGraph G, VerNodeElemtype v)
//查找顶点下标
{
	int num = -1;
	for (int i = 0; i < G.n; i++)
	{
		if (G.vexs[i] == v)
			num = i;
	}
	return num;
}


//初始化图
Status InitGraph(MGraph &G, GraphKind k,VerNodeElemtype *vexs,int n)
{
	int i, j, info;
	if (n < 0 || (n > 0 && NULL == vexs))
		return	ERROR;
	if (k == DG || k == UDG)
		info = 0;
	else if (k == DN || k == UDN)
		info = INFINTY;
	else
		return ERROR;

	//顶点数和边数初始化
	G.n = n;
	G.e = 0;
	if (0 == n)
		return OK;	//一个空图

	if (NULL == (G.vexs = (VerNodeElemtype*)malloc(n * sizeof(int*))))
		return	OVERFLOW;
	
	//建立顶点数组
	for ( i = 0; i < G.n; i++)
	{
		G.vexs[i] = vexs[i];
	}

	//分配边表数组分配内存
	if (NULL == (G.arcs = (int**)malloc(n*sizeof(int*))))
	{
		return	OVERFLOW;
	}

	//分配每个指针所指向的数组
	for ( i = 0; i < n; i++)
	{
		if (NULL == (G.arcs[i] = (int*)malloc(sizeof(int))))
			return	OVERFLOW;
	}

	if (NULL == (G.tag = (int*) malloc (n*sizeof(int))))
	{
		return OVERFLOW;
	}

	//初始化标志数组和关系数组
	for ( i = 0; i < n; i++)
	{
		G.tag[i] = UNVISITED;
		for (j = 0; j < n; j++)
			G.arcs[i][j] = info;
	}
	return OK;
}

//无向图
Status CreateUDG(MGraph &G, VerNodeElemtype *vexs, int n, ArcInfo *arc, int e)
{
	int i, j, k;
	VerNodeElemtype v, w;

	//初始化
	if (InitGraph(G, G.kind, vexs, n) != OK)
		return ERROR;
	G.e = e;

	for ( k = 0; k < G.e; k++)
	{
		v = arc[k].v;
		w = arc[k].w;
		i = LocateVex(G, v);
		j = LocateVex(G, w);

		if (i < 0 || j < 0)
			return ERROR;
		G.arcs[i][j] = G.arcs[j][i] = 1;
	}
	return	OK;
}

//无向带权图
Status CreateUDN(MGraph &G, VerNodeElemtype *vexs, int n, ArcInfo *arc, int e)
{
	int i, j, k;
	VerNodeElemtype v, w;

	//初始化
	if (InitGraph(G, G.kind, vexs, n) != OK)
		return ERROR;
	G.e = e;

	for (k = 0; k < G.e; k++)
	{
		v = arc[k].v;
		w = arc[k].w;
		i = LocateVex(G, v);
		j = LocateVex(G, w);

		if (i < 0 || j < 0)
			return ERROR;
		G.arcs[i][j] = G.arcs[j][i] = 1;
	}
	return	OK;
}

//有向图
Status CreateDG(MGraph &G, VerNodeElemtype *vexs, int n, ArcInfo *arc, int e)
{
	return FALSE;
}

//有向带权图
Status CreateDN(MGraph &G, VerNodeElemtype *vexs, int n, ArcInfo *arc, int e)
{
	return FALSE;
}

Status CreateGraph(MGraph &G, GraphKind k, VerNodeElemtype *vexs, int n, ArcInfo *arc, int e)
{
	if (n < 0 || e < 0 || (n > 0 && NULL == vexs) || (e > 0 && NULL == arc))
		return ERROR;
	G.kind = k;
	switch (G.kind)
	{
	case UDG:
		return CreateUDG(G,vexs,n,arc,e);
	case UDN:
		return CreateUDN(G, vexs, n, arc, e);
	case DG:
		return CreateDG(G, vexs, n, arc, e);
	case DN:
		return CreateDN(G, vexs, n, arc, e);
	default:
		return	ERROR;
	}
}