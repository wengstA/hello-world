#include<iostream>
using namespace std;
int V = 0,E = 0;
int Dis[105];
int G[105][105];
bool Final[105] = { 0 };
int Path[105] = { 0 };
void Create()
{
	
	cin >> V >> E;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			G[i][j] = 9999;
	}
	for (int i = 0; i < E; i++)
	{
		int x, y;
		cin >> x >> y;
		int weight;
		cin >> weight;
		G[x][y] = weight;
		G[y][x] = weight;
	}
}

void PrintPath(int x)
{
	if (x == -1)
		return;
	else
	{
		PrintPath(Path[x]);
		cout <<x<<' ';
	}
}
int main()
{
	Create();
	int i;
	for (i = 1; i < V; i++)
	{
		Dis[i] = G[0][i];
		Path[i] = 0;
	}
	Path[0] = -1;
	Final[0] = true;
	//初始化
	int v = 1;
	//1.先找Dis的最小值，若不衔接的点，值都是无穷大
	for ( v = 1; v < V; v++)
	{
		int minpo = 0;
		int mindis = 9999;
		for (int w = 0; w < V; w++)
		{
			if (!Final[w] && (Dis[w] < mindis))
			{
				mindis = Dis[w];
				minpo = w;
			}
		}
			if (mindis < 9999)
			{//说明成功搜索到了相对应的值
				Final[minpo] = true;
			}
			else break;
			//2.体系纳入了新的点之后要更新dis的距离
			for (int w = 1; w < V; w++)
			{
				if (!Final[w] && (mindis + G[minpo][w] < Dis[w]))
				{
					Dis[w] = mindis + G[minpo][w];
					Path[w] = minpo;
				}
			}
	}
	if (v != V)
	{
		cout << "图并不连通";
	}
	else {
		for (i = 0; i < V; i++)
			cout << Path[i] << ' ';
	}
	int x=0;
	cout << "请输入你想查询的0到x的路径的X的值：";
	cin >> x;
	PrintPath(x);
	cout << endl;
	}
	

