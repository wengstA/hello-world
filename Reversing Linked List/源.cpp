#include <stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Node {
	int path[6];
	int data;
	int next[6];
}Node;
int main()
{
	Node* p=NULL;
	scanf("%p", p);
	//p = (Node*)malloc(sizeof(Node));
	scanf("%d", &p->data);
	scanf("%p", &p->next);
	printf("%p");
}