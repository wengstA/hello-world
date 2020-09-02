#include<iostream>
#include<string.h>
#define pop 3
#define push 6
using namespace std;

typedef struct Node{
	char data;
	int root=0;
}Node;
int main()
{
	//初始化变量 
	int way=0;//定义本次应该插入左数还是应该插入右树 
	int poptime=0;//定义弹出的次数（在前序遍历当中，弹出的次数一定等于节点个数） 
	int N; cin >> N;//树的节点数 
	getchar();//吸收换行符 
	Node s[N+10];
	int top=0;
	
     char List[100][10];
     int i=0;
     while(poptime!=N)
     {
     	gets(List[i]);//读取这一次的文字
     	int length=strlen(List[i]);
		if(length==pop)
		 {
		 	poptime++;
		 }
		i++;
	 }
     int ListLength=i;
     i=0;
     poptime=0;
     while(poptime!=N)
     {
	    Node A;
     	int length=strlen(List[i]);
     	if(length==push)
     	{//如果是push ,不需要做特别的处理 
     		
     		A.data=List[i][5];
     		cout<<"给你看看push进了"<<List[i][5]<<endl;
            s[top++]=A;
		 }
		 else 
		 {//说明是pop，有两种情况
		     //三种情况：1.是根，未出 
		     //2.是跟，已经出了
			 //3.不是根，直接出 
			 A=s[top-1];//读取栈顶元素 
		 	int nextlength=strlen(List[i+1]);
		 	cout<<"下一长度是"<<nextlength<<endl;
		 	if(A.root==1)
           {//如果是根就先把这个输出了再判断后面的 
           cout<<"是根";
        	cout<<s[--top].data<<' ';
			 poptime++;
		   }
			if (nextlength == push)
			{
				cout << "这是根" << endl;
				s[top - 1].root = 1;
			}
			else if (nextlength == pop)
			{
				cout << "不是根";
				cout << s[--top].data << ' ';
				poptime++;
			}
			else
				cout << "啥都不是";
		 }
		 i++;
	 }
     
}

