#include <iostream>
using namespace std;
void merge(int *a,int start,int mid,int last)//每一个跨度span的左右数组合并
{
    int l=start;//看成原本归并排序中的左数组的最左边的下标
    int r=mid+1;//看成原本归并排序中的右数组的最左边的下标
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
void split(int *a,int span,int length)//按照span对整个数组逐步进行自下而上的合并
{
    int curindex=0;
    while(curindex+2*span-1<length)//右数组不能超过a数组长度
    {
        merge(a,curindex,curindex+span-1,curindex+2*span-1);
        curindex+=2*span;
    }
    if(curindex+span-1<length-1) merge(a,curindex,curindex+span-1,length-1);
    //这里没把-1约掉是为了方便看出二者关系，即右数组不够一个跨度，我们要特殊地合并
}
void mergesort(int *a,int length)//确定每一次合并的跨度span
{
    int span=1;
    while(span<length)//大于length的合并无意义
    {
        split(a,span,length);//按照这个跨度对整个数组逐步进行合并
        for(int i=0;i<length;i++) cout<<a[i]<<" ";//每完成一次合并打印一次
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





