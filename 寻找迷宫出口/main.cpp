#include <iostream>
typedef long long ll;
using namespace std;  //算法的模板
char  a[15][15];
int m,n,v[15][15];      //标记走过的点
int dx[5]={0,1,0,-1,0};  //哨兵节点
int dy[5]={0,0,1,0,-1};   //表示右下左上
int ok;
void dfs(int x,int y)
{
    v[x][y]=1;
    if(ok||x==n&&y==m)
    {
        ok=1;
        return;    //发现走到了终点就不走了
    }
    for(int i=1;i<=4;i++)
    {
        int cx=x+dx[i],cy=y+dy[i];   //利用for循环，把上左下右都走一次
        if(cx>=1&&cx<=n&&cy>=1&&cy<=m&&a[cx][cy]=='0'&&v[cx][cy]==0)   //保证条件：1.没有出界，走出在方格之内
                                                                 //2.没有走过这个节点
            dfs(cx,cy); //他一定会把所有的路都走完
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j;
    cin>>n>>m;
    //做一个矩阵的输入
    for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
             cin>>a[i][j];
    dfs(1,1);
    if(v[n][m]==1)//当走出的时候，最后一个节点会变成1
        cout<<"yes";
    else
        cout<<"no";

    return 0;
}
