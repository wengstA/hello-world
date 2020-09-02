#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m;
vector<int> e[1000005];
int visited[100005]={0};
void dfs(int cur)
{
	cout<<cur<<' ';
	visited[cur]=1;//遍历这个点的邻接表 
    for(int i=0;i<e[cur].size();i++)
    {
    	if(!visited[e[cur][i]])
    	dfs(e[cur][i]);
	} 
}

void bfs(int cur)
{
	//!!!!进来先标1 
   //bfs不是递归，而是循环 
  //系统队列做
  visited[cur]=1;
  queue<int> q;
  q.push(cur);
  while(!q.empty())
  {
  	int temp=q.front();//获取头节点 
	 cout<<temp<<" ";
     q.pop();
    for(int i=0;i<e[temp].size();i++)
    {
    	if(!visited[e[temp][i]])
		   {
		   	visited[e[temp][i]]=1;//这么做可以保证每一个在队列里面的值都是没有被访问过的 
		   	q.push(e[temp][i]);
		   }
	}
  	  
	  
  
   } 
  
}
int main()
{
	//采用邻接表来进行存储
    //int n,m;
	cin>>n>>m;//点，边
	int x,y;
	
  for(int i=1;i<=m;i++)
  {
  	cin>>x>>y;
  	e[x].push_back(y);//邻接点放进去 
  	e[y].push_back(x);
  }
  //做一个口袋遍历
  dfs(1); 
  cout<<endl;
  memset(visited,0,sizeof(visited));
  bfs(1);
 } 
