#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        unsigned long long n;
        scanf("%llu", &n);
        if (n % 2)
        {
            printf("0\n");
            continue;
        }
        float f = log2(n);
        int k = floor(f);
        while (1)
        {
            unsigned long long x = pow(2, k);
            if (n % x == 0)
            {
                printf("%d", k);
                break;
            }
            else
                k--;
        }
        printf("\n");
    }
}