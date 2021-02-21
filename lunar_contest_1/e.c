#include <stdio.h>

int main()
{
    long long a, b;
    int dem = 0;
    int i = 2;
    scanf("%lld %lld", &a, &b);
    if (a>b)
    {
        if(a%b)
            goto A;
        a = a / b;
    }
    else
    {
        if (b%a)
            goto A;
        a = b / a;
    }
    while (i<4)
    {
        while (a%i==0)
        {
            dem++;
            a = a / i;
        }
        i++;
    }
    A: if (!dem)
        dem--;
    printf("%d", dem);
}