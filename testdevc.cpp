#include<iostream>
using namespace std;

typedef struct heap{
	int element[100];
	int size=0;
	int capacity=100;
}*Heap;

void Print(Heap H,int length)
{
	for(int i=1;i<=length;i++){
		cout<<H->element[i]<<" "<<endl;
	}
}
Heap InsertHeap(int data,Heap H);
int main()
{
	int M,N;
	cin>>M>>N;
	Heap H;
	for(int i=0;i<M;i++)
	{
		int data;
		cin>>data;
		InsertHeap(data,H);
	}
	Print(H,M);
}
Heap InsertHeap(int data,Heap H)
{
	int i=0;
	if(!H)
	{
	H=(Heap)malloc(sizeof(struct heap));
	H->element[1]=data;
	H->size=1;
	H->element[0]=-10000;
	}
	else
    for(i=H->size++;H->element[i/2]<=data;i/=2)
     H->element[i]=H->element[i/2];
     H->element[i]=data;
     H->size++;
}
