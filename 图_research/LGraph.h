#pragma once
#include <stdio.h>
#include <malloc.h>
#include "Graph.h"

#define MaxVertexNum 10
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

bool Visited[MaxVertexNum] = { false };

//�ߵĶ���
typedef struct ENode
{
	Vertex V1, V2;    //�����<V1,V2>
	WeightType Weight;    //Ȩ��
}*Edge;

//�ڽӵ�Ķ���
typedef struct AdjVNode
{
	Vertex AdjV;    //�ڽӵ��±�
	WeightType Weight;    //��Ȩ��
	struct AdjVNode* Next;    //ָ����һ���ڽӵ��ָ��
}*PtrToAdjVNode;

//�����ͷ���Ķ���
typedef struct VNode
{
	/* DataType Data;    //�涥������ݣ��ܶ�����£����������ݣ���ʱData���Բ��ó��� */
	struct AdjVNode* FirstEdge;    //�߱�ͷָ��
}AdjList[MaxVertexNum];

//ͼ���Ķ���
typedef struct GNode
{
	int num_V;        //������
	int num_E;        //����
	AdjList G;  //�ڽӱ��ʾ��ͼ
}*LGraph;

LGraph BuildGraph(int vertex_num, int edge_num,Edge *edge)
{
	LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->num_V = vertex_num;
	Graph->num_E = edge_num;
	for (int i = 0; i < Graph->num_V; ++i)
		Graph->G[i].FirstEdge = NULL;    //��ʼ�����б�ͷָ��ΪNULL


	
	return Graph;
}