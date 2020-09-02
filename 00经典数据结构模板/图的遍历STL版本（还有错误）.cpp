#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

vector<int> e[100005];
int n,m,x,y;
int v[10005]={0};//����߹��� 
void dfs(int cur)
{
	cout<<cur<<' ';
	v[cur]=1;//�ڽӵ㶼�洢��v[cur][i]���� 
	for(int i=0;i<e[cur].size();i++)
	{
		if(!v[e[cur][i]])
		dfs(e[cur][i]);
	}
 } 
 void bfs(int cur)//��α��� 
 {
 	v[cur]=1;
 //��д	int i,	[10000005],f=0,r=0;//����f++,���r++
	queue<int> q; 
//����	q.push(x),q.front(),q.pop()
     q.push(cur);
     while(!q.empty())
     {
     	int t=q.front();
     	cout<<t<<' ';
     	q.pop();
     	for(int i=0;i<e[t].size();i++)
		 {
		 	if(!v[e[t][i]])
		 	{
		 		v[e[t][i]]=1;
		 		q.push(e[t][i]);//���зŽ�ȥ 
			 }
		  } 
	 }
 	
 }
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int i,j,x,y;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		//a[x][y]=a[y][x]=1;
	    e[x].push_back(y);
	    //e[y].push_back(x);//����ͼ 
	}
	for(int i=1;i<=n;i++)
	{
		sort(e[i].begin(),e[i].end());
	}
	
	dfs(1);
	cout<<endl;
	memset(v,0,sizeof(v));
	bfs(1);
	return 0;
}
