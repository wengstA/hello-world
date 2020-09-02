#include<iostream>
#include<vector>
#include<vector>
using namespace std;
int main()
{
	//采用邻接表来进行存储
    int n,m;
	cin>>n>>m;//点，边
	int x,y;
	vector<int> e[n+1];
  for(int i=1;i<=m;i++)
  {
  	cin>>x>>y;
  	e[x].push_back(y);//邻接点放进去 
  }
  //做一个口袋遍历
  for(int i=1;i<=n;i++)//注意是n，点输出而不是 
  {
  	cout<<i<<"--->"; 
  	for(int j=0;j<e[i].size();j++)
  	{
  		cout<<e[i][j]<<' ';
	  }
	  cout<<endl;
   } 
 } 
