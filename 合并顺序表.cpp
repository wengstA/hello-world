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


Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
  // 在带头结点的单链线性表L的第i个元素之前插入元素e
  LinkList p,s;
  p = L;   
  int j = 0;
  while (p && j < i-1) {  // 寻找第i-1个结点
    p = p->next;
    ++j;
  } 
  if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
  s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
  s->data = e;  s->next = p->next;      // 插入L中
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // 算法2.10
  // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // 寻找第i个结点，并令p指向其前趋
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
  q = p->next;
  p->next = q->next;           // 删除并释放结点
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
	LinkList pre=L1;//插到L1 
	while(p)
	{
			if(pre->next&&p->data>=pre->data&&p->data<=pre->next->data){  //这是中间的节点 
				
					ListInsert_L(L1,i,p->data);
					p=p->next;
					if(!p)break;
            
			}
			else if(!(pre->next)&&p->data>=pre->data)  //尾节的情况 
			{
			 pre->next=p;
			 break;   //在尾结点可以全部接上 
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
