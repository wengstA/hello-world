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
		i = match[i];//最末尾的结点不相同的情况，当一直不相同—>当下match的（类递归
		if (pattern[i + 1] == pattern[j])//末尾节点相同的情况
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
	while (s < n && p < m) {    //保证在循环内，不会超过长的也不会超过短的
		if (string[s] == pattern[p]) {
			s++; p++;
		}  //匹配的情况循环继续
		else if (p > 0)p = match[p - 1] + 1;  //不匹配的情况，短的指针回到对应match
		else s++;//p还在头的位置，不存在回溯的情况
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