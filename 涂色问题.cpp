//思路：反过来，找没有没包围的为0
//BFS，能够拓展到0的格子，就在b数组把他变成0 
//先把b数组里的所有都标成2，用a来读取输入的矩阵，再根据b把a的值修改一下 
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

const int maxn=101;

int a[maxn][maxn],b[maxn][maxn];
int n;
bool vis[maxn][maxn];

struct xOy{
	int x,y;
};
//bfs 的模板 入队初始状态，循环出队遍历 
void bfs()
{
	queue<xOy> q;
	xOy head;
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i][1]==0)q.push((struct xOy){i,1});//边界的情况 
		if(a[i][n]==0)q.push((struct xOy){i,n});
	}
	for(i=1;i<=n;i++)
	{
		if(a[1][i]==0)q.push((struct xOy){1,i});//边界的情况 
		if(a[n][i]==0)q.push((struct xOy){n,i});
	}
	while(!q.empty())  //队列不空 
	{
		head=q.front();//储存队列队头 
		q.pop();//出队列队头 
		if(vis[head.x][head.y])continue;//如果为1 就跳过不处理 
		vis[head.x][head.y]=true;//已经走过了这点就标记 
		b[head.x][head.y]=0;//是边界值，把他变成0 
		if(head.x-1>0&&a[head.x-1][head.y]==0)q.push((struct xOy){head.x-1,head.y});//由于x是在1开始存储的，如果x-1是0，边界，入队 
		if(head.x+1<=n&&a[head.x+1][head.y]==0)q.push((struct xOy){head.x+1,head.y});
		if(head.y-1>0&&a[head.x][head.y-1]==0)q.push((struct xOy){head.x,head.y-1});
		if(head.y+1<=n&&a[head.x][head.y+1]==0)q.push((struct xOy){head.x,head.y+1});
		}
		return ; 
}
int main(){
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        b[i][j]=2;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++){
        cin>>a[i][j];
        if(a[i][j]==1)b[i][j]=1;
    }
    bfs();
	n=i-1;
    for(i=1;i<=n;i++){
    
      for(j=1;j<=n;j++)
        cout<<b[i][j]<<" ";
      cout<<endl;
    }
    return 0;
}
