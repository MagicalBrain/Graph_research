#pragma once
#include <stdio.h>
#include "Graph_List.h"
#include "Graph_Matrix.h"

/*
* 6����д�㷨�ж����ڽӱ�ʽ�洢������ͼG�Ƿ����src��dst��·��
*/

bool delete_edge(GraphPointer G, VerNodeElemtype src, VerNodeElemtype dst)
{
	if (G != NULL && G->num_V > 2)
	{
		for (int i = 0; i < G->num_V; i++)
		{
			if (G->vList[i].vertex == src)
			{
				ArcNode* q = G->vList[i].first_edge;
				if (q->adjvex == dst)
				{
					G->vList[i].first_edge = q->next;
					q->next = NULL;
					free(q);
					return true;
				}
				ArcNode* p = q->next;
				while (p != NULL)
				{
					if (p->adjvex == dst)
					{
						q = p->next;
						p->next = NULL;
						free(p);
						return true;
					}
					p = p->next;
				}
				return false;
			}
		}
	}
	return false;
}