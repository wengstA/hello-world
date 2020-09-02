#include<iostream>
typedef long long ll;

using namespace std;

int n,a[105];
int st[1000],top=0;

int main()
{
	int i,j,start;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;a[i]!=n;i++)
	{
		st[top++]=a[i];
	}
	cout<<n<<' ';
	start=i+1;
	for(i=1;i<n;i++)
	{
		int stop=0;
		if(top)
		 stop=st[top-1];
		 int maxv=0;
		 for(j=start;j<=n;j++)
		 {
		 	if(maxv<a[j])maxv=a[j];
		 }
		 if(stop>maxv)
		 {
		 	cout<<stop<<' ';
		 	top--;
		 }
		 else
		 {
		 	for(j=start;a[j]!=maxv;j++)
		 		st[top++]=a[j];
		 		cout<<maxv<<' ';
		 		start=j+1;
			 
		 }
	}
 } 
