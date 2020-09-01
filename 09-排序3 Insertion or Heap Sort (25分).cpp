#include<iostream>
using namespace std;
int N;
int initial[1005];
int compare[1005];
int Temp[1005];
void Create()
{
	cin >> N;
	for (int i=0; i < N; i++)
		cin >> initial[i];
	for (int i=0; i < N; i++)
		cin >> compare[i];
}
void Insertion(int position)
{

	int tmp = initial[position];
	int i = 0;
	for (i = position; (i > 0) && (compare[i-1] >=tmp); i--)
		compare[i] = compare[i - 1];
	compare[i] = tmp;
	for (i = 0; i < N; i++)
	{
		cout << compare[i];
		if (i != N - 1)
			cout << " ";
	}

}
void swap(int& A, int& B)
{
	int temp = A;
	A = B;
	B = temp;
}
int getBigchild(int parent)
{
	int child =(parent + 1) * 2;
	return child;
}
void HeapAdjust()
{
	int Big = compare[0]; int i;
	int position;
	for (i = N - 1; compare[i] > Big; i--) { ; }
	position = i;
	swap(compare[0], compare[position]);
	int temp = compare[0];
	int parent = 0, child = getBigchild(0);
	for (parent; (getBigchild(parent) <position)&& compare[parent] >=temp; parent = child)
	{
		child = getBigchild(parent);
		if ((child != position-1) && (compare[child - 1] > compare[child]))
			child = child - 1;
		compare[parent] = compare[child];
	}
	if (getBigchild(parent) == position)
	{
		if (compare[position - 1] > temp)
		{
			compare[parent] = compare[position - 1];
			compare[position - 1] = temp;
		}
		else compare[parent] = temp;
	}
	else compare[parent] = temp;
	for (int i = 0; i < N; i++)
	{
		cout << compare[i];
		if (i != N - 1)
			cout << " ";
	}
}
void Print(int* Number)
{
	for (int i = 0; i < N; i++)
	{
		cout << Number[i];
		if (i != N - 1)
			cout << ' ';
	}
	
}

int main()
{
	int i = 1;
	Create();
	while ((compare[i - 1] <= compare[i]) && (i < N)) { i++; }
	int insert = 1;
	int position = i;
	for (i; i < N; i++)
	{
		if (compare[i] != initial[i])
		{
			insert = 0;
			break;
		}
	}
	if (insert)
	{
		cout << "Insertion Sort" << endl;
		Insertion(position);
	}
	else
	{
		cout << "Heap Sort" << endl;
		HeapAdjust();
	}
	


}
