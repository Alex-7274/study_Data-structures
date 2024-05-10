#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
线性表，顺序存储结构，顺序表≈数组
*/



#define MAX_SIZE 10 //定义线性表最大容量
//线性表结构体定义
typedef struct {
	int data[MAX_SIZE];
	int length;
} sqlist;

//初始化线性表
void InitList(sqlist *list){ //在函数参数中，*list通常用于表示该参数是一个指针，并允许函数修改指针所指向的值。
	list->length = 0; //表示访问结构体指针list所指向的结构体中的length成员。
}

//添加元素
int AddElement(sqlist *list, int element){
	if (list->length >= MAX_SIZE){
		return 0; //判断表是否已满
	}
	list->data[list->length] = element; //将元素添加到数组末尾
	list->length++;
	return 1;
}

//插入元素（在list的位序i处插入元素e）
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

//删除操作（删除list中第i个位置的元素并引用变量e返回）
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

//顺序表的按位查找（获取list中第i个位置的元素值）
int GetElem(sqlist list, int i){
	return list.data[i - 1];
}

/*合并两个顺序表
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

//逆向打印表
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

//打印线性表
void PrintList(sqlist list){
	for (int i = 0; i <list.length; i++)
	{
		printf("%d\n", list.data[i]);
	}
	printf("\n");
}

int main() {
	sqlist list; //创建结构体变量list

	InitList(&list); //调用初始化函数

	for (int i = 0;i<=MAX_SIZE;i++)
	{
		AddElement(&list, i); //将线性表填满
	}

	printf("初始顺序表为：\n");
	PrintList(list);//调用打印函数

	if (ListInsert(&list,5,50)==true)
	{
		printf("插入元素之后的表为：\n");
		for (int i = 0; i < list.length; i++)
		{
			printf("data[%d] = %d\n", i, list.data[i]);
		}
		printf("表长度为：%d\n\n", list.length);
	}

	if (ListDelete(&list, 3) == true)
	{
		printf("删除元素之后的表为：\n");
		for (int i = 0; i < list.length; i++)
		{
			printf("data[%d] = %d\n", i, list.data[i]);
		}
		printf("表长度为：%d\n\n", list.length);
	}
	return 0;
}
