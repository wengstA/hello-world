
#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int* elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList ,& L)
{

	ElemType List[LIST_INIT_SIZE];
	*L.elem=List;
	*L.length=0;
	*L.listsize=LIST_INIT_SIZE;

}

int Load_Sq(SqList*L)
{
	// 输出顺序表中的所有元素
	int i;
	if (L.lenth==0) printf("The List is empty!");  // 请填空
	else
	{
		printf("The List is: ");
		for (int i=0;i<L.length-1;i++) printf("%d ",L.elem+L.length-1);  // 请填空
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList& L, int i, int e)
{
	// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
	if(i<L.length){
		length=i;
		L.elem[i-1]=e;
	}
	else{
		fot(ElemType pre=L.lenght;pre>i;pre--)
		{
			L.elem[pre]=L.elem[pre-1];
		}
		L.elem[i-1]=e;
	}

	// 请补全代码

}

int ListDelete_Sq(SqList& L, int i, int& e)
{
	// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
	// i的合法值为1≤i≤L.length
	for(int pre=i-1;pre<L.length-1;pre++)
	{
		L.elem[pre]=L.elem[pre+1];
	}
	length--;
	// 请补全代码
   return 0;
}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if (InitList_Sq(SqList & T))    // 判断顺序表是否创建成功
	{
		printf("A Sequence List Has Created.\n");
	}
	while (1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1: scanf("%d%d", &i, &x);
			if (!(i>=1&&i<=T.length+1); printf("Insert Error!\n"); // 判断i值是否合法，请填空
			else printf("The Element %d is Successfully Inserted!\n", x);
			break;
		case 2: scanf("%d", &i);
			if (!(i>=1&&i<=T.length) printf("Delete Error!\n"); // 判断i值是否合法，请填空
			else printf("The Element %d is Successfully Deleted!\n", e);
			break;
		case 3: Load_Sq(T);
			break;
		case 0: return 1;
		}
	}
}
