#include<iostream>
#include<vector>
using namespace std;
vector<int>e[10005];
int judge(int number)
{
	int now=number;
	int count=0;
	while(now!=0)
	{
	   count++;
		now/=10;
		
	}
	return count;
}
int main()
{
//	cout<<judge(1000);
	ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k,n,a[10005];
	cin>>n;
	int maxdigit=0;
	for(i=1;i<=n;i++)
		{
		 cin>>a[i];
		maxdigit=max(judge(a[i]),maxdigit);//输入数据并且查看maxdigit	
		}
		int digit=1;
		for(k=1;k<=maxdigit;k++)
		{  
			for(i=1;i<=n;i++)
			e[a[i]/digit%10].push_back(a[i]);//基数储存 ,次位储存 
			int l=1;
			for(i=0;i<=9;i++)
			{
				for(j=0;j<e[i].size();j++)//输出该位的所有储存值 
				 a[l++]=e[i][j];//按照顺序回存 
				e[i].clear();//全部情况 
			}
			for(i=1;i<=n;i++)
              printf("%d ",a[i]);
              cout<<endl;
              digit*=10;
		}
		return 0;
}
