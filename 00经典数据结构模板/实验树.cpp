#include<iostream>
#include<malloc.h>
using namespace std;
#define ElementType int
#define Status int
#define MAXSIZE 105
#define ERROR 0
#define OK 1
typedef struct TreeNode {
	//�������Ľ��ṹ 
	ElementType data ;
	struct TreeNode* Lchild=NULL;
	struct TreeNode* Rchild=NULL;
	int visited=0;
}*BinTree,TreeNode;

typedef struct Queue{
	//������еĽṹ 
	BinTree queue[MAXSIZE];
	int f=0,r=0;
}Queue;
 
 
 typedef struct Stack{
 	BinTree Stack[MAXSIZE];
 	int top=0;
 }Stack;
 
 Status PopStack(Stack &s,BinTree &out)
 {
 	if(s.top==0)return ERROR;
 	else
    {
 	  out=s.Stack[--s.top];
	   return OK;	
    }
 }

//����ԭ�ͣ�
 Status GetTop(Stack s,BinTree &out);
 Status IsEmpty(Stack S);
 Status PushStack(Stack &s,BinTree data);
 Status PushQueue(BinTree A,Queue &q);
 Status PopQueue(BinTree &A,Queue &q);
 Status PopQueue(BinTree &A,Queue &q)
 void Pre_Order(BinTree BST);
 void Mid_Order(BinTree BST);
 void L_Order(BinTree BST);
 void LevelOrder(BinTree BST);
 int Insert(int Curdata,BinTree &BST);
 Status Find(ElementType f,BinTree BST);
 int SearchDeep(BinTree BST,int &MaxH);
 int CountLeaves(BinTree BST,int &CountL);
  Status SwapLR(BinTree BST);
  void NPre_Order(BinTree BST);
  void NMid_Order(BinTree BST);
  void NL_Order(BinTree BST);
   
   
Status GetTop(Stack s,BinTree &out)
{
	if(s.top==0)return ERROR;
 	else
    {
 	  out=s.Stack[s.top-1];
	   return OK;	
    }
}

Status IsEmpty(Stack S)
{
	if(S.top==0)
	return OK;
	else return ERROR; 
}

Status PushStack(Stack &s,BinTree data)
{
	if(s.top==MAXSIZE+1)
	   return ERROR;
    else
    {
    	s.Stack[s.top++]=data;
	}
}

Status PushQueue(BinTree A,Queue &q)
{
	//Ԫ����� 
	if((q.r+1)%MAXSIZE==q.f)
	   return ERROR;
    else 
    {
    	
	    q.queue[q.r]=A;
    	q.r=(q.r+1)%MAXSIZE;
    	return OK;
	}
}

Status PopQueue(BinTree &A,Queue &q)
{
	//Ԫ�س��� 
	if(q.f==q.r) return ERROR;
	else
	{
		A=q.queue[q.f];
		q.f=(q.f+1)%MAXSIZE; 	
		return OK;
	}
}

void Pre_Order(BinTree BST)
 {//ǰ����� 
 	if(!BST) return;
 	cout<<BST->data<<' ';
 	Pre_Order(BST->Lchild);
 	Pre_Order(BST->Rchild);
 }
 
 void Mid_Order(BinTree BST)
 {//������� 
 	if(!BST) return;
	Mid_Order(BST->Lchild);
 	cout<<BST->data<<' ';
 	Mid_Order(BST->Rchild);
 }
 
 void L_Order(BinTree BST)
 {//������� 
 	if(!BST) return;
 	L_Order(BST->Lchild);
 	L_Order(BST->Rchild);
 	cout<<BST->data<<' ';
 	BST->visited=0;
 }
 
 void LevelOrder(BinTree BST)
 {//������� 
    Queue q;
    BinTree F;
    PushQueue(BST,q);
    int result=PopQueue(F,q);
   while(result)
    { 
    	cout<<F->data<<' ';
    	if(F->Lchild)
    	 PushQueue(F->Lchild,q);
   	    if(F->Rchild)
    	 PushQueue(F->Rchild,q);
		result=PopQueue(F,q);  
	}
  } 

int Insert(int Curdata,BinTree &BST)
{
    BinTree Node=(BinTree)malloc(sizeof(TreeNode));
    Node->data=Curdata;
    Node->Lchild=NULL;
    Node->Rchild=NULL;
    if(!BST)
     BST=Node;
    else
    {
   	   BinTree p=BST,pre=BST;
   	   while(p)
   	   {
   	   	pre=p;
   	   	if(Curdata>p->data)
   	   	  p=p->Rchild;
 	    else
 	      p=p->Lchild;
       }
       if(Curdata>pre->data)
        pre->Rchild=Node;
       else
        pre->Lchild=Node;
	}
}

