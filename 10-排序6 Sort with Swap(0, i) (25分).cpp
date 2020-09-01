#include<iostream>
#include<algorithm>
using namespace std;

int N;
int order[100005];
int initial[100005];
int position[100005];
void create()
{
	cin>>N;int number;
	for(int i=0;i<N;i++)
     {
	 cin>>number;
	 order[i]=number;
	 initial[i]=number;
	 position[number]=i;
	  }  
 } 
 int main()
 {
 	create();
 	sort(order,order+N);
 	for(int i=0;i<N;i++)
	  cout<<order[i];
 }
 
