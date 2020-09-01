#include<iostream>
using namespace std;

int answer[10005] = { 0 };
int top = 0;
void connect(int root[])
{
		int n1, n2;
		int current, R;
		cin >> n1 >> n2;  
		int c1 = n1, r1 = root[c1];
		int c2 = n2, r2 = root[c2];
		while(r1 > 0)
		{
			c1 = r1;
			r1 = root[c1];
		}
		while (r2 > 0)
		{
			c2 = r2;
			r2 = root[c2];
		}
		if ((!r1) && (!r2))
		{
			root[n1] = -1;
			root[n2] = n1;
			return;
		}
		if (r1< r2)
		{
			//root[c1] += r2;
			root[c2] = c1;
		}
		
		else if(r1>r2)
		{
			//root[c2] += r1;
			root[c1] = c2;
		}
		else
		{
			root[c1]--;
			root[c2] = c1;
		}
	
}
void check(int root[])
{
	int c1 = 0, c2 = 0;
	cin >> c1 >> c2;
	int r1 = root[c1];
	int r2 = root[c2];
	if (r1 == r2 && r1 == 0)
	{
		answer[top++] = 2;
		return;
	}
	while (r2 > 0)
	{
		c2 = r2;
		r2 = root[c2];
	}
	while (r1 > 0)
	{
		c1 = r1;
		r1 = root[c1];
	}
	if (c1 == c2)
	{
		answer[top++] = 1;
	}
	else
		answer[top++] = 2;
}

int main()
{
	int N = 0;
	cin >> N;
	int* root = new int[N + 1];
	//≥ı ºªØ
	for (int i = 0; i <= N; i++)
	{
		root[i] = 0;
	}
	char judge = 'S';
	
	while (1)
	{
		scanf("%c", &judge);
		if (judge == 'S')
			break;
		switch (judge)
		{
		case 'I':connect(root); break;
		case 'C': check(root); break;
		}
	}
	/*for (int i = 0; i <= N; i++)
	{
		cout << i << ": " << root[i] << endl;
	}*/
	int p = 0;
	while (answer[p])
	{
		switch (answer[p++])
		{
		case 1:cout << "yes"; break;
		case 2:cout << "no"; break;
		}
		
			cout << endl;
	}
	int count = 0;
	
	for (int i = 1; i <= N; i++)
	{
		if (root[i] <=0)
			count++;
	}
	if (count == 1)
		cout << "The network is connected.";
	else
		cout << "There are " << count << " components.";
	
}

