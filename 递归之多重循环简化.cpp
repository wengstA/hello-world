#include <iostream>
typedef long long ll;
using namespace std;
int n,k,ans[100];//把第cur个数字储存起来
void print()
{

    for(int i=1;i<=k;i++)
        cout<<ans[i]<<' ';
        cout<<endl;

}
void dfs(int x,int cur)/*ra表示范围是1->x，cur表示他是第几个数*/
{
    int i;
	if(cur==k+1)   //在cur更新到k的时候循环相应次数并且输出
            print(); 
    for(i=x;i>=1;i--)  /*每次进入循环总是递归到最小的一位开始输出*/
    {
        ans[cur]=i;
        dfs(i-1,cur+1);  //每次进入一个不是末位的数字都要进行一轮循环
    }

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j;
    cin>>n;
	cin>>k;
    dfs(n,1);
    return 0;
}
