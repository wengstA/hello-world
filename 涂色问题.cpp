//˼·������������û��û��Χ��Ϊ0
//BFS���ܹ���չ��0�ĸ��ӣ�����b����������0 
//�Ȱ�b����������ж����2����a����ȡ����ľ����ٸ���b��a��ֵ�޸�һ�� 
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
//bfs ��ģ�� ��ӳ�ʼ״̬��ѭ�����ӱ��� 
void bfs()
{
	queue<xOy> q;
	xOy head;
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i][1]==0)q.push((struct xOy){i,1});//�߽����� 
		if(a[i][n]==0)q.push((struct xOy){i,n});
	}
	for(i=1;i<=n;i++)
	{
		if(a[1][i]==0)q.push((struct xOy){1,i});//�߽����� 
		if(a[n][i]==0)q.push((struct xOy){n,i});
	}
	while(!q.empty())  //���в��� 
	{
		head=q.front();//������ж�ͷ 
		q.pop();//�����ж�ͷ 
		if(vis[head.x][head.y])continue;//���Ϊ1 ������������ 
		vis[head.x][head.y]=true;//�Ѿ��߹������ͱ�� 
		b[head.x][head.y]=0;//�Ǳ߽�ֵ���������0 
		if(head.x-1>0&&a[head.x-1][head.y]==0)q.push((struct xOy){head.x-1,head.y});//����x����1��ʼ�洢�ģ����x-1��0���߽磬��� 
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
