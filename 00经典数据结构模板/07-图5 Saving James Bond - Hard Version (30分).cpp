#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef struct Node {
	int x;
	int y;
}Node;
Node G[105];
int V = 0;
//Dijkstra算法专属
int Final[105] = { 0 };
int dis[105] = { 9999 };
int path[105] = { 0 };
int root[105] = { 0 };
vector<int>Graph[105];
int D = 0;
int Distance(int x1, int y1, int x2, int y2)
{//检测能不能跳到
	int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if (x1 == 50 && y1 == 50)
	{
		if (sqrt(distance) <= 15)
			distance = 0;
		else
			distance = sqrt(distance) - 15;
	}
	else
		distance = sqrt(distance);
	return distance;
}
bool OK(int x1, int y1, int x2, int y2)
{
	int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if (D * D >= distance)
		return true;
	else return false;
}
bool far(int x1, int y1, int x2, int y2)
{
	int dis1 = 0, dis2 = 0;
	dis1 = (x1 - 50) * (x1 - 50) + (y1 - 50) * (y1 - 50);
	dis2 = (x2 - 50) * (x2 - 50) + (y2 - 50) * (y2 - 50);
	if (dis2 - dis1 > 0)
		return true;
	else
		return false;
}//确保2相比1离原点越来越远
void Create()
{
	cin >> V >> D;
	G[0].x = 50;
	G[0].y = 50;
	//储存原始数据
	for (int i = 1; i <= V; i++)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		x = x + 50;
		y = y + 50;
		Node A;
		A.x = x;
		A.y = y;
		G[i] = A;
	}
	//储存有边的数据
	for (int i = 0; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
			if (i != j)
			{
				if (OK(G[i].x, G[i].y, G[j].x, G[j].y))
				{
					if (far(G[i].x, G[i].y, G[j].x, G[j].y))//说明j比i远,让i指向j
					{
						Graph[i].push_back(j);
					}

				}
			}
	}
	
}
void PrintPath(int x,int change)
{
	if (x == 0)
		return;
	PrintPath(path[x],1);
	cout << G[x].x - 50 << ' ' << G[x].y - 50;
	if(change)
		cout << endl;
}
void Initiate()
{

	for (int i = 1; i <= V; i++)
	{
		dis[i] = 9999;
		Distance(50, 50, G[i].x, G[i].y);
		Final[i] = false;
		path[i] = 0;
		root[i] = 0;
	}
	Final[0] = true;
	for (int i = 0; i < Graph[0].size(); i++)
	{
		int position = Graph[0][i];
		dis[position] = 1;
		
	}
}
int Dijkstra(int &minstep)
{	
	minstep = 1000;
	int minpo = 0;
	
	int out = 0;int end = 0;
	for(int i=0;i<=V;i++)
	{//1.先搜索Dis数组里面最短的路径(没有访问过)
	//2.根据记录的最短的位置，更新最短距离（保证更新点相对这个点离原点更加遥远）

		int mindis = 9999;
		int min = 0;
		for (int v = 1; v <= V; v++)
		{
			if (!Final[v] && mindis > dis[v])
			{
				mindis = dis[v];
				min = v;
			}
		}
		if (min != 0)
		{
			Final[min] = true;
		}
		/*else break;*/
		int parent = path[min];
		int child = min;
		while (parent)
		{
			child = parent;
			parent = path[child];
		}
			for (int w = 0; w < Graph[min].size(); w++)
			{
				int po = Graph[min][w];
				
				if (dis[min] + 1 < dis[po])
				{
					dis[po] = dis[min] + 1;
					path[po] = min;
					root[po] = child;
				}
				else if (dis[min] + 1 == dis[po] &&(!far(G[root[po]].x, G[root[po]].y, G[child].x, G[child].y)))
				{
					
					path[po] = min;
					root[po] = child;
				}
			}
		
	/*cout << endl<<"min is" << ' ' << G[min].x-50<<" "<<G[min].y-50<< ' ';
	for (int k = 1; k <= V; k++)
	{
		cout <<"||"<< dis[k] << ' ' << root[k] << ' ' << "||";
	 }*/
	}	
		

	/*for (int i = 1; i <= V; i++)
		cout <<"i is"  <<i<<' '<<dis[i] << ' ';
	cout << endl;*/

	for (int i = 1; i <= V; i++)
	{
		if (G[i].x + D >=100 || G[i].x - D <=0 || G[i].y + D>=100 || G[i].y - D <=0)
		{
			if (minstep > dis[i])
			{
				minstep = dis[i];
				minpo = i;
			}
			else if (minstep==dis[i]&&(!far(G[root[minpo]].x, G[root[minpo]].y, G[root[i]].x, G[root[i]].y)))
			{
				minstep = dis[i];
					minpo = i;
			}
		}
	}
	return minpo;
}
int main()
{
	Create();
	Initiate();
	if (D >= 35)
	{
		cout << 1;
		return 0;
	}
	int minstep = 0;
	int minpo = Dijkstra(minstep);
	minstep++;
	int change = 0;
	if (minpo)
	{
		cout << minstep << endl;
		PrintPath(minpo,change);
	}
	else
		cout << 0;
}
