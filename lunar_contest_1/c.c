#include <stdio.h>
unsigned long long UCLN(unsigned long long a,unsigned long long b)
{
    while (a>0)
    {
        if (a<b)
        {
            unsigned long long i = a;
            a = b;
            b = i;
        }
        a = a % b;
    }
    return b;
}
unsigned long long BCNN(unsigned long long a, unsigned long long b) 
{    
    return (a / UCLN(a,b)) * b;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        unsigned long long a, b, c;
        scanf("%llu%llu%llu", &a, &b, &c);
        unsigned long long uc = UCLN(a, b);
        unsigned long long bc = (a / uc) * b;
        printf("%llu %llu", UCLN(uc,c), BCNN(bc,c));
        printf("\n");
    }
}