           单链表
#include"stdio.h"
#include"stdlib.h"
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
}node; 
//建立空链表 
node *init()
{
	return NULL;
}
//输出链表中各结点的值
void display(node *head)
{
	node *p;
	p=head;
	if(!p)printf("\n单链表空");
	else
	{
		printf("\n各单链表的值为：\n");
		while(p)
		{
			printf("%5d",p->info);
			p=p->next;
		}
	}
 } 
 //查找地i个结点
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
//第i个结点后插入x
node *insert(node *head,datatype x,int i)
{
	node *p,*q;
	q=find(head,i);
	if(!q)
	{
		printf("\n不存在第%d个结点",i);
	 } 
	else{
	
	p=(node*)malloc(sizeof(node));
	p->info=x;
	if(i==0)//单链表最前面插入x 
	{
	p->next=head;
	p=head;	
	}
	else//q后插入 
	{
		p->next=q->next;
		q->next=p;
	}
}
}
//删除
node *dele(node *head,datatype x)
{
	node *pre=NULL,*p=head;
	if(!p)
	{
	printf("单链表空");
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
   //前插创建链表 
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
//后插创建
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
	printf("\n输入要查询的结点："); 
	scanf("%d",&i);
	p=find(head,i);
	printf("%d",p->info);
	printf("请输入插入值：");
	scanf("%d",&i);
	printf("请输入插入的位置：");
	scanf("%d",&x);
	head=insert(head,i,x);
	display(head);
	printf("\n输入要删处的值：");
	scanf("%d",&i);
	head=dele(head,i);
	display(head);
	return 0;
	
}
带头单链表
#include"stdio.h"
#include"stdlib.h"
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
}node;
//建立一个空的带头结点链表
node *init()
{
	node *head;
	head=(node*)malloc(sizeof(node));
    head->next=NULL;
	return head;	
 }
//输出带头结点的值
void display(node *head)
{
	node *p=head;
		printf("\n各单链表的值为：\n");
		while(p)
		{
		
			printf("%5d",p->info);
			p=p->next;
		}
 } 
 //查找地i个结点的值
 node *find(node *head,int i)
 {
 	node *p=head;
 	int j=0;
 	if(i<0)
 	{
 		printf("\n不存在第%d个结点",i);
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
  //在i个节点后插入x 
node *insert(node *head,int i,datatype x)
{
	node *p,*q;
	q=find(head,i);
	if(!q)
	{
		printf("\n不存在第%d个结点",i);
	 } 
	 p=(node*)malloc(sizeof(node));
	 p->info=x;
	 p->next=q->next;
	 q->next=p;
	 return head;
 } 
 //删除一个值为x操作
 node *dele(node *head,datatype x)
 {
 	node *pre=head,*p;
 	p=head->next;
 	if(!p)
 	{
 		printf("链表为空");
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
  //前插创建链表 
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
//后插创建
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
	printf("\n输入要查询的结点："); 
	scanf("%d",&i);
	p=find(head,i);
	printf("%d",p->info);
	printf("请输入插入位置：");
	scanf("%d",&i);
	printf("请输入插入的值：");
	scanf("%d",&x);
	head=insert(head,i,x);
	display(head);
	printf("\n输入要删处的值：");
	scanf("%d",&i);
	head=dele(head,i);
	display(head);
	return 0;
	
}
 

