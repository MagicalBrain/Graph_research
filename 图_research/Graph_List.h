#pragma once
#include <iostream>

//ͼ��ʵ�֡����ڽӱ�

//�߱���Ķ���

typedef struct ArcNode
{
	int adjvex;	//�߱����ڶ�����е�����
	struct ArcNode* next;	//���ڵ�ĺ��
}ArcNode,*ArcList;

//�������

typedef struct VerNode
{
	int vertex;	//�����ֵ
	ArcNode* first_edge;
}VerNode, * VerList;

typedef struct Graph
{
	VerList vList;	//��������
	int num_V;	//�������
	int num_E;	//�ߵĸ���
}Graph;

//��ʼ��ͼ���ڽӱ�
void InitGraphList(Graph G)
{
	//��ʼ��ͼ���ڽӱ�
	////��ʼ���ڽӱ�Ķ����
	G.vList = (VerList)malloc(sizeof(VerNode));
	G.num_V = 0;

	//��ʼ���ڽӱ�ı߱�
	G.vList[0].first_edge = NULL;
	G.vList[0].vertex = 0;
	G.num_E = 0;
}


//����һ��ͼ���ڽӱ�
void CreateGraphList(Graph *G, int num_V, int num_E, int* vertex, int (*edge)[2])
/*
* G: ָ��һ��ͼ��ָ��
* num_V: ����ĸ���
* num_E: �ߵĸ���
* vertex: ���ж���ֵ������
* edge�����бߵĶ�ά����
*/
{
	//��ʼ��ͼ���ڽӱ�
	G->vList = (VerList)malloc(num_V * sizeof(VerNode));
	//��ʼ���ڽӱ�Ķ����
	G->num_V = num_V;
	for (int i = 0; i < G->num_V; i++)
	{
		G->vList[i].vertex = vertex[i];
		G->vList[i].first_edge = NULL;
	}

	//��ʼ�������ı߱�����
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