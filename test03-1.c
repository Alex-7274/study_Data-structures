#include<stdio.h>
#include<stdlib.h>

//���������ʵ��
//���ṹ�嶨��
typedef struct BTNode{
	char data;
	struct BTNode *LChild, *RChild;
}BTNode, *BTree;

//ǰ�����
void PreOrderTraverse(BTree T){
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrderTraverse(T->LChild);
	PreOrderTraverse(T->RChild);
}

//�������
void InOrderTraverse(BTree T){
	if (T == NULL)
		return;
	PreOrderTraverse(T->LChild);
	printf("%c", T->data);
	PreOrderTraverse(T->RChild);
}

//�������
void PostOrderTraverse(BTree T){
	if (T == NULL)
		return;
	PostOrderTraverse(T->LChild);
	PostOrderTraverse(T->RChild);
	printf("%c", T->data);
}

//������������������������������д洢
//char str[24];
//int index = 0;


//ǰ�򷨴���������
void CreateTree(BTree *T){		//ע�� ����ʹ�ö���ָ�룬��Ϊ����Ҫ�޸�ָ���ֵ
	char ch;
	//����һ ÿ�εݹ��������ֵ ����12#3##4##
	scanf_s("%c", &ch);
	//ch = str[index++];  //������ �������ַ���
	if (ch == '#')		//ͨ�����롮#���������Ƿ�������ҷ�֧�ӽ��
		*T = NULL;		//���롮#��������ս��,'##'���������ӽڵ㶼Ϊ��
	else{
		*T = (BTNode *)malloc(sizeof(BTNode));
		(*T)->data = ch;
		CreateTree(&(*T)->LChild);
		CreateTree(&(*T)->RChild);
	}
}

int main(){

	BTree root = (BTNode *)malloc(sizeof(BTNode));
	printf("����ǰ�����˳����������������\n");
	//scanf_s("%s",str);  //��������Ӧ����
	CreateTree(&root);
	printf("\n������������\n");
	PreOrderTraverse(root);
	printf("\n������������\n");
	InOrderTraverse(root);
	printf("\n������������\n");
	PostOrderTraverse(root);
	printf("\n");
	

	/*
	//��������������ֽ�ʾ��
	BTree root = (BTNode *)malloc(sizeof(BTNode));//���������
	root->data = 1;

	BTNode *p1 = (BTNode *)malloc(sizeof(BTNode));//�����ڵ�p1��ʹ���ڵ����ָ֧��p1
	p1->data = 2;
	root->LChild = p1;

	BTNode *p1_1 = (BTNode *)malloc(sizeof(BTNode));//p1�����ӽڵ�
	p1_1->data = 4;
	p1->LChild = p1_1;

	BTNode *p2 = (BTNode *)malloc(sizeof(BTNode));//�����ڵ�p2��ʹ���ڵ����ָ֧��p2
	p2->data = 3;
	root->RChild = p2;

	BTNode *p2_1 = (BTNode *)malloc(sizeof(BTNode));//p2�����ӽڵ�
	p2_1->data = 5;
	p2->RChild = p2_1;

	printf("����%d�����ӽ�㣺%d�����ӽڵ㣺%d\n",root->data,root->LChild->data,root->RChild->data);

	printf("���ӽڵ�p1�����ӽڵ�p1_1:%d\n",p1->LChild->data);
	printf("���ӽڵ�p2�����ӽڵ�p2_1:%d\n", p2->RChild->data);
	*/
	
	return 0;
}
