#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n * n;i++)
    {
        if(i%n==0)
            printf("%d\n", i);
        else 
        {
            printf("%d ", i);
        }
    }
}