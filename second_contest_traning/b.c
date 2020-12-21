#include<stdio.h>
#include <math.h>
int main()
{
    int n;
    int i = 2;
    int dem = 0;
    scanf("%d",&n);
    while (n>1)
    {
        if (n%i==0) 
        {
            dem++;
            n = n / i;
        }
        else 
        {
            if (dem!=0)
            {
                printf("%d^%d x ", i, dem);
            }
            dem = 0;
            i++;
        }
    }
    if (n==1)
        printf("%d^%d  ", i, dem);
    printf("\b\b ");
}