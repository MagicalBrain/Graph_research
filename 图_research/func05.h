#pragma once
#include <stdio.h>
#include "Graph_List.h"
#include "Graph_Matrix.h"

/*
* 5、判断一个以邻接表为存储结构的有向图是否存在环。
*/

bool isCircule(Graph G)
{
	if (G.num_E > 0 && G.num_V > 0)
	{
		for (int i = 0; i < G.num_V; i++)
		{
			G.vList[i].info = 1;
			ArcNode* p = G.vList[i].first_edge;
			while (p != NULL)
			{
				p->adjvex;
			}
		}
	}
	return false;
}