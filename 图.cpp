/*
无向图的建立
1.借用二维数组
2.用户自己判断节点的关系
3.从关系，建立自己的表
*/
#include <stdio.h>
#include <queue>
#include<stdio.h>
#define MAX 20
typedef struct
{
	//表示结点的位置
	char verctory[MAX];
	//表示结点的边
	char arcs[MAX][MAX];
}Graph;
/**初始化**/
//边初始化为0
void SETGraph(Graph *G, int a)
{
	int i, j;
	for (i = 0; i<a; i++)
	{
		for (j = 0; j<a; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
}
/**创建**/
void CreatGraph(Graph *G, int a)
{
	int i, j;
	printf("请输入结点数据：\n");
	for (i = 0; i<a; i++)
	{
		scanf("%c", &G->verctory[i]);//获取结点
		getchar();
	}
	for (i = 0; i<a; i++)
	{
		for (j = i + 1; j<a; j++)
		{
			printf("%c与%c之间是否有关:\n", G->verctory[i], G->verctory[j]);
			scanf("%d", &G->arcs[i][j]);//存于边的信息
			G->arcs[j][i] = G->arcs[i][j];//因为是无向图，所以对应的二维矩阵沿对角线对称
		}
	}

}
/**深度搜寻**/
//1.a,n存点数
//2.visited
void ArrayGraph(Graph *G, int n, int a, bool visited[])
{
	int i;
	printf("%c\t", G->verctory[n]);
	visited[n] = true;
	for (i = 0; i<a; i++)
	{
		if (G->arcs[n][i] != 0 && visited[i] == 0)
		{
			ArrayGraph(G, i, a, visited);
		}
	}
	for (i = 0; i<a; i++)
	{
		if (visited[i] == 0)
		{
			ArrayGraph(G, i, a, visited);
		}

	}
}
/**初始化**/
void DFS(Graph *G, int n, int a)
{
	bool visited[MAX];
	int i;
	for (i = 0; i<a; ++i)
	{
		visited[i] = false;
	}
	ArrayGraph(G, n, a, visited);
}
void printGraph(Graph *G, int a, int n)
{
	Graph *p = G;
	for (int i = 0; i <MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			printf("%d",p->arcs[i][j]);
			if (p->arcs[i][j]==0)
			{
				break;
			}
		}
		printf("%d", p->verctory[i]);

		if (p->verctory[i]==0)
		{
			break;
		}
	}
}
int main(void)
{
	Graph G;
	int a;
	int n;
	printf("请输入想要输入的点数；\n");
	scanf("%d", &a);
	SETGraph(&G, a);
	CreatGraph(&G, a);
	printf("请输入开始的点：\n");
	scanf("%d", &n);
	getchar();
	printf("\n深度搜寻为：\n");
	DFS(&G, n, a);
	printGraph(&G, a, n);


		system("pause");
}