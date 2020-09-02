#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)
typedef long long ll;
using namespace std;

int main()
{
	int a;
  SqQueue S;
	QElemType x, e;
  if(______________________)    // 判断顺序表是否创建成功，请填空
	{
		printf("A Queue Has Created.\n");
	}
	while(1)
	{
	printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d", &x);
				  if(______________________) printf("Enter Error!\n"); // 判断入队是否合法，请填空
				  else printf("The Element %d is Successfully Entered!\n", x);
				  break;
			case 2: if(______________________) printf("Delete Error!\n"); // 判断出队是否合法，请填空
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: if(______________________)printf("Get Head Error!\n"); // 判断Get Head是否合法，请填空
				  else printf("The Head of the Queue is %d!\n", e);
				  break;
			case 4: printf("The Length of the Queue is %d!\n",______________________);  //请填空
				  break;
			case 5: ______________________ //请填空
				  break;
			case 0: return 1;
		}
	}
}
