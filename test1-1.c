#include<stdio.h>
#include<stdlib.h>
/*
线性结构，数组
*/

//随机访问数组
int randomAccess(int *nums,int size)
{
	int randomIndex = rand() % size;
	int randomNum = nums[randomIndex];
	return randomNum;
}

//在index处插入元素num
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

//删除index处的元素
void removeItem(int *nums, int size, int index)
{
	for (int i = index; i < size -1 ; i++)
	{
		nums[i] = nums[i + 1];
	}
}

//遍历
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

//查找元素
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

/* 扩展数组长度 */
int *extend(int *nums, int size, int enlarge) {
	// 初始化一个扩展长度后的数组
	int *res = (int *)malloc(sizeof(int) * (size + enlarge));
	// 将原数组中的所有元素复制到新数组
	for (int i = 0; i < size; i++) {
		res[i] = nums[i];
	}
	// 初始化扩展后的空间
	for (int i = size; i < size + enlarge; i++) {
		res[i] = 0;
	}
	// 返回扩展后的新数组
	return res;
}

int main()
{
	//初始化数组
	int arr[5] = { 0 };
	int nums[5] = { 1, 3, 2, 5, 4};
	printf("随机挑选数组中的一个元素：%d\n",randomAccess(nums, 5));

	printf("遍历输出数组：");
	traverse(nums, 5);

	printf("请输入你想删除的数组元素下标：");
	int p;
	scanf_s("%d", &p);
	removeItem(nums, 5, p);
	traverse(nums, 4);

	return 0;
}
