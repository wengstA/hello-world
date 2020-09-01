#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
	int level;
}node,*Node;

typedef struct list{
	Node rear=NULL;
	Node front=NULL;
	int length=0;
}*List;

void Insert(int data,List G_List)
{
	Node A=(Node)malloc(sizeof(Node));
	A->data=data;
	if(!G_List->front)
	{
	  G_List->front=A;
	 G_List->rear=A;
    }
	 else
	 {
	 	G_List->rear->next=A;
	  } 
	  G_List->length++;
 } 
 
 int main()
 {
// 	int N,M;
// 	cin<<N<<M;
 	List Graph[10];
 	for(int i=1;i<10;i++)
 	{
 		Graph[i]->front=NULL;
 		Graph[i]->rear=NULL;
 		Graph[i]->length=0;
	 }
	 Insert(3,Graph[1]);
	 Insert(4,Graph[1]);
	 Insert(5,Graph[2]);
//	 for(Node A=Graph[1]->front;A;A=A->next)
//	 {
//	 	cout<<A->data<<' ';
//	 }
    cout<<Graph[1]->length;
 }
