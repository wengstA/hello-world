#include <iostream>
typedef long long ll;
using namespace std;  //�㷨��ģ��
char  a[15][15];
int m,n,v[15][15];      //����߹��ĵ�
int dx[5]={0,1,0,-1,0};  //�ڱ��ڵ�
int dy[5]={0,0,1,0,-1};   //��ʾ��������
int ok;
void dfs(int x,int y)
{
    v[x][y]=1;
    if(ok||x==n&&y==m)
    {
        ok=1;
        return;    //�����ߵ����յ�Ͳ�����
    }
    for(int i=1;i<=4;i++)
    {
        int cx=x+dx[i],cy=y+dy[i];   //����forѭ�������������Ҷ���һ��
        if(cx>=1&&cx<=n&&cy>=1&&cy<=m&&a[cx][cy]=='0'&&v[cx][cy]==0)   //��֤������1.û�г��磬�߳��ڷ���֮��
                                                                 //2.û���߹�����ڵ�
            dfs(cx,cy); //��һ��������е�·������
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j;
    cin>>n>>m;
    //��һ�����������
    for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
             cin>>a[i][j];
    dfs(1,1);
    if(v[n][m]==1)//���߳���ʱ�����һ���ڵ����1
        cout<<"yes";
    else
        cout<<"no";

    return 0;
}
