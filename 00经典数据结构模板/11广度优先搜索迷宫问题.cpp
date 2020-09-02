#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
typedef long long ll;
using namespace std;
char a[35][35];
int n,m,v[35][35];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct node
{
	int x,y;
};
int bfs(int sx,int sy) //两个值放到队列里面，每次进2出2 
{
	memset(v,0,sizeof(v));
	node q[105];
	int i,j,f=0,r=0;
//	q[r].x=x,q[r++].y=y;//注意递增的位置
	q[r++]={sx,sy};
	v[sx][sy]=1;  //记录是第几层，可以算是第几步 
	while(f!=r)
	{
		node t=q[f++];
		for(i=0;i<4;i++)
		{
		  int cx=t.x+dx[i],cy=t.y+dy[i];
		  if(cx>=1&&cx<=n&&cy>=1&&cy<=n&&a[cx][cy]=='0'&&v[cx][cy]==0)
		  {
		  	v[cx][cy]=1;//记录步数 
		  	q[r++]={cx,cy};//入队，在for循环下 总共会入4次 
		  	if(cx==1||cx==n||cy==1||cy==n)return 0;
		   } 
	 } 
}
return 1;//从来都没有遇到边界 
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) //录入迷宫 
	 for(j=1;j<=n;j++)
	 cin>>a[i][j];
	// bfs(1,1);
   for(i=2;i<n;i++)
     for(j=2;j<n;j++)
	 {
	 	if(a[i][j]=='0'&&bfs(i,j))
	 	  {
	 	  	   a[i][j]='2';
	 	  	 // break;
		   }
	  } 
	  for(i=1;i<=n;i++){
	  	for(j=1;j<=n;i++)
     cout<<a[i][j]<<' ';
     cout<<endl;
	  }
     
}
