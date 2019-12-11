#pragma once
#include <iostream>
#include <fstream>
#include "Graph_List.h"
#include "Graph_Matrix.h"

using namespace std;

/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 图.dot -o 图.png
*/


void fprint_Graph(Graph G, char str[])
{
	if (G.vList != NULL)
	{
		ofstream Graph;
		Graph.open(str);
		Graph << "digraph G{" << endl;
		if (G.kind == UDG)
		{
			for (int i = 0; i < G.num_V; i++)
			{
				Graph << G.vList[i].info << ";" << endl;
			}

			for (int i = 0; i < G.num_V; i++)
			{
				ArcNode* p = G.vList[i].first_edge;

				while (p != NULL)
				{
					Graph << G.vList[i].info << "->" << G.vList[p->adjvex].info
						<< "[ arrowhead=\"none\"]"  << ";" << endl;
					p = p->next;
				}
			}
		}
		else if (G.kind == DG)
		{
			for (int i = 0; i < G.num_V; i++)
			{
				Graph << G.vList[i].vertex << ";" << endl;
			}

			for (int i = 0; i < G.num_V; i++)
			{
				ArcNode* p = G.vList[i].first_edge;

				while (p != NULL)
				{
					Graph << G.vList[i].vertex << "->" << G.vList[p->adjvex].vertex << ";" << endl;
					p = p->next;
				}
			}
		}
		Graph << "}" << endl;
		Graph.close();
	}
}




void fprint_MGraph(MGraph G, char str[])
{
	if (G.e > 0 && G.n > 0)
	{
		ofstream Graph_M;
		Graph_M.open(str);
		//if (!Graph_M.is_open())
			//cout << "文件打开失败！" << endl;

		Graph_M << "digraph G{" << endl;

		for (int i = 0; i < G.n; i++)
		{
			for (int j = 0 + i; j < G.n; j++)
			{
				if (G.arcs[i][j] == 1)
				{
					Graph_M << G.vexs[i] << "->" << G.vexs[j] << "[ arrowhead=\"none\"]" << ";" << endl;
				}
				
			}

		}

		Graph_M << "}" << endl;
		Graph_M.close();
	}
}

void printf_arcs(MGraph G)
{
	if (G.e > 0 && G.n > 0)
	{
		for (int i = 0; i < G.n; i++)
		{
			for (int j = 0; j < G.n; j++)
			{
				//cout << G.vexs[i] << " " << G.vexs[j] << " " << G.arcs[i][j] << endl;
				printf("%d ", G.arcs[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}