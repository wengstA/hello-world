#include<iostream>
using namespace std;

int main()
{
	int xishu[1000] = {0};
	int zhishu[1000] = {0};
	int i = 0;
	cin >> xishu[i] >> zhishu[i];
	xishu[i] = xishu[i] * zhishu[i];
	if(zhishu[i]!=0)zhishu[i] -= 1;
	while (getchar() != '\n')   //做数据录入
	{
		cin >> xishu[++i] >> zhishu[i];
		xishu[i] = xishu[i] * zhishu[i];
		if(zhishu[i]!=0)
		zhishu[i] -= 1;
	}
	xishu[++i] = 2222;
	i = 0;
	while (xishu[i+1] !=2222)
	{
		if(!(xishu[i]==0&&zhishu[i]==0))
		cout << xishu[i]<<' ' << zhishu[i]<<' ';
		i++;
	}
	if((!(xishu[i] == 0 && zhishu[i] == 0))||i==0)
	cout<< xishu[i]  <<' '<<zhishu[i];
	return 0;
	
}