#pragma once
#include <stdio.h>

#define VerNodeElemtype int

/*ͼ������
* DG������ͼ
* DN������Ȩͼ
* UDG������ͼ
* UDN������Ȩͼ
*/
typedef enum { DG, DN, UDG, UDN } GraphKind;

//�ߵ�
typedef struct {
	VerNodeElemtype v, w;	//�ߵ���ʼ��
	int info;	//�ߵ�Ȩֵ��
}ArcInfo;