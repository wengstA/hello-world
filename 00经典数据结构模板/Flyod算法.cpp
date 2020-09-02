//Floyd算法
#include<iostream>
using namespace std;
int V, E;
int G[1055][1005];
void Create()
{
	cin >> V >> E;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			G[i][j] = 9999;
		}
	}
	for (int i = 0; i < E; i++)
	{
		int x, y;
		cin >> x >> y;
		int weight; cin >> weight;
		G[x][y] = weight;
	}
}

void Floyd()
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < V; k++)
			{
				if (j != k)
				{//不是在对角线上
					if (j != i && k != i)
					{//不是在对应的行列范围内
						if (G[j][i] + G[i][k] < G[j][k])
						{
							G[j][k] = G[j][i] + G[i][k];
						}

					}
				}
			}
		}
	}
}
int main()
{
	Create();
	Floyd();
	cout << "请输入你想查询的两点之间的距离 ";
	int n1 = 0, n2 = 0;
	cin >> n1 >> n2;
	cout <<endl<< "他们之间的距离是" << G[n1][n2];
}
