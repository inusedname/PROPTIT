#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long a, b, n;
        scanf("%lld%lld%lld", &a, &b, &n);
        if (n % a == b)
            printf("%lld", n);
        // số phải có dạng : b+ka với k=0,1,2...
        // b + ka <= n
        // ka <= n - b
        // k <= (n - b) / a
        else
        {
            int index = floor((n - b) / a);
            printf("%lld", b + index * a);
        }
        printf("\n");
    }
}