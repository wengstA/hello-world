#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int
using namespace std;

typedef int Status;
typedef struct
{
    int* elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList& L)
{  // 算法2.3
  // 构造一个空的线性表L。
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) return ERROR;        // 存储分配失败
    L.length = 0;                  // 空表长度为0
    L.listsize = LIST_INIT_SIZE;   // 初始存储容量
    return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList& L, int i, ElemType e)
{  // 算法2.4
  // 在顺序线性表L的第i个元素之前插入新的元素e，
  // i的合法值为1≤i≤ListLength_Sq(L)+1
    ElemType* p;
    if (i < 1 || i > L.length + 1) return ERROR;  // i值不合法
    if (L.length >= L.listsize) {   // 当前存储空间已满，增加容量
        ElemType* newbase = (ElemType*)realloc(L.elem,
            (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) return ERROR;   // 存储分配失败
        L.elem = newbase;             // 新基址
        L.listsize += LISTINCREMENT;  // 增加存储容量
    }
    ElemType* q = &(L.elem[i - 1]);   // q为插入位置
    for (p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p;
    // 插入位置及之后的元素右移
    *q = e;       // 插入e
    ++L.length;   // 表长增1
    return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList& L, int i, ElemType& e)
{  // 算法2.5
  // 在顺序线性表L中删除第i个元素，并用e返回其值。
  // i的合法值为1≤i≤ListLength_Sq(L)。
    ElemType* p, * q;
    if (i<1 || i>L.length) return ERROR;  // i值不合法
    p = &(L.elem[i - 1]);                   // p为被删除元素的位置
    e = *p;                               // 被删除元素的值赋给e
    q = L.elem + L.length - 1;                // 表尾元素的位置
    for (++p; p <= q; ++p) *(p - 1) = *p;     // 被删除元素之后的元素左移
    --L.length;                           // 表长减1
    return OK;
} // ListDelete_Sq
Status CreateList(SqList& L)
{
    InitList_Sq(L);
    cin >> L.length;
    int data;
    for (int i = 0; i < L.length; i++)
    {
        cin >> data;
        L.elem[i] = data;
    }
    return OK;
}
Status LoadList(SqList& L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << ' ';
    }
    cout << "\n";
    return OK;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n1;
    int i=1, j;
    int current = 0;
    SqList L1,L2,L3;
    CreateList(L1);
    CreateList(L2);
    InitList_Sq(L3);
    L3.length = L1.length;
    for (int j = 0; j < L1.length; j++)
    {
        L3.elem[j] = L1.elem[j];
    }
    while (current <= L2.length)  //往L1里面插入值
    {
        if (L2.elem[current] <=L1.elem[i-1])ListInsert_Sq(L1, i, L2.elem[current++]);
        if (current >= L2.length)break;
        else if (i == L1.length && L1.elem[i-1] < L2.elem[current])ListInsert_Sq(L1, i + 1, L2.elem[current++]);
        if (current >= L2.length)break;
        else  i++;
    }
    cout << "List A:";
    LoadList(L3);
    cout << "List B:";
    LoadList(L2);
    cout << "List C:";
    LoadList(L1);
}
