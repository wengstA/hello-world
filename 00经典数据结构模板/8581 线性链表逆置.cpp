#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int
using namespace std;
typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;


Status ListCreate(LinkList &L,int n)
{
	L=new LNode;    //一定要分配空间 
	LinkList p,pre=L;
	int i=1;
	for(i=1;i<=n;i++)
	{
	  p=new LNode;
	  cin>>p->data;
	  p->next=NULL;
	  pre->next=p;
	  pre=p;
	}
	return OK;
}
Status ListLoad_L(LinkList &L1)
{
	LinkList p=L1->next;
	while(p){
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<"\n";
	return OK;
}
Status ListReverse_L(LinkList &L1,LinkList &L2)
{

	LinkList current=L1->next;
	LinkList pre=NULL;
	while(current) 
	{
		L2=new LNode;
		L2->data=current->data;
		L2->next=pre;
		pre=L2;
		current=current->next;
	}
	L2=new LNode;
	L2->next=pre;
	return OK;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	LinkList L1,L2;
	int n;
	cin>>n;
	ListCreate(L1,n);
//	ListLoad_L(L1);
	ListReverse_L(L1,L2);
	cout<<"The list is:";
	ListLoad_L(L1);
	cout<<"The turned List is:";
	ListLoad_L(L2);
}
