#include<iostream>
using namespace std;
void Print(int N,int number[])
{
	for(int i=1;i<=N;i++)
	cout<<number[i]<<' ';
	cout<<endl;
 } 
void adjust(int i,int N,int number[])
{//�������е��� 
    //Print(N,number);
	int parent,child;
	int temp=number[i];//���潫�ᱻ�����parent��� 
	//cout<<"temp"<<temp<<endl;
	for(parent=i;parent*2<=N;parent=child)//��i��㿪ʼ����С��� 
	{
		child=parent*2;
		if((child!=N)&&(number[child]<number[child+1]))child++;//��֤����������������Ǹ� 
		//cout<<"child"<<number[child]<<endl;
		if(temp>=number[child])break;//�������λ��parent��ʵ�����ݣ��Ѿ���ת�Ƶ������� 
		else number[parent]=number[child];
			//Print(N,number);
	}
	number[parent]=temp;
}
void BuildHeap(int N,int number[])
{
	//Print(N,number);
	for(int i=N/2;i>0;i--){//�����һ���ڵ�ĸ���㿪ʼ,iԽСԽ�߲㣡�� 
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
