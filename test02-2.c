#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
������㷨ʵ����ԭ��
*/

//�����ṹ���ʾһ�����
typedef struct student
{
	//������
	const char *name;
	int age;
	//ָ����
	struct student *next;

}student;

//�������ӣ��γ�����
int CreatLink(){
	student *p, *head, *p1, *p2;//p���ͷ��㣬p2�����һ�ε��ڴ�λ�ã�p1��Ǻ�һ��
	head = NULL;
	p2 = NULL;
	for (int i = 0; i <=10; i++)
	{
		p1 = (student *)malloc(sizeof(student));//�����ڴ�
		p1->age = i;
		p1->next = NULL;//��ʱp1����ͷҲ��β���
		if (head == 0)
		{//�������Ϊ�գ�p1����ͷ�ڵ�
			head = p1;
			p2 = p1;
		}
		else
		{//���򣬽�p1��ӵ������ĩβ
			p2->next = p1;
			p2 = p1;
		}
	}

	//�����������
	p1->next = NULL;//p1ָ��β���
	p = head;//pΪ����׼���Ĺ���ָ��
	printf("����");
	while (p != NULL)
	{
		printf("%d ", p->age);
		p = p->next;
	}

	printf("\n�ͷ��ڴ�\n");
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

	L1->next = L2;//������������������������  L1->L2->...

	free(L1, L2);
	return 0;
}
