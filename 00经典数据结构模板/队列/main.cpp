#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int QElemType;
#define MAXQSIZE 100 // �����г���(����ѭ�����У������г���Ҫ��1)
typedef long long ll;
using namespace std;

int main()
{
	int a;
  SqQueue S;
	QElemType x, e;
  if(______________________)    // �ж�˳����Ƿ񴴽��ɹ��������
	{
		printf("A Queue Has Created.\n");
	}
	while(1)
	{
	printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d", &x);
				  if(______________________) printf("Enter Error!\n"); // �ж�����Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Entered!\n", x);
				  break;
			case 2: if(______________________) printf("Delete Error!\n"); // �жϳ����Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: if(______________________)printf("Get Head Error!\n"); // �ж�Get Head�Ƿ�Ϸ��������
				  else printf("The Head of the Queue is %d!\n", e);
				  break;
			case 4: printf("The Length of the Queue is %d!\n",______________________);  //�����
				  break;
			case 5: ______________________ //�����
				  break;
			case 0: return 1;
		}
	}
}
