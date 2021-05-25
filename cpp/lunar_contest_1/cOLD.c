#include <stdio.h>
 
int main()
{
    int t;
    scanf("%d", &t);
    while (t)
    {
        unsigned long long a, b, c;
        scanf("%llu%llu%llu",&a,&b,&c);
        unsigned long long af = a, bf = b, cf = c;
        unsigned long long uc, bc;
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
        uc = b;
        bc = (af / uc) * bf;
        //a & b changed
        if (c%uc)
            uc = 1;
        unsigned long long bcf = bc;
        while (c>0)
        {
            if (c<bc)
            {
                unsigned long long i = c;
                c = bc;
                bc = i;
            }
            c = c % bc;
        }
        bc = (bcf / bc) * cf;
        printf("%llu %llu", uc, bc);
        printf("\n");
        t--;
    }
}