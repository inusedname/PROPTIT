#include <stdio.h>

int max(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int i;
    for (i = max(a, b); i <= a * b;i=i+max(a,b))
        if (i%a==0&&i%b==0)
        {
            printf("%d", i);
            printf("\n%lld", (long long)(a * b) / i);
            break;
        }
}