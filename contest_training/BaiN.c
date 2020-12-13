#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    int x = x2 - x1;
    int y = y2 - y1;
    int a = x4 - x3;
    int b = y4 - y3;
    if (x!=0&&y!=0&&a!=0&&b!=0)
        {
            if(x*b==a*y)
                printf("NO");
                else
                    printf("YES!");
        }
    if ((x==0&&a==0)||(y==0&&b==0))
        printf("NO");
    if ((x==0&&b==0)||(y==0&&a==0))
        printf("YES!");
    int dem = 0;
    if (x==0)
        dem++;
    if (y==0)
        dem++;
    if (a==0)
        dem++;
    if (b==0)
        dem++;
    if (dem==1)
        printf("YES!");
}