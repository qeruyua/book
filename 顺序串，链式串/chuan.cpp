
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 100
typedef struct{
	char str[MAXSIZE];
	int length; 
}string;
//插入
string *strinsert(string *s,int i,string *t)
{
	int k;
	if(i<1||i>s->length+1||s->length+t->length>MAXSIZE-1)
	printf("不能插入！");
	else
	{
		for(k=s->length-1;k>=i-1;k--)
		s->str[t->length+k]=s->str[k];
		for(k=0;k<t->length;k++)
		s->str[i+k-1]=t->str[k];
		s->length=s->length+t->length;
		s->str[s->length]='\0';
	}
	return (s);
 } 
//删除
string *dele(string *s,int i,int len)
{
	int k;
	if(i<1||i>s->length||i+len-1>s->length)
	printf("不能删除！");
	else
	{
	for(k=i+len-1;k<s->length;k++)
	s->str[k-len]=s->str[k];
	s->length=s->length-len;
	s->str[s->length]='\0';
    }
    return (s);
 } 
//连接
string *concat(string *s1,string *s2)
{
	string *r;
	int i;
	if(s1->length+s2->length>MAXSIZE)
	{
	printf("不能连接");return 0;
    }
	else
	{
		r=(string*)malloc(sizeof(string));
		for(i=0;i<s1->length;i++)
		r->str[i]=s1->str[i];
		for(i=s1->length;i<s1->length+s2->length;i++)
		r->str[i] =s2->str[i-s1->length];
		r->length=s1->length+s2->length;
		r->str[r->length]='\0';
	}
	return (r);
}
//求字符串
string *str(string *s,int i,int len)
{
	int k;
	string *r;
	if(i<1||i>s->length||i+len-1>s->length)
	{
		printf("错误");
		return 0;
	}
	else
	{
		r=(string*)malloc(sizeof(string));
		for(k=0;k<len;k++)
		r->str[k]=s->str[i+k-1];
		r->length=len;
		r->str[s->length]='\0';
	}
	return (r);
 } 
 void init(string *s)
 {
 	s->length=0;
  } 
 //创建
 string *creat(string *s)
 {
 	char c[10];
 	int i=0,j;
 	printf("请输入字符串：");
 	scanf("%s",c);
 	j=strlen(c);
 	
 	s=(string *)malloc(sizeof(string));
 	for(i=0;i<j;i++)
 	{ 
 		s->str[i]=c[i];
	 }
	 s->length=j;
	 s->str[s->length]='\0';
	 return (s);
  }
 //输出
 void print(string *s)
 {
 	int i;
 	if(!s->length)
 	printf("字符串为空");
 	else
 	{
 	for(i=0;i<s->length;i++)
 	printf("%c",s->str[i]);
 	printf("\n");
    }
  } 
int main()
{
	char a[20];
	string *s=NULL,*r=NULL,*p=NULL;
	int i,j;
	s=creat(s);
	print(s);
	printf("请输入要插入的起始位置：");
	scanf("%d",&i); 
	r=creat(r);
	s=strinsert(s,i,r);
	print(s);
	printf("请输入要删除的起始位置：");
	scanf("%d",&i); 
    printf("请输入要删除的长度：");
	scanf("%d",&j);
	s=dele(s,i,j);
	print(s);
	p=creat(p);
	s=concat(s,p);
	print(s); 
	printf("请输入子字符串的起始位置：");
	scanf("%d",&i); 
    printf("请输入子字符串的长度：");
	scanf("%d",&j);
	s=str(s,i,j);
	print(s);
	return 0;
 }
