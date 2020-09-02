#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void hnt(int n,char A,char B,char C)
{
    if(n==1)
    {
        printf("把盘子%d%从c移动到%c\n",n,A,C);
        return;
    }
    hnt(n-1,A,C,B);
    printf("把盘子%d%从c移动到%c\n",n,A,C);
    hnt(n-1,B,A,C);
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,n;
    cin>>n;
    hnt(n,'A','B','C');

    return 0;
}
