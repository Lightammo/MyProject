#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NEW (struct node*)malloc(sizeof(struct node))
struct node{
    char name[20],tel[12];
    struct node *next;
};
struct node* create()
{
    static struct node* h;
    struct node *q,*p;
    char name[20],tel[12];
    h=NULL;
    printf("name:");
    gets(name);
    while(strlen(name)!=0)
    {
        p=NEW;
        if (p==NULL)
        {
            printf("Error");
            exit(0);
        }
        strcpy(p->name,name);
        printf("Tel:");
        gets(p->name);
        p->next=NULL;
        if(h==NULL)
            h=p;
        else
            q->next=p;
        q=p;
        printf("name:");
        gets(name);
    }
    return h;
}
int main()
{
    struct node *head;
    head=create();
    printf("%p",head);
    return 0;
    
}