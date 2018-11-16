
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 100
typedef struct{
	char str[MAXSIZE];
	int length; 
}string;
//����
string *strinsert(string *s,int i,string *t)
{
	int k;
	if(i<1||i>s->length+1||s->length+t->length>MAXSIZE-1)
	printf("���ܲ��룡");
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
//ɾ��
string *dele(string *s,int i,int len)
{
	int k;
	if(i<1||i>s->length||i+len-1>s->length)
	printf("����ɾ����");
	else
	{
	for(k=i+len-1;k<s->length;k++)
	s->str[k-len]=s->str[k];
	s->length=s->length-len;
	s->str[s->length]='\0';
    }
    return (s);
 } 
//����
string *concat(string *s1,string *s2)
{
	string *r;
	int i;
	if(s1->length+s2->length>MAXSIZE)
	{
	printf("��������");return 0;
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
//���ַ���
string *str(string *s,int i,int len)
{
	int k;
	string *r;
	if(i<1||i>s->length||i+len-1>s->length)
	{
		printf("����");
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
 //����
 string *creat(string *s)
 {
 	char c[10];
 	int i=0,j;
 	printf("�������ַ�����");
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
 //���
 void print(string *s)
 {
 	int i;
 	if(!s->length)
 	printf("�ַ���Ϊ��");
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
	printf("������Ҫ�������ʼλ�ã�");
	scanf("%d",&i); 
	r=creat(r);
	s=strinsert(s,i,r);
	print(s);
	printf("������Ҫɾ������ʼλ�ã�");
	scanf("%d",&i); 
    printf("������Ҫɾ���ĳ��ȣ�");
	scanf("%d",&j);
	s=dele(s,i,j);
	print(s);
	p=creat(p);
	s=concat(s,p);
	print(s); 
	printf("���������ַ�������ʼλ�ã�");
	scanf("%d",&i); 
    printf("���������ַ����ĳ��ȣ�");
	scanf("%d",&j);
	s=str(s,i,j);
	print(s);
	return 0;
 }