Status Find(ElementType f,BinTree BST)
{
	BinTree cur=BST;
	while(cur)
	{
		if(f==cur->data)
		return OK;
		else if(f>cur->data)
		  cur=cur->Rchild;
        else if(f<cur->data)
          cur=cur->Lchild;
	}
	if(!cur)
	 return ERROR;
}

int SearchDeep(BinTree BST,int &MaxH)
{//˼·��Height=max(HL,HR)+1; 
   ElementType HL=0,HR=0;
   BinTree cur=BST;
   if(cur)
   {
   HL=SearchDeep(cur->Lchild,MaxH);
   HR=SearchDeep(cur->Rchild,MaxH);
   MaxH=max(HL,HR)+1;//ȡ���������ϴ����� 
   return MaxH;//����������� 
   }
  else return 0;//���� 
}

int CountLeaves(BinTree BST,int &CountL)
{//�����Ҷ�ӽ����뷨��ͬ����û�е�ʱ��ͼ�1 
  BinTree cur=BST;
  if(cur)
  {
  	if(!cur->Lchild&&!cur->Rchild)
	  CountL++;
	 else 
	   CountLeaves(cur->Lchild,CountL);
	   CountLeaves(cur->Rchild,CountL);
  }
  return CountL;
}

Status SwapLR(BinTree BST)
{//˼·:����ÿһ���ڵ���˵���ǽ��������ӽڵ� 
	BinTree cur=BST,A;
 	if(cur)
	{ 
	    
		if(cur->Lchild&&cur->Rchild)
		 {
		  A=cur->Lchild;
		  cur->Lchild=cur->Rchild;
		  cur->Rchild=A;
		  } 
		  SwapLR(cur->Lchild);
    	  SwapLR(cur->Rchild);
	}
	else return ERROR;
   return OK;
	
}

 void NPre_Order(BinTree BST)
{
	Stack S;
	BinTree cur=BST;
   while(cur||!IsEmpty(S))
   {
   	while(cur)
   	{
	cout<<cur->data<<' ';
   	 PushStack(S,cur);
	 cur=cur->Lchild;	
    }
    if(!IsEmpty(S))
    {
    	PopStack(S,cur);
    	cur=cur->Rchild;
	}
   }	
}
void NMid_Order(BinTree BST)
{
	Stack S;
	BinTree cur=BST;
   while(cur||!IsEmpty(S))
   {
   	while(cur)
   	{
   	 PushStack(S,cur);
	 cur=cur->Lchild;	
    }
    if(!IsEmpty(S))
    {
    	PopStack(S,cur);
    	cout<<cur->data<<' ';
    	cur=cur->Rchild;
	}
   }
	
}

void NL_Order(BinTree BST)
{//���������˼·�ǣ��������ߵ��˾�ͷ֮�����������ߣ��Ƚ� ���������֮�������������
  BinTree cur=BST;
  Stack S;S.top=0;
  	while(cur||!IsEmpty(S))
  	{
  	  	while(cur)
  	  	{
  	  	 PushStack(S,cur);
  	  	 cur=cur->Lchild;
		}
		if(!IsEmpty(S))
		{
			PopStack(S,cur);			
			if(cur->Rchild&&!cur->visited)
			{//����ջ 
			   cur->visited=1;//����Ѿ����ʹ��� 
			   PushStack(S,cur);
			}
			else
			{
				cout<<cur->data<<' '; //��������� 
			}
			cur=cur->Rchild;
		}
    }
    
	
}
int main()
{
	 ios::sync_with_stdio(0),cin.tie(0);/**< Ϊcincout���� */
	int N;
	cin>>N;
	ElementType Curdata=0;
	BinTree BST=NULL;
	for(int i=1;i<=N;i++)
	 {
	 	cin>>Curdata;
	 	Insert(Curdata,BST);
	 }
//	 Pre_Order(BST);//����������
//	 cout<<endl;
//	 Mid_Order(BST);//���������� 
//	 cout<<endl; 
cout<<"���Ǻ���:"; 
	 L_Order(BST);//���������� 
	 cout<<endl;
//	 LevelOrder(BST);//�������
//	 cout<<endl; 
//	 ElementType find=0;
//	 printf("Pleas enter an number you want to find:");
//     cin>>find;
//     int result=Find(find,BST);//���� 
//     if(result)
//      printf("We found %d\n",find);
//     else 
//      printf("%d is not an element of the Tree\n",find);
// int MaxH=0;
// MaxH=SearchDeep(BST,MaxH);
//     cout<<MaxH<<endl;
//     int CountL;
//     CountL=CountLeaves(BST,CountL);
//     cout<<CountL;
//      SwapLR(BST);
//   NMid_Order(BST); 
//   cout<<endl;
//   NPre_Order(BST);
//   cout<<endl;
cout<<"�����ԱȰɣ�"; 
   NL_Order(BST);
   cout<<endl;   
 } 
