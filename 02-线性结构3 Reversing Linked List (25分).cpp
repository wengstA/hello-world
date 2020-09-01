#include<iostream>
using namespace std;

typedef struct Node {
	int pre=0; 
	int data=0;
	int next=0;
}Node;

void Print(Node list[], int length,int head)
{
	int position = head;
	while(position!=-1)
	{
		printf("%05d ", position);
		cout << list[position].data<<' ';
		position = list[position].next;
		if (position != -1)
			printf("%05d\n", position);
		else cout << -1;
	
	}
}
void Reverse(Node* List, int length, int head,int R)
{
	if(R==1)
	{
	  Print(List,length,head);
	  return ;
	 } 
	int rest = length;
	int h=head;//ͷָ��ָ�� 
	int rr=0,rp=0;//βָ��ָ�� 
	int position=head;//��¼���ڵ�λ�� 
	while (rest >= R)
	{
		for(int i=0;i<R;i++)
	    {
	    	if(i==0)
   	       {
			   h=position;//��һ��Ԫ�ز������� 
			   position=List[position].next;
		   } 
  	        else//�����Ԫ�ط�תָ�� 
  	        {
  	        	if(i==R-1)
  	        	  {
  	        	  	rr=List[position].next;//��һ���ڵ�������¼ 
  	        	  	rp=position;//���һ��Ԫ�ؼ�¼λ�á�����һ��Ԫ�� 
					}
  	        	int temp=List[position].next;
  	        	List[position].next=List[position].pre;
  	        	List[position].pre=temp;
  	        	position=List[position].pre;
  			 }
  			 
		}
		//��ת����������ͷβ 
		int prepre=List[h].pre;
	
		if(rest==length)
		  head=rp;
        else
       	List[prepre].next=rp;
		  List[h].next=rr;//��һ��Ԫ��ָ����һ����Ԫ��Ԫ��
		  if(rr!=-1)
		  {
		  	List[rr].pre=h;
		  }
		rest=rest-R; 
    }
    //cout<<endl;
	Print(List, length, head);
	}

int Pre(Node* &list,int length,int head)
{
	int pre=-2;int position=head;
	int LL=0;
	while(position!=-1)
	{
		list[position].pre=pre;
		pre=position;
		position=list[position].next;   
		LL++; 
	}
	return LL;
}
int main()
{
	int head = 0, N = 0, R = 0;
	cin >> head >> N >> R;
	Node* List = new Node[100000];
	int add;
	for (int i = 0; i < N; i++)
	{
		cin >> add;
		cin>> List[add].data >> List[add].next;
    } 
    int length=Pre(List,N,head);
	Reverse(List,length, head,R);

}
