#include <bits/stdc++.h>
//静态链表
typedef long long ll;
using namespace std;
int n,nex[1000000];
char a[1000000005];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j;
   cin>>n;
   while(n--)
   {

       scanf("%s",a);
       len=strlen(a);
       for(i=0;i<len;i++)
        nex[i]=i+1;
        int p=0;
        while(p<=len)
        {

            p2=nex[p];
            p3=next[p2];   //删除3
            p4=next[p3];    //这里类似于链表的attach，由于nex的数组下标和内含值是相差一的，可产生attach的效果
            if(a[p]==a[p2])
            {
                if(a[p2]==a[p3]||a[p3]==a[p4])   /*AAA   AABB*/
                {

                nex[p2]=nex[p3];   //类似于链表的表达形式干掉了3
                continue;    //如果还是等于就要跳过别的回到循环
                }

            }
            p=nex[p];
        }
        p=0;
        while(p<=len)
        {

            printf("%c",a[p]);
            p=nex[p];   //链表
        }
        printf("\n");
   }
    return 0;
}
