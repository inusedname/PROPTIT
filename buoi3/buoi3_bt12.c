#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n;i++)
    {
        if (n==1)
            break;
        while (1)
        {
            if (n%i==0)
            {
                printf("%d ", i);
                n = n / i;
            }
            else
                break;
        }
    }
}