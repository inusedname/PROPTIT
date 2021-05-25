#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t)
    {
        int n;
        scanf("%d", &n);
        int dem = 0;
        while(1)
        {
            if (n==1)
            {   
                dem++;
                printf("%d", dem);
                break;
            }
            if (n%2==1)
                dem++;
            n = n / 2;
        }
        printf("\n");
        t--;
    }
    
}