#include<stdio.h>
#include<math.h>
int nto(int n)
{
    int i;
    for (i = 2; i <= sqrt(n);i++)
        if (n%i==0)
            return 0;
    return 1;
}
int sum(int n)
{
    int temp = n;
    int r, dem = 0;
    while (n>0)
    {
        r = n % 10;
        dem = dem + r;
        n = n / 10;
    }
    if (nto(dem))
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (sum(n)&&nto(n))
        printf("YES");
    else
        printf("NO");
}