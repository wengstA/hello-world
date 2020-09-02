#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next;
}Node, * List;
List rear[10], front[10];
int judge(int number)
{
	int count = 0;
	while (number)
	{
		count++;
		number/= 10;
	}
	return count;
}

void Print(List A)
{
	for (List P = A; P; P = P->next)
		printf("%03d ",P->data);
	cout << endl;
}
List CreateList(int n, int& maxdigit)
{
	List A, head = NULL, tail = NULL;
	//int number=0;
	for (int i = 0; i < n; i++) {
		A = new Node;
		cin >> A->data;
		maxdigit = max(maxdigit, judge(A->data));
		A->next = NULL;
		if (!head)head = A;
		if (tail)
			tail->next = A;
		tail = A;
	}
	//	Print(head);
	return head;
}
int Sort(int maxdigit, List A)
{
	//cout << maxdigit << endl;
	int c = 1;
	int i, j, k;
	List p;
	for (k= 0; k< maxdigit; k++)
	{
		if (!c) break;
		for (p = A; p; p = p->next)
		{//获取最小位的方法
			j = p->data / c % 10;
			if (!front[j])
				front[j] = p;
			if (rear[j])
				rear[j]->next = p;
			rear[j] = p;
		}
		 A= NULL;
		for (i = 9; i >= 0; i--)
		{
			if (front[i]) {
             rear[i]->next = A;
			 A = front[i];
			 front[i] = NULL, rear[i] = NULL;
			}
			
		}
		Print(A);
		c *= 10;
	}
	return 0;
}
int main()
{
	int N; cin >> N;
	int maxdigit = 0;
	List A = CreateList(N, maxdigit);
	//Print(A);
	Sort(maxdigit, A);
}
