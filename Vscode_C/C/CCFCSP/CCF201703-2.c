#include<stdio.h>
#include<math.h>//      <简 单>
#include<string.h>
#include<stdlib.h>
#define NEW (struct Linenode*)malloc(sizeof(struct Linenode))
int num=1,n,m;
struct Linenode* Head;
struct Linenode
{
    int num;
    struct Linenode *prior,*next;
};

struct Linenode* create()//创建一个双链表,返回它的首地址h
{
    static struct Linenode* h;
    struct Linenode *q,*p;
    h=NULL;
    while(num<=n)
    {
        p=NEW;
        
        p->num=num;
        num++;
        p->next=NULL;
        p->prior=NULL;
        if(h==NULL)
            h=p;
        else
        {
            q->next=p;
            p->prior=q;
        }
        q=p;   
    }
    return h;
}

void Front_Inter(struct Linenode *L,struct Linenode *T)//在目标节点T前插节点L
{
    if(L->next==NULL||L->prior==NULL)
    {
        if (L->next==NULL)//尾节点
        {
            L->prior->next=L->next;
        }
        else if(L->prior==NULL)//首节点,首节点没办法前移动,这里缺乏健壮性
        {
            Head=L->next;//把头也跟着换了
            L->next->prior=L->prior;
        }
    }
    else
    {
        L->next->prior=L->prior;
        L->prior->next=L->next;
    }   //断开需要调整的L结构体和前后的连结
    if(T->prior!=NULL)  //非末位结构体
    {
        T->prior->next=L;
        L->next=T;
        L->prior=T->prior;
        T->prior=L;
    }
    else
    {
        L->next=T;
        T->prior=L;
        Head=L;     //更换头节点的连结
        L->prior=NULL;
    }
}

void Back_Inter(struct Linenode *L,struct Linenode *T)//在目标节点T后插节点L
{
    if(L->next==NULL||L->prior==NULL)
    {
        if (L->next==NULL)//尾节点--尾节点没办法后移动,这里缺乏健壮性
        {
            L->prior->next=L->next;
        }
        else if(L->prior==NULL)//首节点
        {
            Head=L->next;//把头也跟着换了
            L->next->prior=L->prior;
        }
    }
    else
    {
        L->next->prior=L->prior;
        L->prior->next=L->next;
    }   //断开需要调整的L结构体和前后的连结
    if(T->next!=NULL)   //非末位结构体
    {
        T->next->prior=L;
        L->prior=T;
        L->next=T->next;
        T->next=L;
    }
    else
    {
        L->prior=T;
        T->next=L;
        L->next=NULL;        
    }
}

struct Linenode * Search(int Num)//返回一个结构体num为Num的指针
{
    struct Linenode *f;
    f=Head;
    while(f!=NULL)
    {
        if(f->num==Num)
            return f;
        f=f->next;
    }
    return NULL;
}

void Instruct(int Loc,int goTo)//调整链表的函数,需要的学号, 以及去哪
{
    struct Linenode *s,*t;
    int i;
    s=Search(Loc);
    if(s!=NULL)
    {
        t=s;
        if(goTo==0)
        {
            exit(0);
        }
        else if(goTo>0)
        {
            for(i=0;i<goTo;i++)
            {
                if(t->next!=NULL)   //至多走到末位结构体
                    t=t->next;
                else
                    break;
            }
            Back_Inter(s,t);
        }
        else 
        {
            for(i=0;i<abs(goTo);i++)
            {
                if(t->prior!=NULL)  //至多走到首位位结构体
                    t=t->prior;
                else
                    break;
            }
            Front_Inter(s,t);
        }
    }
}

int main()
{
    int i,No,In;
    scanf("%d%d",&n,&m);
    struct Linenode *W;
    Head=create();
    for(i=0;i<m;i++)//接收指令
    {
        scanf("%d%d",&No,&In);
        Instruct(No,In);
        
    }
    W=Head;
    while(W!=NULL)//简单遍历一下
    {
        printf("%d",W->num);
        if(W->next!=NULL)
            printf(" ");
        else
            printf("\n");
        W=W->next;
    }
    return 0;
}