#include<iostream>
using namespace std;
void Print(int N,int number[])
{
	for(int i=1;i<=N;i++)
	cout<<number[i]<<' ';
	cout<<endl;
 } 
void adjust(int i,int N,int number[])
{//单个进行调整 
    //Print(N,number);
	int parent,child;
	int temp=number[i];//储存将会被替代的parent结点 
	//cout<<"temp"<<temp<<endl;
	for(parent=i;parent*2<=N;parent=child)//从i结点开始，先小后大 
	{
		child=parent*2;
		if((child!=N)&&(number[child]<number[child+1]))child++;//保证是左右子树更大的那个 
		//cout<<"child"<<number[child]<<endl;
		if(temp>=number[child])break;//现在这个位置parent其实有两份，已经被转移到上面了 
		else number[parent]=number[child];
			//Print(N,number);
	}
	number[parent]=temp;
}
void BuildHeap(int N,int number[])
{
	//Print(N,number);
	for(int i=N/2;i>0;i--){//从最后一个节点的父结点开始,i越小越高层！！ 
	   adjust(i,N,number);  
	}
	Print(N,number);
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void Sort(int n,int number[])
{
	for(int i=n;i>1;i--){
	swap(number[i],number[1]);
	adjust(1,i-1,number);
	Print(n,number);
	}
//	swap(number[n-1],number[1]);
//	//Print(n,number);
//	adjust(1,n-2,number);
//	Print(n,number);

}
int main()
{
	int n;cin>>n;
	int number[n+1]={0};
	for(int i=1;i<=n;i++)
	  cin>>number[i];
	BuildHeap(n,number);
	Sort(n,number);
}
