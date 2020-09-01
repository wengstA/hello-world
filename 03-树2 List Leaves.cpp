#include<iostream>
using namespace std;

typedef struct TreeNode{
    int data;
    int lchild;
    int rchild;
}TreeNode,*Tree;

void CreateTree(int N, Tree &T)
{
    char lchild, rchild;
    for (int i = 0; i < N; i++)
    {
        T[i].data = i;
        cin >> lchild >> rchild;
        if (isdigit(lchild))
            T[i].lchild = lchild - '0';
        else T[i].lchild = -1;
        if (isdigit(rchild))
            T[i].rchild = rchild - '0';
        else T[i].rchild = -1;
    }
}
int FindRoot(Tree& T, int N)
{
    int i = 0, j = 0;
    int root = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (T[j].lchild ==i|| T[j].rchild ==i)
                break;
        }
        if (j == N)
            root = i;
    }
    return root;
}
void Print(int N, Tree T)
{
    for (int i = 0; i < N; i++)
    {
        cout << T[i].data << " " << T[i].lchild << ' ' << T[i].rchild << endl;
    }
}

void LevelCheck(Tree T,int N,int root)
{//��һ����α���
    int* level = new int[N];//��������Ͷ��������
    int f = 0, r = 0;
    level[r++] = root;//�Ѹ�������
    int blank = 0;
    while (f != r)
    {
        int top = level[f++];//ȡ��ͷԪ��
        if (T[top].lchild == -1 && T[top].rchild == -1)
        {
            if (!blank)
            {
                cout << T[top].data;//���������
                blank = 1;
            }
            else cout << ' ' << T[top].data;
        }
        if(T[top].lchild!=-1)
         level[r++] = T[top].lchild;//�������Чֵ�����
        if(T[top].rchild!=-1)
         level[r++] = T[top].rchild;
    }

}
int main()
{
    int N; cin >> N;
    Tree T = new TreeNode[N];
    CreateTree(N, T);
    //Print(N, T);
   int root= FindRoot(T, N);
   LevelCheck(T, N, root);
}
