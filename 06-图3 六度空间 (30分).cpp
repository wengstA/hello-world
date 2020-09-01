#include<iostream>
#include<vector>
using namespace std;
int visited[10005];
vector<int> G[10005];


typedef struct QNode
{
	int step = 0;
	int position = 0;
}QNode;
int BFS(int x)
{
	QNode Queue[1005];
	int r = 0, f = 0;
	Queue[r].position= x;//»Î∂”
	Queue[r++].step = 0;
	visited[x] = true;
	int count = 1;
	while (f != r)
	{
		x = Queue[f++].position;
		for (int i = 0; i < G[x].size(); i++)
		{
			int next = G[x][i];
			if (!visited[next]&&Queue[f-1].step<6)
			{
				visited[next] =true;
				Queue[r].position = G[x][i];
				Queue[r].step = Queue[f-1].step + 1;
				r++;
				
				count++;
			}
			
		}
	}
	return count;
}
int main()
{
	int n, m;
	cin >> n >> m;

	int x, y;
	for (int i = 1; i <=m; i++)
	{
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	for (int i = 1; i <=n; i++)
	{
	
		for (int i = 1; i <= n; i++)
			visited[i] = false;
		int count = BFS(i);
		float percent;
		percent=((float)count / (float)n)*100;
		printf("%d: %.2f%c",i, percent,'%');
		if (i != n)
			cout << endl;
	}

}
