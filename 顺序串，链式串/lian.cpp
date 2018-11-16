#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct linknode{
	char data;
	struct linknode *next;
}node;
node *creat(node *head)
{
	char c;
	node *p=NULL,*r=NULL;
	p=(node *)malloc(sizeof(node));
	while((c=getchar())!='\n')
	{
		//p=(node *)malloc(sizeof(node));
		p->data=c;
		if(head==NULL)
		head=p;
		else
		r->next=p;
		r=p;
		p=(node *)malloc(sizeof(node));
	}
	r->next=NULL;
	return head;
}
//����
node *insert(node *head,int i,node *s)
{
	node *p=head,*q=s;
	int j=1;
    while(p&&j<i-1)
    {
    	p=p->next;j++;
	}
	if(!p)
	{
	printf("������");
	return NULL;
    }
    else
    {
    	while(q&&q->next)
    	{
    	q=q->next;
        }
    	q->next=p->next;
    	p->next=s;
	}
	return head;
 } 
 //ɾ��
 node *dele(node *head,int i,int len)
 {
 	int k=1;
 	node *p=head,*q=NULL,*r=NULL;
	while(p&&k<i)
	{
		q=p;p=p->next;
		k++;
	  }  
	if(!p)
	{
	printf("error1\n");
	return NULL; 
    }
	else
	{
		k=1;
		while(p&&k<len)
		{
			p=p->next;
			k++;
		}
		if(!p)
		{
			printf("error2\n");
			return NULL;
		}
		else
		{
			if(!q)
			{
			r=head;
			head=p->next;	
			}
			else
			{
			r=q->next;
			q->next=p->next;
		    }
		}
		p->next=NULL;
		while(r!=NULL)
		{
			p=r;
			r=r->next;
			free(p);
		}
		
	}
	return head; 
  } 
//����
node *concat(node *head,node *s)
{
	node *p=head;
	if(!head)
	{
		head=s;
	     return head;
	}
	else
	{
		if(s)
		{
			while(p->next)
			{
				p=p->next;
			}
			p->next=s;
		}
	}
	return (head);
}
//���ַ���
node *str(node *head,int i,int len)
{
	int k=1;
	node *p=head,*q=NULL,*r=NULL,*t=NULL;
	while(p&&k<i)
	{
	p=p->next;
	k++;	
	}
	if(!p)
	{
    printf("error\n");
	return NULL;
	}
	else
	{
	r=(node*)malloc(sizeof(node)); 
	r->data=p->data;
	r->next=NULL;
	k=1;q=r;
	while(p->next&&k<len)
	{
		p=p->next;
		k++;
		t=(node *)malloc(sizeof(node));
		t->data=p->data;
		q->next=t;
		q=t;
		}
		if(k<len)
		{
			printf("error\n");
			return NULL;
			}	
			else
			{
				q->next=NULL;
				return r;
			}
	}
 } 
 //���
 void print(node *head)
 {
 	node *p=head;
 	while(p)
 	{
 		printf("%c",p->data);
 		p=p->next;
	 }
	 printf("\n");
 	
  } 
  int main()
  {
  	node *head=NULL,*q=NULL;
  	int i,j;
  	printf("����Ҫ������ַ�����");
  	head=creat(head);
  	print(head);
  	printf("�������ַ�����\n");
  	q=creat(q);
  	printf("���������ַ���\n");
  	head=concat(head,q);
  	print(head);
  	printf("������Ҫɾ����λ�ã�");
  	scanf("%d",&i);
  	printf("������Ҫɾ���ĳ��ȣ�");
  	scanf("%d",&j);
  	head=dele(head,i,j);
	print(head);
	printf("���������ַ�����λ�ã�");
  	scanf("%d",&i);
  	printf("���������ַ����ĳ��ȣ�");
  	scanf("%d",&j);
  	head=str(head,i,j);
	print(head);
    printf("�����뽫���ַ����������ַ�����λ�ã�");
  	scanf("%d",&i);
	head=insert(head,i,q);
  	print(head);  
	return 0;
  }
