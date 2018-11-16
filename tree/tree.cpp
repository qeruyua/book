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
//前序递归创建
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
 //进栈
 void push(seqstack *s,node *t )
 {
 	s->data[s->top]=t;s->top++;
  }
  //出栈
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
   //前序递归
   void preorder1(node *t)
   {
   	if(t)
   	{
   		printf("%c",t->data);
   		preorder1(t->lchild);
   		preorder1(t->rchild);
	   }
	} 
   //前序遍历的非递归实现
  void preorder(node *t)
  {
  	printf("非递归前序遍历"); 
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
   //中序遍历递归
   void inorder1(node *t)
   {
   	if(t)
   	{
   		inorder1(t->lchild);
   		printf("%c",t->data);
   		inorder1(t->rchild);
	   }
	} 
   //中序遍历
   void inorder(node *t)
   {
   	printf("非递归中序遍历"); 
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
	//后序遍历递归
	void postorder1(node *t)
	{ 
		if(t)
		{
			postorder1(t->lchild);
   		postorder1(t->rchild);
   		printf("%c",t->data);
		}
		
	 } 
	//后序遍历
	void postorder(node *t)
	{
		printf("非递归后序遍历"); 
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
	 	printf("前序递归：") ;
	 	preorder1(t);
	 	printf("\n");
	 	preorder(t);
	 	printf("\n");
	 	printf("中序递归：") ;
	 	inorder1(t);
	 	printf("\n");
	 	inorder(t);
	 	printf("\n");
	 	printf("后序递归：") ;
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

bintree create()             //树的创建
{  //前序遍历建立，递归算法 
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

//遍历实现
typedef struct stack         //栈的定义，用于后序遍历 
{
	bintree data[1000];
	int tag[1000];
	int top;                  //栈顶 
} se;

void push(se *s, bintree t)   //进栈 
{
	s->data[s->top] = t;
	s->top++;
}

bintree pop(se *s)            //出栈
{
	if (s->top != 0)
	{
		s->top--;
		return(s->data[s->top]);
	}
	else
		return NULL;
}

void pre(bintree t)          //前序遍历 ,非递归
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

void in(bintree t)         //中序遍历,非递归
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

void post(bintree t)            //后序遍历,非递归
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

void pre1(bintree t)                 //前序遍历，递归
{
	if (t)
	{
		printf("%c", t->data);
		pre1(t->lchild);
		pre1(t->rchild);
	}
}

void in1(bintree t)                   //中序遍历，递归
{
	if (t)
	{
		in1(t->lchild);
		printf("%c", t->data);
		in1(t->rchild);
	}
}

void post1(bintree t)                 //后序遍历，递归
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
	printf("前序遍历非递归结果为");
	pre(t);
	printf("\n");
	printf("前序遍历递归结果为");
	pre1(t);
	printf("\n");

	printf("中序遍历非递归结果为");
	in(t);
	printf("\n");
	printf("中序遍历递归结果为");
	in1(t);
	printf("\n");

	printf("后序遍历非递归结果为");
	printf("\n");
	post(t);
	printf("后序遍历递归结果为");
	post1(t);
	printf("\n");
	system("pause");
	return 0;
}
	  
	   
	 
