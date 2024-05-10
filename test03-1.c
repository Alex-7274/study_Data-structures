#include<stdio.h>
#include<stdlib.h>

//二叉链表的实现
//结点结构体定义
typedef struct BTNode{
	char data;
	struct BTNode *LChild, *RChild;
}BTNode, *BTree;

//前序遍历
void PreOrderTraverse(BTree T){
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrderTraverse(T->LChild);
	PreOrderTraverse(T->RChild);
}

//中序遍历
void InOrderTraverse(BTree T){
	if (T == NULL)
		return;
	PreOrderTraverse(T->LChild);
	printf("%c", T->data);
	PreOrderTraverse(T->RChild);
}

//后序遍历
void PostOrderTraverse(BTree T){
	if (T == NULL)
		return;
	PostOrderTraverse(T->LChild);
	PostOrderTraverse(T->RChild);
	printf("%c", T->data);
}

//方法二：先序遍历创建二叉树的序列存储
//char str[24];
//int index = 0;


//前序法创建二叉树
void CreateTree(BTree *T){		//注意 这里使用二级指针，因为我们要修改指针的值
	char ch;
	//方法一 每次递归进行输入值 例：12#3##4##
	scanf_s("%c", &ch);
	//ch = str[index++];  //方法二 先输入字符串
	if (ch == '#')		//通过输入‘#’来决定是否添加左右分支子结点
		*T = NULL;		//输入‘#’代表传入空结点,'##'代表左右子节点都为空
	else{
		*T = (BTNode *)malloc(sizeof(BTNode));
		(*T)->data = ch;
		CreateTree(&(*T)->LChild);
		CreateTree(&(*T)->RChild);
	}
}

int main(){

	BTree root = (BTNode *)malloc(sizeof(BTNode));
	printf("按照前序遍历顺序来创建二叉树：\n");
	//scanf_s("%s",str);  //方法二对应代码
	CreateTree(&root);
	printf("\n先序遍历结果：\n");
	PreOrderTraverse(root);
	printf("\n中序遍历结果：\n");
	InOrderTraverse(root);
	printf("\n后序遍历结果：\n");
	PostOrderTraverse(root);
	printf("\n");
	

	/*
	//二叉树创建步骤分解示例
	BTree root = (BTNode *)malloc(sizeof(BTNode));//创建根结点
	root->data = 1;

	BTNode *p1 = (BTNode *)malloc(sizeof(BTNode));//创建节点p1，使根节点左分支指向p1
	p1->data = 2;
	root->LChild = p1;

	BTNode *p1_1 = (BTNode *)malloc(sizeof(BTNode));//p1的左子节点
	p1_1->data = 4;
	p1->LChild = p1_1;

	BTNode *p2 = (BTNode *)malloc(sizeof(BTNode));//创建节点p2，使根节点左分支指向p2
	p2->data = 3;
	root->RChild = p2;

	BTNode *p2_1 = (BTNode *)malloc(sizeof(BTNode));//p2的右子节点
	p2_1->data = 5;
	p2->RChild = p2_1;

	printf("根：%d，左子结点：%d，右子节点：%d\n",root->data,root->LChild->data,root->RChild->data);

	printf("左子节点p1的左子节点p1_1:%d\n",p1->LChild->data);
	printf("右子节点p2的右子节点p2_1:%d\n", p2->RChild->data);
	*/
	
	return 0;
}
