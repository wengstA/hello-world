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
int bfs(int sx,int sy) //����ֵ�ŵ��������棬ÿ�ν�2��2 
{
	memset(v,0,sizeof(v));
	node q[105];
	int i,j,f=0,r=0;
//	q[r].x=x,q[r++].y=y;//ע�������λ��
	q[r++]={sx,sy};
	v[sx][sy]=1;  //��¼�ǵڼ��㣬�������ǵڼ��� 
	while(f!=r)
	{
		node t=q[f++];
		for(i=0;i<4;i++)
		{
		  int cx=t.x+dx[i],cy=t.y+dy[i];
		  if(cx>=1&&cx<=n&&cy>=1&&cy<=n&&a[cx][cy]=='0'&&v[cx][cy]==0)
		  {
		  	v[cx][cy]=1;//��¼���� 
		  	q[r++]={cx,cy};//��ӣ���forѭ���� �ܹ�����4�� 
		  	if(cx==1||cx==n||cy==1||cy==n)return 0;
		   } 
	 } 
}
return 1;//������û�������߽� 
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) //¼���Թ� 
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
