#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int dem = 0;
    for (int i = 1; i <= sqrt(n);i++)
    {
        if (n%i==0)
            if (i==n/i)
                dem++;
            else
                dem = dem + 2;
    }
    printf("%d", dem);
}