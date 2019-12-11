#pragma once
#include <stdio.h>
#include <malloc.h>
#include "Graph.h"

//ͼ��ʵ�֡����ڽӱ�

//�߱���Ķ���

typedef struct ArcNode
{
	int adjvex;	
	/*
	*�߱����ڶ�����е�����������������±ꣿ��
	* ����Ƕ����ֵ����ô����Щ������Ӧ���У�ÿһ��ͨ���߱������������յ�ʱ��Ҫ����һ�鶥������
	*/
	struct ArcNode* next;	//���ڵ�ĺ��
	int info;	//�ߵ�Ȩֵ
}ArcNode,*ArcList;

//�������
typedef struct VerNode
{
	VerNodeElemtype vertex;	//�����ֵ
	ArcNode* first_edge;	//����ı߱��еĵ�һ���ڵ�
	int info;	//�����Ȩֵ	
	int tag;
	/*
	* ���
	* �Ƿ񱻷��ʹ�(0:��, 1:�ѱ�����)
	*/
}VerNode, * VerList;

typedef struct Graph
{
	VerList vList;	//��������
	int num_V;	//�������
	int num_E;	//�ߵĸ���
	GraphKind kind;	//ͼ������
}Graph,*GraphPointer;

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


//����һ��ͼ���ڽӱ�(����ͼ)
void CreateGraphList_UDG(Graph *G, int num_V, int num_E, int* vertex, ArcInfo* edge)
/*
* G: ָ��һ��ͼ��ָ��
* num_V: ����ĸ���
* num_E: �ߵĸ���
* vertex: ���ж���ֵ������
* edge�����бߵĶ�ά����
*/
{
	//����ͼ������Ϊ����ͼ
	G->kind = UDG;
	//��ʼ��ͼ���ڽӱ�
	G->vList = (VerList)malloc(num_V * sizeof(VerNode));
	//��ʼ���ڽӱ�Ķ����
	G->num_V = num_V;
	for (int i = 0; i < G->num_V; i++)
	{
		G->vList[i].vertex = i;
		//G->vList[i].vertex = vertex[i];
		G->vList[i].first_edge = NULL;
		G->vList[i].info = vertex[i];
	}

	//��ʼ�������ı߱�����
	G->num_E = num_E;
	for (int i = 0; i < G->num_E; i++)
	{
		for (int j = 0; j < num_V; j++)
		{
			if (edge[i].v == vertex[j])
			{
				if (G->vList[j].first_edge == NULL)
				{
					G->vList[j].first_edge = (ArcNode*)malloc(sizeof(ArcNode));
					ArcNode* p = (ArcList)malloc(sizeof(ArcNode));
					int k;
					for (k = 0; k < G->num_V; k++)
						if (G->vList[k].info == edge[i].w)
							break;

					p->adjvex = k;
					p->info = edge[i].w;
					G->vList[j].first_edge = p;
					G->vList[j].first_edge->next = NULL;
				}
				else
				{
					ArcNode* r = G->vList[j].first_edge;
					ArcNode* p = (ArcList)malloc(sizeof(ArcNode));
					int k;
					for (k = 0; k < G->num_V; k++)
						if (G->vList[k].info == edge[i].w)
							break;

					p->adjvex = k;
					p->info = edge[i].w;

					p->next = r->next;
					r->next = p;
				}
				
			}
			
		}
		for (int j = 0; j < num_V; j++)
		{
			if (edge[i].w == vertex[j])
			{
				if (G->vList[j].first_edge == NULL)
				{
					G->vList[j].first_edge = (ArcNode*)malloc(sizeof(ArcNode));
					ArcNode* p = (ArcList)malloc(sizeof(ArcNode));
					int k;
					for (k = 0; k < G->num_V; k++)
						if (G->vList[k].info == edge[i].v)
							break;

					p->adjvex = k;
					p->info = edge[i].v;
					G->vList[j].first_edge = p;
					G->vList[j].first_edge->next = NULL;
				}
				else
				{
					ArcNode* r = G->vList[j].first_edge;
					ArcNode* p = (ArcList)malloc(sizeof(ArcNode));
					int k;
					for (k = 0; k < G->num_V; k++)
						if (G->vList[k].info == edge[i].v)
							break;

					p->adjvex = k;
					p->info = edge[i].v;

					p->next = r->next;
					r->next = p;
				}
			}
		}
		
	}
}


//����һ��ͼ���ڽӱ�(��������������Ȩͼ)
void CreateGraphList_UDN(Graph* G, int num_V, int num_E, int* vertex, ArcInfo* edge)
{
	puts("��û��ɣ�");
}


//����һ��ͼ���ڽӱ�(����ͼ)
void CreateGraphList_DG(Graph* G, int num_V, int num_E, int* vertex, ArcInfo* edge)
/*
* G: ָ��һ��ͼ��ָ��
* num_V: ����ĸ���
* num_E: �ߵĸ���
* vertex: ���ж���ֵ������
* edge�����бߵĶ�ά����
*/
{
	//����ͼ������Ϊ����ͼ
	G->kind = DG;
	//��ʼ��ͼ���ڽӱ�
	G->vList = (VerList)malloc(num_V * sizeof(VerNode));
	//��ʼ���ڽӱ�Ķ����
	G->num_V = num_V;
	for (int i = 0; i < G->num_V; i++)
	{
		G->vList[i].vertex = i;
		G->vList[i].first_edge = NULL;
		G->vList[i].info = vertex[i];
	}

	//��ʼ�������ı߱�����
	G->num_E = num_E;
	for (int i = 0; i < G->num_E; i++)
	{
		for (int j = 0; j < num_V; j++)
		{
			if (edge[i].v == vertex[j])
			{
				ArcNode* r = G->vList[j].first_edge;
				ArcNode* p = (ArcList)malloc(sizeof(ArcNode));
				int k;
				for (k = 0; k < G->num_V; k++)
					if (G->vList[k].vertex == edge[i].w)
						break;

				p->adjvex = k;

				G->vList[j].first_edge = p;
				p = r;
				G->vList[j].first_edge->next = p;
			}

		}
	}
}


//����һ��ͼ���ڽӱ�(������Ȩͼ)
void CreateGraphList_DN(Graph* G, int num_V, int num_E, int* vertex, ArcInfo* edge)
{
	puts("��û��ɣ�");
}


bool CreateGraphList(Graph* G, int num_V, int num_E, int* vertex, ArcInfo* edge, GraphKind kind)
{
	if (num_V < 0 || num_E < 0 || NULL == vertex || NULL == edge)
		return false;
	G->kind = kind;
	switch (G->kind)
	{
	//��������ͼ
	case UDG:
		CreateGraphList_UDG(G, num_V, num_E, vertex, edge);
		break;
	//����������Ȩͼ
	case UDN:
		CreateGraphList_UDN(G, num_V, num_E, vertex, edge);
		break;
	//��������ͼ
	case DG:
		CreateGraphList_DG(G, num_V, num_E, vertex, edge);
		break;
	case DN:
		CreateGraphList_DN(G, num_V, num_E, vertex, edge);
		break;
	default:
		puts("���ʹ���");
		break;
	}
}