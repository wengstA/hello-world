#include<iostream>
using namespace std;

typedef struct TreeNode {
	int data = 0;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
	int Height = 0;
}*Tree,TreeNode;


int max(int a, int b)
{
	return (a > b ? a : b);

}

int Height(Tree A)
{
	if (!A)
		return 0;
	int LH = 0, RH = 0;
	int MaxH = 0;
	LH = Height(A->lchild);
	RH = Height(A->rchild);
	MaxH = max(LH, RH)+1;
	return MaxH;
}

Tree SingleLeftRotation(Tree A)
{
	Tree B = A->lchild;
	A->lchild = B->rchild;
	B->rchild = A;
	A->Height = Height(A);
	B->Height = Height(B);
	return B;
}
Tree SingleRightRotation(Tree A)
{
	Tree B = A->rchild;
	A->rchild = B->lchild;
	B->lchild = A;
	A->Height = max(Height(A->lchild), Height(A->rchild)) + 1;
	B->Height = max(Height(B->lchild), Height(B->rchild)) + 1;
	return B;
}
Tree DoubleLeftRightRotaion(Tree A)
{
	A->lchild = SingleRightRotation(A->lchild);
	return  SingleLeftRotation(A);
}
Tree DoubleRightLeftRotation(Tree A)
{
	A->rchild = SingleLeftRotation(A->rchild);
	return SingleRightRotation(A);
}
 

Tree InsertTree(int data,Tree &T)
{//记得更新树的高度 
	//用递归的方法来做
	
	if (!T)
	{
	Tree newNode = (Tree)malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->Height = 0;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
		T = newNode;
	}
	else if (data < T->data)
	{
		T->lchild = InsertTree(data, T->lchild);
		if (Height(T->lchild) - Height(T->rchild) == 2)
		{
			if (T->lchild && data < T->lchild->data)//说明是左左旋转
				T = SingleLeftRotation(T);
			else if(T->lchild->rchild)//说明左右旋转
				T = DoubleLeftRightRotaion(T);

		}
	}
	else if (data > T->data)
	{
		T->rchild = InsertTree(data, T->rchild);
		if (Height(T->rchild) - Height(T->lchild) == 2)
			if (T->rchild && data > T->rchild->data)//说明是右右旋转
				T = SingleRightRotation(T);
			else if(T->rchild&&T->rchild->lchild)//说明是右左旋转
				T = DoubleRightLeftRotation(T);
	}
		T->Height = max(Height(T->lchild), Height(T->rchild)) + 1;
	return T;
}
int main()
{
	int N; cin >> N;
	Tree AVL = NULL;
	int number = 0;
	for (int i =0 ; i < N; i++)
	{
		cin >> number;
		InsertTree(number,AVL);
	}
	if(AVL)
	 cout << AVL->data;
}
