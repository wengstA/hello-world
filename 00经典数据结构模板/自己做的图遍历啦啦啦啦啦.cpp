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
	visited[cur]=1;//�����������ڽӱ� 
    for(int i=0;i<e[cur].size();i++)
    {
    	if(!visited[e[cur][i]])
    	dfs(e[cur][i]);
	} 
}

void bfs(int cur)
{
	//!!!!�����ȱ�1 
   //bfs���ǵݹ飬����ѭ�� 
  //ϵͳ������
  visited[cur]=1;
  queue<int> q;
  q.push(cur);
  while(!q.empty())
  {
  	int temp=q.front();//��ȡͷ�ڵ� 
	 cout<<temp<<" ";
     q.pop();
    for(int i=0;i<e[temp].size();i++)
    {
    	if(!visited[e[temp][i]])
		   {
		   	visited[e[temp][i]]=1;//��ô�����Ա�֤ÿһ���ڶ��������ֵ����û�б����ʹ��� 
		   	q.push(e[temp][i]);
		   }
	}
  	  
	  
  
   } 
  
}
int main()
{
	//�����ڽӱ������д洢
    //int n,m;
	cin>>n>>m;//�㣬��
	int x,y;
	
  for(int i=1;i<=m;i++)
  {
  	cin>>x>>y;
  	e[x].push_back(y);//�ڽӵ�Ž�ȥ 
  	e[y].push_back(x);
  }
  //��һ���ڴ�����
  dfs(1); 
  cout<<endl;
  memset(visited,0,sizeof(visited));
  bfs(1);
 } 
