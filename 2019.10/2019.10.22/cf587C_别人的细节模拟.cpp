// By fearlessgao, contest: Codeforces Round #587 (Div. 3), problem: (C) White Sheet, Accepted, #

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int x1,x2,y1,y2,X1,X2,Y1,Y2;
int main()
{
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for(int i=0;i<2;i++)
    {
        scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
        if(X1<=x1&&X2>=x2)
        {
            if(y1>=Y1)y1=max(y1,Y2);
            if(y2<=Y2)y2=min(y2,Y1);
        }
        if(Y1<=y1&&Y2>=y2)
        {
            if(x1>=X1)x1=max(x1,X2);
            if(x2<=X2)x2=min(x2,X1);
        }
    }
    if(x1>=x2&&y1>=y2)printf("NO\n");
    else printf("YES\n");
    return 0;
}