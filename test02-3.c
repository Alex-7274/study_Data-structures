#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*
������㷨ʵ��
*/


//������������δ���������ܻ��о�����������
LinkList *initList(LinkList *L);
LinkList *createList(int len);
int insertLinkList(LinkList *L, int pos, ElemType e);
int deleteLinkList(LinkList *L, int pos, ElemType *e);
void reverseLinkList(LinkList *L);
int seachLinkList(LinkList *L, ElemType e);
int getLen(LinkList *L);
int isEmpty(LinkList *L);
void printLinkList(LinkList *L);

typedef int ElemType;

//���嵥����ṹ
typedef struct Node
{
	ElemType data;//������
	struct Node *next;//ָ����ָ����һ�ڵ�
} LinkList;


int main()
{
	LinkList *L;
	ElemType e;
	int len, pos;
	printf("����Ԫ�ظ�����");
	scanf_s("%d", &len);
	printf("\n�����룺");
	L = createList(len);
	printf("��ǰ��������Ԫ�أ�");
	printLinkList(L);
	printf("\n����λ�úͲ���ֵ(�м��ÿո����)��");
	scanf_s("%d%d", &pos, &e);
	insertLinkList(L, pos, e);
	printf("\n����Ԫ�غ���������Ԫ�أ�");
	printLinkList(L);
	printf("\n������ɾ��Ԫ��λ�ã�");
	scanf_s("%d", &pos);
	deleteLinkList(L, pos, &e);
	printf("\nԪ��%d��ɾ��", e);
	printf("\nɾ������������Ԫ�أ�");
	printLinkList(L);
	printf("\n���������Ԫ�أ�");
	scanf_s("%d", &e);
	if (seachLinkList(L, e) != -1)
	{
		printf("\n%dλ�ڣ�%d", e, seachLinkList(L, e));
	}
	else printf("\n%dδ�ҵ�", e);
	reverseLinkList(L);
	printf("\nת�ú���������Ԫ�أ�");
	printLinkList(L);
	return 0;
}


//��ʼ��������ͷ���
LinkList *initList(LinkList *L)
{
	L = (LinkList *)malloc(sizeof(LinkList));//Ϊͷ������ռ�
	L->next = NULL;//ͷ���ָ�����ÿ�
	return L;
}


//����ָ�������ĵ�����
LinkList *createList(int len)
{
	int i;
	ElemType e;
	LinkList *L = NULL, *r, *n;//�ֱ���ͷָ�롢βָ�롢��ָ��
	L = initList(L);
	r = L;//βָ���ʼ��Ϊͷָ��
	for (i = 0; i < len; i++)
	{
		scanf_s("%d", &e);
		n = (LinkList *)malloc(sizeof(LinkList));//����ռ�
		n->data = e;
		n->next = NULL;//��ָ��ָ�����ÿ�

		r->next = n;//����ָ�����뵥����ĩβ
		r = r->next;//βָ��������
	}
	return L;
}


//��Ԫ�ز���ָ��λ��
int insertLinkList(LinkList *L, int pos, ElemType e)
{
	if (pos < 1 || pos > getLen(L) + 1) 
	{
		return 0;//����λ�ô���
	}
	LinkList *r = L, *n;
	n = (LinkList *)malloc(sizeof(LinkList));
	n->data = e;
	n->next = NULL;
	while (--pos > 0)
	{
		r = r->next;//��βָ���ƶ�������λ��
	}
	n->next = r->next;//�Ȱ���ָ�루����ֵ������βָ���һ���ڵ�
	r->next = n;//�ٰ���ָ�루����ֵ������βָ��֮��
	return 1;
}


//��ָ��λ��Ԫ��ɾ��
int deleteLinkList(LinkList *L, int pos, ElemType *e)
{
	if (pos < 1 || pos > getLen(L)) return 0;//ɾ��λ�ô���
	LinkList *r = L, *d;
	while (--pos > 0)
	{
		r = r->next;//��βָ���ƶ���ɾ��λ��
	}
	d = r->next;//ɾ��Ԫ�ؽڵ�
	*e = d->data;//����ɾ��Ԫ��ֵ
	r->next = d->next;//��βָ������ɾ���ڵ�������һ���ڵ�
	free(d);//�ͷ�ɾ���ڵ�
	return 1;
}


//ת�õ���������ͷ�巨
void reverseLinkList(LinkList *L)
{
	LinkList *r, *p, *q;//����βָ�루����ͷָ�룩��������ָ�롢����ָ��
	r = L->next;//βָ�����ͷָ��
	p = q = r->next;//�ӵڶ���Ԫ�ؿ�ʼ
	r->next = NULL;//βָ���ÿ�
	while (q)//q�൱��q != NULL
	{
		q = q->next;//����ָ�����
		p->next = r;//������ָ������βָ��֮ǰ
		L->next = p;//������ָ������ͷָ��֮��
		r = p;//βָ����ǰ��
		p = q;//������ָ�������ָ��ͬ��
	}
}


//����ָ��Ԫ�أ�����ָ��Ԫ��λ��
int seachLinkList(LinkList *L, ElemType e)
{
	if (isEmpty(L)) return -1;
	int pos = 1;//λ���1��ʼ���±���㿪ʼ
	LinkList *r = L->next;
	while (r)
	{
		if (r->data == e) return pos;//�ҵ�ָ��Ԫ�أ�����λ��
		r = r->next;//βָ�����
		pos++;
	}
	return -1;//���������δ�ҵ�����-1
}


int getLen(LinkList *L)
{
	if (L->next == NULL) return 0;//ͷָ��ָ����Ϊ�գ�˵�����������κ�Ԫ��
	int len = 0;
	LinkList *r = L->next;
	while (r)
	{
		r = r->next;//βָ�����
		len++;
	}
	return len;
}


int isEmpty(LinkList *L)
{
	return !L->next;//L->next == NULL���
}


void printLinkList(LinkList *L)
{
	LinkList *p;
	p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}