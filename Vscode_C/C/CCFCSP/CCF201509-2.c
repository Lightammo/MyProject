#include<stdio.h>

int t;
int Datecut(int date,int Year)
{
    int R;
    t=1;
    if((Year%4==0&&Year%100!=0)||Year%400==0)
        R=29;
    else
        R=28;
    switch(1)
    {
        case 1 :{if(date>31) 
                    {date-=31;t++;}
                else break;}
        case 2 :{if(date>R) 
                    {date-=R;t++;}
                else break;}
        case 3 :{if(date>31) 
                    {date-=31;t++;}
                else break;}
        case 4 :{if(date>30) 
                    {date-=30;t++;}
                else break;}
        case 5 :{if(date>31) 
                    {date-=31;t++;}
                else break;}
        case 6 :{if(date>30) 
                    {date-=30;t++;}
                else break;}
        case 7 :{if(date>31) 
                    {date-=31;t++;}
                else break;}
        case 8 :{if(date>31) 
                    {date-=31;t++;}
                else break;}
        case 9 :{if(date>30) 
                    {date-=30;t++;}
                else break;}
        case 10:{if(date>31) 
                    {date-=31;t++;}
                else break;}
        case 11:{if(date>30) 
                    {date-=30;t++;}
                else break;}
        case 12:{if(date>31) 
                    {date-=31;t++;}
                else break;}
    }
    return date;
}

int main()
{
    int d,days=0,month=0,year;
    scanf("%d%d",&year,&d);
    days=Datecut(d,year);
    month=t;
    printf("%d\n%d",month,days);
    return 0;
}