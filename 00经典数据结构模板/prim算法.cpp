#include<iostream>
#include<queue>
using namespace std;
int G[105][105];
int V = 0, E = 0;
int Lowcost[1005] = { 99999 };
int Parent[1005] = { 0 };

int Find()
{
    int minpo = 0;
    int mindis = 9999;
    for (int i = 0; i < V; i++)
    {
        if (Lowcost[i]&&Lowcost[i]< mindis)
        {
            minpo = i;
            mindis = Lowcost[i];
        }
    }
    return minpo;
}


void Prim()
{
    for (int i = 0; i < V; i++)
    {
        Parent[i] = 0;
        Lowcost[i] = G[0][i];
    }
    Parent[0] = -1;
    Lowcost[0] =0;
  
    int parent = 0;
    for (int i = 1; i < V; i++)
    {//从1开始寻找非常重要，因为第一个点已经进去了 
        int k = Find();//找到下一个点
        if (k)
        {
            Lowcost[k] = 0;//生长到K点

            for (int i = 1; i < V; i++)//0已经在第一步遍历过了，从1开始
            {
                if (G[k][i]&&(Lowcost[i] >G[k][i]))
                {
                    Lowcost[i] = G[k][i];
                    Parent[i] = k;
                }
            }
        }
        else
        {
            cout << i<<" 图不连通";
            break;
        }
           

    }
    for (int i = 0; i < V; i++)
    {
        cout << Parent[i]<<' ';
    }
}
int main()
{
    cin >> V >> E;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            G[i][j] = 99999;//初始化图结构
        }
    }
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        int weight = 0;
        cin >> weight;
        G[x][y] = weight;
        G[y][x] = weight;
    }
    //for (int i = 0; i < V; i++)
    //{
    //    for (int j = 0; j < V; j++)
    //    {
    //        cout<<G[i][j]<<' ';//初始化图结构
    //    }
    //    cout << endl;
    //}
    //尝试prim算法
    Prim();
}
