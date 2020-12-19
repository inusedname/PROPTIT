#include<stdio.h>
int max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}
int main()
{
    int a, b;
    long long lcm, i;
    scanf("%d%d", &a, &b);
    for (i = max(a,b); i <= a * b;i=i+i)
    {
        if (i%a==0&&i%b==0)
            break;
    }
    printf("%lld", (a*b)/i);
}