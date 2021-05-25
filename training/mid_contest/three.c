#include <stdio.h>
#include <math.h>
int Ktcp(int i)
{
    if ((int)sqrt(i)==(float)sqrt(i))
        return 1;
    else
        return 0;
}
int main()
{
    long long n;
    scanf("%lld", &n);
    int sum = 0;
    int i;
    for (i = 1;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {
            if(i==n/i)
            {
                if (Ktcp(i))
                {
                    sum++;
                }
            }
            else 
            {
                if (Ktcp(i))
                {
                    sum++;
                }
                if (Ktcp(n/i))
                {
                    sum++;
                }
            }
        }
    }
    printf("%d", sum);
}