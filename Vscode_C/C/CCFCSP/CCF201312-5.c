#include <stdio.h>
#include<string.h>
#define N 50
#define Direction 4
struct dir
{
    int i,j;
}go[Direction]={{0,-1},{0,1},{-1,0},{1,0}};//左、右、上、下

char maze[N+1][N+1];
int map1[N+1][N+1]={0},map2[N+1][N+1]={0};

int R,C;

int Jadge(int i,int j)
{
    if(maze[i][j]!='#'&&!map1[i][j])
        return 1;
    else
        return 0;
}

void DFS(int i,int j)
{   
    int t;
    int nexti,nextj;
    map1[i][j]=1;
    if(maze[i][j]=='S'||maze[i][j]=='T'||maze[i][j]=='+')
    {
        for(t=0;t<4;t++)
        {
            nexti=i+go[t].i;
            nextj=j+go[t].j;
            if(Jadge(nexti,nextj))
                DFS(nexti,nextj);
        }
    }
    else if(maze[i][j]=='|')
    {
        for(t=2;t<4;t++)
        {
            nexti=i+go[t].i;
            nextj=j+go[t].j;
            if(Jadge(nexti,nextj))
                DFS(nexti,nextj);
        }
    }
    else if(maze[i][j]=='-')
    {
        for(t=0;t<2;t++)
        {
            nexti=i+go[t].i;
            nextj=j+go[t].j;
            if(Jadge(nexti,nextj))
                DFS(nexti,nextj);
        }
    }
     else if(maze[i][j]=='.')
    {
        t=3;
        nexti=i+go[t].i;
        nextj=j+go[t].j;
        if(Jadge(nexti,nextj))
            DFS(nexti,nextj);
    }
}

int main()
{
    memset(maze,'#', sizeof(maze));
    scanf("%d %d\n",&R,&C);
    int i,j;
    int is,js,it,jt;
    for(i=1;i<=R;i++)
    {
        for(j=1;j<=C+1;j++)
        {   
            scanf("%c",&maze[i][j]);
            if(maze[i][j]=='\n')
            {
                maze[i][j]='#';
            }
            if(maze[i][j]=='S')
            {
                is=i;
                js=j;
            }
            else if(maze[i][j]=='T')
            {
                it=i;
                jt=j;
            }            
        }
    }
    DFS(is,js);
    memcpy(map2,map1,sizeof(map1));

    if(map2[it][jt])
    {
        int count=0;
        for(i=0;i<=R;i++)
        {
            for(j=0;j<=C+1;j++)
            {
                if(map2[i][j])
                {
                    memset(map1,0,sizeof(map1));
                    DFS(i,j);
                    if(!map1[it][jt])
                        count++;
                }
            }
        }
        printf("%d",count);
    }
    else
    {
        printf("I'm stuck!");
    }
    return 0;
}