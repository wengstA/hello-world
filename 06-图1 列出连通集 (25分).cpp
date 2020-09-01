#include<iostream>
using namespace std;
bool visited[15];
int G[11][11];
int n, m;//顶点数，边数

void DFS(int x)
{
	visited[x] = true;
	cout << x << ' ';
	for (int i = 0; i <=10; i++)
	{
		if (G[x][i])
		{
			int next = i;
			if (!visited[next])
				DFS(next);
		}
	}
}

void BFS(int x)
{
	int queue[10];
	int f = 0,r = 0;
	visited[x] = true;
	queue[r++] = x;
	while (f != r)
	{
		int x = queue[f++];
		cout << x << ' ';
		for (int i = 0; i <=10; i++)
		{
			if (G[x][i])
			{
				if (!visited[i])
				{
					visited[i] = true;
					queue[r++] = i;//入队
				}
			}
		}

	}
}
int main()
{
	
	cin >> n >> m;
	//初始化
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			G[i][j] = 0;
	}
	//输入v1,v2；
	int v1 = 0, v2 = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			cout << "{ ";
			DFS(i);
			cout << "}" << endl;
		}
	}
	for (int i = 0; i <=10; i++)
		visited[i] = 0;
	int have = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			if (!have)
				have = 1;
			else cout << endl;
			cout << "{ ";
			BFS(i);
			cout << "}";
		}
	}
}
