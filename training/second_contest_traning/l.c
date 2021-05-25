#include <stdio.h>
long long subtract(int n)
{
    int i;
    long long dem = 0;
    for (i = 2; i <= n;i++)
    {
        long long tam = i;
        if (tam%2==0)
            while(tam%2==0)
            {
                dem++;
                tam = tam / 2;
            }

        if (tam%5==0)
            while(tam%5==0)
            {
                dem--;
                tam = tam / 5;
            }
    }
    return dem;
}
int main()
{
    long long n;
    scanf("%lld", &n);
    long long ans = subtract(n) % 4;
    if (subtract(n))
        switch (ans)
        {
            case 0 : 
                ans = 6;
                break;
            case 1 :
                ans = 2;
                break;
            case 2 :
                ans = 4;
                break;
            case 3 :
                ans = 8;
                break;
        }
    else
        ans = 1;
    long long i;
    long long k=1;
    for (i = n; i > 2;i--)
    {
        int temp = i;
        if (temp%2==0)
        {
            while (temp%2==0)
                temp = temp / 2;
        }
        if (temp%5==0)
        {
            while (temp%5==0)
                temp = temp / 5;
        }
            k = ((k % 10) * temp) % 10;
    }
    printf("%lld",(k*ans)%10);
}