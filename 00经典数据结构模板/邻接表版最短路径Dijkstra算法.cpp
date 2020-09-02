//Dijkstra算法的邻接表实现方法
#include<iostream>
#include<vector>
using namespace std;
int V, E;
bool Final[1005] = { 0 };
int Dis[1005] = { 0 };
int Path[1005] = { 0 };
typedef struct Node
{
	int position;
	int weight;
}Node;
vector<Node>* Create()
{
	cin >> V >> E;
	vector<Node> *G = new vector<Node>[V];
	int x=0,y=0;int weight = 0;
	for (int i = 0; i < E; i++)
	{
		cin >> x >> y >> weight;
		Node A;
		A.position = y;
		A.weight = weight;
		G[x].push_back(A);
		A.position = x;
		G[y].push_back(A);
	}
	return G;
}
void Initial(vector<Node>* G)
{
	for (int i = 0; i < V; i++)
	{
		Dis[i] = 99999;
		Path[i] = 0;
	}
	Path[0] = -1;
	for (int i = 0; i < G[0].size(); i++)
	{
		int position = G[0][i].position;
		int weight = G[0][i].weight;
		Dis[position] = weight;
	}
}
void PrintPath(int x)
{
	if (x == -1)
	{
		for (int i = 0; i < V; i++)
			cout << Path[i] << ' ';
		cout << endl;
		return;
	}
	else
		PrintPath(Path[x]);
	    cout << x;
}
void Prim(vector<Node>* G)
{
	for (int i = 1; i < V; i++)
	{
		//1.寻找下一步最小路径
		//2.纳入体系并且更新Dis
		
		Final[0] = true;
		for (int v = 1; v < V; v++)
		{//一定要把所有顶点放入
			int minpo = 0; int mindis = 99999;
			for (int w = 1; w < V; w++)
			{
				if (!Final[w] && mindis > Dis[w])
				{
					mindis = w;
					minpo = w;
				}
			}
			//找到最小值
				if (mindis <99999)
				{
					Final[minpo] = true;
					for (int w = 1; w < G[minpo].size(); w++)
					{
						int position = G[minpo][w].position;
						int weight = G[minpo][w].weight;
						if (!Final[position] &&( G[minpo][w].weight + Dis[minpo] < Dis[position]))
						{
							Dis[position] = G[minpo][w].weight + Dis[minpo];
							Path[position] = minpo;
						}
					}
				}
				else
					break;
			
		}
	}
}
int main()
{//创立图
	vector<Node>*G=Create();
 //Initial
	Initial(G);
//Prim
	Prim(G);
//搜索路径
	int x;
	cout << "The route you want to search  ";
	cin >> x;
	PrintPath(x);


    
}
