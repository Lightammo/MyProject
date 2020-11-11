#include<stdio.h>
#define N 101
int main()
{
    int n;
    scanf("%d",&n);
    int a[N][4]={0},b[N][N]={0};
    int i,j,x,y;
    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
        for(x=a[i][0];x<a[i][2];x++)
        {
            for(y=a[i][1];y<a[i][3];y++)
            {
                b[x][y]=1;
            }
        }
    }
    int Area=0;
    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(b[i][j]==1)
            {
                Area++;
            } 
        }
    }
    printf("%d",Area);
    return 0;
}