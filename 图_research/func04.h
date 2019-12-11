#pragma once
#include <stdio.h>
#include "Graph_List.h"
#include "Graph_Matrix.h"

/*
* 4��G��һ��ʹ���ڽӱ�洢�ṹ�洢������ͼ������㷨ɾ��G�ж���src��dst�ı�
*/

bool delete_edge(GraphPointer G, VerNodeElemtype src, VerNodeElemtype dst)
{
	int flag = 0;
	if (G != NULL && G->num_V > 2)
	{
		if (G->kind != UDG)
		{
			puts("��������ͼ��");
			return false;
		}

		//�ȱ����ҳ����ı߱���
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

		//���ҳ��յ�ı߱���
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