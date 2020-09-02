#include<malloc.h> 
#include<stdio.h> 
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������

typedef int SElemType; // ����ջԪ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��

struct SqStack
{
     SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
     SElemType *top; // ջ��ָ��
     int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S)       
{      
// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
 S.base=new SElemType[STACK_INIT_SIZE];
 S.top=S.base;
 S.stacksize=0;
return OK;	
}

Status Push(SqStack &S,SElemType e)   
{
// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
if(S.base&&S.stacksize<=STACK_INIT_SIZE){
	 *S.top=e;
	 S.top++;
	 S.stacksize++;
	 return OK;
}
else return ERROR;	
}

Status Pop(SqStack &S,SElemType &e)   
{
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.base&&S.stacksize>0) {
		S.top--;
	    e=S.base[--S.stacksize];
	     return OK;	
		 }
	return ERROR;
}

Status GetTop(SqStack S,SElemType &e)   
{ 
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.base&&S.stacksize>0) {
	e=*(S.top-1);
	return OK;
	}
	return ERROR;
}

int StackLength(SqStack S) 
{
	if(S.base)
  return S.stacksize;	
}

Status StackTraverse(SqStack S)
{
// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
	SElemType *p = (SElemType *)malloc(sizeof(SElemType)); 
	p =S.top;       //�����
	if(!p)printf("The Stack is Empty!"); //�����
	else
	{
		printf("The Stack is: ");
		p--;
		while(p>=S.base)            //�����
		{
			printf("%d ", *p);
			  p--;             //�����
		}
	}
	printf("\n");
	return OK;
}

int main()
{
     int a;
     SqStack S;
     SElemType x, e;
     if(InitStack(S))  // �ж�˳����Ƿ񴴽��ɹ��������
{
	printf("A Stack Has Created.\n");
}
while(1)
	{
    printf("1:Push \n2:Pop \n3:Get the Top \n4:Return the Length of the Stack\n5:Load the Stack\n0:Exit\nPlease choose:\n");
	scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d", &x);
		      if(!Push(S,x) )printf("Push Error!\n"); // �ж�Push�Ƿ�Ϸ��������
		      else printf("The Element %d is Successfully Pushed!\n", x); 
		      break;
		case 2: if(!Pop(S,e) )printf("Pop Error!\n"); // �ж�Pop�Ƿ�Ϸ��������
			  else printf("The Element %d is Successfully Poped!\n", e);
		  	  break;
		case 3: if(!GetTop(S,e))printf("Get Top Error!\n"); // �ж�Get Top�Ƿ�Ϸ��������
			  else printf("The Top Element is %d!\n", e);
		   	  break;
			case 4: printf("The Length of the Stack is %d!\n",StackLength(S)); //�����
				  break;
			case 5: StackTraverse(S); //�����
				  break;
			case 0: return 1;
		}
	}
}
