#pragma once
#include <stdio.h>
#include "Graph_List.h"
#include "Graph_Matrix.h"

/*
* 4、G是一个使用邻接表存储结构存储的无向图，设计算法删除G中顶点src到dst的边
*/

bool delete_edge(GraphPointer G, VerNodeElemtype src, VerNodeElemtype dst)
{
	int flag = 0;
	if (G != NULL && G->num_V > 2)
	{
		if (G->kind != UDG)
		{
			puts("不是无向图！");
			return false;
		}

		//先遍历找出起点的边表结点
		for (int i = 0; i < G->num_V; i++)
		{
			if (G->vList[i].info == src)
			{
				ArcNode* q = G->vList[i].first_edge;
				if (G->vList[q->adjvex].info == dst)
				{
					G->vList[i].first_edge = q->next;
					free(q);
					q = NULL;
					flag++;
					break;
				}
				else
				{
					ArcNode* p = q->next;
					while (p != NULL)
					{
						if (G->vList[p->adjvex].info == dst)
						{
							q->next = p->next;
							free(p);
							p = NULL;
							flag++;
							break;
						}
						else
						{
							q = p;
							p = p->next;
						}
					}
				}
				
			}
		}

		//再找出终点的边表结点
		for (int i = 0; i < G->num_V; i++)
		{
			if (G->vList[i].info == dst)
			{
				ArcNode* q = G->vList[i].first_edge;
				if (G->vList[q->adjvex].info == src)
				{
					G->vList[i].first_edge = q->next;
					free(q);
					q = NULL;
					flag++;
					break;
				}
				else
				{
					ArcNode* p = q->next;
					while (p != NULL)
					{
						if (G->vList[p->adjvex].info == src)
						{
							q->next = p->next;
							free(p);
							p = NULL;
							flag++;
							break;
						}
						else
						{
							q = p;
							p = p->next;
						}
					}
				}
			}
		}
	}
	if (flag == 2)
		return true;
	else
		return false;
}