#include<stdio.h>
#include<stdlib.h>
/*
���Խṹ������
*/

//�����������
int randomAccess(int *nums,int size)
{
	int randomIndex = rand() % size;
	int randomNum = nums[randomIndex];
	return randomNum;
}

//��index������Ԫ��num
void insert(int *nums, int size, int num, int index)
{
	for (int i = size - 1 ; i > index; i++)
	{
		for (int i = size - 1; i > index; i++)
		{
			nums[i] = nums[i - 1];
		}
		nums[index] = num;
	}
}

//ɾ��index����Ԫ��
void removeItem(int *nums, int size, int index)
{
	for (int i = index; i < size -1 ; i++)
	{
		nums[i] = nums[i + 1];
	}
}

//����
void traverse(int *nums, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count = nums[i];
		printf("%d ",count);
	}
	printf("\n");
}

//����Ԫ��
int find(int *nums, int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (nums[i] == target)
		{
			return i;
		}
	}
	return	-1;
}

/* ��չ���鳤�� */
int *extend(int *nums, int size, int enlarge) {
	// ��ʼ��һ����չ���Ⱥ������
	int *res = (int *)malloc(sizeof(int) * (size + enlarge));
	// ��ԭ�����е�����Ԫ�ظ��Ƶ�������
	for (int i = 0; i < size; i++) {
		res[i] = nums[i];
	}
	// ��ʼ����չ��Ŀռ�
	for (int i = size; i < size + enlarge; i++) {
		res[i] = 0;
	}
	// ������չ���������
	return res;
}

int main()
{
	//��ʼ������
	int arr[5] = { 0 };
	int nums[5] = { 1, 3, 2, 5, 4};
	printf("�����ѡ�����е�һ��Ԫ�أ�%d\n",randomAccess(nums, 5));

	printf("����������飺");
	traverse(nums, 5);

	printf("����������ɾ��������Ԫ���±꣺");
	int p;
	scanf_s("%d", &p);
	removeItem(nums, 5, p);
	traverse(nums, 4);

	return 0;
}
