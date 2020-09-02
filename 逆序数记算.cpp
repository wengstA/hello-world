//逆序数 
#include<iostream>
#include<algorithm>
using namespace std;
int findmax(int *number,int len,int Lmax)
{
	
	for(int k=0;k<=len;k++){
		Lmax=max(*number+k,Lmax);
	}
	return Lmax;
 } 
void Print(int number[],int N)
{
	for(int k=0;k<N;k++)
	  cout<<number[k]<<' ';
	  cout<<endl;
}
int InsertAndJ(int number[],int N)
{
     int count=0; 
	//cout<<number[0]<<' ';
	int *p;
	for(int i=1;i<N;i++)
	{
	   sort(number,number+i-1);//先这个元素之前排序
 	   //Print(number,N);
	   p=lower_bound(number,number+i-1,number[i]);//在之前的排列中找大于等于的值 
	   if(*p<number[i])//说明没有比他大的 
	       continue;
		 else{
		 	int Flength=p-number;
		 	int length=i-Flength;
		 	count+=length;
		 } 
	   }   
	   cout<<count;
	  
	}


int main()
{
	int N;
	cin>>N;
	int i=0;
	int number[N]={0};
	for(i=0;i<N;i++)
	  cin>>number[i];
	   InsertAndJ(number,N);
	  
}
