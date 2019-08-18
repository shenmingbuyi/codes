#include <stdio.h>
#include <stdlib.h>
//存取数据类型
typedef char Data;
//定义二叉树
typedef struct Node
{
	Data data;
	struct Node *LChild;
	struct Node *RChild;
}TNode, *BiTree;   
void CreateBiTree(BiTree* bt)  //用先序遍历创建二叉树
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
void FirstTree(BiTree root) //先序遍历二叉树
{
	if (root != NULL)
	{
		printf("%c", root->data);
		FirstTree(root->LChild);
		FirstTree(root->RChild);
	}
}
int LeafCount = 0;
void leaf(BiTree root)  //求出叶子结点的数目
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
	//二叉树用父节点指向子节点，
	printf("用先序遍历创建二叉树:\n");
	CreateBiTree(&bt);
	FirstTree(bt);
	printf("\n");
	printf("这棵树的叶子结点数目为：\n");
	leaf(bt);
	printf("%d\n", LeafCount);

	system("pause");
}