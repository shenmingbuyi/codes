#include <stdio.h>
#include <stdlib.h>
//��ȡ��������
typedef char Data;
//���������
typedef struct Node
{
	Data data;
	struct Node *LChild;
	struct Node *RChild;
}TNode, *BiTree;   
void CreateBiTree(BiTree* bt)  //�������������������
{
	char ch;
	ch = getchar();
	if (ch == '.')
		(*bt) = NULL;
	else
	{
		*bt = (BiTree)malloc(sizeof(TNode));
		(*bt)->data = ch;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
}
void FirstTree(BiTree root) //�������������
{
	if (root != NULL)
	{
		printf("%c", root->data);
		FirstTree(root->LChild);
		FirstTree(root->RChild);
	}
}
int LeafCount = 0;
void leaf(BiTree root)  //���Ҷ�ӽ�����Ŀ
{
	if (root != NULL)
	{
		leaf(root->LChild);
		leaf(root->RChild);

		if (root->LChild == NULL && root->RChild == NULL)
			LeafCount++;
	}
}

int main()
{
	BiTree bt;
	//�������ø��ڵ�ָ���ӽڵ㣬
	printf("�������������������:\n");
	CreateBiTree(&bt);
	FirstTree(bt);
	printf("\n");
	printf("�������Ҷ�ӽ����ĿΪ��\n");
	leaf(bt);
	printf("%d\n", LeafCount);

	system("pause");
}