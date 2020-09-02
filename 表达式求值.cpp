#include<iostream>
#include<stdio.h>
using namespace std;

int isdigit(char number)
{
	if(number>='0'&&number<='9')
	return 1;
	else return 0;
}
//求后缀表达式
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
		{//如果是数字的话直接压进去就可以了 
			 Push(expression[i],afexpression,aTop);
			 continue;
		}
		else if(opTop==-1)Push(expression[i],opstack,opTop); //没什么比较的，直接压到符号栈里面 
		else {//不是数字，而且符号栈里面有值 
			GetTop(out,opstack,opTop);
			//cout<<"out是"<<out<<endl;
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
	    	     //cout<<"在括号里的out"<<out<<endl;
			 	if(out!='(')Push(out,afexpression,aTop);
			 	
			 }break;
			  cout<<opstack<<endl;
			}
		}
	}
	while(opTop!=-1)
	{
		
		Pop(out,opstack,opTop);
		//cout<<"最后阶段的out是"<<out<<endl;
		Push(out,afexpression,aTop);
	}
	afexpression[aTop+1]='\0';
	//printf("%s",afexpression);
	//cout<<endl;
	//上述步骤获得了后缀表达式
	//下面开始根据后缀表达式求值 
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
