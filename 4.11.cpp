#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAXSIZE 100
typedef struct linknode
{
    char data;
    struct linknode *next;
}node;
node *strcreate(node *s)
{
    char ch;
    node *p,*r;
    s=NULL;r=NULL;
    while((ch=getchar())!='\n')
    {
        p=(node*)malloc(sizeof(node));
        p->data=ch;
        if(s==NULL)
            s=p;
        else
            r->next=p;
        r=p;
    }
    if(r!=NULL) r->next=NULL;
    return s;
}
node* strcopy(node *t2)
{
    node *l=NULL,*r=NULL,*s,*p;
    p=t2;
    while(p)
    {
        s=(node*)malloc(sizeof(node));
        s->data=p->data;
        if(l==NULL) l=r=s;
        else{
            r->next=s;
            r=s;
        }
        p=p->next;
    }
    if(r!=NULL) r->next=NULL;
    return l;
}
node* strreplace(node *s,node *t1,node *t2)
{
    node *p,*q,*r,*c,*pre,*temp,*pos;
    int flag=1;
    if(s==NULL||t1==NULL) return s;
    pre=NULL;
    pos=s;
    while(pos&&flag)
    {
        p=pos;
        q=t1;
        while(p&&q)
        {
            if(p->data==q->data)
            {
                p=p->next;q=q->next;
            }
            else
            {
                pre=pos;
                pos=pos->next;
                p=pos;
                q=t1;
            }
        }
        if(q!=NULL) flag=0;
        else
        {
            flag=1;
            r=pos;
            while(r!=p)
            {
                c=r;
                r=r->next;
                free(c);
            }
            if(t2!=NULL)
            {
                temp=r=strcopy(t2);
                while(r->next!=NULL)   r=r->next;
                r->next=p;
                if(pre==NULL)   s=temp;
                else  pre->next=temp;
                pre=r;
                pos=p;
            }
            else
            {
                if(pre==NULL)   s=p;
                else    pre->next=p;
                pos=p;
            }
        }
    }
    return s;
}
void print(node *s)
{
    node *p=s;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
}
int main()
{
    node *s=NULL,*t1=NULL,*t2=NULL;
    printf("请输入字符串\n");
    s=strcreate(s);
    printf("请输入被替换的字符串\n");
    t1=strcreate(t1);
    printf("请输入要替换成的字符串\n");
    t2=strcreate(t2);
    s=strreplace(s,t1,t2);
    print(s);
    return 0;
}
