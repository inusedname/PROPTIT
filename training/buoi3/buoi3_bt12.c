#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i = 2;
    while (i<=sqrt(n))
    {
        if (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
        else
            {i++;}
    }
    if (n>1)
        printf("%d", n);
}