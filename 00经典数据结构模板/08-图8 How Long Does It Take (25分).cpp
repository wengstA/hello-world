#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int Indegree[1005] = { 0 };
int Ear[1005];

typedef struct Node
{
	int data;
	int dis;
}Node;
vector<Node> G[1005];
queue<int> Q;
int V, E;
void Create()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int S = 0, E = 0, dis = 0;
		cin >> S >> E >> dis;
		Node A;
		A.data = E, A.dis = dis;
		G[S].push_back(A);
		Indegree[E]++;
	}
}

int Initial()
{
	int end = 0;
	for (int i = 0; i < V; i++)
	{
		Ear[i] = 9999;
		if (!Indegree[i])
			Q.push(i);
		if (!G[i].size())
			 end = i;
	}
	return end;
}
void TP()
{
	Create();
	int end=Initial();
	while (!Q.size())
	{
		int out = Q.front();
		Q.pop();
		for (int i = 0; i < G[out].size(); i++)
		{
			int position = G[out][i].data;
			int distance = G[out][i].dis;
			if (--Indegree[position]==0)
				Q.push(position);
			if (Ear[position] > distance + Ear[out])
				Ear[position] = distance + Ear[out];
		}
	}
	cout << Ear[end];
}

