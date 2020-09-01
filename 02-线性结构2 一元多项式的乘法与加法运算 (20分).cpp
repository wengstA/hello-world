#include<iostream>
#include<malloc.h>
using namespace std;
int i, j, n;
//coef 是系数 expon 是指数
typedef struct Node {
	int coef;
	int expon;
	struct Node* next;
}LNode, * PNode;
void ReadLink(PNode& L)
{

	PNode tail = NULL;
	cin >> n;              //记录几个 
	PNode p;
	for (i = 0; i < n; i++)
	{
		p = (PNode)malloc(sizeof(LNode));
		cin >> p->coef >> p->expon;
		if (!L)L = p;
		if (tail)tail->next = p;
		tail = p;
		p->next = NULL;
	}
}
PNode DeleteZero(PNode L)
{
	if (L == NULL)
		return NULL;
	PNode pre= NULL;
	for (PNode P = L; P; P = P->next)
	{
		if (P->coef == 0)
		{
			if (P == L)
			{
				L = P->next;
			}
			else pre->next = P->next;
		}
		pre = P;
	}
	return L;
}
void Load(PNode& L)
{
	PNode p = L;
	int tag = 0;
	L=DeleteZero(L);
	while (p)
	{
		if (p->next)
		{
			if (p->coef != 0)
			{
				cout << p->coef << ' ' << p->expon << ' ';
				tag = 1;
			}

		}

		else if (p->coef != 0)
		{
			cout << p->coef << ' ' << p->expon;
			tag = 1;
		}
		p = p->next;
	}
	if (!tag)cout << '0' << ' ' << '0';
}
int compare(PNode& p1, PNode& p2)
{
	if (p1->expon > p2->expon) return 1;
	if (p1->expon < p2->expon) return -1;
	else return 0;
}
void attach(PNode& rear, int e, int c)
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	p->coef = c;
	p->expon = e;
	p->next = NULL;
	if (rear)
		rear->next = p;
	rear = p;
}
void attachtail(PNode& rear, PNode p)
{
	rear->next = p;
}
PNode Add(PNode& L1, PNode& L2, PNode& L3)
{
	PNode p1 = L1, p2 = L2;
	L3 = (PNode)malloc(sizeof(LNode));
	PNode rear = L3;
	while (p1 && p2)
	{
		switch (compare(p1, p2))
		{
		case 1: attach(rear, p1->expon, p1->coef);
			p1 = p1->next; break;
		case -1:attach(rear, p2->expon, p2->coef);
			p2 = p2->next; break;
		case 0:int sum = p2->coef + p1->coef;
			attach(rear, p1->expon, sum);
			p1 = p1->next;
			p2 = p2->next;
			break;
		}
	}
	if (p1 || p2)
	{
		if (p1) attachtail(rear, p1);
		if (p2) attachtail(rear, p2);
	}
	L3 = L3->next;
	return L3;
}
PNode Mult(PNode& L1, PNode& L2, PNode& L4)
{
	PNode p1 = L1, p2 = L2;
	L4 = (PNode)malloc(sizeof(LNode));
	PNode L5 = NULL;
	while (p1)
	{

		L4 = NULL; PNode tail = NULL;
		p2 = L2;
		while (p2)
		{
			PNode p4 = (PNode)malloc(sizeof(Node));
			p4->coef = p1->coef * p2->coef;    //系数相乘
			p4->expon = p1->expon + p2->expon;  //指数相加
			p4->next = NULL;
			if (!L4)L4 = p4;
			if (tail)tail->next = p4;
			tail = p4;
			p2 = p2->next;
		}
		PNode L6;
		L5 = Add(L5, L4, L6);
		p1 = p1->next;
	}
	return L5;
}
int main()
{
	PNode L1 = NULL, L2 = NULL;
	PNode L3 = NULL; PNode L4 = NULL;
	ReadLink(L1);
	ReadLink(L2);
	Add(L1, L2, L3);
	L4 = Mult(L1, L2, L4);
	Load(L4);
	cout << endl;
	Load(L3);
	return 0;
}