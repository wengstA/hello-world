#include<iostream>
using namespace std;
int main()
{
	int N = 0;
	cin >> N;
	int* Number = new int[N];
	for (int i = 0; i < N; i++)
	{
		Number[i] = 0;
	}
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		int number = 0; cin >> number;
		for (j = 0; j <i; j++)
		{
			if (number < Number[j])
			{
					for ( k = i + 1; k > j; k--)
					{
						Number[k] = Number[k - 1];
					}
				break;
			}
		}
		Number[j] = number;
	}
	for (int i = 0; i < N; i++)
	{
		cout << Number[i];
		if (i != N - 1)
			cout << ' ';
	}
}
