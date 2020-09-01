#include<iostream>
using namespace std;
int visited[10005] = { 0 };
typedef struct Node {
	int x;
	int y;
}Node;

bool judge(int x1, int x2, int y1, int y2,int D)
{
	if (x1==50&&y1==50)
	{
		D = D + 15;
	}
	else if (x2 == 50 && y2 == 50)
	{
		D += 15;
	}
	int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if (distance >D* D)
		return false;
	else 
		 return true;
	
}
bool DFS(int x,int y,int D,Node position[],int N)
{
	
	int result=0;
	if (x ==50 && y == 50)
	{
		if (x + D + 15 >= 100 || y + D + 15 >= 100 || x - D <= 0 || y - D <= 0)
			return true;
	}

	if (x + D >= 100 || y + D >= 100 || x - D <= 0 || y - D <= 0)
		return true;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (judge(x, position[i].x, y, position[i].y,D)&&(!visited[i]))
			{//跳的到而且没有访问过
				visited[i] = true;
				result = DFS(position[i].x, position[i].y, D, position, N);
				if (result) break;
			}
		}

	}	
	return result;
}
int main()
{
	int N = 0, D = 0;
	cin >> N >> D;
	Node* position = new Node[N];
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		x += 50;y += 50;
		position[i].x = x;
		position[i].y = y;
	}
	int result = DFS(50, 50,D,position,N);
	if (result)
		cout << "Yes";
	else
		cout << "No";
}
