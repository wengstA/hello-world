#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
typedef int Position;
#define NotFound -1

void Builtmatch(char* pattern, int* match)
{
	Position i=0, j=0;
	int m = strlen(pattern);
	match[0] = -1;
	for (j =1; j < m; j++)
	{
		i = match[j - 1];
		while ((i >= 0) && (pattern[i + 1] != pattern[j]))
		i = match[i];//��ĩβ�Ľ�㲻��ͬ���������һֱ����ͬ��>����match�ģ���ݹ�
		if (pattern[i + 1] == pattern[j])//ĩβ�ڵ���ͬ�����
			match[j] = i + 1;
		else match[j] = -1;
	}
}
Position KMP(char* string, char* pattern)
{
	int n = strlen(string);
	int m = strlen(pattern);
	Position s, p, * match;
	if (n < m)return NotFound;
	match = new Position [m];
	Builtmatch(pattern, match);
	s = p = 0;
	while (s < n && p < m) {    //��֤��ѭ���ڣ����ᳬ������Ҳ���ᳬ���̵�
		if (string[s] == pattern[p]) {
			s++; p++;
		}  //ƥ������ѭ������
		else if (p > 0)p = match[p - 1] + 1;  //��ƥ���������̵�ָ��ص���Ӧmatch
		else s++;//p����ͷ��λ�ã������ڻ��ݵ����
	}
	return(p == m) ? (s - m) : NotFound;
}
int main()
{
	char string[] = "This is a simple example";
	char pattern[] = "simple";
	Position p = KMP(string, pattern);
	if (p == NotFound)printf("Not Found.\n");
	else printf("%s\n", string + p);
	return 0;
}