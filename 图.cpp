/*
����ͼ�Ľ���
1.���ö�ά����
2.�û��Լ��жϽڵ�Ĺ�ϵ
3.�ӹ�ϵ�������Լ��ı�
*/
#include <stdio.h>
#include <queue>
#include<stdio.h>
#define MAX 20
typedef struct
{
	//��ʾ����λ��
	char verctory[MAX];
	//��ʾ���ı�
	char arcs[MAX][MAX];
}Graph;
/**��ʼ��**/
//�߳�ʼ��Ϊ0
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
/**����**/
void CreatGraph(Graph *G, int a)
{
	int i, j;
	printf("�����������ݣ�\n");
	for (i = 0; i<a; i++)
	{
		scanf("%c", &G->verctory[i]);//��ȡ���
		getchar();
	}
	for (i = 0; i<a; i++)
	{
		for (j = i + 1; j<a; j++)
		{
			printf("%c��%c֮���Ƿ��й�:\n", G->verctory[i], G->verctory[j]);
			scanf("%d", &G->arcs[i][j]);//���ڱߵ���Ϣ
			G->arcs[j][i] = G->arcs[i][j];//��Ϊ������ͼ�����Զ�Ӧ�Ķ�ά�����ضԽ��߶Գ�
		}
	}

}
/**�����Ѱ**/
//1.a,n�����
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
/**��ʼ��**/
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
	printf("��������Ҫ����ĵ�����\n");
	scanf("%d", &a);
	SETGraph(&G, a);
	CreatGraph(&G, a);
	printf("�����뿪ʼ�ĵ㣺\n");
	scanf("%d", &n);
	getchar();
	printf("\n�����ѰΪ��\n");
	DFS(&G, n, a);
	printGraph(&G, a, n);


		system("pause");
}