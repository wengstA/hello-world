#include <bits/stdc++.h>
//��̬����
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
            p3=next[p2];   //ɾ��3
            p4=next[p3];    //���������������attach������nex�������±���ں�ֵ�����һ�ģ��ɲ���attach��Ч��
            if(a[p]==a[p2])
            {
                if(a[p2]==a[p3]||a[p3]==a[p4])   /*AAA   AABB*/
                {

                nex[p2]=nex[p3];   //����������ı����ʽ�ɵ���3
                continue;    //������ǵ��ھ�Ҫ������Ļص�ѭ��
                }

            }
            p=nex[p];
        }
        p=0;
        while(p<=len)
        {

            printf("%c",a[p]);
            p=nex[p];   //����
        }
        printf("\n");
   }
    return 0;
}
