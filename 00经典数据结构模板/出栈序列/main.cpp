#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,a[105];
int st[1000],top=0;//��top��Ϊջ��ָ�룬top==0Ϊ��ջ
//st[top++]=x;//��x��ջ��ջ��ָ��+1
//top--;//��ջ
int main()
{
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;a[i]!=n;i++)
        st[top++]=a[i];
    cout<<n<<' ';
    int l=i+1,stop,maxn;
    for(i=1;i<n;i++)
    {
        stop=0;
        if(top)
          stop=st[top-1];
        maxn=0;
        for(j=l;j<=n;j++)
            maxn=max(maxn,a[j]);
        if(stop>maxn)
        {
            cout<<st[top-1]<<' ';
            --top;
        }
        else
        {
            for(j=l;a[j]!=maxn;j++)
                st[top++]=a[j];
            cout<<maxn<<' ';
            l=j+1;
        }
    }
    return 0;
}
