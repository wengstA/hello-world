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
{  // �㷨2.3
  // ����һ���յ����Ա�L��
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) return ERROR;        // �洢����ʧ��
    L.length = 0;                  // �ձ���Ϊ0
    L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
    return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList& L, int i, ElemType e)
{  // �㷨2.4
  // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
    ElemType* p;
    if (i < 1 || i > L.length + 1) return ERROR;  // iֵ���Ϸ�
    if (L.length >= L.listsize) {   // ��ǰ�洢�ռ���������������
        ElemType* newbase = (ElemType*)realloc(L.elem,
            (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) return ERROR;   // �洢����ʧ��
        L.elem = newbase;             // �»�ַ
        L.listsize += LISTINCREMENT;  // ���Ӵ洢����
    }
    ElemType* q = &(L.elem[i - 1]);   // qΪ����λ��
    for (p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p;
    // ����λ�ü�֮���Ԫ������
    *q = e;       // ����e
    ++L.length;   // ����1
    return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList& L, int i, ElemType& e)
{  // �㷨2.5
  // ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
    ElemType* p, * q;
    if (i<1 || i>L.length) return ERROR;  // iֵ���Ϸ�
    p = &(L.elem[i - 1]);                   // pΪ��ɾ��Ԫ�ص�λ��
    e = *p;                               // ��ɾ��Ԫ�ص�ֵ����e
    q = L.elem + L.length - 1;                // ��βԪ�ص�λ��
    for (++p; p <= q; ++p) *(p - 1) = *p;     // ��ɾ��Ԫ��֮���Ԫ������
    --L.length;                           // ����1
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
    while (current <= L2.length)  //��L1�������ֵ
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
