typedef char SElemType;
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量
struct SqStack
{
 SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
 SElemType *top; // 栈顶指针
 int stacksize; // 当前已分配的存储空间，以元素为单位
 }; // 顺序栈
Status InitStack(SqStack &S)
{
    S=new SElemType;

 }

Status StackEmpty(SqStack S)
{

 }
Status Push(SqStack &S,SElemType e)
{
 }
 Status Pop(SqStack &S,SElemType &e)
{
 }
void check()
 { // 对于输入的任意一个字符串，检验括号是否配对
   SqStack s;
   SElemType ch[80],*p,e;
   if(InitStack(s)) // 初始化栈成功
   {
    //printf("请输入表达式\n");
     __________________________________;
     p=ch;
     while(*p) // 没到串尾
       switch(*p)
       {
         case '(':
         case '[':_______________________;
                  break; // 左括号入栈，且p++
         case ')':
         case ']':if(!StackEmpty(s)) // 栈不空
                  {
                   _________________________; // 弹出栈顶元素
                    if(*p==')'&&e!='('||___________________&&___________________)
                                                // 弹出的栈顶元素与*p不配对
{
                      printf("isn't matched pairs\n");
                      exit(ERROR);
                    }
                    else
                    {
                     __________________________;
                      break; // 跳出switch语句
                    }
                  }
                  else // 栈空
                  {
                    printf("lack of left parenthesis\n");
                    exit(ERROR);
                  }
         default: ______________________; // 其它字符不处理，指针向后移
       }
     if(StackEmpty(s)) // 字符串结束时栈空
       printf("matching\n");
     else
       printf("lack of right parenthesis\n");
   }
 }
int main()
 {
   check();
 }
