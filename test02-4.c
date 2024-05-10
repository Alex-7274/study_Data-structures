#include<stdio.h>
#include<stdlib.h>


//��㹹����
typedef struct ListNode{
	int value;
	struct ListNode *next;
} ListNode;


//�������
ListNode *newListNode(int val){
	ListNode *node;
	node = (ListNode *)malloc(sizeof(ListNode));
	node->value = val;
	node->next = NULL;
	return node;
}


//������Ľ��n0֮�������p
void insert(ListNode *n0,ListNode *p){
	ListNode *n1 = n0->next;
	p->next = n1;
	n0->next = p;
}


//ɾ��������n0֮����׸����
void removeItem(ListNode *n0){
	if (!n0->next)
	{
		return;
	}
	ListNode *p = n0->next;
	ListNode *n1 = p->next;
	n0->next = n1;
}


//��������������Ϊindex�Ľ��
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


//����ֵΪtarget���׸����
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
	//��ʼ������ 1->2->3->4->5->NULL
	//��ʼ�����
	ListNode *n0 = newListNode(0);
	ListNode *n1 = newListNode(1);
	ListNode *n2 = newListNode(2);
	ListNode *n3 = newListNode(3);
	ListNode *n4 = newListNode(4);
	ListNode *n5 = newListNode(5);
	//�ѽ���������γ�����
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;


	//�����������
	ListNode *p = n0;//����һ�������õĹ���ָ��
	printf("����");
	while (p != NULL)
	{
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
	return 0;
}