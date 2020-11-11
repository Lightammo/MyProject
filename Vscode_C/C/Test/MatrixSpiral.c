/*
    filename:MatrixSpiral.c
    author:Lyn#reo
    create:2020.10.18
    #可以根据需要修改
    #如有二次发送的必要
    #请留下修改者和修改日期:)
    #感激您的真诚#
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 102
/*定义一个结构体储存行径的方向*/
struct Direction{
    int i,j;
}Go[4]={{0,1},{1,0},{0,-1},{-1,0}};

/*以及一个全局变量作为行径方向的索引*/
int t=0;

int nextx,nexty;
char map[N][N];
int Element[N][N];

int JadgeDextroversion(int x,int y)//对坐标进行判断
{
    if(map[x][y]=='#')
    {
        t++;//调整坐标索引
        return 0;
    }
    return 1;
}

void OutTunnelsOrder(int x,int y)
{
    printf("%d",Element[x][y]);//输出指令
    printf(" ");
    map[x][y]='#';//留下标记
}

void SpiralOrder(int x,int y)
{
    JadgeDextroversion(x+Go[t%4].i,y+Go[t%4].j);
    //判断下一次的索引坐标
    OutTunnelsOrder(x,y);
    nextx=x+Go[t%4].i;
    nexty=y+Go[t%4].j;
    if(JadgeDextroversion(nextx,nexty))
    //判断被赋值的next
    {
        SpiralOrder(nextx,nexty);//递归进行下一个坐标
    }
    else
    {
        exit(0);
    }
}

int main()
{
    memset(map,'#',sizeof(map));
    memset(Element,0,sizeof(Element));

    int m,n;
    scanf("%d%d",&m,&n);
    int i,j;
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            scanf("%d",&Element[i][j]);
            map[i][j]='\0';
        }
    }
    SpiralOrder(1,1);//从(1,1)进入
    return 0;
}