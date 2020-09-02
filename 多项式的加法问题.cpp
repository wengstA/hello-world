#include<iostream>
#include<malloc.h>
using namespace std;
int i,j,n;

typedef struct Node{
	int coef;
	int expon;
	struct Node *next;
}LNode,*PNode;
PNode ReadLink(PNode &L)
{
   PNode tail;
   cin>>n;              //¼ÇÂ¼¼¸¸ö 
   PNode p;
   for(i=0;i<n;i++)
   {
	p=(PNode)malloc(sizeof(LNode));
   cin>>p->coef>>p->expon;
   if(!L)L=p;
   tail=p;
   p->next=NULL;
   } 
  // return L; 
}
void Load(PNode &L)
{
	PNode p=L;
	while(p)
	{
		cout<<p->coef<<' '<<p->expon<<' ';
		p=p->next;
	}
}
int main()
{
	PNode L1;
	ReadLink(L1);
	Load(L1);
	return 0;
}
