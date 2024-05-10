#include<stdio.h>
#include<stdlib.h>


//结点构造体
typedef struct ListNode{
	int value;
	struct ListNode *next;
} ListNode;


//创建结点
ListNode *newListNode(int val){
	ListNode *node;
	node = (ListNode *)malloc(sizeof(ListNode));
	node->value = val;
	node->next = NULL;
	return node;
}


//在链表的结点n0之后插入结点p
void insert(ListNode *n0,ListNode *p){
	ListNode *n1 = n0->next;
	p->next = n1;
	n0->next = p;
}


//删除链表结点n0之后的首个结点
void removeItem(ListNode *n0){
	if (!n0->next)
	{
		return;
	}
	ListNode *p = n0->next;
	ListNode *n1 = p->next;
	n0->next = n1;
}


//访问链表中索引为index的结点
ListNode *access(ListNode *head, int index){
	for (int i = 0; i < index; i++)
	{
		if (head == NULL)
		{
			return NULL;
		}
		head = head->next;
	}
	return head;
}


//查找值为target的首个结点
int find(ListNode *head, int target)
{
	int index = 0;
	while (head)
	{
		if (head->value==target)
		{
			return index;
		}
		head = head->next;
		index++;
	}
	return -1;
}


int main()
{
	//初始化链表 1->2->3->4->5->NULL
	//初始化结点
	ListNode *n0 = newListNode(0);
	ListNode *n1 = newListNode(1);
	ListNode *n2 = newListNode(2);
	ListNode *n3 = newListNode(3);
	ListNode *n4 = newListNode(4);
	ListNode *n5 = newListNode(5);
	//把结点连起来形成链表
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;


	//遍历输出链表
	ListNode *p = n0;//创建一个遍历用的工具指针
	printf("链表：");
	while (p != NULL)
	{
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
	return 0;
}