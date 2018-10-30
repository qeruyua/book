#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 100
typedef struct{
	char str[MAXSIZE];
	int length; 
}string;
int strcompare(string s1,string s2)
{
	int i=0;
	while(s1.str[i]&&s2.str[i])
	{
		if(s1.str[i]>s2.str[i])
		return 1;
		else if(s1.str[i]<s2.str[i])
		return -1;
		else i++;
	}
	if(!s1.str[i]&&s2.str[i])return -1;
	else if(!s2.str[i]&&s1.str[i]) return 1;
	else if(!s2.str[i]&&!s1.str[i]) return 0;
 } 
 //获得next[]
 int getnext(string p,int next[])
 {
 	int i,j;
 	next[0]=-1;
 	i=0;j=-1;
 	while(i<p.length)
 	{
 		if(j==-1||p.str[i]==p.str[j])
 		{++i;++j;next[i]=j;
		 }
		 else
		 j=next[j];
	 }
	 for(i=0;i<p.length;i++)
	 printf("%d",next[i]);
	 return next;
  } 
  //kmp匹配
  int kmp(string t,string p,int next[])
  {
  	int i=0,j=0;
  	while(i<t.length&&j<p.length)
  	{
  		if(j==-1||t.str[i]==p.str[j])
  		{i++;j++;
		  }
		  else
		  j=next[j];
	  }
	  if(j==p.length)return (i-p.length);
	  else return (-1);
  }
  //替换
  void rel(string t,string p,string p1,int i)
  {
  	string s;
  	int j,l,count,k=0;
  	l=t.length+p1.length-p.length;
  	for(j=0;j<i;j++)
  	{
  		s.str[j]=t.str[j];
	  }
	  count=j;
	  for(j=i;j<i+p1.length;j++)
	  {
	  	s.str[j]=p1.str[j-i];
	  }
	  for(j=i+p1.length;j<l;j++)
	  {
	  	s.str[j]=t.str[j+k];
	  	k++;
	  }
	  for(i=0;i<l;i++)
	  {
	  	printf("%c",s.str[i]);
	  }
   } 
 int main()
 {
 	string s1,s2,s3;
 	int i,j,k,next[20]="000";
 	printf("请输入第一个顺序串："); 
 	scanf("%s",s1.str);
 	s1.length=strlen(s1.str);
 	
 	printf("请输入第二个顺序串：");
 	scanf("%s",&s2.str);
 	s2.length=strlen(s2.str);
 	printf("请输入第三个顺序串：");
 	scanf("%s",&s3.str);
 	s3.length=strlen(s3.str);
 	i=strcompare(s1,s2);
 	if(i==1)
 	printf("第一个顺序串大"); 
 	else if(i==-1)
 	printf("第二个顺序串大"); 
 	else
 	printf("两个顺序串一样大");
 	printf("\n\nkmp匹配\n");
 	j=getnext(s2,next);
 	k=kmp(s1,s2,j);
 	rel(s1,s2,s2,k);
	 return 0; 
 }
