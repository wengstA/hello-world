#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;

int number[105],top=0;
int z[105];
int out[105],out_top=0;
int n;
int main()
{
    int i,j;
     ios::sync_with_stdio(0),cin.tie(0);
     cin>>n;
     for(i=0;i<n;i++)
     {
         cin>>number[i];
     }
     i=0;
     while(i!=n)
     {
         ///���С��ջ��Ԫ�أ���ջ��ֱ�����ڵ�Ԫ�ر�ջ��Ԫ�ش�Ϊֹ

          while(number[i]<z[top-1]&&top)   ///��ʱӦ�ó�ջ
         {
            out[out_top++]=z[top--];
         }

        if(!top||number[i]>z[top-1])
            z[top++]=number[i];
        i++;
    }
    for(i=0;i<n;i++)
    {
        cout<<out[i];
    }
}
