#include<iostream>
#include<vector>
#include<vector>
using namespace std;
int main()
{
	//�����ڽӱ������д洢
    int n,m;
	cin>>n>>m;//�㣬��
	int x,y;
	vector<int> e[n+1];
  for(int i=1;i<=m;i++)
  {
  	cin>>x>>y;
  	e[x].push_back(y);//�ڽӵ�Ž�ȥ 
  }
  //��һ���ڴ�����
  for(int i=1;i<=n;i++)//ע����n������������� 
  {
  	cout<<i<<"--->"; 
  	for(int j=0;j<e[i].size();j++)
  	{
  		cout<<e[i][j]<<' ';
	  }
	  cout<<endl;
   } 
 } 
