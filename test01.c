#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
���Ա�˳��洢�ṹ��˳��������
*/



#define MAX_SIZE 10 //�������Ա��������
//���Ա�ṹ�嶨��
typedef struct {
	int data[MAX_SIZE];
	int length;
} sqlist;

//��ʼ�����Ա�
void InitList(sqlist *list){ //�ں��������У�*listͨ�����ڱ�ʾ�ò�����һ��ָ�룬���������޸�ָ����ָ���ֵ��
	list->length = 0; //��ʾ���ʽṹ��ָ��list��ָ��Ľṹ���е�length��Ա��
}

//���Ԫ��
int AddElement(sqlist *list, int element){
	if (list->length >= MAX_SIZE){
		return 0; //�жϱ��Ƿ�����
	}
	list->data[list->length] = element; //��Ԫ����ӵ�����ĩβ
	list->length++;
	return 1;
}

//����Ԫ�أ���list��λ��i������Ԫ��e��
bool ListInsert(sqlist *list, int i, int e){
	if (i<1 || i>list->length || i>=MAX_SIZE)
	{
		return false;
	}
	for (int j = list->length; j >= i; j--)
	{
		list->data[j] = list->data[j - 1];
	}
	list->data[i - 1] = e;
	list->length++;
	return true;
}

//ɾ��������ɾ��list�е�i��λ�õ�Ԫ�ز����ñ���e���أ�
bool ListDelete(sqlist *list, int i){
	if (i<1||i>list->length)
	{
		return false;
	}

	for (int j = i; j < list->length; j++)
	{
		list->data[j - 1] = list->data[j];
	}
	list->length--;
	return true;
}

//˳���İ�λ���ң���ȡlist�е�i��λ�õ�Ԫ��ֵ��
int GetElem(sqlist list, int i){
	return list.data[i - 1];
}

/*�ϲ�����˳���
bool CombineList1(sqlist list1, sqlist list2, sqlist &list3) {
	InitList(list3);
	int i = 0, j = 0;
	int k = 0;
	while (i < list1.length)
		list3->data[k++] = list1.data[i++];
	while (j < list2.length)
		list3->data[k++] = list2.data[j++];
	list3->length = k;
	return true;
}
*/

//�����ӡ��
void ReverseList(sqlist list){
	int temp;
	for (int i = 0; i < list.length / 2; i++)
	{
		temp = list.data[i];
		list.data[i] = list.data[list.length - i - 1];
		list.data[list.length - i - 1] = temp;
	}
	for (int i = 0; i <list.length; i++)
	{
		printf("%d\n", list.data[i]);
	}
}

//��ӡ���Ա�
void PrintList(sqlist list){
	for (int i = 0; i <list.length; i++)
	{
		printf("%d\n", list.data[i]);
	}
	printf("\n");
}

int main() {
	sqlist list; //�����ṹ�����list

	InitList(&list); //���ó�ʼ������

	for (int i = 0;i<=MAX_SIZE;i++)
	{
		AddElement(&list, i); //�����Ա�����
	}

	printf("��ʼ˳���Ϊ��\n");
	PrintList(list);//���ô�ӡ����

	if (ListInsert(&list,5,50)==true)
	{
		printf("����Ԫ��֮��ı�Ϊ��\n");
		for (int i = 0; i < list.length; i++)
		{
			printf("data[%d] = %d\n", i, list.data[i]);
		}
		printf("����Ϊ��%d\n\n", list.length);
	}

	if (ListDelete(&list, 3) == true)
	{
		printf("ɾ��Ԫ��֮��ı�Ϊ��\n");
		for (int i = 0; i < list.length; i++)
		{
			printf("data[%d] = %d\n", i, list.data[i]);
		}
		printf("����Ϊ��%d\n\n", list.length);
	}
	return 0;
}
