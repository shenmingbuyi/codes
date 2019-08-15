 #include<stdio.h>
 #include<stdlib.h>

typedef struct
{
     int *elem;
     int count;
 }HashTable;

int m = 0;
//��ʼ��hash 
int InitHashTable(HashTable *table)
{
    int i;
    m = 12;
	table->count = m;
	table->elem = (int*)malloc(sizeof(int)*12);
    for (i = 0; i<m; i++)
		table->elem[i] = -32768;
    return 1;
 }
//����ؼ��ֽ���ɢ�б�  
void InsertHash(HashTable *Table, int key)
   {
	   int addr = key%m;;
	   while (Table->elem[addr] != -32768)
		  addr = (addr + 1) % m;
	   Table->elem[addr] = key;
   }

//ɢ�б���ҹؼ���  
   int SearchHash(HashTable Table, int key, int *addr)
{
	*addr = key%m;;
	while (Table.elem[*addr] != key)
  {
		     *addr = (*addr + 1) % m;
			 if (Table.elem[*addr] == -32768 || *addr == key%m)
		         {
		             return -1;
		         }
		 }
     return *addr;
  }
void destroyhashtable(HashTable Table)
{
	int* p1,p2;
	for (int i = 0; i < 11; i++)
	{
		p1 = Table.elem[i];
		p1 = p2;
		free(p2);
	}
	

}
int main()
{
     int a[12] = { 12,46,78,45,56,78,41,58,52,53,49,47 };
     HashTable TableHeader;
     int i=0;
	 InitHashTable(&TableHeader);
     for (i = 0; i<m; i++)
		 InsertHash(&TableHeader, a[i]);
     printf("����֮��Ĺ�ϣ��Ϊ��");
     for (i = 0; i<m; i++)
		 printf("%d,", TableHeader.elem[i]);
	 int addr=0, j=0;
	 j = SearchHash(TableHeader, a[3], &addr);
	 printf("������a[3]�ĵ�ַ�ǣ�%d", j);
	 system("pause");
}
