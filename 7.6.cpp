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
	//��ʼ������ 
	int way=0;//���屾��Ӧ�ò�����������Ӧ�ò������� 
	int poptime=0;//���嵯���Ĵ�������ǰ��������У������Ĵ���һ�����ڽڵ������ 
	int N; cin >> N;//���Ľڵ��� 
	getchar();//���ջ��з� 
	Node s[N+10];
	int top=0;
	
     char List[100][10];
     int i=0;
     while(poptime!=N)
     {
     	gets(List[i]);//��ȡ��һ�ε�����
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
     	{//�����push ,����Ҫ���ر�Ĵ��� 
     		
     		A.data=List[i][5];
     		cout<<"���㿴��push����"<<List[i][5]<<endl;
            s[top++]=A;
		 }
		 else 
		 {//˵����pop�����������
		     //���������1.�Ǹ���δ�� 
		     //2.�Ǹ����Ѿ�����
			 //3.���Ǹ���ֱ�ӳ� 
			 A=s[top-1];//��ȡջ��Ԫ�� 
		 	int nextlength=strlen(List[i+1]);
		 	cout<<"��һ������"<<nextlength<<endl;
		 	if(A.root==1)
           {//����Ǹ����Ȱ������������жϺ���� 
           cout<<"�Ǹ�";
        	cout<<s[--top].data<<' ';
			 poptime++;
		   }
			if (nextlength == push)
			{
				cout << "���Ǹ�" << endl;
				s[top - 1].root = 1;
			}
			else if (nextlength == pop)
			{
				cout << "���Ǹ�";
				cout << s[--top].data << ' ';
				poptime++;
			}
			else
				cout << "ɶ������";
		 }
		 i++;
	 }
     
}

