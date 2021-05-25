#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    int i = 2;
    int count = 0;
    scanf("%d",&n);
    while(i<=sqrt(n))
    {
        while (n%i==0)
        {
            count++;
            n = n / i;
        }
        if (count)
            if (n!=1)
                printf("%d^%d x ", i, count);
            else
                printf("%d^%d", i, count);
        i++;
        count = 0;        
    }
    if (n>1)
        printf("%d^%d", n, count + 1);
}