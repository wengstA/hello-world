#include<iostream>
using namespace std;

int s[10005];
int SStop=0;
int M=0;
bool push(int data)
{
	if(SStop==M)
	 return false;
	 else
	 {
	 	s[SStop++]=data;
	 }
	 return true;
}
int pop()
{
    int data;
	if(!SStop)
	 return false;
    else
    {
    	
    	data=s[--SStop];
	}
	return data;
}
bool Judge(int length,int List[])
{
	int po=1;//顺序序列 
	int L=0;//比较序列 
	while(po!=length+1&&L!=length)
	{
		int PR=push(po);//压入栈
	
		if(!PR)
		{
			cout<<"NO";
			return false;
		}
		//对序列和栈内已有元素作处理 
		if(s[SStop-1]==List[L])
		{
			while(s[SStop-1]==List[L])
			{
				int result=pop();
				L++;
				if(!result||L==length)
				 break;
            }	 
	    }
	  	po++;	
	}
	if(po==length+1&&L==length)
	 cout<<"YES";
	 else cout<<"NO";
}
int main()
{
	int N,K;
	cin>>M>>N>>K;//栈的大小、输入个数，lines 
	int order[N];
	int List[K][N];
	//输入 数据 

	for(int i=0;i<K;i++)
	{
		for(int j=0;j<N;j++)
		 cin>>List[i][j];
	}
	for(int i=0;i<K;i++)
	{
		SStop=0;
	 Judge(N,List[i]);	
	 if(i!=K-1)
	 cout<<endl;
    }  
 } 
