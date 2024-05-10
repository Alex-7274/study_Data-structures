#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<stdlib.h>

/*
链表，链式存储结构，顺序存取
*/


typedef struct Node {
	//数据域
	int data;
	//指针域
	struct student *next;
}LinkNode;

//初始化链表并返回头节点指针
LinkNode* InitList(){
	LinkNode* temp = (LinkNode*)malloc(sizeof(LinkNode));//创建一个结构体指针并分配空间
	temp->next = NULL;//将结构体指针的指针域赋值为null
	return temp;//返回初始化完成的结构体指针
}

LinkNode *L = InitList;//创建一个指向结构体的指针来记录头节点

//增加结点（头插法）
void CreateLink_H(){
	LinkNode *L = (LinkNode*)malloc(sizeof(LinkNode));//创建一个带头节点的单链表
	L->next = NULL;
	int n = 3, e = 0;//n为创建的新结点个数，e为结点数据
	for (int i = 0; i < n; i++)
	{
		LinkNode *P = (LinkNode*)malloc(sizeof(LinkNode));//生成新结点P
		e = i;
		P->data = e;//给新结点赋值
		P->next = L->next;
		L->next = P;//将新结点插入表头
	}
}

//增加结点（尾插法）
void CreateLink_R(LinkNode* L)
{
	//创建一个带头结点的单链表
	LinkNode* L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	//创建一个尾指针指向头结点(空链表中的头就是尾)
	LinkNode* r = L;
	int n = 3, e = 0;//n为创建的新结点个数,e为结点的数据
	for (int i; i < n; i++)
	{
		//创建一个新结点
		LinkNode* P = (LinkNode*)malloc(sizeof(LinkNode));
		//给新结点P的数据域赋值
		e = i;
		P->data = e;
		//将新结点插入表尾
		P->next = NULL;
		r->next = P;
		//r指向新的尾结点
		r = P;
	}
}