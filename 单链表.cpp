           ������
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
	node *p;
	p=head;
	if(!p)printf("\n�������");
	else
	{
		printf("\n���������ֵΪ��\n");
		while(p)
		{
			printf("%5d",p->info);
			p=p->next;
		}
	}
 } 
 //���ҵ�i�����
 node *find(node *head,int i)
 {
 	int j;
 	node *p=head;
 	if(i<1)return NULL;
 	while(p&&j!=i)
 	{
 		p=p->next;
 		j++;
	 }
	 return p;
   }  
//��i���������x
node *insert(node *head,datatype x,int i)
{
	node *p,*q;
	q=find(head,i);
	if(!q)
	{
		printf("\n�����ڵ�%d�����",i);
	 } 
	else{
	
	p=(node*)malloc(sizeof(node));
	p->info=x;
	if(i==0)//��������ǰ�����x 
	{
	p->next=head;
	p=head;	
	}
	else//q����� 
	{
		p->next=q->next;
		q->next=p;
	}
}
}
//ɾ��
node *dele(node *head,datatype x)
{
	node *pre=NULL,*p=head;
	if(!p)
	{
	printf("�������");
	return head;	
	}
	p=head;
	while(!p&&p->info!=x)
	{
		pre=p;p=p->next;
	}
	if(p)
	{
		if(!pre) head=head->next;
		else pre->next=p->next;
		free(p);
	}
	return head;
 } 
   //ǰ�崴������ 
node *create()
{
	node *head,*p;
	int x;
	scanf("%d",&x);
	while(x!=-1)
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
int main()
{
	node *head,*p;
	int i,x;
	init();
	head=creat();
	display(head);
	printf("\n����Ҫ��ѯ�Ľ�㣺"); 
	scanf("%d",&i);
	p=find(head,i);
	printf("%d",p->info);
	printf("���������ֵ��");
	scanf("%d",&i);
	printf("����������λ�ã�");
	scanf("%d",&x);
	head=insert(head,i,x);
	display(head);
	printf("\n����Ҫɾ����ֵ��");
	scanf("%d",&i);
	head=dele(head,i);
	display(head);
	return 0;
	
}
��ͷ������
#include"stdio.h"
#include"stdlib.h"
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
}node;
//����һ���յĴ�ͷ�������
node *init()
{
	node *head;
	head=(node*)malloc(sizeof(node));
    head->next=NULL;
	return head;	
 }
//�����ͷ����ֵ
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
 //���ҵ�i������ֵ
 node *find(node *head,int i)
 {
 	node *p=head;
 	int j=0;
 	if(i<0)
 	{
 		printf("\n�����ڵ�%d�����",i);
	 }
	 else
	 	if(i==0)
	 	return p;
	 while(p&&i!=j)
	 {
	 	p=p->next;
	 	j++;
	 }
	 return p;
  } 
  //��i���ڵ�����x 
node *insert(node *head,int i,datatype x)
{
	node *p,*q;
	q=find(head,i);
	if(!q)
	{
		printf("\n�����ڵ�%d�����",i);
	 } 
	 p=(node*)malloc(sizeof(node));
	 p->info=x;
	 p->next=q->next;
	 q->next=p;
	 return head;
 } 
 //ɾ��һ��ֵΪx����
 node *dele(node *head,datatype x)
 {
 	node *pre=head,*p;
 	p=head->next;
 	if(!p)
 	{
 		printf("����Ϊ��");
		 exit(1); 
	 }
	 while(p&&p->info!=x)
	 {
	 	pre=p;
	 	p=p->next;	
	 }
	 if(p)
	 {
	 	pre->next=p->next;
	 	free(p);
	 }
	 return head;
  } 
  //ǰ�崴������ 
node *create()
{
	node *head,*p;
	int x;
	scanf("%d",&x);
	while(x!=-1)
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
int main()
{
	node *head,*p;
	int i,x;
	init();
	head=creat();
	display(head);
	printf("\n����Ҫ��ѯ�Ľ�㣺"); 
	scanf("%d",&i);
	p=find(head,i);
	printf("%d",p->info);
	printf("���������λ�ã�");
	scanf("%d",&i);
	printf("����������ֵ��");
	scanf("%d",&x);
	head=insert(head,i,x);
	display(head);
	printf("\n����Ҫɾ����ֵ��");
	scanf("%d",&i);
	head=dele(head,i);
	display(head);
	return 0;
	
}
 

