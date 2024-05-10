#include<stdio.h>
#include<stdlib.h>
/*
二叉树算法的实现，本质就是一堆链表结点
*/

//定义二叉树结点的结构体
typedef struct TreeNode{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

//创建新结点
TreeNode *createNode(int value){
	TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// 插入节点（这里实现了插入新结点作为左/右子结点）  
void insertNode(TreeNode** root, int value,int isLeft) {
	if (*root == NULL) {
		// 如果根节点为空，则创建新节点作为根节点 
		*root = createNode(value);
	}
	else
	{
		// 否则，递归地在左子树或右子树中插入节点  
		if (isLeft)
		{
			insertNode(&((*root)->left), value, 1);
		}
		else
		{
			insertNode(&((*root)->right), value, 0);
		}
	}
}

// 前序遍历二叉树
void preOrderTraversal(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->value);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

// 中序遍历二叉树  
void inOrderTraversal(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	inOrderTraversal(root->left);
	printf("%d ", root->value);
	inOrderTraversal(root->right);
}

// 后序遍历二叉树  
void postOrderTraversal(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%d ", root->value);
}

// 释放二叉树内存  
void freeTree(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

int main(){
	TreeNode *root = NULL;

	/*
		insertNode(&root, 1, 1);
	insertNode(&root, 2, 1);
	insertNode(&root, 3, 0);
	insertNode(&root, 4, 1);
	insertNode(&root->right, 5, 1);
	insertNode(&root->right, 6, 0);
	insertNode(&root, 7, 0);
	*/

	insertNode(&root, 1, 1);
	insertNode(&root, 2, 0);
	insertNode(&root, 3, 1);
	insertNode(&root, 4, 0);
	insertNode(&root, 5, 1);


	printf("前序遍历二叉树");
	preOrderTraversal(root);
	printf("\n");

	printf("中序遍历二叉树");
	inOrderTraversal(root);
	printf("\n");

	printf("后序遍历二叉树");
	postOrderTraversal(root);
	printf("\n");

	freeTree(root);

	return 0;
}