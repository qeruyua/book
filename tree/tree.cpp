/*#include"stdio.h"
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
   void preorder1(node *t)
   {
   	if(t)
   	{
   		printf("%c",t->data);
   		preorder1(t->lchild);
   		preorder1(t->rchild);
	   }
	} 
   //ǰ������ķǵݹ�ʵ��
  void preorder(node *t)
  {
  	printf("�ǵݹ�ǰ�����"); 
  	seqstack s;
  	s.top=0;
  	while((t)||s.top!=0)
  	{
  		if(t)
  		{
  			printf("%c",t->data);
  			push(&s,t);
  			t=t->lchild;
		  }
		  else
		  {
		  	t=pop(&s);
		  	t=t->rchild;
		  }
	  }
   } 
   //��������ݹ�
   void inorder1(node *t)
   {
   	if(t)
   	{
   		inorder1(t->lchild);
   		printf("%c",t->data);
   		inorder1(t->rchild);
	   }
	} 
   //�������
   void inorder(node *t)
   {
   	printf("�ǵݹ��������"); 
   	seqstack s;
   	s.top=0;
   	while((t!=NULL)||(s.top!=0))
   	{
   		if (t)
   		{
   			push(&s,t);
   			t=t->lchild;
		   }
		   else
		   {
		   	t=pop(&s);
		   	printf("%c",t->data);
		   	t=t->rchild;
		   }
	   }
	} 
	//��������ݹ�
	void postorder1(node *t)
	{ 
		if(t)
		{
			postorder1(t->lchild);
   		postorder1(t->rchild);
   		printf("%c",t->data);
		}
		
	 } 
	//�������
	void postorder(node *t)
	{
		printf("�ǵݹ�������"); 
		seqstack s;
		s.top=0;
		while((t)||s.top!=0)
		{
			if(t)
			{
				s.data[s.top]=t;
				s.tag[s.top]=0;
				s.top++;
				t=t->lchild;
			}
			else if(s.tag[s.top-1]==1)
			{
				s.top--;
				t=s.data[s.top];
				printf("%c",t->data);
				t=NULL;
			}
			else
			{
				t=s.data[s.top-1];
				s.tag[s.top-1]=1;
				t=t->rchild;
			}
		}
	 }
	 int main()
	 {
	 	node *t=NULL;
	 	seqstack *s=0;
	 	t=create();
	 	printf("ǰ��ݹ飺") ;
	 	preorder1(t);
	 	printf("\n");
	 	preorder(t);
	 	printf("\n");
	 	printf("����ݹ飺") ;
	 	inorder1(t);
	 	printf("\n");
	 	inorder(t);
	 	printf("\n");
	 	printf("����ݹ飺") ;
	 	postorder1(t);
	 	printf("\n");
	 	postorder(t);
	 	return 0;
	  } 
*/


#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node {
	datatype data;
	struct node *lchild, *rchild;
}bintnode;
typedef bintnode *bintree;

bintree create()             //���Ĵ���
{  //ǰ������������ݹ��㷨 
	char ch;
	bintree t;
	if ((ch = getchar()) == '#')
		t = NULL;
	else
	{
		t = (bintnode*)malloc(sizeof(bintnode));
		t->data = ch;
		t->lchild = create();
		t->rchild = create();

	}
	return t;
}

//����ʵ��
typedef struct stack         //ջ�Ķ��壬���ں������ 
{
	bintree data[1000];
	int tag[1000];
	int top;                  //ջ�� 
} se;

void push(se *s, bintree t)   //��ջ 
{
	s->data[s->top] = t;
	s->top++;
}

bintree pop(se *s)            //��ջ
{
	if (s->top != 0)
	{
		s->top--;
		return(s->data[s->top]);
	}
	else
		return NULL;
}

void pre(bintree t)          //ǰ����� ,�ǵݹ�
{
	se s;
	s.top = 0;
	while ((t) || (s.top != 0))
	{
		if (t)
		{
			printf("%c", t->data);
			push(&s, t);
			t = t->lchild;
		}
		else
		{
			t = pop(&s);
			t = t->rchild;
		}
	}
}

void in(bintree t)         //�������,�ǵݹ�
{
	se s;
	s.top = 0;
	while ((t != NULL) || (s.top != 0))
	{
		if (t)
		{
			push(&s, t);
			t = t->lchild;
		}
		else
		{
			t = pop(&s);
			printf("%c", t->data);
			t = t->rchild;
		}
	}

}

void post(bintree t)            //�������,�ǵݹ�
{
	se s;
	s.top = 0;
	while ((t) || (s.top != 0))
	{
		if (t)
		{
			s.data[s.top] = t;
			s.tag[s.top] = 0;
			s.top++;
			t = t->lchild;
		}
		else
			if (s.tag[s.top - 1] == 1)
			{
				s.top--;
				t = s.data[s.top];
				printf("%c", t->data);
				t = NULL;
			}
			else
			{
				t = s.data[s.top - 1];
				s.tag[s.top - 1] = 1;
				t = t->rchild;
			}
	}
}

void pre1(bintree t)                 //ǰ��������ݹ�
{
	if (t)
	{
		printf("%c", t->data);
		pre1(t->lchild);
		pre1(t->rchild);
	}
}

void in1(bintree t)                   //����������ݹ�
{
	if (t)
	{
		in1(t->lchild);
		printf("%c", t->data);
		in1(t->rchild);
	}
}

void post1(bintree t)                 //����������ݹ�
{
	if (t)
	{
		post1(t->lchild);
		post1(t->rchild);
		printf("%c", t->data);
	}
}

int main()
{
	bintree *t = NULL;
	se *s = 0;
	t = create();
	printf("ǰ������ǵݹ���Ϊ");
	pre(t);
	printf("\n");
	printf("ǰ������ݹ���Ϊ");
	pre1(t);
	printf("\n");

	printf("��������ǵݹ���Ϊ");
	in(t);
	printf("\n");
	printf("��������ݹ���Ϊ");
	in1(t);
	printf("\n");

	printf("��������ǵݹ���Ϊ");
	printf("\n");
	post(t);
	printf("��������ݹ���Ϊ");
	post1(t);
	printf("\n");
	system("pause");
	return 0;
}
	  
	   
	 
