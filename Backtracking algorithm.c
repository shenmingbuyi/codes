#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void back(int* a, int b, int n)
{
	int c[100];
	int candi;
	int i;

	if (b == n) 
	{
		printf("{");
		for (i = 1; i <= b; ++i)
		{
			if (a[i] == 1)
			{
				printf("%d", i);
			}
		}
		printf("}\n");
	}
	else {
		b = b + 1;
		
		
			c[0] = -1;
			c[1] = 1;
			candi = 2;
		
		for (i = 0; i < candi; i++) 
		{
			a[b] = c[i];
			back(a, b, n);
		}
	}
}

void generate(int n) 
{
	int *a = (int*)malloc(sizeof(int)*n);
	 memset(a, 0, sizeof(int) * n);
	 for (int i = 0; i < n; i++)
	 {
		 a[i] = i + 1;
	 }
	back(a, 0, n);
}
int main()
{
	generate(3);
	system("pause");
	return 0;
}