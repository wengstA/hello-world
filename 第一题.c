
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
	// ���˳����е�����Ԫ��
	int i;
	if (L.lenth==0) printf("The List is empty!");  // �����
	else
	{
		printf("The List is: ");
		for (int i=0;i<L.length-1;i++) printf("%d ",L.elem+L.length-1);  // �����
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList& L, int i, int e)
{
	// �㷨2.4����˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
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

	// �벹ȫ����

}

int ListDelete_Sq(SqList& L, int i, int& e)
{
	// �㷨2.5,��˳�����Ա�L��ɾ����i��λ�õ�Ԫ�أ�����e������ֵ
	// i�ĺϷ�ֵΪ1��i��L.length
	for(int pre=i-1;pre<L.length-1;pre++)
	{
		L.elem[pre]=L.elem[pre+1];
	}
	length--;
	// �벹ȫ����
   return 0;
}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if (InitList_Sq(SqList & T))    // �ж�˳����Ƿ񴴽��ɹ�
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
			if (!(i>=1&&i<=T.length+1); printf("Insert Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
			else printf("The Element %d is Successfully Inserted!\n", x);
			break;
		case 2: scanf("%d", &i);
			if (!(i>=1&&i<=T.length) printf("Delete Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
			else printf("The Element %d is Successfully Deleted!\n", e);
			break;
		case 3: Load_Sq(T);
			break;
		case 0: return 1;
		}
	}
}
