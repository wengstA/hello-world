#include<iostream>
using namespace std;

typedef struct TreeNode {
	int data;
	struct TreeNode* lchild = NULL;
	struct TreeNode* rchild = NULL;
}*Tree, TreeNode;

void InitialTree(Tree& T, int N)
{

	for (int i = 0; i < N; i++)
	{
		Tree P = T;//ÿһ�ֶ�Ҫ��ͷ��ʼ 
		//�������
		Tree A; Tree pre;
		int number;
		cin >> number;
		A = (Tree)malloc(sizeof(TreeNode));
		A->data = number;
		A->lchild = NULL;
		A->rchild = NULL;
		if (!i)
		{
			//cout<<"YES";
			T = A;//��������
			P = T;
			continue;
		}
		int way;
		while (P)
		{
			pre = P;
			if (P->data < number)
			{
				P = P->rchild;
				way = 0;

			}
			else
			{
				P = P->lchild;
				way = 1;
			}
		}
		if (way)//˵�������
		{
			pre->lchild = A;
		}
		else pre->rchild = A;
	}
}

void Print(Tree T)
{
	if (!T)return;
	cout << T->data << " ";
	Print(T->lchild);
	Print(T->rchild);
}

bool Compare(int infor[], Tree T, int N, Tree IT)
{
	for (int i = 0; i < N; i++)
	{
		Tree P = T;//ÿһ�ֶ�Ҫ��ͷ��ʼ 
		Tree Ip = IT;//��¼ԭ�����ƶ� 
		//�������
		Tree A; Tree pre;
		A = (Tree)malloc(sizeof(TreeNode));
		A->data = infor[i];
		int number = infor[i];
		A->lchild = NULL;
		A->rchild = NULL;
		if (!i)
		{
			//cout<<"YES";
			T = A;//��������
			P = T;
			if (T[0].data != IT[0].data)
				return false;
			continue;
		}
		int way;
		while (P)
		{
			pre = P;
			if (P->data < number)
			{
				P = P->rchild;
				Ip = Ip->rchild;
				way = 0;

			}
			else
			{
				P = P->lchild;
				Ip = Ip->lchild;
				way = 1;
			}
			//ÿ�ּ���Ƿ����
			if(P&&Ip)
			{
				if (P->data != Ip->data)
					return false;
			}
			if ((!Ip) && P)
				return false;
		}
		if (way)//˵�������
		{
			pre->lchild = A;
		}
		else pre->rchild = A;
	}

	return true;
}
int main()
{
	int N, L;//N�����֣�L���Ƚ� 
	cin >> N;
	while (N)
	{
		cin >> L;
		int** ma = NULL;
		ma = new int* [L];
		for (int i = 0; i < L; i++)
		{
			ma[i] = new int[N];
		}
		Tree T = NULL;
		InitialTree(T, N);
		//Print(T);
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < N; j++)
				cin >> ma[i][j];
		}
		Tree cmp = NULL;
		for (int i = 0; i < L; i++)
		{
			if (Compare(ma[i], cmp, N, T))
				cout << "Yes";
			else cout << "No";
			//if (i != L - 1)cout << endl;
			cout << endl;
		}
		cin >> N;
	}
}
