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
//	   sort(number,number+i-1);//先这个元素之前排序
//	   p=lower_bound(number,number+i-1,number[i]);//在之前的排列中找大于等于的值 
//	   if(*p<number[i])//说明前面的都比它要小
//	   {
//	   	 int Lmax=findmax(number,i-1,*p);
//			cout<<Lmax<<' ';
//			continue;//找前面序列里最小的 
//	   } 
//	   if(p==number)cout<<*p<<' ';//当指向第一个元素的时候
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
		s.insert(x);//已经放进去了，找的时候会返回你现在的位置 
		it=s.lower_bound(x);//找出值x所在的位置 
        if(it==s.begin())//这是第一位 ，元素在头 
        {
        	it++;
        	cout<<*it<<' ';
        	continue;
		}
		it++;//注意这是最后的后一位 
		if(it==s.end())
		{
			it--;
			it--;
			cout<<*it<<' ';
			continue;
		 }
		int behind=*it;//这是后驱 
		it--;//复位 
		int now=*it;
		it--;//往前调
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


