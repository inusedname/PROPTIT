#include <stdio.h>
#include <math.h>

int main ()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n;i++)
    {
        int dem = 0;
        for (int j = 2; j <= sqrt(i);j++)
            if (i%j==0)
            {
                dem++;
                break;
            }
        if(!dem)
            printf("%d ", i);
    }
}