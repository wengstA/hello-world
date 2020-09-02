#include<iostream>
using namespace std;
int N;
int L1[105];
int L2[105];
void Create()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> L1[i];
}
void Merge(int *A,int *TmpA,int begin,int begin2,int end)
{
	int p1=begin,c1 = begin, p2 = begin2;
	while (p1 != begin2 && p2 != end)
	{
		if (A[p1] < A[p2])
			TmpA[c1++] = A[p1++];
		else
			TmpA[c1++] = A[p2++];
			
	}
	if (p1 < begin2)
		p2 = p1;
	for (; c1 < end; c1++)
		TmpA[c1] = A[p2++];
	 
}

void Merge_Pass(int *A,int *TmpA,int length)
{
	int i = 0;
	for ( i = 0; i + length * 2 < N; i += length * 2)
		Merge(A, TmpA, i, i + length, i + 2 * length);
	if (i + length < N)
		Merge(A, TmpA, i, i + length, N);
	else
		for (int j = i; j < N; j++)TmpA[j] = A[j];
}
void Sort()
{
	int length = 1;
	while(length<N)
	{
		Merge_Pass(L1, L2, length);
		length *= 2;
		Merge_Pass(L2, L1, length);
		length *= 2;
     }
}
int main()
{
	Create();
	Sort();
	
	for (int i = 0; i < N; i++)
		 cout << L1[i] << " ";
}
