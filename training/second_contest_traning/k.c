#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    n = n - 1;
    while (n>=0)
    {
        printf("%d ", n);
        n--;
    }
}