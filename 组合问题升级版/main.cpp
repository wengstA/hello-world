
#include <iostream>
typedef long long ll;
using namespace std;
int n,rest,bit,store[100];

void print()
{
    int i=0;
    cout<<n<<'=';
    while(store[i]!=0)
        {
            cout<<store[i];
        if(store[i+1]!=0)
            cout<<'+';
            i++;
        }
    cout<<' '<<endl;
}
//每一位就是一个拆分的循环
//void dfs(int rest,int bit)   //由于是整数拆分，每次进入递归循环应该都是用rest
//{
//    int i;
//    for(i=rest;i>=1;i--)
//    {
//        store[bit]=i;
//        //if(bit>0&&store[bit]>store[bit-1]) continue;
//    	if(rest-i==0)    //先写结束条件,单层循环里面（for）rest的值不会更新，所以一点过
//        print();
//    	else dfs(rest-i,bit+1);//更新rest和bit的值,不要写成bit++的形式，只是传入值的副本变了
//    }
////    return 0;
//}
void dfs(int pre,int rest,int bit)   //由于是整数拆分，每次进入递归循环应该都是用rest
{
    int i;
    for(i=min(pre,rest);i>=1;i--)   //向下传递一个目前函数状态的参数
    {
        store[bit]=i;
        //if(bit>0&&store[bit]>store[bit-1]) continue;
    	if(rest-i==0)    //先写结束条件,单层循环里面（for）rest的值不会更新，所以一点过
        print();
    	else dfs(i,rest-i,bit+1);//更新rest和bit的值,不要写成bit++的形式，只是传入值的副本变了
    }
//    return 0;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
   cin>>n;
   rest=n;
   dfs(n,n,0);
    return 0;
}
