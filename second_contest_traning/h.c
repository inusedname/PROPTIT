#include <stdio.h>
#include <math.h>
int Ngto (int n)
{
    if (n==1)
        return 0;
    for (int i = 2; i <= sqrt(n);i++)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n, i;
    scanf("%d", &n);
    if (n==1)
    {
        printf("-1");
        return 0;
    }
    for (i = 2; i <= n;i++)
    {
        if (i==10||i==100||i==1000||i==10000)
            i = 2 * i + 1;
        int temp = i;
        while (1)
        {
            if (!Ngto(temp)) break;
            if (temp<10)
            {
                printf("%d ", i);
                break;
            }
            else temp = temp / 10;
        }
    }
}