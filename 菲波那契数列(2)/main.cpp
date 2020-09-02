#include <iostream>
typedef long long ll;
using namespace std;
int output[1000005];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    output[1]=1;
    output[2]=1;
    for(int i=3;i<=20;i++)
    {
         output[i]=output[i-1]+output[i-2];
         //cout<<output[i]<<endl;
    }
    output[1]=1;
    output[2]=1;
    int n;
    cin>>n;
    int store[n];
    for(int i=0;i<n;i++)
    {
        cin>>store[i];
    }
    for(int i=0;i<n;i++)
    {
        int data=(output[store[i]]%1000);
        cout<<data;
        cout<<endl;
    }
    return 0;
}
