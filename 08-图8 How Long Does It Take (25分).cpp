
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int Indegree[1005] = { 0 };
int Ear[1005];
int E[1005];
; typedef struct Node
{
	int data;
	int dis;
};
vector<Node> G[1005];
queue<int> Q;
int V, E;
int Last[1005] , p = 0;
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

void Initial()
{
	
	for (int i = 0; i < V; i++)
	{
		Ear[i] = 0;
		if (!Indegree[i])
		{
			Q.push(i);
			Ear[i] = 0;
		}
		if (!G[i].size())
		   Last[p++] = i;
	}
}
void TP()
{
	Create();
	Initial();
	int cnt = 0;
	while (Q.size())
	{
		int out = Q.front();
		Q.pop();
		cnt++;
		for (int i = 0; i < G[out].size(); i++)
		{
			int position = G[out][i].data;
			int distance = G[out][i].dis;
			if (--Indegree[position]==0)
				Q.push(position);
			if (Ear[position] < distance + Ear[out])
				Ear[position] = distance + Ear[out];
		}
	}
	if (cnt != V)
		cout << "Impossible";
	else
	{
		int min = 0;
		for (int i = 0; i < p; i++)
		{
			int position = Last[i];
			if (Ear[position] > min)
				min = Ear[position];
		}
		cout << min;
	}
}
 
int main()
{
	TP();
	/*for (int i = 0; i < V; i++)
		printf("%02d ", Ear[i]);
	cout << endl;
	for (int i = 0; i < V; i++)
		printf("%02d ", i);*/

}
