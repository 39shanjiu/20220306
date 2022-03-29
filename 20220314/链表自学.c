#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//void Creat_LinkList(LinkList *(L), int n)//接收指针的地址,结构体指针类型。
//{
//	//头插法
//	//头插法就是让后面每个节点都插入在头节点的下一个
//	//其中，头节点中的地址要不断的传给插入来的节点p->Next = (*L)->Next
//	//插入的节点要让头节点的指针域不断的指向它(*L)->Next = p
//	//L表示的时头节点
//	int i;
//	LinkList p;//链表主体。
//	*L = (LinkList*)malloc(sizeof(Node));//头节点的空间申请
//	(*L)->Next = NULL;//头节点指向空指针。
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));//申请一个节点空间
//		p->data = i;//插入数据。
//		p->Next = (*L)->Next;//让L指向的地址给p。
//		(*L)->Next = p;//让头节点指向p的地址。
//		//结合《大话数据结构》p59页。
//	}
//}
//typedef struct Node
//{
//	int data;//数据域
//	struct Node* Next;//指针域。它指向的时地址。
//}Node,*LinkList;//创建两个这样的结构体
////*LinkList 表示创建了一个结构体指针
//int main()
//{
//	LinkList* L;//L结构体指针的变量名
//	int lenth = 10;
//	//
//	//Creat_LinkList(&L,lenth);//传地址。指针的地址
//	//头插法
//	//头插法就是让后面每个节点都插入在头节点的下一个
//	//其中，头节点中的地址要不断的传给插入来的节点p->Next = (*L)->Next
//	//插入的节点要让头节点的指针域不断的指向它(*L)->Next = p
//	//L表示的时头节点
//	int i;
//	LinkList p;//链表主体。
//	L = (LinkList*)malloc(sizeof(Node));//头节点的空间申请
//	*L->Next = NULL;//头节点指向空指针。
//	for (i = 0; i < lenth; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));//申请一个节点空间
//		p->data = i;//插入数据。
//		p->Next = L->Next;//让L指向的地址给p。
//		L->Next = p;//让头节点指向p的地址。
//		//结合《大话数据结构》p59页。
//	}
//	 i = 0;
//	LinkList ps;
//	ps = (*L)->Next;
//	for (i = 0; i < lenth; i++)
//	{
//		printf("%d ", ps->Next->data);
//		ps = ps->Next;
//	}
//	return 0;
//}