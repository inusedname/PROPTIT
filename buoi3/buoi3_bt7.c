#include <stdio.h>
#include <math.h>
int main ()
{
    int n;
    scanf("%d",&n);
    int nga = n-1;
    int sao = 1;
    for (int i=1; i<2*n; i++)
    {
        for (int j=1; j<=abs(nga); j++)
            {printf("~");}
        for (int q=1; q<=sao; q++)
            {printf("*");}
        nga--;
        if(i<n)
        {
            sao=sao+2;
        }
        else 
        {
            sao=sao-2;
        }
        printf("\n");
    }
}
