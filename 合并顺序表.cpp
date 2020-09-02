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


Status ListInsert_L(LinkList &L, int i, ElemType e) {  // �㷨2.9
  // �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
  LinkList p,s;
  p = L;   
  int j = 0;
  while (p && j < i-1) {  // Ѱ�ҵ�i-1�����
    p = p->next;
    ++j;
  } 
  if (!p || j > i-1) return ERROR;      // iС��1���ߴ��ڱ�
  s = (LinkList)malloc(sizeof(LNode));  // �����½��
  s->data = e;  s->next = p->next;      // ����L��
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // �㷨2.10
  // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // Ѱ�ҵ�i����㣬����pָ����ǰ��
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // ɾ��λ�ò�����
  q = p->next;
  p->next = q->next;           // ɾ�����ͷŽ��
  e = q->data;
  free(q);
  return OK;
} // ListDelete_L
Status ListCreate_L(LinkList &L)
{
	int n;
	cin>>n;
	int i=1;
	int number;
    L=new LNode;
	L->data=-999;
	LinkList p;
	LinkList pre=new LNode;
	pre=L;
	for(i=1;i<=n;i++)
	{
		p=new LNode;
		cin>>number;
		p->data=number;
		p->next=NULL;
		pre->next=p;
		pre=p;
	}
	return OK;
}
Status ListMerge_L(LinkList &L1,LinkList &L2)
{
	int i=1;
	LinkList p=L2->next,current;
	LinkList pre=L1;//�嵽L1 
	while(p)
	{
			if(pre->next&&p->data>=pre->data&&p->data<=pre->next->data){  //�����м�Ľڵ� 
				
					ListInsert_L(L1,i,p->data);
					p=p->next;
					if(!p)break;
            
			}
			else if(!(pre->next)&&p->data>=pre->data)  //β�ڵ���� 
			{
			 pre->next=p;
			 break;   //��β������ȫ������ 
			}
			else{
			pre=pre->next;i++;
			} 	
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
Status ListStore_L(LinkList &L1,LinkList &L2)
{
	L2=new LNode;
	LinkList p=L1->next,pre=L2,current;
	while(p)
	{
		current=new LNode;
		current->data=p->data;
		p=p->next;
		current->next=NULL;
		pre->next=current;
		pre=current;
	}
	return OK;
}
int main ()
{
  ios::sync_with_stdio(0),cin.tie(0);
  int n1,n2;
  LinkList L1,L2,store;
  ListCreate_L(L1);
  ListStore_L(L1,store);
  ListCreate_L(L2);
  ListMerge_L(L1,L2);
  cout<<"List A:";
  ListLoad_L(store);
   cout<<"List B:";
  ListLoad_L(L2);
   cout<<"List C:";
  ListLoad_L(L1);
}
