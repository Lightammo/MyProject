#include<stdio.h>
#define N 1000
int main()
{
    int n,i,j,h=0,sum=0,Area=0;
    scanf("%d",&n);
    int a[N]={0};
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(h<a[i])
           h=a[i];
    }
    for(j=1;j<=h;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>=j)
            {
                sum+=j;
                if(Area<sum)
                    Area=sum;
            }
            else
            {
                sum=0;
            }
        }
    }
    printf("%d",Area);
    return 0;
}