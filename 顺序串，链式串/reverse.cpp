#include"stdio.h"
#include"stdlib.h"
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
}node;
//���������� 
node *init()
{
	return NULL;
}
//��������и�����ֵ
void display(node *head)
{
	node *p=head;
		printf("\n���������ֵΪ��\n");
		while(p)
		{
		
			printf("%5d",p->info);
			p=p->next;
		}
 } 
 //ǰ�崴������ 
 node *create()
{
	node *p=NULL,*head=NULL;
	int x;
	scanf("%d",&x);
    while(x!=0)
	{
		p=(node*)malloc(sizeof(node));
		p->info=x;
		p->next=head;
		head=p;
		scanf("%d",&x);
    }
	 return head;
}
//��崴�� 
node *creat()
{
	node *head=NULL,*p,*r=NULL;
	int x;
	scanf("%d",&x);
	while(x!=0)
	{
		p=(node*)malloc(sizeof(node));
		p->info=x;
		if(head==NULL)
		head=p;
		else
	    r->next=p;
	    r=p;
		scanf("%d",&x);
		  if(r!=NULL)
	     r->next=NULL;
	 } 
	 return head;
}
//����������� 
void count(node *head)
{
	node *p=head;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	printf("\n������Ϊ:");
	printf("%d\n",i);
}
//�� ֵΪy�Ľ��ǰ����x 
void insert(node *head,datatype y,datatype x)
{
	node *p=head,*q;
	if(!p)
	{
		printf("\n���ݱ�Ϊ��");
	}
	while(p&&p->info!=y)
	{
         p=p->next;
	}
	if(p)
	{
		q=(node*)malloc(sizeof(node));
		q->info=x;
		q->next=p;
	}
}
//��ת������
node *reverse(node *head)
{
	node *p=head,*q;
	head=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q->next=head;
		head=q;
	}
	return head;
 } 
int main()
{
	node *head;
	init();
	head=creat();
	display(head);
	head=reverse(head);
	display(head);
	count(head);
	return 0;
}
 

