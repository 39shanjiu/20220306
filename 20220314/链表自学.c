#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//void Creat_LinkList(LinkList *(L), int n)//����ָ��ĵ�ַ,�ṹ��ָ�����͡�
//{
//	//ͷ�巨
//	//ͷ�巨�����ú���ÿ���ڵ㶼������ͷ�ڵ����һ��
//	//���У�ͷ�ڵ��еĵ�ַҪ���ϵĴ����������Ľڵ�p->Next = (*L)->Next
//	//����Ľڵ�Ҫ��ͷ�ڵ��ָ���򲻶ϵ�ָ����(*L)->Next = p
//	//L��ʾ��ʱͷ�ڵ�
//	int i;
//	LinkList p;//�������塣
//	*L = (LinkList*)malloc(sizeof(Node));//ͷ�ڵ�Ŀռ�����
//	(*L)->Next = NULL;//ͷ�ڵ�ָ���ָ�롣
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));//����һ���ڵ�ռ�
//		p->data = i;//�������ݡ�
//		p->Next = (*L)->Next;//��Lָ��ĵ�ַ��p��
//		(*L)->Next = p;//��ͷ�ڵ�ָ��p�ĵ�ַ��
//		//��ϡ������ݽṹ��p59ҳ��
//	}
//}
//typedef struct Node
//{
//	int data;//������
//	struct Node* Next;//ָ������ָ���ʱ��ַ��
//}Node,*LinkList;//�������������Ľṹ��
////*LinkList ��ʾ������һ���ṹ��ָ��
//int main()
//{
//	LinkList* L;//L�ṹ��ָ��ı�����
//	int lenth = 10;
//	//
//	//Creat_LinkList(&L,lenth);//����ַ��ָ��ĵ�ַ
//	//ͷ�巨
//	//ͷ�巨�����ú���ÿ���ڵ㶼������ͷ�ڵ����һ��
//	//���У�ͷ�ڵ��еĵ�ַҪ���ϵĴ����������Ľڵ�p->Next = (*L)->Next
//	//����Ľڵ�Ҫ��ͷ�ڵ��ָ���򲻶ϵ�ָ����(*L)->Next = p
//	//L��ʾ��ʱͷ�ڵ�
//	int i;
//	LinkList p;//�������塣
//	L = (LinkList*)malloc(sizeof(Node));//ͷ�ڵ�Ŀռ�����
//	*L->Next = NULL;//ͷ�ڵ�ָ���ָ�롣
//	for (i = 0; i < lenth; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));//����һ���ڵ�ռ�
//		p->data = i;//�������ݡ�
//		p->Next = L->Next;//��Lָ��ĵ�ַ��p��
//		L->Next = p;//��ͷ�ڵ�ָ��p�ĵ�ַ��
//		//��ϡ������ݽṹ��p59ҳ��
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