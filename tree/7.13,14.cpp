13Ҷ�ڵ���
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
typedef char datatype;
typedef struct bintnode{
	datatype data;
	struct bintnode *lchild,*rchild;
}node;
typedef struct stack
{
	node *data[100];
	int tag[100];
	int top;
 } seqstack;
//ǰ��ݹ鴴��
node *create()
{
	char c;
	node *t;
	if((c=getchar())=='#')
	t=NULL; 
	else
	{
		t=(node *)malloc(sizeof(node));
		t->data=c;
		t->lchild=create();
		t->rchild=create(); 
	}
	return t;
 } 
 //��ջ
 void push(seqstack *s,node *t )
 {
 	s->data[s->top]=t;s->top++;
  }
  //��ջ
  node *pop(seqstack *s)
  {
  	if (s->top!=0)
  	{
  		s->top--;
  		return s->data[s->top]; 
	  }
	  else
	  return NULL;
  	
   }
      //ǰ��ݹ�
   int preorder1(node *t)
   {static int c=0; 
   	if(t)
   	{
   		if((t->lchild==NULL)&&(t->rchild==NULL))
   		c++;
   		//printf("%c",t->data);
   		else
   		{
   		preorder1(t->lchild);
   		preorder1(t->rchild);
     	}
	}
	   return c;
	} 
   //ǰ������ķǵݹ�ʵ��
  void preorder(node *t)
  {
  	int a=0;
  	printf("�ǵݹ�ǰ�����"); 
  	seqstack s;
  	s.top=0;
  	while((t)||s.top!=0)
  	{
  		if(t)
  		{
  			if((t->lchild==NULL)&&(t->rchild==NULL))
   		    a++;
  			push(&s,t);
  			t=t->lchild;
		  }
		  else
		  {
		  	t=pop(&s);
		  	t=t->rchild;
		  }
	  }
	  printf("%d",a);
   }
 int main()
 {
 	   node *t=NULL;
 	   int c;
	 	seqstack *s=0;
	 	t=create();
	 	printf("ǰ��ݹ飺") ;
	 	c=preorder1(t);
	 	printf("%d",c);
	 	printf("\n");
	 	preorder(t);
	 	printf("\n");
  }




14��������µ����һ���ڵ�
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
typedef char datatype;
typedef struct bintnode{
	datatype data;
	struct bintnode *lchild,*rchild;
}node;
typedef struct stack
{
	node *data[100];
	int tag[100];
	int top;
 } seqstack;
//ǰ��ݹ鴴��
node *create()
{
	char c;
	node *t;
	if((c=getchar())=='#')
	t=NULL; 
	else
	{
		t=(node *)malloc(sizeof(node));
		t->data=c;
		t->lchild=create();
		t->rchild=create(); 
	}
	return t;
 } 
 //��ջ
 void push(seqstack *s,node *t )
 {
 	s->data[s->top]=t;s->top++;
  }
  //��ջ
  node *pop(seqstack *s)
  {
  	if (s->top!=0)
  	{
  		s->top--;
  		return s->data[s->top]; 
	  }
	  else
	  return NULL;
  	
   }
      //ǰ��ݹ�
   int preorder1(node *t)
   {static int c=0; 
   	if(t)
   	{
   		if((t->lchild==NULL)&&(t->rchild==NULL))
   		c++;
   		//printf("%c",t->data);
   		else
   		{
   		preorder1(t->lchild);
   		preorder1(t->rchild);
     	}
	}
	   return c;
	} 
   //ǰ������ķǵݹ�ʵ��
  void preorder(node *t)
  {
  	int a=0;
  	printf("�ǵݹ�ǰ�����"); 
  	seqstack s;
  	s.top=0;
  	while((t)||s.top!=0)
  	{
  		if(t)
  		{
  			if((t->lchild==NULL)&&(t->rchild==NULL))
   		    a++;
  			push(&s,t);
  			t=t->lchild;
		  }
		  else
		  {
		  	t=pop(&s);
		  	t=t->rchild;
		  }
	  }
	  printf("%d",a);
   }
 int main()
 {
 	   node *t=NULL;
 	   int c;
	 	seqstack *s=0;
	 	t=create();
	 	printf("ǰ��ݹ飺") ;
	 	c=preorder1(t);
	 	printf("%d",c);
	 	printf("\n");
	 	preorder(t);
	 	printf("\n");
  }

