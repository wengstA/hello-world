//¹þÀû²¨ÌØËã·¨
#include<iostream>
using namespace std;
int V, E;
int G[105][105];
int visited[105];
void Create()
{
	cin >> V >> E;
	for (int i = 1; i <=V; i++)
		for (int j = 1; j <=V; j++)
			G[i][j] = 9999;
	for (int i = 0; i < E; i++)
	{
		int x = 0, y = 0;
		int weight;
		cin >> x >> y >> weight;
		G[x][y] = weight;
		G[y][x] = weight;
	}
}
void Flyod()
{
	int i = 0, j = 0, k = 0;
	for (i = 1; i <=V; i++)
	{
		for (j = 1; j <=V; j++)
		{
			for (k = 1; k <=V; k++)
			{
				if (j != k)
				{
					if (j != i && k != i)
					{
						if (G[j][i] + G[i][k] < G[j][k])
						G[j][k] = G[j][i] + G[i][k];
					}
				}
			}
		}
	}
}
void Judge(int x)
{
	visited[x] = true;
	for (int i = 1; i <=V; i++)
	{
		if (!visited[i] && G[x][i] < 9999)
		{
         Judge(i);
		}
	}
	
	return;
}
int main()
{
	Create();
	Judge(1);
	int link = 1;
	for (int i = 1; i <= V; i++)
		if (!visited[i])
			link = 0;
	Flyod();
	
	int mindis = 9998, maxposition = 0;
	int i = 0;
	if (V == 1)
		cout << 1<<' '<<0;
	else {
		for (i = 1; i <= V; i++)
		{
			int have = 0;
			int maxdis = 0;
			for (int j = 1; j <= V; j++)
			{
				if (G[i][j] > maxdis&& G[i][j] != 9999 && (i != j))
				{
					maxdis = G[i][j];
				}
			}
			
			if (maxdis < mindis)
			{
				mindis = maxdis;
				maxposition = i;
			}
		}
		if (link)
			cout << maxposition << ' ' << mindis;
		else
			cout << 0;
	}
}
