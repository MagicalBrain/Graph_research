#pragma once
#include <stdio.h>
#include "Graph_List.h"
#include "Graph_Matrix.h"

/*
* 3、设计算法将邻接表表示的网alG转换为邻接矩阵表示的网mG。
*/

MGraph* alG2mG(Graph G)
{
	if (G.vList == NULL || G.num_E < 0 || G.num_V < 0)
		return NULL;

	//初始化MG
	MGraph* re = (MGraph*)malloc(sizeof(MGraph));
	re->e = G.num_E;
	re->n = G.num_V;
	re->vexs = (VerNodeElemtype*)malloc(re->n * sizeof(VerNodeElemtype));

	//初始化邻接矩阵的二维数组
	////分配空间
	re->arcs = (int**)malloc(sizeof(int*));
	for (int i = 0; i < re->n; i++)
	{
		re->arcs[i] = (int*)malloc(re->n * sizeof(int));
	}

	////初始化为0
	for (int i = 0; i < re->n; i++)
	{
		for (int j = 0; j < re->n; j++)
		{
			re->arcs[i][j] = 0;
		}
	}

	//传顶点数组的值
	for (size_t i = 0; i < G.num_V; i++)
	{
		re->vexs[i] = G.vList[i].vertex;
	}

	for (int i = 0; i < G.num_V; i++)
	{
		int r = LocateVex(*re, G.vList[i].vertex);
		ArcList p = G.vList[i].first_edge;
		while (p!=NULL)
		{
			int c = LocateVex(*re, G.vList[p->adjvex].vertex);
			re->arcs[r][c] = 1;
			re->arcs[c][r] = 1;
			p = p->next;
		}
	}
	
	return re;
}