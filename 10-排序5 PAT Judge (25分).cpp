#include<iostream>
using namespace std;

int N;
int Number[10005];

int main()
{
	int N, K, M;
	cin >> N >> K >> m;
	int list = new int[K];
	int *mark = new int*[N];
	for (int i = 0; i < N; i++)
		mark[i] = new int[K];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			mark[i][j] = -2;
		}
	}//???
	for (int i = 0; i < M; i++)
	{
		int position, problem, score;
		cin >> position >> problem >> score;
		mark[position][problem] = score;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << mark[i][j] << ' ';
		cout << endl;
	}
}