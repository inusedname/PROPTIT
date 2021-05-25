#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t)
    {
        int a, b, c, d, e;
        long long i;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        for (i = 1; i < 1000000000000000000; i++)
            if (i%a==0&&i%b==0&&i%c==0&&i%d==0&&i%e==0)
            {
                   printf("%d", i);
                   break;
            }
        printf("\n");
        t--;
    }
}