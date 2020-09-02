#include<iostream>
using namespace std;

int* Array;
void Shell(int N)
{
	int i;
	for (int D = N/2; D > 0; D /= 2)
	{
		for (int p = D; p < N; p++)
		{//因为是和前面的比较调整顺序，但是推进是往后推进的，所以应该确定起始位置
			int temp = Array[p];
			for (i = p; i >=D && Array[i - D] > temp; i=i-D)
				Array[i] = Array[i - D];
			Array[i] = temp;  
		}
		
	}
}
int main()
{
	int N; cin >> N;
	Array = new int[N];
	for (int i = 0; i < N; i++)
		cin >> Array[i];
	Shell(N);
	for (int i = 0; i < N; i++)
	{
		cout << Array[i];
		if (i != N - 1)
			cout << ' ';
	}
}
