#pragma once
#include <stdio.h>

//ͼ�ı�ʾ�����ڽӾ����ʵ��

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;

#define UNVISITED 0
#define VISITED 1
#define INFINTY MAXINT

#define VexType int

/*ͼ������
* DG������ͼ
* DN������Ȩͼ
* UDG������ͼ
* UDN������Ȩͼ
*/
typedef enum{DG,DN,UDG,UDN} GraphKind;

typedef struct {
	VexType v, w;	//�ߵ���ʼ��
	int info;	//�ߵ�Ȩֵ��
}ArcInfo;

//ͼ���ڽӾ�����
typedef struct MGraph
{
	VexType* vexs;	//��������
	int **arcs;		//�ڽӾ���
	int n;		//����ĸ���
	int e;		//�ߵĸ���
	GraphKind kind;		//ͼ������
	int *tag;
}MGraph;

int LocateVex(MGraph G, VexType v)
//���Ҷ����±�
{
	int num = -1;
	for (int i = 0; i < G.n; i++)
	{
		if (G.vexs[i] == v)
			num = i;
	}
	return num;
}


//��ʼ��ͼ
Status InitGraph(MGraph &G, GraphKind k,VexType *vexs,int n)
{
	int i, j, info;
	if (n < 0 || (n > 0 && NULL == vexs))
		return	ERROR;
	if (k == DG || k == UDG)
		info = 0;
	else if (k == DN || k == UDN)
		info = INFINITY;
	else
		return ERROR;

	//�������ͱ�����ʼ��
	G.n = n;
	G.e = 0;
	if (0 == n)
		return OK;	//һ����ͼ

	if (NULL == (G.vexs = (VexType*)malloc(n * sizeof(int*))))
		return	OVERFLOW;
	
	//������������
	for ( i = 0; i < G.n; i++)
	{
		G.vexs[i] = vexs[i];
	}

	//����߱���������ڴ�
	if (NULL == (G.arcs = (int**)malloc(n*sizeof(int*))))
	{
		return	OVERFLOW;
	}

	//����ÿ��ָ����ָ�������
	for ( i = 0; i < n; i++)
	{
		if (NULL == (G.arcs[i] = (int*)malloc(sizeof(int))))
			return	OVERFLOW;
	}

	if (NULL == (G.tag = (int*) malloc (n*sizeof(int))))
	{
		return OVERFLOW;
	}

	//��ʼ����־����͹�ϵ����
	for ( i = 0; i < n; i++)
	{
		G.tag[i] = UNVISITED;
		for (j = 0; j < n; j++)
			G.arcs[i][j] = info;
	}
	return OK;
}

//����ͼ
Status CreateUDG(MGraph &G, VexType *vexs, int n, ArcInfo *arc, int e)
{
	int i, j, k;
	VexType v, w;

	//��ʼ��
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

//�����Ȩͼ
Status CreateUDN(MGraph &G, VexType *vexs, int n, ArcInfo *arc, int e)
{
	int i, j, k;
	VexType v, w;

	//��ʼ��
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

//����ͼ
Status CreateDG(MGraph &G, VexType *vexs, int n, ArcInfo *arc, int e)
{
	return FALSE;
}

//�����Ȩͼ
Status CreateDN(MGraph &G, VexType *vexs, int n, ArcInfo *arc, int e)
{
	return FALSE;
}

Status CreateGraph(MGraph &G, GraphKind k, VexType *vexs, int n, ArcInfo *arc, int e)
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