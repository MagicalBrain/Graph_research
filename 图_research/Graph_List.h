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


//��ʼ��ͼ���ڽӱ�
void InitGraphList(VerNode *G)
{
	;
}


//����һ��ͼ���ڽӱ�
void CreateGraphList(VerNode* G, int num_V, int num_E, int* vertex, int** edge)
{
	G = (VerList)malloc(num_V * sizeof(VerNode));
	for (int i = 0; i < num_V; i++)
	{
		G[i].vertex = vertex[i];
		G[i].first_edge = NULL;
	}
}