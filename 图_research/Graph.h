#pragma once
#include <stdio.h>

#define VerNodeElemtype int

/*图的种类
* DG：有向图
* DN：有向权图
* UDG：无向图
* UDN：无向权图
*/
typedef enum { DG, DN, UDG, UDN } GraphKind;

//边的
typedef struct {
	VerNodeElemtype v, w;	//边的起始点
	int info;	//边的权值？
}ArcInfo;