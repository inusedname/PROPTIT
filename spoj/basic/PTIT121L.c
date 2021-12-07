#include <stdio.h>
#include <math.h>
#define ll long long

int ktcp(ll x)
{
    int sq = sqrt(x);
    if ((ll)sq * sq == x)
        return 1;
    return 0;
}
void swap(ll *x, ll *y)
{
    ll tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int flag = 0;
    ll a1, b1, a2, b2, a3, b3;
    scanf("%lld%lld%lld%lld%lld%lld", &a1, &b1, &a2, &b2, &a3, &b3);
    if (a1 > b1)
        swap(&a1, &b1);
    if (a2 > b2)
        swap(&a2, &b2);
    if (a3 > b3)
        swap(&a3, &b3);
    ll area = a1 * b1 + a2 * b2 + a3 * b3;
    if (ktcp(area)) // tổng diện tích là 1 số chính phương 4 9 16 25...
    {
        // ba cạnh lớn của ba hình chữ nhật bằng nhau và bằng tổng của ba cạnh con
        if (b1 == b2 && b1 == b3 && b1 == a1 + a2 + a3)
            flag = 1;
        else
        {
            // cạnh lớn nhất trong cả 3 hình. có một cặp cạnh bằng nhau trong hai hình còn lại và có giá trị bằng cạnh lớn nhất kia trừ đi cạnh bé của cùng hình đó.
            if (b1 > b2 && b1 > b3)
            {
                ll u = b1 - a1;
                if ((a2 == u || b2 == u) && (a3 == u || b3 == u))
                    flag = 1;
            }
            else if (b2 > b1 && b2 > b3)
            {
                ll u = b2 - a2;
                if ((a1 == u || b1 == u) && (a3 == u || b3 == u))
                    flag = 1;
            }
            else
            {
                ll u = b3 - a3;
                if ((a1 == u || b1 == u) && (a2 == u || b2 == u))
                    flag = 1;
            }
        }
    }
    if (flag == 1)
        printf("YES");
    else
        printf("NO");
}
