#include<iostream>
using namespace std;
int N;
int* Number;

int* BuildHeap()
{
	cin >> N;
	 Number = new int[N+1];
	for (int i = 1; i <=N; i++)
		cin >> Number[i];
	int child, parent;
	int i = 0; int temp;
	for (int i = N / 2; i > 0; i--)
	{
		temp = Number[i];
		for ( parent = i; parent * 2 <= N; parent = child)
		{
			child = parent * 2;
			if (child!=N&&Number[child] > Number[child + 1])
				child = child + 1;
			if (Number[child] >= temp)break;
			Number[parent] = Number[child];
		}
		Number[parent] = temp;
	}
	
	return Number;
}
void Print()
{
	int parent, child=0;
	for (int i = N; i>0; i--)
	{
		cout << Number[1];
		if (i!= 1)
			cout << ' ';
		Number[1] = Number[i];
		int temp = Number[1];
		for (parent = 1; parent * 2 <=i; parent = child)
		{
			child = parent * 2;
			if (child != i && Number[child] > Number[child + 1])
				child = child + 1;
			if (temp < Number[child])break;
			Number[parent] = Number[child];
		}
		Number[parent] = temp;
	}
}
int main()
{
	BuildHeap();
	Print();
}
