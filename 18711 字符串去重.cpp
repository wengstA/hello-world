#include<iostream>
#include<cstdio>
#include<vector>
#define OK 1
#define Status int
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	char *s;
	s=new char[n+1];
	int al[26]={0};
	scanf("%s",s);
	for(i=0;i<n;i++) 
	   al[s[i]-'a']++;
	for(i=0;i<26;i++){
		if(al[i]) 
		   cout<<(char)('a'+i);
	}
	return 0;
}

