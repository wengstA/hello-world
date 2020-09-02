#include<iostream>
#include<set>
using namespace std; 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int i,j,n,m;
	set<int> st;
	
	cin>>n;
	while(n!=-1)
	{
			for(i=0;i<n;i++){
	    cin>>m;
		st.insert(m);
	}
	set<int>::iterator it;//这是一个迭代器，相当于指针 
	for(it=st.begin();it!=st.end();it++)
	{
		cout<<*it;
	}
	cout<<endl;
	it=lower_bound(st.begin(),st.end(),10);
	cout<<*it;
	st.clear();
	cout<<"come on ,input and I will get text"<<endl;
	cin>>n;
	}

	return 0;
}
