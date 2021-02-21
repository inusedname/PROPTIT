#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t)
    {
        long long n;
        scanf("%d", &n);
        int i = 0;
        for (i = 2; i <= sqrt(n);i++)
            while (n%i==0)
            {  
                printf("%d ", i);
                n = n / i ;
            }
        if (n!=1)
            printf("%d", n);
        printf("\n");
        t--;
    }
}