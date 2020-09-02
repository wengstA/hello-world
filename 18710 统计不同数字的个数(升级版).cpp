#include<iostream>
#include<cstdio>
#include<vector>
#define OK 1
#define Status int
#define MAX 200005
using namespace std;
int main()
{
	int n,i;
	int c=0;
	scanf("%d",&n);
	int position;
	int push[MAX]={0};
	for(i=0;i<n;i++)
    {
        scanf("%d",&position);
        push[position]++;
        if(push[position]==1)c++;
    }
    printf("%d",c);
    return 0;
}

