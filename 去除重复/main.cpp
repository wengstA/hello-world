#include<iostream>
#include<cstdio>
#include<vector>
#define OK 1
#define Status int
using namespace std;
int main()
{
	int n,i;
	int c=0;
	cin>>n;
	int position;
	int *push[200005];
	for(i=0;i<n;i++)
    {
        cin>>position;
        push[position]++;
    }
    for(i=0;i<n;i++)
    {
        if(push[i])
        {cout<<"here is"<<i<<"and c is"<<c<<"\n";
            c++;}
    }
    cout<<c;
}
