#include<iostream>
using namespace std;
//Bubble
int main()
{
	int N; cin >> N;
	int* Array = new int[N];
	for (int i = 0; i < N; i++)
		cin >> Array[i];
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N - j - 1; i++)
		{
			if (Array[i] > Array[i+ 1])
			{
				int temp = Array[i];
				Array[i] = Array[i + 1];
				Array[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		
			cout << Array[i];
if (i != N - 1)
		cout<< ' ';
	}

}
