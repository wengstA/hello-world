#include<iostream>
#define Status int
#define OK 1
#define ERROR 0
using namespace std;
int m, n, k;
int i = 0;
int* stack, * line, * se;
int top_line=0, top_se=0;
int top_stack = 0;
void read()
{
	for (i = 0; i < n; i++)
	{
		cin >> se[i];
	}
}
Status push()
{
	//把Line的栈顶元素push到stack中
	if (top_stack < m)
	{
		stack[top_stack++] = line[--top_line];
		return OK;
	}
	else return ERROR;
}
Status pop()
{
	//把stack栈顶元素弹出来
	if (top_stack)
	{
		top_stack--;
		//cout << stack[top_stack] << ' ';
		return OK;
	}
	else return ERROR;
}
Status check()
{
	top_line = n; top_stack = 0;
	read();//对数入的顺序进行存储
	i = 0; int result = 1;
	while (i != n)
	{
		//先检查stack的栈顶是不是，再检查line
		if (top_stack > 0 && stack[top_stack - 1] == se[i])
		{
			i++;
			pop();
		}
		else if (se[i] == line[top_line - 1]) //直接从line中弹出
		{
			result = push();
			if (!result)break;
			else pop();
			i++;
			//cout << line[top_line] << ' ';
		}
		else if (line[top_line - 1] != se[i])
		{
			while (se[i] != line[top_line - 1])
			{

				result = push();
				//若stack已经满了但是还没有找到
				if (!result && se[i] != line[top_line - 1])
					break;
			}
			if (!result)
				break;
		}
	}
	return result;
}
int main()
{
	cin >> m >> n >> k;
	stack = new int[m];
	line = new int[n];
	se = new int[n];
	//对顺序数组进行输入
	for (i = 0; i < n; i++)
	{
		line[i] = n-i;
	}
	int a = 0;
	int* answer = new int[k];
	for (a = 0; a < k; a++)
	{
		int result=check();
		answer[a] = result;
	}
	for (i = 0; i < k; i++)
	{
		switch (answer[i])
		{ 
		case 0:cout << "NO"; break;
		case 1:cout << "YES"; break;
		}
		if (i != k - 1)cout << endl;
	}
	return OK;
}

