#include<stdio.h>
#define N 14
int main()
{
    char a[N]={'\0'};
    int i,sum=0,n=1;
    for(i=0;i<N-1;i++)
    {
        scanf("%c",&a[i]);
        if(a[i]!='-'&&i!=12)
        {
            sum+=((int)a[i]-48)*n;
            n++;
        }
    }
    sum%=11;
    char temp='\0';
    temp=(sum+'0');
    if(sum==10)
    {
        temp='X';
    }
    if(a[12]==temp)
    {
        printf("Right");
    }
    else 
    {
        a[12]=temp;
        printf("%s",a);
    }
    return 0;
}