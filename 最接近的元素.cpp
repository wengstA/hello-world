//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<set> 
//using namespace std;
//int in[100005],find[10005];
//int findmax(int *number,int len,int Lmax)
//{
//	
//	for(int k=0;k<=len;k++){
//		Lmax=max(*number+k,Lmax);
//	}
//	return Lmax;
// } 
//int InsertAndJ(int number[],int N)
//{
//	cout<<number[0]<<' ';
//	int *p;
//	for(int i=1;i<N;i++)
//	{
//	   sort(number,number+i-1);//�����Ԫ��֮ǰ����
//	   p=lower_bound(number,number+i-1,number[i]);//��֮ǰ���������Ҵ��ڵ��ڵ�ֵ 
//	   if(*p<number[i])//˵��ǰ��Ķ�����ҪС
//	   {
//	   	 int Lmax=findmax(number,i-1,*p);
//			cout<<Lmax<<' ';
//			continue;//��ǰ����������С�� 
//	   } 
//	   if(p==number)cout<<*p<<' ';//��ָ���һ��Ԫ�ص�ʱ��
//	   else{
//	   	if(*p-number[i]<=number[i]-*(p-1))
//	      cout<<*p<<' ';
//	       else cout<<*(p-1)<<' ';
//	   }   
//	  
//	}
//}
//
//int main()
//{
//	int N;
//	cin>>N;
//	int i=0;
//	int number[N]={0};
//	for(i=0;i<N;i++)
//	  cin>>number[i];
//	   InsertAndJ(number,N);
//	  
//}
#include<iostream>
#include<set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int n,i,x,number;
	multiset<int> s;
    multiset<int>::iterator it;
	cin>>n;
	cin>>x;
	cout<<x<<' ';
	s.insert(x);
	for(i=2;i<=n;i++)
	{
		cin>>x;
		s.insert(x);//�Ѿ��Ž�ȥ�ˣ��ҵ�ʱ��᷵�������ڵ�λ�� 
		it=s.lower_bound(x);//�ҳ�ֵx���ڵ�λ�� 
        if(it==s.begin())//���ǵ�һλ ��Ԫ����ͷ 
        {
        	it++;
        	cout<<*it<<' ';
        	continue;
		}
		it++;//ע���������ĺ�һλ 
		if(it==s.end())
		{
			it--;
			it--;
			cout<<*it<<' ';
			continue;
		 }
		int behind=*it;//���Ǻ��� 
		it--;//��λ 
		int now=*it;
		it--;//��ǰ��
		int pre=*it;
		if(now-pre>=behind-now)
		{
			cout<<behind<<' ';
		}
		else if(now-pre<behind-now)
		{
			cout<<pre<<' ';
		}	
	}
	return 0;
}


