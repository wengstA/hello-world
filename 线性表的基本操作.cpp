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
// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
   L.elem=new ElemType[LIST_INIT_SIZE];
   L.length=0;
   return OK;
// 请补全代码

}

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	int i;
	if(L.length==0) printf("The List is empty!");  // 请填空
	else
	{
		printf("The List is: ");
		for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);  // 请填空
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
	if(InitList_Sq(T))    // 判断顺序表是否创建成功
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
					if(!ListInsert_Sq(T,i,x)) printf("Insert Error!\n"); // 判断i值是否合法，请填空
					else printf("The Element %d is Successfully Inserted!\n", x);
					break;
			case 2: scanf("%d",&i);
					if(!ListDelete_Sq(T,i,e)) printf("Delete Error!\n"); // 判断i值是否合法，请填空
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}

