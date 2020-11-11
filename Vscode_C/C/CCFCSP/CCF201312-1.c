#include<stdio.h>
#define N 10001
int main()
{
    int n,v;
    scanf("%d",&n);
    int a[N]={0};
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&v);
        a[v]++;
    }
    int temp=0;
    for(i=N;i>0;i--)
    {
        if(a[i]>=temp)
        {
            temp=a[i];
            v=i;
        }
    }
    printf("%d",v);
    return 0;
}