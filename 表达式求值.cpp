#include<iostream>
#include<stdio.h>
using namespace std;

int isdigit(char number)
{
	if(number>='0'&&number<='9')
	return 1;
	else return 0;
}
//���׺���ʽ
void Push(char c,char s[],int &top)
{
	s[++top]=c;
}
void Pop(char &c,char s[],int &top)
{
	 c=s[top--];
}
void GetTop(char &c,char s[],int &top)
{
	c=s[top];
}
void nPush(int number,int s[],int &nTop)
{
	s[++nTop]=number;
}
void nPop(int &number,int s[],int &top)
{
	number=s[top--];
}
int main()
{
	char afexpression[105];
    char opstack[105];
    int aTop=-1;
    int opTop=-1;
    char out;
	char expression[105];
	scanf("%s",expression);
	int i=0;
	for(i=0;expression[i]!='=';i++)
	{
		if(isdigit(expression[i]))
		{//��������ֵĻ�ֱ��ѹ��ȥ�Ϳ����� 
			 Push(expression[i],afexpression,aTop);
			 continue;
		}
		else if(opTop==-1)Push(expression[i],opstack,opTop); //ûʲô�Ƚϵģ�ֱ��ѹ������ջ���� 
		else {//�������֣����ҷ���ջ������ֵ 
			GetTop(out,opstack,opTop);
			//cout<<"out��"<<out<<endl;
			switch(expression[i])
			{
			 case '+':
			 case '-':
			 if(out=='*'||out=='/'||out=='+'||out=='-')
			 {
			 	while((out=='*'||out=='/'||out=='+'||out=='-')) 
			   {
			   Pop(out,opstack,opTop);
			   Push(out,afexpression,aTop);
			   	GetTop(out,opstack,opTop);
			   }
			   Push(expression[i],opstack,opTop);
			     break; 
			 }
			 else
			 {
			 	Push(expression[i],opstack,opTop);break;
			 }
			 case '(':
			 case '/':
			 case '*':Push(expression[i],opstack,opTop);break;
			 case ')':
			    while(out!='('){
	    	     Pop(out,opstack,opTop);
	    	     //cout<<"���������out"<<out<<endl;
			 	if(out!='(')Push(out,afexpression,aTop);
			 	
			 }break;
			  cout<<opstack<<endl;
			}
		}
	}
	while(opTop!=-1)
	{
		
		Pop(out,opstack,opTop);
		//cout<<"���׶ε�out��"<<out<<endl;
		Push(out,afexpression,aTop);
	}
	afexpression[aTop+1]='\0';
	//printf("%s",afexpression);
	//cout<<endl;
	//�����������˺�׺���ʽ
	//���濪ʼ���ݺ�׺���ʽ��ֵ 
	int  number[105];int numTop=-1;
	for(int i=0;afexpression[i]!='\0';i++)
	{
		int n1=0,n2=1;
		if(isdigit(afexpression[i]))
		 {
		 	n1=(int)(afexpression[i]-'0');
		 	//cout<<n1+1<<' ';
		 	nPush(n1,number,numTop);
		  } 
	
		  else{
		  	int t1,t2;
		  	//cout<<"here"<<endl; 
		  	nPop(t1,number,numTop);
			nPop(t2,number,numTop);
			//cout<<t1<<' '<<t2<<endl;
		  	switch(afexpression[i])
		{
			
			case '+':nPush((t1+t2),number,numTop);break;
			case '-':nPush((t2-t1),number,numTop);break;
			case '*':nPush((t1*t2),number,numTop);break;
			case '/':nPush((t2/t1),number,numTop);break;
		}
		  }
		
        
	 } 
	 cout<<number[numTop];
 } 
