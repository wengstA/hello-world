#include<iostream>
using namespace std;
int N;
int L1[105];
int L2[105];

void Merge(int s1,int s2,int end)
{
	int p1 = s1, p2 = s2;
	int c1 = s1;
	while (p1 != s2 && p2 != end)
	{
		if (L1[p1] > L1[p2])
			L2[c1++] = L1[p2++];
		else
			L2[c1++] = L1[p1++];
	}
	//将已经排好序的复制回去
	int cut = c1;
	if (p1 < s2)
	{
		
		for (; c1 < end; c1++)
			L1[c1] = L1[p1++];
	}
	for (int i = s1; i < cut; i++)
		L1[i] = L2[i];
	
}
void Sort(int begin,int end)
{
	
	if (begin+1== end)return;//注意是+1
	int middle = (begin + end) / 2;
	Sort(begin,middle);
	Sort(middle,end);
	Merge(begin, middle, end);
}
void Create()
{
	cin >> N; 
	for (int i = 0; i < N; i++)
		cin >> L1[i];
}
int main()
{
	Create();
	Sort(0, N);
	for (int i = 0; i < N; i++)
	{
		cout << L1[i];
		if (i != N - 1)
			cout << " ";
	}

}
