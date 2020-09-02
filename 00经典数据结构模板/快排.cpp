#include<iostream>
using namespace std;
int N;
int Number[1005];
void Create()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Number[i];
}

int Median3(int left,int right)
{
	//思路：先把left，center形成一个有序的序列，再插入right
	int center = (right + left) / 2;
	if (Number[left] > Number[center])
		swap(Number[left], Number[right]);
	if (Number[left] > Number[right])
		swap(Number[left], Number[right]);
	if(Number[center]>Number[right])
		swap(Number[center],Number[right]);
	
	swap(Number[right - 1], Number[center]);
	return Number[right - 1];
}
void swap(int& A, int& B)
{
	int temp = A;
	A = B;
	B = temp;
}
void Sort(int left,int right)
{
	if (right - left <= 1)return;
	int pivot = Median3(left, right);
	int  i = left; int j = right - 1;
	for (;;)
	{
		while (Number[++i] < pivot) {}
		while (Number[--j] > pivot) {}
		if (i < j)
			swap(Number[i], Number[j]);
		else break;
	}
	swap(Number[i], Number[right - 1]);
	
	Sort(left, i);
	Sort(i + 1, right);
}
int main()
{
	Create();
	Sort(0, N - 1);
	for (int i = 0; i < N; i++)
		cout << Number[i] << ' ';
}
