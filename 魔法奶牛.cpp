#include<iostream>
typedef long long ll;
using namespace std;
int n,block=0;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k;
    int left_black=0;
    int right_white=0;
	int mincount;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1) right_white++;
	 } //输入并且对黑白奶牛进行计数 
	 int count=right_white;
	 mincount=right_white;
	for(j=0;j<n;j++)
	{
		if(a[j]==2)
		{
			left_black++;
		}
		else right_white--;
		count=left_black+right_white;
		mincount=min(count,mincount);
	 } 
	cout<<mincount;
}
	
	
