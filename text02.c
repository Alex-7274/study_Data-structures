#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<stdlib.h>

/*
������ʽ�洢�ṹ��˳���ȡ
*/


typedef struct Node {
	//������
	int data;
	//ָ����
	struct student *next;
}LinkNode;

//��ʼ����������ͷ�ڵ�ָ��
LinkNode* InitList(){
	LinkNode* temp = (LinkNode*)malloc(sizeof(LinkNode));//����һ���ṹ��ָ�벢����ռ�
	temp->next = NULL;//���ṹ��ָ���ָ����ֵΪnull
	return temp;//���س�ʼ����ɵĽṹ��ָ��
}

LinkNode *L = InitList;//����һ��ָ��ṹ���ָ������¼ͷ�ڵ�

//���ӽ�㣨ͷ�巨��
void CreateLink_H(){
	LinkNode *L = (LinkNode*)malloc(sizeof(LinkNode));//����һ����ͷ�ڵ�ĵ�����
	L->next = NULL;
	int n = 3, e = 0;//nΪ�������½�������eΪ�������
	for (int i = 0; i < n; i++)
	{
		LinkNode *P = (LinkNode*)malloc(sizeof(LinkNode));//�����½��P
		e = i;
		P->data = e;//���½�㸳ֵ
		P->next = L->next;
		L->next = P;//���½������ͷ
	}
}

//���ӽ�㣨β�巨��
void CreateLink_R(LinkNode* L)
{
	//����һ����ͷ���ĵ�����
	LinkNode* L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	//����һ��βָ��ָ��ͷ���(�������е�ͷ����β)
	LinkNode* r = L;
	int n = 3, e = 0;//nΪ�������½�����,eΪ��������
	for (int i; i < n; i++)
	{
		//����һ���½��
		LinkNode* P = (LinkNode*)malloc(sizeof(LinkNode));
		//���½��P��������ֵ
		e = i;
		P->data = e;
		//���½������β
		P->next = NULL;
		r->next = P;
		//rָ���µ�β���
		r = P;
	}
}