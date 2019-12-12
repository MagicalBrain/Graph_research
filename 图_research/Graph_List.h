#pragma once
#include <stdio.h>
#include <malloc.h>
#include "Graph.h"

//图的实现——邻接表

/*---------边表结点的定义---------*/

typedef struct ArcNode
{
	int adjvex;	
	/*
	*边表结点在顶点表中的索引（顶点数组的下标？）
	* 如果是顶点的值，那么在有些遍历的应用中，每一次通过边表结点来访问其终点时都要遍历一遍顶点数组
	*/
	struct ArcNode* next;	//编标节点的后继
	int info;	//边的权值
}ArcNode,*ArcList;

//顶点表结点
typedef struct VerNode
{
	VerNodeElemtype vertex;	//顶点的值
	ArcNode* first_edge;	//顶点的边表中的第一个节点
	int info;	//顶点的权值	
	int tag;
	/*
	* 标记
	* 是否被访问过(0:无, 1:已被访问)
	*/
}VerNode, * VerList;

typedef struct Graph
{
	VerList vList;	//顶点数组
	int num_V;	//顶点个数
	int num_E;	//边的个数
	GraphKind kind;	//图的种类
}Graph,*GraphPointer;


/*---------初始化图的邻接表---------*/

void InitGraphList(Graph G)
{
	//初始化图的邻接表
	////初始化邻接表的顶点表
	G.vList = (VerList)malloc(sizeof(VerNode));
	G.num_V = 0;

	//初始化邻接表的边表
	G.vList[0].first_edge = NULL;
	G.vList[0].vertex = 0;
	G.num_E = 0;
}


//
/*---------构造一个图的邻接表(无向图)---------*/
void CreateGraphList_UDG(Graph *G, int num_V, int num_E, int* vertex, ArcInfo* edge)
/*
* G: 指向一个图的指针
* num_V: 顶点的个数
* num_E: 边的个数
* vertex: 存有顶点值的数组
* edge：存有边的二维数组
*/
{
	//设置图的类型为无向图
	G->kind = UDG;
	//初始化图的邻接表
	G->vList = (VerList)malloc(num_V * sizeof(VerNode));
	//初始化邻接表的顶点表
	G->num_V = num_V;
	for (int i = 0; i < G->num_V; i++)
	{
		G->vList[i].vertex = i;
		//G->vList[i].vertex = vertex[i];
		G->vList[i].first_edge = NULL;
		G->vList[i].info = vertex[i];
	}

	//初始化顶点表的边表并插入
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


/*------------------构造一个图的邻接表(无向网，无向有权图)------------------*/
void CreateGraphList_UDN(Graph* G, int num_V, int num_E, int* vertex, ArcInfo* edge)
{
	puts("还没完成！");
}


//
/*------------------构造一个图的邻接表(有向图)------------------*/
void CreateGraphList_DG(Graph* G, int num_V, int num_E, int* vertex, ArcInfo* edge)
/*
* G: 指向一个图的指针
* num_V: 顶点的个数
* num_E: 边的个数
* vertex: 存有顶点值的数组
* edge：存有边的二维数组
*/
{
	//设置图的类型为有向图
	G->kind = DG;
	//初始化图的邻接表
	G->vList = (VerList)malloc(num_V * sizeof(VerNode));
	//初始化邻接表的顶点表
	G->num_V = num_V;
	for (int i = 0; i < G->num_V; i++)
	{
		G->vList[i].vertex = i;
		G->vList[i].first_edge = NULL;
		G->vList[i].info = vertex[i];
	}

	//初始化顶点表的边表并插入
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


/*----------------构造一个图的邻接表(有向有权图)----------------*/
void CreateGraphList_DN(Graph* G, int num_V, int num_E, int* vertex, ArcInfo* edge)
{
	puts("还没完成！");
}


bool CreateGraphList(Graph* G, int num_V, int num_E, int* vertex, ArcInfo* edge, GraphKind kind)
{
	if (num_V < 0 || num_E < 0 || NULL == vertex || NULL == edge)
		return false;
	G->kind = kind;
	switch (G->kind)
	{
	//创建无向图
	case UDG:
		CreateGraphList_UDG(G, num_V, num_E, vertex, edge);
		break;
	//创建无向有权图
	case UDN:
		CreateGraphList_UDN(G, num_V, num_E, vertex, edge);
		break;
	//创建有向图
	case DG:
		CreateGraphList_DG(G, num_V, num_E, vertex, edge);
		break;
	case DN:
		CreateGraphList_DN(G, num_V, num_E, vertex, edge);
		break;
	default:
		puts("类型错误！");
		break;
	}
}

/*--------------基本操作--------------*/

//获取该顶点的第一个边表结点
int FirstAdject(GraphPointer G,int u)
{
	return G->vList[u].first_edge->adjvex;
}

//
int NextAdject(GraphPointer G, int &u)
{
	int re = G->vList[u].first_edge->next->adjvex;
	u = re;
	return re;
}