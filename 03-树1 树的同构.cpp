#include<iostream>
using namespace std;
//判断树的同构：想法递归来做每个结点都判断子节点是不是为同构 
typedef struct TreeNode {
	char data;
	int lchild, rchild;
}TreeNode, * Tree;
bool CreateTree(Tree T, int N);


bool CreateTree(Tree T, int N)
{
	if (!N)return false;
	for (int i = 0; i < N; i++)
	{
		cin >> T[i].data;
		char lchild, rchild;
		cin >> lchild >> rchild;
		if (isdigit(lchild))
			T[i].lchild = lchild - '0';
		else T[i].lchild = -1;
		if (isdigit(rchild))
			T[i].rchild = rchild - '0';
		else T[i].rchild = -1;
	}
	return true;
}

int FindRoot(Tree T,int N)
{
	int root = 0;
	int i = 0, j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (T[j].lchild == i || T[j].rchild == i)
			{
				break;
			}
		}
		if (j == N)
		{
			root = i;
			return root;
		}
	}
	return root;
}

int Judge(TreeNode p1, TreeNode p2, Tree& T1, Tree& T2, int& result)
{
	//检测是否相等
	if (p1.data != p2.data)
	{
		result = 0;
		return 0;
	}
	if (!result) return 0;
	//if (p1.data) return 0;
	//1.绝对相等 
	if (T1[p1.lchild].data == T2[p2.lchild].data && T1[p1.rchild].data == T2[p2.rchild].data)
	{//分别往左右延申 
		if (p1.lchild!=-1)
			Judge(T1[p1.lchild], T2[p2.lchild], T1, T2, result);
		if (p1.rchild!=-1)
			Judge(T1[p1.rchild], T2[p2.rchild], T1, T2, result);
	}
	//2.相对相等 
	else if (T1[p1.lchild].data == T2[p2.rchild].data && T1[p1.rchild].data == T2[p2.lchild].data)
	{
		if (p1.lchild!=-1)
			Judge(T1[p1.lchild], T2[p2.rchild], T1, T2, result);
		if (p1.rchild!=-1)
			Judge(T1[p1.rchild], T2[p2.lchild], T1, T2, result);
	}
	else result = 0;
	return result;
}
void Print(int N, Tree T1)
{
	for (int i = 0; i < N; i++)
	{
		printf("%c %d %d \n", T1[i].data, T1[i].lchild, T1[i].rchild);
	}
}
int main()
{
	int N; cin >> N;
	Tree T1 = new TreeNode[N];
	CreateTree(T1, N);
	//   Print(N,T1);
	int root1 = FindRoot(T1, N);
	//cout << root1 << endl;
	int N2; cin >> N2;
	Tree T2 = new TreeNode[N2];
	CreateTree(T2, N2);
	int root2 = FindRoot(T2, N2);
	//Print(N2, T2);
	//cout << root2 << endl;

	if (N == N2 && N)
	{
		int result = 1;
		result = Judge(T1[root1], T2[root2], T1, T2, result);
		if (result)
			cout << "Yes";
		else cout << "No";
	}
	else if (N == N2 &&N==0)
		cout << "Yes";
	else cout << "No";

}
