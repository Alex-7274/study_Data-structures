#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
链表的算法实现与原理
*/

//创建结构体表示一个结点
typedef struct student
{
	//数据域
	const char *name;
	int age;
	//指针域
	struct student *next;

}student;

//多结点连接，形成链表
int CreatLink(){
	student *p, *head, *p1, *p2;//p标记头结点，p2标记上一次的内存位置，p1标记后一次
	head = NULL;
	p2 = NULL;
	for (int i = 0; i <=10; i++)
	{
		p1 = (student *)malloc(sizeof(student));//分配内存
		p1->age = i;
		p1->next = NULL;//此时p1既是头也是尾结点
		if (head == 0)
		{//如果链表为空，p1就是头节点
			head = p1;
			p2 = p1;
		}
		else
		{//否则，将p1添加到链表的末尾
			p2->next = p1;
			p2 = p1;
		}
	}

	//遍历输出链表
	p1->next = NULL;//p1指向尾结点
	p = head;//p为遍历准备的工具指针
	printf("链表：");
	while (p != NULL)
	{
		printf("%d ", p->age);
		p = p->next;
	}

	printf("\n释放内存\n");
	student *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}

	return 0;
}


void DeleteNode(){

}

int main()
{
	//CreatLink();
	printf("\n");

	student *L1, *L2;
	L1 = (student *)malloc(sizeof(student));
	L2 = (student *)malloc(sizeof(student));
	L1->next = NULL;
	L2->next = NULL;

	L1->age = 23;
	L1->name = "zy";
	L2->age = 20;
	L2->name = "wk";

	printf("%s,%d", L1->name, L1->age);
	printf("%s,%d", L2->name, L2->age);

	L1->next = L2;//将两个结点链起来，组成链表  L1->L2->...

	free(L1, L2);
	return 0;
}
