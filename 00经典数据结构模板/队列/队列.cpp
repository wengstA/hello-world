#include<malloc.h> 
#include<stdio.h> 
#include<iostream>
#define OK 1
#define ERROR 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int QElemType;
#define MAXQSIZE 100 // �����г���(����ѭ�����У������г���Ҫ��1)
#define MAXSIZE MAXQSIZE
typedef struct
{
   QElemType *base; // ��ʼ���Ķ�̬����洢�ռ�
   int front=0; // ͷָ��,�����в���,ָ�����ͷԪ��
   int rear=0; // βָ��,�����в���,ָ�����βԪ�ص���һ��λ��
 }SqQueue;

Status InitQueue(SqQueue &Q)   
{
// ����һ���ն���Q���ö���Ԥ�����СΪMAXQSIZE
	Q.base=new int[MAXQSIZE];   //����ռ� 
	return OK;
// �벹ȫ����
	
}

Status EnQueue(SqQueue &Q,QElemType &e)  
{ 
// ����Ԫ��eΪQ���µĶ�βԪ��
   if((Q.rear+1)%MAXSIZE==Q.front)return ERROR;   //����һ���ͻ���ͷ�ڵ� 
	Q.rear=(Q.rear+1)%MAXQSIZE;
    Q.base[Q.rear]=e;
	return OK;
// �벹ȫ����
	
}

Status DeQueue(SqQueue &Q, QElemType &e) 
{  
// �����в���, ��ɾ��Q�Ķ�ͷԪ��, ��e������ֵ, ������OK; ���򷵻�ERROR
if(Q.front!=Q.rear)     //��֤���в��ǿն��� 
	{
		Q.front=(Q.front+1)%MAXQSIZE;  //����ָ����ǿյ� 
		e=Q.base[Q.front];
			return OK;
	}
else return ERROR;	
// �벹ȫ����
	
}

Status GetHead(SqQueue &Q, QElemType &e)
{	
// �����в��գ�����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
	if(Q.rear==Q.front) 
	{
		printf("YES");
	return ERROR;
	}
	e=Q.base[Q.front+1];
	return e;	
// �벹ȫ����
	
}

int QueueLength(SqQueue &Q)  
{
// ����Q��Ԫ�ظ���
    if(Q.rear==Q.front) return ERROR;
	int result;
	if(Q.rear>Q.front) result=Q.rear-Q.front;   //û�н���ĩβ���� 
	else result=Q.front-Q.rear+MAXSIZE+1;    //��ͼ 
	return result;
// �벹ȫ����
	
}

Status QueueTraverse(SqQueue &Q)  
{ 
// �����в��գ���Ӷ�ͷ����β���������������Ԫ�أ�������OK�����򷵻�ERROR.
	int i;
	i=Q.front+1;
	if(Q.rear==Q.front)printf("The Queue is Empty!");  //�����
	else{
		printf("The Queue is: ");
		while(i!=Q.rear)     //�����
		{
			printf("%d ",Q.base[i]);  //�����
			i = (i+1)%MAXSIZE;   //�����
		}
	}
	printf("%d",Q.base[i]);
	printf("\n");
	return OK;
}

int main()
{
	int a;
  SqQueue Q;
	QElemType x, e;
  if(InitQueue(Q))    // �ж�˳����Ƿ񴴽��ɹ��������
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
				  if(!EnQueue(Q,x)) printf("Enter Error!\n"); // �ж�����Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Entered!\n", x); 
				  break;
			case 2: if(!DeQueue(Q,e)) printf("Delete Error!\n"); // �жϳ����Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: if(!GetHead(Q,e))printf("Get Head Error!\n"); // �ж�Get Head�Ƿ�Ϸ��������
				  else printf("The Head of the Queue is %d!\n", e);
				  break;
			case 4: printf("The Length of the Queue is %d!\n",QueueLength(Q));  //�����
				  break;
			case 5: QueueTraverse(Q);//�����
				  break;
			case 0: return 1;
		}
	}
}

