#include <iostream>
typedef long long ll;
using namespace std;
int n,k,ans[100];//�ѵ�cur�����ִ�������
void print()
{

    for(int i=1;i<=k;i++)
        cout<<ans[i]<<' ';
        cout<<endl;

}
void dfs(int x,int cur)/*ra��ʾ��Χ��1->x��cur��ʾ���ǵڼ�����*/
{
    int i;
	if(cur==k+1)   //��cur���µ�k��ʱ��ѭ����Ӧ�����������
            print(); 
    for(i=x;i>=1;i--)  /*ÿ�ν���ѭ�����ǵݹ鵽��С��һλ��ʼ���*/
    {
        ans[cur]=i;
        dfs(i-1,cur+1);  //ÿ�ν���һ������ĩλ�����ֶ�Ҫ����һ��ѭ��
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
