#include <stdio.h>
#include <math.h>
int main()
{
    int l, r;
    int i, j ;
    scanf("%d%d", &l, &r);
    int dem = 0;
    int num = 0;
    for (i = l + 1; i < r;i++)
    {
        dem = 0;
        for (j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
                if (j == i / j)
                    dem++;
                else
                    dem = dem + 2;
        }
        if (dem%2!=0)
            num++;
    }
    printf("%d", num);
}   