#include<malloc.h> 
#include<stdio.h> 
#include<iostream>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)
#define MAXSIZE MAXQSIZE
typedef struct
{
   QElemType *base; // 初始化的动态分配存储空间
   int front=0; // 头指针,若队列不空,指向队列头元素
   int rear=0; // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue;

Status InitQueue(SqQueue &Q)   
{
// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
	Q.base=new int[MAXQSIZE];   //分配空间 
	return OK;
// 请补全代码
	
}

Status EnQueue(SqQueue &Q,QElemType &e)  
{ 
// 插入元素e为Q的新的队尾元素
   if((Q.rear+1)%MAXSIZE==Q.front)return ERROR;   //加入一个就会变成头节点 
	Q.rear=(Q.rear+1)%MAXQSIZE;
    Q.base[Q.rear]=e;
	return OK;
// 请补全代码
	
}

Status DeQueue(SqQueue &Q, QElemType &e) 
{  
// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
if(Q.front!=Q.rear)     //保证队列不是空队列 
	{
		Q.front=(Q.front+1)%MAXQSIZE;  //本来指向的是空的 
		e=Q.base[Q.front];
			return OK;
	}
else return ERROR;	
// 请补全代码
	
}

Status GetHead(SqQueue &Q, QElemType &e)
{	
// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
	if(Q.rear==Q.front) 
	{
		printf("YES");
	return ERROR;
	}
	e=Q.base[Q.front+1];
	return e;	
// 请补全代码
	
}

int QueueLength(SqQueue &Q)  
{
// 返回Q的元素个数
    if(Q.rear==Q.front) return ERROR;
	int result;
	if(Q.rear>Q.front) result=Q.rear-Q.front;   //没有进入末尾倒插 
	else result=Q.front-Q.rear+MAXSIZE+1;    //画图 
	return result;
// 请补全代码
	
}

Status QueueTraverse(SqQueue &Q)  
{ 
// 若队列不空，则从队头到队尾依次输出各个队列元素，并返回OK；否则返回ERROR.
	int i;
	i=Q.front+1;
	if(Q.rear==Q.front)printf("The Queue is Empty!");  //请填空
	else{
		printf("The Queue is: ");
		while(i!=Q.rear)     //请填空
		{
			printf("%d ",Q.base[i]);  //请填空
			i = (i+1)%MAXSIZE;   //请填空
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
  if(InitQueue(Q))    // 判断顺序表是否创建成功，请填空
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
				  if(!EnQueue(Q,x)) printf("Enter Error!\n"); // 判断入队是否合法，请填空
				  else printf("The Element %d is Successfully Entered!\n", x); 
				  break;
			case 2: if(!DeQueue(Q,e)) printf("Delete Error!\n"); // 判断出队是否合法，请填空
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: if(!GetHead(Q,e))printf("Get Head Error!\n"); // 判断Get Head是否合法，请填空
				  else printf("The Head of the Queue is %d!\n", e);
				  break;
			case 4: printf("The Length of the Queue is %d!\n",QueueLength(Q));  //请填空
				  break;
			case 5: QueueTraverse(Q);//请填空
				  break;
			case 0: return 1;
		}
	}
}

