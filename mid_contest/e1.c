#include <stdio.h>
#include <math.h>
int ngto(int multi)
{
    if (multi==1||multi==0)
        return 0;
    int i;
    for (i = 2; i <= sqrt(multi);i++)
        if (multi%i==0)
            return 0;
    return 1;
}
int ktdx(int i)
{
    int temp = i;
    int sum = 0, r;
    int multi = 1;
    while (i>0)
    {
        r = i % 10;
        sum = sum * 10 + r;
        i = i / 10;
        multi = multi * r;
    }
    if (sum == temp && ngto(multi))
        return 1;
    else
        return 0;
}
int main()
{
    int a, b;
    int q;
    scanf("%d%d", &a, &b);
    for (q = a + 1; q < b;q++)
    {
        if (ktdx(q))
            printf("%d ", q);
    }
}