typedef char SElemType;
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
#define STACKINCREMENT 2 // �洢�ռ��������
struct SqStack
{
 SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
 SElemType *top; // ջ��ָ��
 int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
 }; // ˳��ջ
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
 { // �������������һ���ַ��������������Ƿ����
   SqStack s;
   SElemType ch[80],*p,e;
   if(InitStack(s)) // ��ʼ��ջ�ɹ�
   {
    //printf("��������ʽ\n");
     __________________________________;
     p=ch;
     while(*p) // û����β
       switch(*p)
       {
         case '(':
         case '[':_______________________;
                  break; // ��������ջ����p++
         case ')':
         case ']':if(!StackEmpty(s)) // ջ����
                  {
                   _________________________; // ����ջ��Ԫ��
                    if(*p==')'&&e!='('||___________________&&___________________)
                                                // ������ջ��Ԫ����*p�����
{
                      printf("isn't matched pairs\n");
                      exit(ERROR);
                    }
                    else
                    {
                     __________________________;
                      break; // ����switch���
                    }
                  }
                  else // ջ��
                  {
                    printf("lack of left parenthesis\n");
                    exit(ERROR);
                  }
         default: ______________________; // �����ַ�������ָ�������
       }
     if(StackEmpty(s)) // �ַ�������ʱջ��
       printf("matching\n");
     else
       printf("lack of right parenthesis\n");
   }
 }
int main()
 {
   check();
 }
