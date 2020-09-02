#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList,*Linklist;

int InitList_Sq(SqList &L)
{
// �㷨2.3������һ���յ����Ա�L�������Ա�Ԥ�����СΪLIST_INIT_SIZE
   L.elem=new ElemType[LIST_INIT_SIZE];
   L.length=0;
   return OK;
// �벹ȫ����

}

int Load_Sq(SqList &L)
{
// ���˳����е�����Ԫ��
	int i;
	if(L.length==0) printf("The List is empty!");  // �����
	else
	{
		printf("The List is: ");
		for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);  // �����
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
  if(i>=1&&i<=L.length)
  {
  	for(int j=L.length;j>=i;j--)  L.elem[j]=L.elem[j-1];
  	L.elem[i-1]=e;
  	L.length++;
  	return OK;
  }
  if(i==L.length+1) 
  {
  	L.length++;
  	L.elem[i-1]=e;
  	return OK;
  }
  return ERROR;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
  if(i>=1&&i<=L.length)
   {
       int j=0;
       e=L.elem[i-1];
       for(j=i-1;j<=L.length-2;j++)
       {
           L.elem[j]=L.elem[j+1];
       }
       L.length--;
       return OK;
   }

   return ERROR;
}


int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T))    // �ж�˳����Ƿ񴴽��ɹ�
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					if(!ListInsert_Sq(T,i,x)) printf("Insert Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
					else printf("The Element %d is Successfully Inserted!\n", x);
					break;
			case 2: scanf("%d",&i);
					if(!ListDelete_Sq(T,i,e)) printf("Delete Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}

