#include<stdio.h>
#include<stdlib.h>
/*
�������㷨��ʵ�֣����ʾ���һ��������
*/

//������������Ľṹ��
typedef struct TreeNode{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

//�����½��
TreeNode *createNode(int value){
	TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// ����ڵ㣨����ʵ���˲����½����Ϊ��/���ӽ�㣩  
void insertNode(TreeNode** root, int value,int isLeft) {
	if (*root == NULL) {
		// ������ڵ�Ϊ�գ��򴴽��½ڵ���Ϊ���ڵ� 
		*root = createNode(value);
	}
	else
	{
		// ���򣬵ݹ�������������������в���ڵ�  
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

// ǰ�����������
void preOrderTraversal(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->value);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

// �������������  
void inOrderTraversal(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	inOrderTraversal(root->left);
	printf("%d ", root->value);
	inOrderTraversal(root->right);
}

// �������������  
void postOrderTraversal(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%d ", root->value);
}

// �ͷŶ������ڴ�  
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


	printf("ǰ�����������");
	preOrderTraversal(root);
	printf("\n");

	printf("�������������");
	inOrderTraversal(root);
	printf("\n");

	printf("�������������");
	postOrderTraversal(root);
	printf("\n");

	freeTree(root);

	return 0;
}