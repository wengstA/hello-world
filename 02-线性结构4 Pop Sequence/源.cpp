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
	//��Line��ջ��Ԫ��push��stack��
	if (top_stack < m)
	{
		stack[top_stack++] = line[--top_line];
		return OK;
	}
	else return ERROR;
}
Status pop()
{
	//��stackջ��Ԫ�ص�����
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
	read();//�������˳����д洢
	i = 0; int result = 1;
	while (i != n)
	{
		//�ȼ��stack��ջ���ǲ��ǣ��ټ��line
		if (top_stack > 0 && stack[top_stack - 1] == se[i])
		{
			i++;
			pop();
		}
		else if (se[i] == line[top_line - 1]) //ֱ�Ӵ�line�е���
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
				//��stack�Ѿ����˵��ǻ�û���ҵ�
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
	//��˳�������������
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

