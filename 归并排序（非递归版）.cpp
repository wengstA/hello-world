#include <iostream>
using namespace std;
void merge(int *a,int start,int mid,int last)//ÿһ�����span����������ϲ�
{
    int l=start;//����ԭ���鲢�����е������������ߵ��±�
    int r=mid+1;//����ԭ���鲢�����е������������ߵ��±�
    int b[last-start+1],j=0;

    while(l<=mid&&r<=last)
    {
        if(a[l]<=a[r]) b[j++]=a[l++];
        else b[j++]=a[r++];
    }
    while(l<=mid) b[j++]=a[l++];
    while(r<=last) b[j++]=a[r++];
    for(int i=0;i<j;i++) a[start++]=b[i];
}
void split(int *a,int span,int length)//����span�����������𲽽������¶��ϵĺϲ�
{
    int curindex=0;
    while(curindex+2*span-1<length)//�����鲻�ܳ���a���鳤��
    {
        merge(a,curindex,curindex+span-1,curindex+2*span-1);
        curindex+=2*span;
    }
    if(curindex+span-1<length-1) merge(a,curindex,curindex+span-1,length-1);
    //����û��-1Լ����Ϊ�˷��㿴�����߹�ϵ���������鲻��һ����ȣ�����Ҫ����غϲ�
}
void mergesort(int *a,int length)//ȷ��ÿһ�κϲ��Ŀ��span
{
    int span=1;
    while(span<length)//����length�ĺϲ�������
    {
        split(a,span,length);//���������ȶ����������𲽽��кϲ�
        for(int i=0;i<length;i++) cout<<a[i]<<" ";//ÿ���һ�κϲ���ӡһ��
        cout<<endl;
        span*=2;
    }
}
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<=n-1;i++) cin>>a[i];
    mergesort(a,n);
}





