#include<iostream>
#include<vector>
using namespace std;
int Final[505];
int Path[505];
int dis[505] = { 9999 };
int price[505] = { 9999 };
int V, E, S, D;
typedef struct Node
{
	int de = 0;
	int length = 0;
	int price = 0;
}Node;
vector<Node> G[505];
void Create_Graph()
{
	cin >> V >> E >> S >> D;
	for (int i = 0; i < E; i++)
	{
		Node A;
		int c1 = 0, c2 = 0;
		cin >> c1 >> c2 >> A.length >> A.price;
		A.de = c2;
		G[c1].push_back(A);
		A.de = c1;
		G[c2].push_back(A);
	}
}
void Initial()
{
	Final[S] = true;
	Path[S] = -1;
	dis[S] = 0;
	price[S] = 0;
	for (int i = 0; i <V; i++)
	{//初始化距离位置
		dis[i] = 9999;
		Path[i] = S;
		price[i] = 9999;
	}
	for (int i = 0; i <G[S].size(); i++)
	{//初步初始化距离
		int p = G[S][i].de;
		dis[p] = G[S][i].length;
		price[p] = G[S][i].price;
	}
}
void Find()
{
  Initial();
 
  for (int i = 0; i <V; i++)
  {
	  //1.先找到路径最短的点
	   //2.更新点的距离和价格，注意是同步更新的
	  int mindis = 9999, minpo = 0;
	  for (int i = 0; i < V; i++)
	  {
		  if (!Final[i]&&dis[i] < mindis)
		  {
			  mindis = dis[i];
			  minpo = i;
		  }
	  }
	  if (mindis < 9999)
	  {
		  if (minpo == D)
			  break;
		  Final[minpo] = true;
		  for (int i = 0; i < G[minpo].size(); i++)
		  {
			  int pos = G[minpo][i].de;
			  int length = G[minpo][i].length;
			  int money = G[minpo][i].price;
			  if (!Final[pos] && length + dis[minpo] <=dis[pos])
			  {
				  if (dis[minpo]+length == dis[pos])
				  {
					  if (price[pos] < money + price[minpo])
						  continue;
				  }
				  dis[pos] = length + dis[minpo];
				  price[pos] = money + price[minpo];
			  }
		  }
	  }
	  else break;
  }
  cout << dis[D] << ' ' << price[D];
}
int main()
{
	Create_Graph();
	
	Find();
}
