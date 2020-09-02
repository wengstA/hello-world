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
	//��ʼ��
	int v = 1;
	//1.����Dis����Сֵ�������νӵĵ㣬ֵ���������
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
			{//˵���ɹ������������Ӧ��ֵ
				Final[minpo] = true;
			}
			else break;
			//2.��ϵ�������µĵ�֮��Ҫ����dis�ľ���
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
		cout << "ͼ������ͨ";
	}
	else {
		for (i = 0; i < V; i++)
			cout << Path[i] << ' ';
	}
	int x=0;
	cout << "�����������ѯ��0��x��·����X��ֵ��";
	cin >> x;
	PrintPath(x);
	cout << endl;
	}
	

