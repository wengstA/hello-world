#include <iostream>
typedef long long ll;
using namespace std;
int n,rest,bit,store[100];

void print(int k)
{
    cout<<n<<'=';
    for(int i=1;i<=k;i++){
    	if(i!=1) 
    	cout<<'+';
    	cout<<store[i];
	}
    cout<<endl;
}
void dfs(int pre,int rest,int bit)   //������������֣�ÿ�ν���ݹ�ѭ��Ӧ�ö�����rest
{
    int i;
    for(i=min(pre,rest);i>=1;i--)   //���´���һ��Ŀǰ����״̬�Ĳ��� 
    {
        store[bit]=i;
        //if(bit>0&&store[bit]>store[bit-1]) continue;
    	if(rest-i==0)    //��д��������,����ѭ�����棨for��rest��ֵ������£�����һ��� 
        print(bit);
    	else dfs(i,rest-i,bit+1);//����rest��bit��ֵ,��Ҫд��bit++����ʽ��ֻ�Ǵ���ֵ�ĸ�������
    }
//    return 0;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
   cin>>n;
   rest=n;
   dfs(n,n,1);
    return 0;
}
